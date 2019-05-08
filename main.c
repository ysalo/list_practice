#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {

    struct node *list_1 = NULL;
    struct node *list_2 = NULL;
    struct node *list_3 = NULL;
    struct node *list_4 = NULL;
    struct node *list_5 = NULL;

    for (int i = 20; i > 15; i--) {
        list_4 = add_to_list(list_4 ,i );
    }

    for (int i = 10; i > 5; i--) {
        list_5 = add_to_list(list_5 ,i );
    }
    for (int i = 22; i > 15; i--) {
        list_1 = add_to_list(list_1 ,i );
    }

    for (int i = 10; i > 5; i--) {
        list_2 = add_to_list(list_2 ,i );
    }
    printf("******************************************************************************************************\n");
    printf("List 1: ") ;
    printAll(list_1);
    printf("Duplicate: %d\n" , nodupdata(list_1));
    printf("List 2: ") ;
    printAll(list_2);
    printf("Duplicate: %d\n" , nodupdata(list_2));
    printf("List 3: ") ;
    printAll(list_3);
    printf("Duplicate: %d\n" , nodupdata(list_3));

    printf("******************************************************************************************************\n\n");
    printf("Delete All Test\n");
    printAll(list_1);
    printf("Delete 100\n");
    list_1 = deleteAll(list_1, 100);
    printAll(list_1);
    list_1 = deleteAll(list_1, 19);
    printf("Delete 19 element in the interior of the list: \n");
    printAll(list_1);
    printf("Delete 16 element in the begging of the list:\n");
    list_1 = deleteAll(list_1, 16);
    printAll(list_1);
    printf("Delete 22 element in the end of the list: \n");
    list_1 = deleteAll(list_1, 22);
    printAll(list_1);

    printf("******************************************************************************************************\n\n");
    list_1 = doubleAll(list_1);
    list_2 = doubleAll(list_2);
    printf("After Double\n");
    printf("List 1: ");
    printAll(list_1);
    printf("Duplicate: %d\n" , nodupdata(list_1));
    printf("List 2: ");
    printAll(list_2);
    printf("Duplicate: %d\n" , nodupdata(list_2));
    printf("List 3: ") ;
    printAll(list_3);
    printf("Duplicate: %d\n" , nodupdata(list_3));
    struct node *one_dup = NULL; //a list with one duplicate
    one_dup = add_to_list(one_dup ,1);
    one_dup = add_to_list(one_dup ,0);
    one_dup = add_to_list(one_dup ,2);
    one_dup = add_to_list(one_dup ,0);
    one_dup = add_to_list(one_dup ,4);
    printf("Duplicate List: ");
    printAll(one_dup);
    printf("Duplicate: %d\n" , nodupdata(one_dup));

    printf("******************************************************************************************************\n\n");

    printf("Test Merge\n");

    printf("Original Lists:\n");
    printf("List 4: ");
    printAll(list_4);
    printf("List 5: ");
    printAll(list_5);

    printf("Merge list4 and list5\n");
    struct node *list_6 = NULL;
    list_6 = merge(list_4, list_5);
    printAll(list_6);
    printf("Merge list3 and list4\n");
    struct node *list_7 = merge(list_3, list_4);
    printAll(list_7);
    printf("******************************************************************************************************\n\n");
    printf("Test Loop Less\n");
    printf("List 1 length: %d\n", looplesslength(list_1));

    printf("List 1 length: %d\n", looplesslength(list_2));
    printf("List 3 length: %d\n", looplesslength(list_3));

    struct node *loop_list = NULL;
    loop_list = add_to_list(loop_list ,1);
    loop_list = add_to_list(loop_list ,2);
    loop_list = add_to_list(loop_list ,3);
    loop_list = add_to_list(loop_list ,4);
    loop_list = add_to_list(loop_list ,5);

    struct node *loop_list_1 = NULL;
    loop_list_1 = add_to_list(loop_list ,1);
    loop_list_1->next = loop_list_1;
    loop_list->next->next->next->next->next = loop_list;
    printf("Loop list 1 length .: %d\n", looplesslength(loop_list_1));

    loop_list->next->next->next->next->next = loop_list;
    printf("Loop list length beg.: %d\n", looplesslength(loop_list));

    loop_list->next->next->next->next->next = loop_list->next;
    printf("Loop list length second element.: %d\n", looplesslength(loop_list));

    loop_list->next->next->next->next->next = loop_list->next->next;
    printf("Loop list length third element.: %d\n", looplesslength(loop_list));

    loop_list->next->next->next->next->next = loop_list->next->next->next;
    printf("Loop list length fourth element.: %d\n", looplesslength(loop_list));

    loop_list->next->next->next->next->next = loop_list->next->next->next->next;
    printf("Loop list length fifth element.: %d\n", looplesslength(loop_list));
    printf("******************************************************************************************************\n");
    return 0;
}
