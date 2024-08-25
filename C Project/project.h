/*
 * project.h
 *
 *  Created on: march 09, 2023
 *      Author: Ahmed Summra
 */

#ifndef PROJECT_H_
#define PROJECT_H_

/*================================INCLUDES=======================================*/
#include<stdio.h>
#include<string.h>
/*===============================================================================*/

/*================================EXTERNS========================================*/
extern struct status main_struct;
extern char flag;
/*===============================================================================*/

/*============================FUNCTIONS PROTOTYPES===============================*/
void main_list(void);
void sub_list(void);
void set_traffic_light(struct status *ptr);
void set_room_temp(struct status *ptr2);
void set_engine_temp(struct status *ptr3);
void print_status(void);
void main_app(void);
/*===============================================================================*/
/*===========================STRUCTURES DEFINITIONS==============================*/
struct status{
	char engine_status[40];
	char AC_status[40];
	int vehicle_speed;
	float room_temperature;
	char engine_temp_controller_status[40];
	float engine_temperature;
};
/*===============================================================================*/




#endif /* PROJECT_H_ */
