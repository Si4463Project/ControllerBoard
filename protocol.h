/*

	Team 14 P2P Protocol Definition

	Asynchronous and connection oriented



*/

#ifndef PROTOCOL_H
#define PROTOCOL_H 1





#define PAYLOAD_SIZE 60


/*
	In flags we have also the ctrl bits
*/

#define FLAG_SYN 0x10
#define FLAG_SYN_ACK 0x20
#define FLAG_ACK 0x30
#define FLAG_CONN 0x01
#define FLAG_DISCON 0x02



//protocol return codes
typedef enum {PROTO_RET_OK=1,PROTO_RET_FAILED} return_code;

typedef enum {
	CONNECTION_STATE_OFF=0,
	CONNECTION_STATE_CONNECTED, 
	CONNECTION_STATE_DISCONNECTED, 
	CONNECTION_STATE_SYN, 
	CONNECTION_STATE_SYNACK,
	CONNECTION_STATE_ACK,
	CONNECTION_STATE_LISTEN
} connection_state;






typedef struct {
	unsigned char address;
	unsigned char flags;
	unsigned char seq_no;
	unsigned char size;
} packet_header;


typedef struct{
	packet_header header;
	unsigned char payload[PAYLOAD_SIZE];
} packet; 

/*
	Hope Gcc for arm knows about this forward way of declaring !!
*/
typedef struct Connection Connection;

typedef struct Connection{
	unsigned char state;
	unsigned int errors;
	unsigned int packets_received;
	unsigned char remote_address;
	unsigned char last_sequence_number;
	unsigned char packet_receive_offset;
	packet pkt; //this is a tricky thing .... long story: a love hate relationship kinda thing

	/* Event Callbacks*/
	void (*_onConnecting)(Connection *c);
	void (*_onConnected)(Connection *c);
	void (*_onDataReady)(Connection *c, unsigned char *ptr, unsigned char sz);
	void (*_onClose)(Connection *c);


} Connection;


/*
	Here we shall store the low level api to actually send the data over the air
*/
typedef struct {
	unsigned char (*low_level_send)(const char *ptr, unsigned char sz);
	unsigned char (*low_level_recv)(Connection *c, char *ptr, unsigned char sz);
	void (*heart_beat)(Connection *c);
} Protocol;


// main stuff for portability
Protocol proto;



/**

	All functions shall be re-entrant ! 

	TODO : Timeout implementation MUST BE DONE !!!!
**/


/*

	Public functions

*/

//initialize protocol structures
return_code init_protocol(void);
//creates a new connection to a given address
return_code connect(Connection* c, const unsigned char addr);

return_code listen(Connection* c);

// disconnect from the remote, logically ofcourse
return_code disconnect(Connection *c);

//tries to return a full data read if one is available 
// returns the payload as well as the size of the payload !
return_code recv_data(Connection *c, unsigned char *payload, unsigned char *size);
//try to send data over the wireless link
return_code send_data(Connection *c, const unsigned char *payload, unsigned char *size);



//External Wireless driver shall call this function in order to read any available data!
// This function shall be offered as part of the protocol structure for the external libs to be able to call it
unsigned char low_level_recv(Connection *c, char *ptr, unsigned char sz);





#endif
