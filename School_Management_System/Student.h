#ifndef _STUDENT_H
#define _STUDENT_H

/*Section: Includes */
#include "List.h"
/* Macro Declaration */
#define NEWSTUDENT      1
#define DELETESTUDENT   2
#define STUDENTLIST     3
#define STUDENTEDIT     4
#define STUDENTSCORE    5
#define RANKSTUDENT     6
#define EXIT            7

/*Section: Macro Function */


/*Section: User Defined Data Type */


/*Section: Function Prototype */
 Error_State NEW_STUDENT   (List_t *myList);
 Error_State DELETE_STUDENT(List_t *myList);
 Error_State STUDENT_LIST  (List_t *myList);
 Error_State STUDENT_EDIT  (List_t *myList);
 Error_State RANK_STUDENT  (List_t *myList); //waits
 Error_State STUDENT_SCORE (List_t *myList);
 Error_State MAIN_MENU ();


#endif //_STUDENT_H

