#include <stdlib.h>
#include "../h/list.h"

//Initialization of the list with a first element containing the any passed in argument of
//the function
List *initialisation(void *any) {
    List *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if ( liste == NULL ||element == NULL ) {
        exit(EXIT_FAILURE);
    }

    element->el = any;
    element->next = NULL;
    liste->premier = element;

    return liste;
}

//Insert at the end of the List liste an element
//containing any also passed in argument of the function
void insert_at_the_end(List *liste, void *any) {
    Element *newEl = malloc(sizeof(*newEl));
    newEl->el = any;
    newEl->next = NULL;

    if ( liste == NULL ||newEl == NULL) {
        exit(EXIT_FAILURE);
    }
    
    Element *test = liste->premier;

    while(test->next != NULL) {
        test = test->next;
    }

    test->next = newEl;
}

//Display the Liste liste. Since elements of the Liste
//are void* types, you should give a function 
//able to display each element from a certain type 
//otherwiser the display_list function doesn't know how to 
//display the elements of its List argument
void display_list(List *liste, void(*f)(void*)) {
   if (liste == NULL) {
      exit(EXIT_FAILURE);
   }

  Element *current = liste->premier; 
  while ( current != NULL) {
      (*f)(current);
      current = current->next;
  }
}
