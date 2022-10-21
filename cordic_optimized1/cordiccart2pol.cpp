#include "cordiccart2pol.h"
#include<iostream>
using namespace std;
data_t  FACTOR = 0.6072529350088812561694;
data_t Kvalues[NO_ITER] = {				1,		0.5000000000,		0.25000000000,		0.12500000000,
							0.06250000000,		0.0312500000,		0.01562500000,		0.00781250000,
							0.00390625000,		0.0019531250,		0.00097656250,		0.00048828125,
							0.000244140625,		1.220703125e-04,	6.103515625e-05,	3.0517578125e-05,
							1.52587890e-05,		7.62939450e-06, 	3.81469725e-06, 	1.9073486300e-06,
							9.53674315e-07,		4.76837157e-07, 	2.38418578e-07, 	1.1920928900e-07,
							5.96046445e-08, 	2.98023222e-08,		1.49011611e-08,		7.4505805500e-09,
							3.72529028e-09,		1.86264514e-09,		9.31322570e-10,		4.6566128500e-10};

data_t angles[NO_ITER] = {	0.78539816339744828000, 0.46364760900080609000, 0.24497866312686414000, 0.12435499454676144000,
							0.06241880999595735000, 0.03123983343026827700, 0.01562372862047683100, 0.00781234106010111110,
							0.00390623013196697180, 0.00195312251647881880, 0.00097656218955931946, 0.00048828121119489829,
							0.00024414062014936177, 0.00012207031189367021, 0.00006103515617420877, 0.00003051757811552610,
							0.00001525878906131576, 0.00000762939453110197, 0.00000381469726560650, 0.00000190734863281019,
							0.00000095367431640596, 0.00000047683715820309, 0.00000023841857910156, 0.00000011920928955078,
							0.00000005960464477539, 0.00000002980232238770, 0.00000001490116119385, 0.00000000745058059692,
							0.00000000372529029846, 0.00000000186264514923, 0.00000000093132257462, 0.00000000046566128731,};


void cordiccart2pol(data_t x, data_t y, data_t &r,  data_t &theta)
{
	printf("=================Optimized1=================\n");
	// Write your code here
	data_t base_radian = 0.0;
	theta = 0.0;
	r = 0.0;
	if(y >= 0) {
		data_t temp = x;
		x = y;
		y = -temp;
		base_radian = 1.57079632679;
	}else{
		data_t temp = y;
		y = x;
		x = -temp;
		base_radian = -1.57079632679;
	}

	for(int j = 0; j < 32 ; j++){

		int sign = (y < 0) ? 1 : -1;

		data_t temp_x = x;

		x = x - sign * Kvalues[j] * y;
		y = y + sign * Kvalues[j] * temp_x;

		theta = theta - sign *  angles[j];
	}
	theta = theta + base_radian;
	r = x * FACTOR;
}
