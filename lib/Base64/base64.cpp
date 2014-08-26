#include "arduino.h"
#include "Base64.h"

static const base64_table[64] = {
	  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

void base64_encode(char* dst, const void* src, int len)
{
	unsigned char* p = src;
	int i=0;
	for( i=0; i <= len-3; i+=3 )
	{
		unsigned int c = (*p) | ((*(p+1))<<8) | ((*(p+2))<<16);
		for( int j=0; j < 4; ++j, ++dst )
		{
			*dst = base64_table[(c>>18)&0x3F];
			c <<= 6;
		}
		p += 3;
	}
	
	if( i < len )
	{
		unsigned int c = 0;
		const int n=len-i;
		for( ; i < len; ++i, ++p )
		{
			c |= *p;
			c <<= 8;
		}
		c <<= 8*(3-n);

		int j=0;
		for( ; j < n+1; ++j, ++dst )
		{
			*dst = base64_table[(c>>18)&0x3F];
			c <<= 6;
		}
		for( ; j < 4; ++j, ++dst )
		{
			*dst = '=';
		}
	}
}

//void base64_decode(char* dst, const void* src, int len);
