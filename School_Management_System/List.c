/*Section: Includes */
#include"List.h"


/*Section: Helper Function Prototypes*/

/*Section: Function Definition */

Error_State List_init(List_t *myList){
	Error_State ret = E_OK;
	if (NULL == myList){
		ret  = E_NOT_OK;
	}
	else{
		myList->ptr_head = NULL;
		myList->ptr_tail = NULL;
		myList->size     = 0;
	}
	return ret;
}

Error_State List_isEmpty(const List_t *myList,bool_t *state){
	Error_State ret = E_OK;
	if ((NULL == myList) && (NULL == state)){
		ret = E_NOT_OK;
	}
	else{
		if (NULL == myList->ptr_head){
			*state = TRUE;
		}
		else{
			*state = FALSE;
		}
	}
	return ret;
}


Error_State List_insertNode(List_t *myList, data_t *ptr_val){
	Error_State ret = E_OK;
	if ((NULL == myList) || (NULL == ptr_val)){
		ret = E_NOT_OK;
	}
	else{
		ListNode_t *pn=(ListNode_t *)malloc(sizeof(ListNode_t));
		if (NULL == pn){
			printf("Heap is Full");
		}
		else{
			bool_t state;
			ret = List_isEmpty(myList,&state);
			pn->ptr_data = ptr_val;
			pn->ptr_next = NULL;
			pn->ptr_prev = NULL;

			myList->size++;
			if (TRUE == state){
				myList->ptr_head = pn;
				myList->ptr_tail = pn;
			}
			else{
				ListNode_t *temp = myList->ptr_head;
				ListEntry *temp_data = temp->ptr_data;
				while((NULL != temp) &&(temp->ptr_data->name[0] < ptr_val->name[0])){
					temp = temp->ptr_next;
				}
				if(temp == myList->ptr_head){	//head
					pn->ptr_next = myList->ptr_head;
					temp->ptr_prev = pn;
					myList->ptr_head = pn;
				}
				else if(NULL == temp){			//tail
					pn->ptr_prev = myList->ptr_tail;
					myList->ptr_tail->ptr_next = pn;
					myList->ptr_tail = pn;
				}
				else{							//Middle
					pn->ptr_next = temp;
					pn->ptr_prev = temp->ptr_prev;
					temp->ptr_prev->ptr_next = pn;
					temp->ptr_prev = pn;
				}
			}
		}
	}
	return ret;
}



Error_State List_deletNode(List_t *myList,data_t *ptr_val){
	Error_State ret = E_OK;
	if (NULL == myList){
		ret = E_NOT_OK;
	}
	else{
		bool_t state;
		ret =List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("List Is Empty. Cannot Delete..\n");
		}
		else{
			ListNode_t *temp = NULL;
			ret = List_searchNode(myList,ptr_val->name,&temp);
			if(NULL == temp){
				printf("NOT FOUND VALUE...\n");
			}
			else{
				if(myList->ptr_tail == myList->ptr_head){	//only one node
					free(temp);
					myList->ptr_head = NULL;
					myList->ptr_tail = NULL;
					myList->size = 0;
				}
				else if(myList->ptr_head == temp){			// at head
					myList->ptr_head = myList->ptr_head->ptr_next;

					free(myList->ptr_head->ptr_prev);
					myList->ptr_head->ptr_prev = NULL;
					myList->size--;

				}
				else if(myList->ptr_tail == temp){			//at tail
					myList->ptr_tail = myList->ptr_tail->ptr_prev;

					free(myList->ptr_tail->ptr_next);
					myList->ptr_tail->ptr_next = NULL;
					myList->size--;
				}
				else{										// at middle
					temp->ptr_prev->ptr_next = temp->ptr_next;
					temp->ptr_next->ptr_prev = temp->ptr_prev;
					temp->ptr_next = NULL;
					temp->ptr_prev = NULL;

					free(temp);
					myList->size--;
				}
			}
		}
	}
	return ret;
}


Error_State List_print(const List_t *myList){
	Error_State ret = E_OK;
	if (NULL == myList){
        ret = E_NOT_OK;
	}
	else{
    bool_t state;
	ret = List_isEmpty(myList,&state);
	if (TRUE == state){
		printf("List is Empty!!!!!!\n");
	}
	else{
		printf("Name\t\tID\tDate Of Birth\tAddress\t\tPhone Number\n");
		ListNode_t *temp = myList->ptr_head;
		data_t *temp_data = NULL;
		while(NULL != temp){
			temp_data = temp->ptr_data;
			printf("%s\t%d\t%s\t\t%s\t\t%s\n",temp_data->name,temp_data->id,temp_data->dateOfBirth
								,temp_data->address,temp_data->phoneNum);
			temp = temp->ptr_next;
		}
	}
	}
	return ret;
}

Error_State List_size(const List_t *myList,uint32 *size){
    Error_State ret = E_OK;
    if ((NULL == myList) && (NULL == size)){
	}
	else{
		*size = myList->size;

	}
	return ret;
}

Error_State List_freeList(List_t *myList){
	Error_State ret = E_OK;
	if (NULL == myList){
		ret = E_NOT_OK;
	}
	else{
		bool_t state;
		ret = List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("The List is Empty. Cannot Free..\n");
		}
		else{
			ListNode_t *current = myList->ptr_head;
			ListNode_t *prev = myList->ptr_head;
			data_t *prev_data = prev->ptr_data;
			while(NULL != current){
				current = current->ptr_next;
				//free(prev_data);
				free(prev);
				prev = current;
			}
			//free(prev_data);
			free(prev);
			myList->ptr_tail = NULL;
			myList->ptr_head = NULL;
			myList->size = 0;
		}
	}
	return ret;
}

Error_State List_searchNode(const List_t *myList,char *search_name,ListNode_t **pptr_result){
	Error_State ret = E_OK;
	if (NULL == myList){
		ret = E_NOT_OK;
	}
	else{
		bool_t state;
		ret =List_isEmpty(myList,&state);
		if(TRUE == state){
			printf("List Is Empty. Cannot Search..\n");
		}
		else{
			ListNode_t *temp = myList->ptr_head;
			while((NULL != temp) && (strcmp(temp->ptr_data->name,search_name))) {
				temp = temp->ptr_next;
			}
			*pptr_result = temp;
		}
	}
	return ret;
}


