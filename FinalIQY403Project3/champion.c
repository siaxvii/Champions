#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "champion.h"

Champion* createChampion(){
    Champion* role = (Champion*)malloc(sizeof(Champion));
    
    int prob = (rand() % 4);
    
    switch(prob){
        case 0:
            role->role = MAGE;
            role->level = 5 + rand() % 4;
            break;
        case 1:
            role->role = FIGHTER;
            role->level = 1 + rand() % 4;
            break;
        case 2:
            role->role = SUPPORT;
            role->level = 3 + rand() % 4;
            break;
        case 3:
            role->role = TANK;
            role->level = 1 + rand() % 8;
            break;
    }
    
    
    role->next = NULL;
    
    return role;
    
}


Champion* addChampion(Champion *head, Champion *c){
    //Check if the original list is empty. If it is, this is the first champion being put in, and becomes the head card
    if(head == NULL) return c;
    if(c == NULL) return head;
	
    if((c->level)>(head->level)){
	c->next = head;
	return c;
    }    

    Champion* previous = NULL;
    Champion* temp = head;

    while(temp!=NULL && temp->level >= c->level){
	previous = temp;
	temp = temp->next;
    }
    
    c->next = temp;
    previous->next = c;

    return head;
    
}


Champion* buildChampionList(int n){
    Champion* head = NULL;
    int i = 0;
    for(i = 0; i <= n; i++){
        Champion* newChampion = createChampion();
        head = addChampion(head, newChampion);
        
    }
    
    return head;
}

void printChampionList(Champion *head){
   while(head->next != NULL){
    //Prints out appropriate character and level for each role
    if(head != NULL){
    
        if(head->role == MAGE){
            printf("M%d ", head->level);
        }
        if(head->role == FIGHTER){
            printf("F%d ", head->level);
        }
        if(head->role == SUPPORT){
            printf("S%d ", head->level);
        }
        if(head->role == TANK){
            printf("T%d ", head->level);
        }
        
        head = head->next;
        
     }
    }
    printf("\n");
    
    
}


//Removes the first node in the linked list
Champion* removeChampion(Champion *head){
    //Checks if the head is null
    if(head == NULL){
        return NULL;
    }
    
    //Gets new head
    Champion* newHead = head->next;
    free(head); //deallocates head
    
    //returns new head
    return newHead;
}


Champion* destroyChampionList(Champion *head){
    
    while(head != NULL) {
        Champion* temp = head;
	head = head->next;
	free(temp);
    } 
    
    return NULL;
    
}
