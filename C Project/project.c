/*
 * project.c
 *
 *  Created on: march 09, 2023
 *      Author: Ahmed Summra
 */

#include "project.h"


/*=============================GLOBAL VARIABLES===================================*/
struct status main_struct={"OFF","OFF",0,20,"OFF",125};
char flag=1;
/*================================================================================*/

/*=============================FUNCTIONS IMPLEMENTATION===========================*/
/*********************************************************************************
 * Name: main_list
 * arguments: void
 * returns: void
 * functionality: it prints out the main list to the user*/
void main_list(void){
	printf("a.Turn on the vehicle engine\n");
	printf("b.Turn off the vehicle engine\n");
	printf("c.Quit the system\n");
}
/*********************************************************************************/
/*********************************************************************************
 * Name: sub_list
 * arguments: void
 * returns: void
 * functionality: it prints out the sub list to the user*/
void sub_list(void){
printf("a.Turn off the engine \n");
printf("b.Set the traffic light color \n");
printf("c.Set the room temperature \n");
printf("d.Set the engine temperature \n");
}
/*********************************************************************************/
/*********************************************************************************
 * Name: set_traffic_light
 * arguments: a pointer to structure of type status
 * returns: void
 * functionality: it takes the required traffic color from the user and sets
 * the vehicle speed upon it */
void set_traffic_light(struct status *ptr)
{

	char input;
	printf("enter the traffic light color (R-G-O) \n");
	scanf(" %c",&input);
	switch(input)
	{
	case 'G':  //green color traffic required
	ptr-> vehicle_speed =100;
	strcpy(ptr->engine_status,"ON");
	break;
	case 'O':  //orange color traffic required
	ptr-> vehicle_speed=30;
	strcpy(ptr->engine_status,"ON");
	break;
	case 'R':  //red color traffic required
	ptr-> vehicle_speed=0;
	}
}
/*********************************************************************************/
/*********************************************************************************
 * Name: set_room_temp
 * arguments: a pointer to structure of type status
 * returns: void
 * functionality: it takes the required room temperature from the user and
 * decides if the AC will be ON or OFF it also maintains the room temperature */
void set_room_temp(struct status *ptr2)
{

	int input;
	printf("enter the room temperature \n");
	scanf("%d",&input);
	if(input<10 || input>30)
	{
	strcpy(ptr2->AC_status,"ON");
		ptr2->room_temperature=20;
	}
	else
	{
		strcpy(ptr2->AC_status,"OFF");
		ptr2->room_temperature=input;
	}

}
/*********************************************************************************/
/*********************************************************************************
 * Name: set_engine_temp
 * arguments: a pointer to structure of type status
 * returns: void
 * functionality: it takes the required engine temperature from the user and
 * decides if the engine controller will be ON or OFF it also maintains
 * the engine temperature */
void set_engine_temp(struct status *ptr3)
{

	int input;
	printf("enter the engine temperature \n");
	scanf("%d",&input);
	if(input<100 || input>150)
	{
		strcpy(ptr3->engine_temp_controller_status,"ON");
		ptr3->engine_temperature=125;
	}
	else
	{
		strcpy(ptr3->engine_temp_controller_status,"OFF");
		ptr3->engine_temperature=input;
	}

}
/*********************************************************************************/
/*********************************************************************************
 * Name: print status
 * arguments: void
 * returns: void
 * functionality: it prints out the current status of the system to the user */
void print_status(void)
{
	printf("the engine status is %s \n",main_struct.engine_status);
	printf("************************ \n");
	printf("the AC status is %s \n",main_struct.AC_status);
	printf("the vehicle speed is %dKM/H \n",main_struct.vehicle_speed);
	printf("the room temperature is %f degree \n",main_struct.room_temperature);
	printf("the engine temperature controller status is %s \n",main_struct.engine_temp_controller_status);
	printf("the engine temperature is %f degree \n",main_struct.engine_temperature);
}
/*********************************************************************************/
/*********************************************************************************
 * Name: main_app
 * arguments: void
 * returns: void
 * functionality: it represents the main application it takes what the user wants
 *to do and depending on this it jumps to the different functions. it handles the
 *printing of the status and the requirement if the speed of the vehicle is 30km/h*/
void main_app(void)
{
char input2;
static char flag_room=1;
static char flag_engine=1;

for(;;)
{
scanf(" %c",&input2); //the required from the sub list
switch(input2)
	{
	case 'a':  //turn off the engine choice
		printf("the engine is OFF \n");
		printf("************************ \n");
		main_list();
		break;
	case 'b':  //set traffic light choice
		set_traffic_light(&main_struct);
		flag_room=1;
		flag_engine=1;
		break;
	case 'c':  //set room temperature choice
		set_room_temp(&main_struct);
		flag_room=1;
		break;
	case 'd':  //set engine temperature choice
		set_engine_temp(&main_struct);
		flag_engine=1;
		break;
	default:
		printf("ERROR \n");
		flag =0;
		break;
	}

	if(main_struct.vehicle_speed==30&&flag_room) //to apply the requirement when speed
	{							//is equal to 30km/h once each time the speed hits 30
		strcpy(main_struct.AC_status,"ON");
		main_struct.room_temperature=main_struct.room_temperature*1.25+1;
	}
	if(main_struct.vehicle_speed==30&&flag_engine)
	{
		strcpy(main_struct.engine_temp_controller_status,"ON");
		main_struct.engine_temperature=main_struct.engine_temperature*1.25+1;
	}

	if(input2=='b' || input2=='c' || input2=='d')// the user has changed something so print out the current status
	{
		print_status();
		printf("=========================\n");
		sub_list();
		flag_engine=0;
		flag_room=0;
		continue;
	}
	else  		//turn off the engine choice or the user enter a wrong input
	{
		break;
	}

}
}



