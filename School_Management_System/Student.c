
/*Section: Includes */
#include "Student.h"
#include <string.h>
/*Section: Helper Function Prototypes*/

/*Section: Function Definition */
 Error_State NEW_STUDENT   (List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
            data_t *ptr_new = (data_t *) malloc(sizeof(data_t));
            if(NULL == ptr_new){
                printf("Heap is full\n");
                ret = E_NOT_OK;
            }
            else{
                printf("\n****************************************************************************************************\n");
                printf("Enter The Student Name : ");
                fflush(stdin);
                gets(&(ptr_new->name));
                printf("Enter The Student Address : ");
                fflush(stdin);
                gets(&(ptr_new->address));
                printf("Enter The Student Date Of Birth : ");
                fflush(stdin);
                gets(&(ptr_new->dateOfBirth));
                printf("Enter The Student Phone Number : ");
                fflush(stdin);
                gets(&(ptr_new->phoneNum));
                printf("Enter The Student ID: ");
                fflush(stdin);
                scanf("%d",&(ptr_new->id));
                ptr_new->computer_science = 0;
                ret = List_insertNode(myList, ptr_new);
            }
     }
     return ret;
 }


 Error_State DELETE_STUDENT(List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
         data_t ptr_temp ;
         fflush(stdin);
         printf("Enter The Student Name : ");
         fflush(stdin);
         gets(&(ptr_temp.name));
         ptr_temp.computer_science = 0;
         ret = List_deletNode (myList,&ptr_temp);
     }
     return ret;
 }


 Error_State STUDENT_LIST  (List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
        ret = List_print(myList);
     }
     return ret;
 }


 Error_State STUDENT_EDIT  (List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
        char searchName[100];
        ListNode_t *ptr_temp;
        fflush(stdin);
        printf("Enter The Name of Student You want to Edit : ");
        gets(&(searchName));
        ret = List_searchNode(myList,searchName,&ptr_temp);
        if(NULL == ptr_temp){
            printf("Not Found.. Cannot Edit...\n");
        }
        else{
            printf("\n****************************************************************************************************\n");
            printf("The Student Name : %s\n",ptr_temp->ptr_data->name);
            printf("The Student ID : %d \n ",ptr_temp->ptr_data->id);
            printf("Enter The New Student Address : ");
            fflush(stdin);
            gets(&(ptr_temp->ptr_data->address));
            printf("Enter The New Student Date Of Birth : ");
            fflush(stdin);
            gets(&(ptr_temp->ptr_data->dateOfBirth));
            printf("Enter The New Student Phone Number : ");
            fflush(stdin);
            gets(&(ptr_temp->ptr_data->phoneNum));
            printf("The Student Computer Science Score: %d \n ",ptr_temp->ptr_data->computer_science);
        }

     }
     return ret;
 }
struct myNode *rootPtrComp;

 Error_State RANK_STUDENT  (List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
        ListNode_t** TempArray = (ListNode_t**)malloc(myList->size * sizeof(ListNode_t*));
        if (NULL == TempArray )
        {
            printf("Memory is Full!!!!!!!!!!!!!!!!!!!!!!!!!!!!1\n");

        }
        else{
            ListNode_t *ptr_temp = myList->ptr_head;
            for (uint8 i = 0; i < myList->size; i++)
            {
                TempArray[i] = ptr_temp;
                ptr_temp = ptr_temp->ptr_next;
            }
            for(uint8 i = 0;i < (myList->size -1);i++){
                for(uint8 j = i+1; j<myList->size;j++){
                    if(TempArray[j]->ptr_data->computer_science > TempArray[i]->ptr_data->computer_science){
                        ptr_temp = TempArray[j];
                        TempArray[j] = TempArray[i];
                        TempArray[i] = ptr_temp;
                    }
                }
            }
            printf("\n****************************************************************************************************\n");
            printf("Name\t\tComputer Score\n");
            printf("----\t\t---------------\n");
            for(uint8 i = 0;i < myList->size;i++){
                printf("%s\t\t%d\n",TempArray[i]->ptr_data->name,TempArray[i]->ptr_data->computer_science);
            }
        }

     }
     return ret;
 }


 Error_State STUDENT_SCORE (List_t *myList){
     Error_State ret = E_OK;
     if(NULL == myList){
        ret = E_NOT_OK;
     }
     else{
        ListNode_t *ptr_temp = myList->ptr_head;
        bool_t state;
        ret = List_isEmpty(myList,&state);
        if (TRUE == state){
            printf("List is Empty Cannot Update Score\n");
        }
        else{
            while(NULL != ptr_temp ){
                printf("*************************************************************\n");
                printf("The Student Name is : %s\n",ptr_temp->ptr_data->name);
                printf("The Student ID is : %d\n",ptr_temp->ptr_data->id);
                printf("Enter The Student Computer Science Score  : ");
                fflush(stdin);
                scanf("%d",&(ptr_temp->ptr_data->computer_science));
                ptr_temp = ptr_temp->ptr_next;
            }

        }
     }
     return ret;
 }


 Error_State MAIN_MENU (){
     Error_State ret = E_NOT_OK;
     uint8 choice;
     List_t L1;
     ret = List_init(&L1);
     printf("*********** WELCOME **************\n");

     do{

         printf("Please Enter One of These Numbers : \n");
         printf("\t\t (1) To Insert New Student.\n\t\t (2) To Delete Student\n");
         printf("\t\t (3) To List Students Alphabetically.\n\t\t (4) To Edit Student Info\n");
         printf("\t\t (5) To Insert Student Score.\n\t\t (6) To Rank Students \n");
         printf("Kindly Enter Your choice Here :  ");
         scanf("%d",&choice);

         switch(choice){
         case NEWSTUDENT:
             ret = NEW_STUDENT(&L1);
            break;
         case DELETESTUDENT:
             ret = DELETE_STUDENT(&L1);
            break;
         case STUDENTLIST:
             ret = STUDENT_LIST(&L1);
            break;
        case STUDENTEDIT:
            ret = STUDENT_EDIT(&L1);
            break;
        case STUDENTSCORE:
            ret = STUDENT_SCORE(&L1);
            break;
        case RANKSTUDENT:
            ret = RANK_STUDENT(&L1);
            break;
        case EXIT:
            goto her;
            break;
        default:
            printf("\n!!!!!!!!!!!! Enter a valid choice !!!!!!!!!!!\n");
            break;
         }
     }while(EXIT != choice);
 her:    return ret;
}

