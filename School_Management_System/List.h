
#ifndef _LIST_H
#define _LIST_H

/*Section: Includes */
#include "STD_Types.h"
#include <stdio.h>
#include <stdlib.h>
/* Macro Declaration */


/*Section: Macro Function */


/*Section: User Defined Data Type */


typedef enum{
	E_NOT_OK  = 0,
	E_OK      = 1
}Error_State;

typedef enum {
	FALSE = 0,
	TRUE  = 1
}bool_t;
typedef struct{
	char  name[100];
	char  dateOfBirth[100];
	char  address[100];
	char  phoneNum[100];
	int    id;
	//int    math;
	int    computer_science;
}data_t;

typedef struct data_t ListEntry;

typedef struct myNode{
	data_t *ptr_data;
	struct myNode *ptr_next;
	struct myNode *ptr_prev;
	 ;
}ListNode_t;

typedef struct{
	ListNode_t *ptr_head;
	ListNode_t *ptr_tail;
	uint32 size;
}List_t;


/*Section: Function Prototype */

Error_State List_init(List_t *myList);
Error_State List_insertNode(List_t *myList,data_t *ptr_val); // insert at tail not working
Error_State List_deletNode(List_t *myList,data_t *ptr_val);
Error_State List_print(const List_t *myList);
Error_State List_size(const List_t *myList,uint32 *size);
Error_State List_freeList(List_t *myList);
Error_State List_searchNode(const List_t *myList,char *search_name,ListNode_t **pptr_result);
Error_State List_isEmpty(const List_t *myList,bool_t *state);


#endif //_LIST_H
