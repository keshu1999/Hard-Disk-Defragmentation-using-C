#include "OtherOps.h"


int free_size = MAX_SIZE;		//Initialy everything is free
int free_ele = MAX_ELE;				

int List_No = 0;			//Global variable which will store the number of lists created 
int Objects[MAX_SIZE];			//Array containing the elements with corresponding nexts and prevs	
int Heads[MAX_LIST];			//Array of index which store corresponding Head index of each List. eg:Head index of free list is stored in Heads[0], Head index of List 1 is stored in Heads[1] ..
int Count[MAX_LIST] = {0};		//Array that will store the number of elements of the list corresponding to each index. eg: Count[1] contains number of elements in List 1


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Create_List()
{
	free_size-=3;						//As soon as new list is created, free size is decreased by 3 units. It will be checked later that the free size is not becoming 0
	free_ele--;			
	int element;	
	List_No++;			
	printf("The sequence number of the newly created list is: %d\n",List_No);
	printf("\nEnter key value to be inserted in the newly created list -> %d: ",List_No);
	scanf("%d",&element);
	if(free_size<0)						//If the free size is not available, it will return to main with error 
	{
		printf("FAILURE: MEMORY NOT AVAILABLE\n\n");
		List_No--;
		return;
	}
	Heads[List_No] = Heads[0];			
	Heads[0] = Objects[Heads[0]+1];
	Objects[Heads[List_No]] = element;
	Objects[Heads[List_No]+2] = -1;
	Objects[Heads[List_No]+1] = -1;
	Count[List_No]++;
	Count[0]--;						//After creating a new list, count will increment by 1 for the corresponding List number and count will decrease for free array
	printf("SUCCESS!!!\n\n");
	return;
}


				
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void Insert_In_List()								//Insert in sorted order
{
	if(List_No==0)
	{
		printf("Please input a List first!!!\n");
		return;
	}	
	int list_num, last, key, temp, nfl;	
	printf("List you want to insert in: ");
	scanf("%d",&list_num);

	while((list_num>List_No)||(list_num<=0))				//If user tries to input a list which is not existent
	{
		printf("\nPlease insert a List Number from 1 to %d: ",List_No);
		scanf("%d",&list_num);
	}
	
	if(Heads[list_num]==-1)					//If the list had been deleted before, the head points to null and then to insert in list, we try to insert in
		Heads[list_num] = Heads[0];			//first free location and update head pointer

	printf("\nEnter the key value: ");
	scanf("%d",&key);
	free_size-=3;						//As soon as new element is created, free size is decreased by 3 units. It will be checked later that the free size is not becoming 0
	free_ele--;	
	if(free_size<0)								//If the free size is not available, it will return to main with error 
	{
		printf("FAILURE: MEMORY NOT AVAILABLE\n\n");
		return;
	}
	nfl= Objects[Heads[0]+1];						//NFL will store the next free location after element would have been inserted.
	if(Count[list_num]==0)							//If we want to insert in a list which has been deleted 
	{
		Objects[Heads[list_num]] = key;					//Insert key and then update next to -1. Prev is by default -1 for a free location
		Objects[Heads[list_num]+1] = -1;	
	}
	else
	{
		last = Find_Last(list_num);						//To store index of last before inserting
	
		//The next 4 lines will append the key to the end of the list
		Objects[Heads[0]+2] = Find_Last(list_num);	
		Objects[Heads[0]+1] = -1;
		Objects[Find_Last(list_num)+1] = Heads[0];
		Objects[Heads[0]] = key;
		
		//Heads[0] which is start off free location points to the new key inserted 
		//We will insert the element in the end and traverse from the start of the list, checking if key is greater than element of the list
		temp = Heads[list_num];
		while(Objects[temp+1]!=-1)						//Until we reach the last element
		{
			if(key>Objects[temp])
				temp = Objects[temp+1];					//If key is greater, just increment the pointer to next of the element
			else
			{	
				if(Objects[temp+2]!=-1)					//If the key to be inserted is lesser than the first element itself then the 
					Objects[Objects[temp+2]+1] = Heads[0];		//previous of the previous head is new head.
																		
				Objects[Heads[0]+1] = temp;				//Changing the nexts and the previous of element added, the net and the previous
				Objects[Heads[0]+2] = Objects[temp+2];
				Objects[temp+2] = Heads[0];
				Objects[last+1] = -1;					//Changing the next of last element to null which was made as nfl to point to key inserted
				break;	
			}
		}
		if(Objects[Heads[0]+2]==-1)						//Update the new head if it is inserted in the start
			Heads[list_num] = Heads[0];	
	}
	Heads[0] = nfl;								//Index of Next free Location updated
	Count[0]--;								//Number of elements in Free array decreased and that of in the list increased
	Count[list_num]++;

	printf("\nSUCCESS!!!\n\n");
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Delete_Node()
{
	if(List_No==0)
	{
		printf("Please input a List first!!!\n");
		return;
	}	
	int list_num, key, temp, next, prev;	
	printf("List you want to delete from : ");
	scanf("%d",&list_num);
	while((list_num>List_No)||(list_num<=0))				//If user tries to input a list which is not existent
	{
		printf("\nPlease insert a List Number from 1 to %d: ",List_No);
		scanf("%d",&list_num);
	}

	if(Count[list_num]==0)							//Suppose the list is empty
	{
		printf("\nFAILURE: LIST EMPTY\n");
		return;
	}

	printf("\nEnter the key value: ");
	scanf("%d",&key);
	
	temp = Heads[list_num];							
	while(temp!=-1)								//Traversing the list
	{
		if(Objects[temp]==key)
		{
			next = Objects[temp+1];					//Saving the next and prev indices in temporary variables
			prev = Objects[temp+2];
			
			Objects[temp+1] = Heads[0];				//We are adding the Node to the free list by appending it to start of free list
			Objects[temp+2] = -1;					
			Heads[0] = temp;					//Updating Free head to the index of element to be deleted

			if(prev!=-1)						//If it was the middle/last element
				Objects[prev+1] = next;
			if(next!=-1)						//If it was the start or the middle element
				Objects[next+2] = prev;
			if(prev==-1)						//For the deletion of head element, head array must be updated
				Heads[list_num] = next;

			Count[list_num]--;
			Count[0]++;
			free_size+=3;
			free_ele++;
			printf("\nSUCCESS!!\n");
			return;
		}
		temp = Objects[temp+1];						//temp going to next element
	}
	printf("\nFAILURE: ELEMENT NOT FOUND\n");				//After traversing the whole list, if key is not found
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void Count_Nodes()								//To count the total number of elements inserted
{
	if(List_No==0)
	{
		printf("Please input a List first!!!\n");
		return;
	}	
	int sum = 0;
	for(int i=1;i<MAX_LIST;i++)
		sum+=Count[i]; 
	printf("Total number of nodes in all lists are %d\n", sum);
}	

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Count_List()								//To count the number of elements in a given list number
{
	if(List_No==0)
	{
		printf("Please input a List first!!!\n");
		return;
	}
	int list_num;	
	printf("Enter the list number: ");
	scanf("%d",&list_num);
	while((list_num>List_No)||(list_num<=0))				//If user tries to input a list which is not existent
	{
		printf("\nPlease insert a List Number from 1 to %d: ",List_No);
		scanf("%d",&list_num);	
	}
	printf("\nTotal number of nodes in list %d are %d.\n", list_num, Count[list_num]); 
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Display_List()
{
	int temp;
	if(List_No==0)
	{
		printf("Please input a List first!!!\n");
		return;
	}	
	for(int i=1;i<=List_No;i++)
	{
		temp = Heads[i];	
		printf("\nElements of List-%d are: \n",i);
		printf("KEY\tNEXT\tPREV\n");		
		while(temp!=-1)
		{		
			if((Objects[temp+1]!=-1)&&(Objects[temp+2]!=-1))			
				printf("%d\t%d\t%d\n",Objects[temp], Objects[temp+1], Objects[temp+2]);
	
			else if((Objects[temp+1]==-1)&&(Objects[temp+2]!=-1))
				printf("%d\tNIL\t%d\n",Objects[temp], Objects[temp+2]);

			else if((Objects[temp+1]!=-1)&&(Objects[temp+2]==-1))
				printf("%d\t%d\tNIL\n",Objects[temp], Objects[temp+1]);

			else			
				printf("%d\tNIL\tNIL\n",Objects[temp]);
			
			temp =  Objects[temp+1];
		}
		printf("\n");
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Display_Free()
{			
	int temp = Heads[0];
	printf("\nElements of free list are: \n");
	printf("[%d",temp);
	temp = Objects[temp+1];	
	while(temp!=-1)
	{
		printf(", %d",temp);
		temp = Objects[temp+1];
	}
	printf("]\n\n");
}
	

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void DEFRAGMENT()
{
	int Defrag[MAX_SIZE] = {0}, temp, j=0;
	for(int i=1;i<=List_No;i++)
	{
		temp = Heads[i];		
		while(temp!=-1)
		{
			Defrag[j] = Objects[temp];
			temp = Objects[temp+1];
			Defrag[j+1] = j+3;
			Defrag[j+2] = j-1;
			j+=3;
		}
		Defrag[j-2] = -1;
	}
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


int Find_Last(int list_num)							//A function to obtain the last index of a given list number
{
	int temp = Heads[list_num];
	while(Objects[temp+1] != -1)
		temp = Objects[temp+1];
	return temp;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
