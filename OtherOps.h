#ifndef _OTHER_OPS
#define _OTHER_OPS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX_SIZE 180			//Maximum number of nodes+prev+next elements in array
#define MAX_ELE (MAX_SIZE/3)		//Maxuimum number of nodes which can be inserted
#define MAX_LIST 10			//Maximum number of lists that can be made

void initialize_Object_array();


void Create_List();


void Insert_In_List();


void Delete_Node();


void Count_Nodes();


void Count_List();


void Display_List();


void Display_Free();


void DEFRAGMENT();


int Find_Last(int list_num);

#endif
