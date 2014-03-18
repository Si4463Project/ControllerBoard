#include <string.h>
#include "protocol.h"



return_code init_protocol(void)
{
	// these must exist !!
	proto.low_level_recv=&low_level_recv; // this function shall not be changed it will be the one called from the lower level
	proto.low_level_send=0;
	proto.heart_beat=0; //this is an optional heart beat callback!
 
	return PROTO_RET_OK;

}


return_code connect(Connection* c, const unsigned char addr)
{

	packet_header hdr;

	//make sure there will be no bus faults !
	if (proto.low_level_send==0) {
		return PROTO_RET_FAILED;
	}

	//here we need to build a packet with only the header and send it to the lower level
	//this call shall check if the connection isn't already setup first
	if ((c->state!=CONNECTION_STATE_OFF) && (c->state!=CONNECTION_STATE_DISCONNECTED)) {
		// we are already connected or trying to ...
		return PROTO_RET_FAILED;
	}
	
	memset(c,0,sizeof(Connection));
	c->remote_address=addr;

	//now build a packet and init the connection
	hdr.address=addr;
	hdr.flags=0;
	hdr.seq_no=0;
	hdr.size=0; //no payload
	//update the connection state
	c->state=CONNECTION_STATE_SYN;


	// TODO make test with the exactly equal ... to ensure proper sync on data
	if (proto.low_level_send((const char*)&hdr,sizeof(packet_header))<sizeof(packet_header)) {
		//some error 
		c->state=CONNECTION_STATE_OFF;
		return PROTO_RET_FAILED;
	}

	//now we sent our SYN packet ... lets wait for the other party !

	return PROTO_RET_OK;
}

return_code listen(Connection* c)
{

	if ((c->state!=CONNECTION_STATE_OFF) && (c->state!=CONNECTION_STATE_DISCONNECTED)) {
		// we are already connected or trying to ...
		return PROTO_RET_FAILED;
	}

	//put this connection into listen mode by simply setting up the state to be in listening mode 
	c->state=CONNECTION_STATE_LISTEN;


	return PROTO_RET_OK;
}


//here we will read from the lower level
// Here we need to figure out what state we are in so we can act accordingly
unsigned char low_level_recv(Connection *c, char *ptr, unsigned char sz)
{
	/*
		This function shall be called by the lower level with new data.
		Our responsability here will be to take the data and make a good packet out of it
		once that is done we can pursue with the generation of other events
	*/




	return 0;
}


return_code disconnect(Connection *c)
{
	//in this case all we care about is to notify the other pary that we no longer have a logical connection
	packet_header hdr;

	hdr.address=c->remote_address;
	hdr.flags=FLAG_DISCON;
	hdr.seq_no=++(c->last_sequence_number);
	hdr.size=0;


	// TODO make test with the exactly equal ... to ensure proper sync on data
	if (proto.low_level_send((const char*)&hdr,sizeof(packet_header))<sizeof(packet_header)) {
		//some error 
		c->errors++;
		c->state=CONNECTION_STATE_OFF;
		return PROTO_RET_FAILED;
	}

	c->state=CONNECTION_STATE_DISCONNECTED;

	//call our callback
	if (c->_onClose!=0) c->_onClose(c);

	return PROTO_RET_OK;
}

//may be removed ... or leave to be determined at later point in time
return_code recv_data(Connection *c, unsigned char *payload, unsigned char *size)
{

	return PROTO_RET_OK;
}



return_code send_data(Connection *c, const unsigned char *payload, unsigned char *size)
{
	unsigned char len=0;

	if (c->state!=CONNECTION_STATE_CONNECTED) {
		// we are not connected so no sending!!
		return PROTO_RET_FAILED;
	}
	

	c->pkt.header.address=c->remote_address;
	c->pkt.header.flags=FLAG_CONN;
	c->pkt.header.seq_no=++(c->last_sequence_number);
	c->pkt.header.size=*size;
	len=*size+sizeof(packet_header);
	//now copy the data
	
	memset(c->pkt.payload,0,sizeof(c->pkt.payload));
	memcpy(c->pkt.payload,payload,(size_t)size);


	// TODO make test with the exactly equal ... to ensure proper sync on data
	if (proto.low_level_send((const char*)&c->pkt,len)<len) {
		//some error 
		c->state=CONNECTION_STATE_OFF;
		c->errors++;
		return PROTO_RET_FAILED;
	}


	return PROTO_RET_OK;
}




