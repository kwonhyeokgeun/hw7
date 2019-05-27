#include <stdio.h> 
#include "phone7.h" 
#include <string.h>

 
void registerPhoneData(); 
void print(); 
void printArray(void *arr, int size); 
void searchByName(); 
void deleteByName(); 
void sort(); 

int size = 0; 
int count_service = 0;
 
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName,sort}; 
 
 
typedef int (*cmp)(const void*, int, int); 
typedef int (*swap)(void*, int, int); 

void sortPhoneBook(void *A, int size, cmp cfn, swap sfn); 

 
int main() 
{ 
	int service;		// a variable for storing user's request 
	do 
	{ 
        printf("============ Telephone Book Management ============"); 
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n"); 
        printf(" Please enter your service number (1-6)> "); 
		scanf("%d", &service); 
		if ( service > 0 && service <= 5 ) 
		{ 
			pFuncs[service-1](); 
		} 
		else if( service ==0 || service > 6) 
		{ 
			printf("You choose a wrong service number\n"); 
		} 
	} while (service != 6);	// if Exit is not entered, the loop continues 
	return 0; 
} 
