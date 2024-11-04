#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{

    int value;

    struct nodo *next;

}Nodo;

void insertAtBeginning(Nodo **list, int insertValue){

    Nodo *neww = malloc (sizeof(Nodo));

    neww->value = insertValue;
    neww->next = NULL;

    if(*list == NULL){
        *list = neww;
    }
    else{
        neww->next = *list;
        *list = neww;
    }

}

void insertAtTheEnd(Nodo **list, int insertValue){

    Nodo *aux;
    Nodo *neww = malloc(sizeof(Nodo));

    neww->value = insertValue;
    neww->next = NULL;

    aux = *list;

    if(*list == NULL){

    *list = neww;

    }
    else{

        while(aux->next != NULL){

            aux = aux->next;

        }
        aux->next = neww;

    }


}

void printList(Nodo **list){

    Nodo *aux;

    aux = *list;

    printf("\n=====LIST=====\n");

    while(aux!=NULL){
        printf("[%d]-->",aux->value);
        aux = aux->next;
    }
    printf("\n==============");

}

void insertOrdered(Nodo **list, int insertValue){
    Nodo *aux;

    Nodo *neww = malloc(sizeof(Nodo));

    neww->value=insertValue;
    neww->next = NULL;

    if(*list == NULL){
        *list = neww;
    }
    else if(neww->value < (*list)->value){
        neww->next = *list;
        *list = neww;
    }
    else{
        aux = *list;
        while(aux ->next != NULL && aux->next->value < neww->value){
            aux=aux->next;
        }
        neww->next = aux->next;
        aux->next = neww;
    }

}

int checkAscendingSort(Nodo **list){

    Nodo *aux = NULL;
    int flag = 0;
    aux = *list;
    while( aux->next != NULL){



        if(aux->value > aux->next->value){
           return 1;
        }
        aux=aux->next;
    }

return 0;
}

void clearList(Nodo **list){

    Nodo *aux;

    while(*list != NULL){

        aux = *list;
        *list = (*list)->next;
        free(aux);

    }


}

void copyList(Nodo **list1, Nodo **list2){
    Nodo *aux;


    clearList(list2);
    aux = *list1;
    while(aux != NULL){

        insertAtTheEnd(list2,aux->value);
        aux= aux->next;
    }

}

int main(){

    Nodo *list = NULL;
    Nodo *list2 = NULL;
    int interface =1, value;

    while(interface !=0 ){

        int option;
        printf("\n\t\t=====[CHOSE AN OPTION]=====");
        printf("\n0- exit");
        printf("\n1- insert at the beginning");
        printf("\n2- insert at the end");
        printf("\n3- insert in the middle");
        printf("\n4- Insert ordered");
        printf("\n5- print list");
        printf("\n6 - A) check if the list is sorted in ascending");
        printf("\n7 - B) copy list");
        printf("\nselect: ");
        scanf("%d", &option);

        switch(option){
    case 0:
            printf("Closing...");
           interface = 0;
    break;

    case 1:
        printf("\nWrite value to insert: ");
        scanf("%d",&value);
        insertAtBeginning(&list,value);

    break;

    case 2:
            printf("\nWrite value to insert: ");
            scanf("%d",&value);
            insertAtTheEnd(&list,value);
    break;

    case 3:
            printf("\nWrite value to insert: ");
            scanf("%d",&value);
    break;

    case 4:
            printf("\nWrite value to insert: ");
            scanf("%d",&value);
            insertOrdered(&list,value);
    break;

    case 5:
        printList(&list);
    break;

    case 6:
        if(checkAscendingSort(&list)){
            printf("\nisn't ascending order");
        }
        else{
            printf("\nis in ascending order");
        }
    break;

    case 7:
        printf("\ncopying...");
        copyList(&list,&list2);
        printList(&list2);


    break;

    default:
            printf("Invalid option, try again.");
    break;

        }

    }



return 0;
}
