//
// grid.c 
// by c. dixson
// 24 march 2009
// using my lat and lon, calculate my grid square (assumes 42 58'23"N 70 55'3"W )
// see: maidenhead locator system http://en.wikipedia.org/wiki/maidenhead_locator_system
//

#include <stdio.h>


int main(void)
{
	const float FIELD_WIDTH = 20.0; 
	const float FIELD_HEIGHT = 10.0; 
	const float SQUARE_WIDTH = 2.0; 
	const float SQUARE_HEIGHT = 1.0;
	const float SUB_WIDTH = 0.0833333333333333;
	const float SUB_HEIGHT = 0.0416666666666667;
	const float SUB_SUB_WIDTH = 0.0083333333333333; 
	const float SUB_SUB_HEIGHT = 0.0041666666666667;

	char buff[9];
	sprintf(buff,"AA00AA00");

	float latitude = 42.9814;
	float longitude = -70.9483;
	float ilong, ilat = 0.0;
	
	latitude += 90.0;
	longitude += 180.0;
	
	ilong = (char)(longitude / FIELD_WIDTH);
	buff[0] += ilong; //F
	
	longitude -= (ilong * FIELD_WIDTH);
	ilat = (char)(latitude / FIELD_HEIGHT);
	buff[1] += ilat; //N

	latitude -= (ilat * FIELD_HEIGHT);
	ilong = (char)(longitude / SQUARE_WIDTH);
	buff[2] += ilong; //4

	longitude -= ilong * SQUARE_WIDTH;
	ilat = (char)(latitude / SQUARE_HEIGHT);
	buff[3] += ilat; //2
	
	latitude -= ilat * SQUARE_HEIGHT;
	ilong = (char)(longitude / SUB_WIDTH);
	buff[4] += ilong;
	
	longitude -= ilong * SUB_WIDTH;
	ilat = (char)(latitude / SUB_HEIGHT);
	buff[5] += ilat;
	
	latitude -= ilat * SUB_HEIGHT;
	ilong = (char)(longitude / SUB_SUB_WIDTH);
	buff[6] += ilong;
	
	ilat = (char)(latitude / SUB_SUB_HEIGHT);
	buff[7] += ilat;

	printf("buff = %s\n",buff);
	
	return 0;
}
