#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define TRUE 1
#define FALSE 0


void printAll(struct node* list) {
    struct node* curr = list;
    printf("List: ");
    while (curr != NULL) { 
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

void add_to_listP2P( struct node **list  ,int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

int inOrder(struct node *list) {
    struct node *curr = list;
    if (curr == NULL)
        return 1;
    while (curr->next != NULL) {
        if (curr->value > curr->next->value) { // SAFETY CHECK:  curr->next != NULL
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}

struct node *delete_from_list(struct node *list, int n) {
   struct node *cur, *prev;
   for (cur = list, prev = NULL;
        cur != NULL ;
        prev = cur, cur = cur->next) {
       if (cur->value == n) {
           if (prev == NULL)
               list = list->next; /* n is in the first node */
           else
               prev->next = cur->next; /* n is in some other node */
           free(cur);
           break;
       }
   }
   return list;
}

struct node *deleteAll(struct node *list, int n) {
    struct node *cur = malloc(sizeof(struct node));
    struct node *prev = malloc(sizeof(struct node));
    cur = list;
    prev = NULL;

    while(cur) {
        if(cur->value == n) { //found the target
            if(prev == NULL) { //target is in the front
                list = list->next;
                free(cur);
                cur = list;
            } else if(cur->next == NULL) { //target is at the end
                prev->next = NULL;
                free(cur);
                cur = prev->next;
            } else { //target is in the middle
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        } else {// target was not found.
            prev = cur;
            cur = cur->next;
        }
    }
    return list;
}

struct node *doubleAll(struct node* list) {

    struct node *curr = malloc(sizeof(struct node));
    curr = list;
    while(curr) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->value = curr->value;
        new_node->next = curr->next;
        curr->next = new_node;
        curr = new_node->next;
    }

    return list;
}

/* Checks that a list contains no duplicate data. */
int nodupdata(struct node *list) {
    struct node  *curr = list;
    if(curr == NULL) {
        return TRUE;
    }
    struct node *next = curr->next;
    while(curr != NULL) { //run until the reference is null
        while(next != NULL) {
            if(curr->value == next->value) {
                return FALSE; //if the current value and the next value are the same there are duplicates
            }
             next = next->next; //move the next reference over

        }
         curr = curr->next; //move the current reference

         if(curr->next == NULL) {
            return TRUE;
         }
         next = curr->next;
    }
    return TRUE;
}

struct node *merge(struct node* list1, struct node* list2) {
    struct node *list3, *f1, *f2, *f3;

    if(!list1) { // check that the list are not empty
        return list2;
    } else if(!list2) {
        return list1;
    }
    f1 = list1; //reference to the first list
    f2 = list2; //reference to the second list

    if(f1->value <= f2->value) { // check which value is larger
        f3 = f1; //set the reference to the third list
        f1 = f1->next; //move the first reference
    } else {
        f3 = f2;
        f2 = f2->next; //move the second reference
    }
    list3 = f3; //set a reference that won't change so that it can be returned to the user

    while(f1 != NULL && f2 != NULL) { //run until either reference is null

        if(f1->value <= f2->value) {
            f3->next = f1;
            f1 = f1->next;
            f3 = f3->next;
        } else {
            f3->next = f2;
            f2 = f2->next;
            f3 = f3->next;
        }
    }

    if(!f1) {
        f3->next = f2; //list 1 ran out append the rest of list2 to list3
    } else {
        f3->next = f1; //list2 ran out append the rest of list1 to the end of list3
    }
    return list3; //return list3

}

int looplesslength(struct node *list) {

    if(!list) {
        return 0;
    }
    int count = 0; //number of nodes
    struct node *cur = list;
    struct node *check; //check node to see if the node has been seen before.

     while(cur) { //go until null is reached
        check = list;//set the check to the beg of the list
        for(int i = 0; i < count; i++) { //check if the node has been seen using the number of nodes as a stop.
            if(cur == check) {
                return count * -1; //loop was found
            }
            check = check->next;
        }
        count++; //node has not been seen increase the counter
        cur = cur->next; //move the current
    }
    return count; //no loop was found
}
