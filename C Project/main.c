/*
 * main.c
 *
 *  Created on: Mar 9, 2023
 *      Author: Ahmed Summra
 */
#include"project.h"

int main(void)
{
setbuf(stdout,NULL);
char input1;
main_list();
for(;;)
{
	scanf(" %c",&input1);   //take requirement from main list

	switch(input1)
	{
	case 'a':  //turn on the engine choice
		printf("the engine is ON \n");
		printf("************************ \n");
		strcpy(main_struct.engine_status,"ON");
		sub_list();
		main_app();
		break;
	case 'b':  //turn off the engine choice
		printf("the engine is OFF \n");
		printf("************************ \n");
		main_list();
		break;
	case 'c':  //quit the system choice
		printf("you have exited system \n");
		break;
	default :
		printf("error\n");
		break;
	}
	if((input1=='a'&&flag) || input1=='b'){  //the user didn't quit the system

		continue;
	}
	else  // the user quit the system
	{
		break;
	}
}
return 0;
}

