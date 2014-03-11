#include "tw88.h"


static uint8_t TW88Registers[256];


uint8_t TW88_Init(void)
{
	//first thing to do would be to make sure that we are on first page
	while (TW88Write(0xff,0x00)==0) {
			//now we detected an error ... we shall resend ?
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
		
	
	while (TW88Write(0x1C, 0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x02,0x40)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x04,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x06,0x03)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x07,0x02)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x08,0x15)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x09,0xF0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
			
	}
	while (TW88Write(0x0A,0x19)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x0B,0xD0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x0C,0xDC)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x0D,0x15)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x10,0x00)==0) {   //brightness
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x11,0x50)==0) { // contrast
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x12,0x70)==0) { //sharpness
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x13,0x9E)==0) { //chroma U
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x14,0x90)==0) {  //chroma V
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x15,0x00)==0) {  //hue 
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x17,0x33)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x18,0x44)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x1C,0x0F)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x1D,0x7F)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x1E,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x1F,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x20,0x50)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
		while (TW88Write(0x21,0x42)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x22,0xF0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0x23,0xD8)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0x24,0xBC)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x25,0xB8)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x26,0x44)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x27,0x2a)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x28,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x29,0x15)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x2A,0x78)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x2B,0x44)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x2C,0x30)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x2D,0x14)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x2E,0xA5)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
				
		while (TW88Write(0x2F,0xE0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x33,0x85)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x34,0x1A)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x35,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x38,0x8E)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x40,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x41,0x20)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x42,0x04)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x43,0x22)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x44,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x45,0x54)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x46,0x20)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x47,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x48,0xCF)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x49,0x20)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0x4A,0x13)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x4B,0x13)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x4C,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x4D,0x30)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x4E,0x64)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x4F,0x1E)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x50,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x60,0xE0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x61,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x62,0x7C)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x63,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x64,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x65,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x66,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x67,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x68,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x69,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x6A,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0x6B,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x6C,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
		while (TW88Write(0x6D,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x6E,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x70,0x60)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x71,0x60)==0) { 
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x72,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x73,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x74,0x60)==0) { ///brightness
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x75,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0x76,0x80)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x77,0x03)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x78,0x3B)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x7C,0x1C)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0x7D,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x7E,0xF6)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x7F,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x80,0x10)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x81,0x1D)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x82,0x03)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x83,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x84,0x67)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x85,0x94)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x86,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0x87,0xFF)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x88,0xCA)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0x89,0x02)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xB0,0x40)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xB1,0x02)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xB2,0xDB)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xB3,0x14)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xB4,0x10)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xB5,0x20)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xB6,0x33)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xBB,0x12)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	
	while (TW88Write(0xB7,0x0D)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xB8,0x04)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xB9,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xBA,0xE0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	

	while (TW88Write(0xBC,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xBD,0x08)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0xBE,0xC2)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	
	
	while (TW88Write(0xBF,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	
	while (TW88Write(0xC0,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xC1,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	

	while (TW88Write(0xC2,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC3,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC4,0x40)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC6,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC7,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC8,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xC9,0xED)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xCA,0xE7)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xD2,0xFF)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xD3,0x07)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xD4,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xD5,0x3F)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xD6,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xD7,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xD8,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xDA,0x3D)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xDB,0xC3)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xDC,0xFC)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xDD,0x70)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	while (TW88Write(0xDE,0x6F)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0xDF,0x6F)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xE0,0x10)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF0,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF4,0x16)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF6,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF7,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF8,0xA0)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xF9,0x01)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xFA,0x30)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xFB,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	while (TW88Write(0xFC,0x48)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xFD,0x30)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xFE,0x51)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xFF,0x01)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xC0,0x01)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}


	while (TW88Write(0xFF,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
		
	return 1;
}





void I2CReset(I2C_TypeDef *i2cport,GPIO_TypeDef *port,uint8_t scl,uint8_t sda)
{
		
		I2C_Cmd(i2cport,DISABLE);
		Delay(4);
		I2C_Cmd(i2cport,ENABLE);
}




uint8_t TW88Write(uint8_t regAddr, uint8_t data)
{
		int8_t retries;
		retries=3;
	
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_BUSY) != RESET) { if ((retries--)>0) Delay(1); else return 0;}
	
		//I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);
		/* Configure slave address, nbytes, reload, end mode and start or stop generation */
		I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_Reload_Mode, I2C_Generate_Start_Write);
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_TXIS) == RESET) {if ((retries--)>0) Delay(1); else return 0; }
		//send the register address	
		I2C_SendData(I2C1, (uint8_t) regAddr);
		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_TCR) == RESET){if ((retries--)>0) Delay(1); else return 0;}

		
		/* Configure slave address, nbytes, reload, end mode and start or stop generation */
		I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_AutoEnd_Mode, I2C_No_StartStop);		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_TXIS) == RESET) {if ((retries--)>0) Delay(1); else return 0;}
		
		I2C_SendData(I2C1, data);
		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_STOPF) == RESET) {if ((retries--)>0) Delay(1); else return 0;}
		
		I2C_ClearFlag(I2C1, I2C_ICR_STOPCF);	
			
		
		return 1;
}


uint8_t TW88Read(uint8_t regAddr, uint8_t *data)
{
		
	
		int8_t retries;
		retries=3;
	
	  while(I2C_GetFlagStatus(I2C1, I2C_ISR_BUSY) != RESET) { if ((retries--)>0) Delay(1); else return 0;}
	
		//I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);
		/* Configure slave address, nbytes, reload, end mode and start or stop generation */
		I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_SoftEnd_Mode, I2C_Generate_Start_Write);
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_TXIS) == RESET) { if ((retries--)>0) Delay(1);else return 0;}
		//send the register address	
		I2C_SendData(I2C1, (uint8_t) regAddr);
		
		
		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_TC) == RESET){ if ((retries--)>0) Delay(1); else return 0;}
		
		///I2C_GenerateSTOP(I2C1,ENABLE);
		
		
		/* Configure slave address, nbytes, reload, end mode and start or stop generation */
		I2C_TransferHandling(I2C1, TW88_I2C_ADDR, 1, I2C_AutoEnd_Mode, I2C_Generate_Start_Read);		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_RXNE) == RESET) {if ((retries--)>0) Delay(1); else return 0;}
		
		*data = I2C_ReceiveData(I2C1);
		
		retries=3;
		while(I2C_GetFlagStatus(I2C1, I2C_ISR_STOPF) == RESET) {if ((retries--)>0) Delay(1); else return 0;}
		
		I2C_ClearFlag(I2C1, I2C_ICR_STOPCF);	
			
		
		return 1;
	
}


uint8_t TW88_AddOSD_Win(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
	/// OSD
	while (TW88Write(0x94,0x0C)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}

	
	while (TW88Write(0x9E,0x00)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0x9C,0x03)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	while (TW88Write(0xA1,x)==0) { // OSD H start
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	while (TW88Write(0xA2,y)==0) {  // OSD V STart
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xA3,w)==0) {  // OSD H Len
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}		
	while (TW88Write(0xA4,h)==0) {  // OSD V Len
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	
	
	while (TW88Write(0xA5,0x86)==0) {  // OSD Window border
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	

	while (TW88Write(0x94,0x00)==0) {  //enable OSD RAM access
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}	

	for (uint8_t idx=0; idx<64;idx++) {
		


		while (TW88Write(0x9C,0x0F)==0) { //font color
				I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
		}		
		while (TW88Write(0x96,idx)==0) {  //RAM Address window position type of thing char index or something
				I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
		}	
		
		while (TW88Write(0x97,0x40+idx)==0) {  //char index
				I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
		}				
		while (TW88Write(0x98,0x07)==0) {
				I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
		}
			
	}		

	
	while (TW88Write(0x9F,0x01)==0) {
			I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
	}
	
	return 1;

}






void ReadAllTW88Regs(void)
{
	
	for (uint8_t x=0;x<=254;x++) {
		//	if (x==2) continue;
			while (TW88Read(x, &TW88Registers[x])==0) {
				  I2CReset(I2C1,GPIOB,GPIO_Pin_6,GPIO_Pin_7);
			}
	}
	
	
	
}
