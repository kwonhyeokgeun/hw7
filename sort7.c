#include <stdio.h> 
#include "phone7.h" 
#include <string.h>
extern int size;

typedef int (*cmp)(const void*, int, int); 
typedef int (*swap)(void*, int, int);

int contactCmpr(const void*, int, int); 
int contactSwap(void*, int, int);


void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-1; j++)
        {
            if(cfn(A, j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}

void sort() 
{ 
 	printf("Sort fuction is called\n"); 
 	printf("Before sorting\n"); 

	printArray(PhoneBook, size); 

	sortPhoneBook(PhoneBook, size, contactCmpr, contactSwap);
	printf("After sorting\n"); 

	printArray(PhoneBook,size);
} 

int contactSwap(void* arr, int i, int j)
{
        contact temp;
	contact* carr = (contact*)arr;
	temp = *(carr+j);
	*(carr+j) = *(carr+i);
	*(carr+i) = temp;
        return 1;
}

int contactCmpr(const void* arr, int i, int j)
{
        if( strcmp( ((contact*)arr+i)->Name, ((contact*)arr+j)->Name) > 0)
                return 1;

        else
                return 0;
}

