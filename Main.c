#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "MenuOps.h"

extern int free_size;			//Initialy everything is free
extern int free_ele;				
extern int List_No;			//Global variable which will store the number of lists created 
extern int Count[MAX_LIST];		//Array that will store the number of elements of the list corresponding to each index. eg: Count[1] contains number of elements in List 1


int main()
{		
	printf("Welcome to RAM allocation of Linked Lists\n\n");
	initialize_Object_array();		
	int option_sel;	
	do{
		option_sel = initialize_menu(); 	
		menu_ops(option_sel);
	}while((option_sel!=0)&&(option_sel!=9));
	return 0;
}










