#include "MenuOps.h"

extern int free_size;			//Initialy everything is free
extern int free_ele;				

extern int List_No;			//Global variable which will store the number of lists created 
extern int Objects[MAX_SIZE];
extern int Heads[MAX_LIST];
extern int Count[MAX_LIST];		//Array that will store the number of elements of the list corresponding to each index. eg: Count[1] contains number of elements in List 1

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void initialize_Object_array()
{
	for(int i=1;i<MAX_SIZE;i=i+3)
	{
		Objects[i] = i+2; 			//A loop which will store the only nexts of each node and in the end store NULL in the second last index
		Objects[i+1] = -1;
	}
	Objects[MAX_SIZE-2] = -1;
	Heads[0] = 0;	
	Count[0] = MAX_ELE;
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int initialize_menu()
{
	int option_selected;
		
	printf("\nSelect an option: \n");
       	printf("1.\tCreate a new list.\n");
       	printf("2.\tInsert a new element in a given list in sorted order\n");
       	printf("3.\tDelete an element from a given list\n");
       	printf("4.\tCount total elements excluding free list\n");
       	printf("5.\tCount total elements of a list\n");
      	printf("6.\tDisplay all lists\n");
       	printf("7.\tDisplay free list\n");
       	printf("8.\tPerform defragmentation\n");
       	printf("9.\tPress 0 to exit\n");
	
       	printf("\n\nO/P:\n");
       	printf("Select an option: ");
       	scanf("%d",&option_selected);

	printf("\n");
	return option_selected;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int menu_ops(int option)
{	
	switch(option)
	{
		case 1:
			Create_List();//Create new list
			break;
		case 2:
			Insert_In_List();//Insert new element
			break;
		case 3:
			Delete_Node();//Delete an element
			break;
		case 4:
			Count_Nodes();//count total elements excluding free
			break;
		case 5:
			Count_List();//count total elements in a list
			break;
		case 6:
			Display_List();//display all lists
			break;
		case 7:
			Display_Free();//Display free lists
			break;
		case 8:
			DEFRAGMENT();//Defragment
			break;
		case 9:
			printf("\nExiting the program!!!\n");
			return 0;		//exit
		case 0:
			printf("\nExiting the program!!!\n");
			return 0;		//exit
		default: 
			printf("Select a valid option\n\n");
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


