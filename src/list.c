#include <stdio.h>
#include <stdlib.h>
//#include "../h/lexer.h"
#include "../h/list.h"

//Initialization of the list with a first element containing the any passed in argument of
//the function
List *initialisation(void) {
    List *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if ( liste == NULL ||element == NULL ) {
        exit(EXIT_FAILURE);
    }

    element->el = NULL;
    element->next = NULL;
    liste->premier = element;

    return liste;
}

//Insert at the end of the List liste an element
//containing any also passed in argument of the function
void insert_at_the_end(List *liste, token *any) {
    Element *newEl = malloc(sizeof(*newEl));
    newEl->el = any;
    newEl->next = NULL;

    if ( liste == NULL ||newEl == NULL) {
        exit(EXIT_FAILURE);
    }
    
    Element *current = liste->premier;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newEl;
}

//Display the Liste liste. Since elements of the Liste
//are void* types, you should give a function 
//able to display each element from a certain type 
//otherwiser the display_list function doesn't know how to 
//display the elements of its List argument
void display_list(List *liste) {
   if (liste == NULL) {
      exit(EXIT_FAILURE);
   }

  Element *current = liste->premier; 
  while ( current != NULL) {
      printf("%s", current->el->content);
      current = current->next;
  }
}
