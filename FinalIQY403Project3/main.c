#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "champion.h"

int main(int argc, char* argv[]){
    
    srand(time(0));
    
    if(argc != 2){
        printf("Error: incorrect number of command line arguments.\n");
        return -1;
    }
    
    int args = atoi(argv[1]);    
    
    if(args < 0){
        printf("Error: Not greater than zero\n");
        return -1;
    }

       
    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");
    
    //Builds the champion lists for both players
    Champion* p1 = buildChampionList(args);
    Champion* p2 = buildChampionList(args);


    int length1 = -1;
    int length2 = -1;

    Champion* p1len = p1;
    Champion* p2len = p2;    

    while(p1len != NULL){
	length1++;
	p1len = p1len->next;
    }

    while(p2len != NULL){
	length2++;
	p2len = p2len->next;
    }

    int loopVal = 1;
    
    int roundNum = 0; 
    while(loopVal){
        printf("----- ROUND %d -----\n", ++roundNum); //Prints out round info
        
        //Prints out champions for each player
        printf("Player 1: ");
        printChampionList(p1);
        printf("Player 2: ");
        printChampionList(p2);
        
        //Gets the type of the player's champions
        ChampionRole cRole1 = p1->role;
        ChampionRole cRole2 = p2->role;
        
        //Gets values of both champions
        int level1 = p1->level;
        int level2 = p2->level;
            
	//Removes first champions after every round
	if(p1 != NULL && p2 != NULL){
	   p1 = removeChampion(p1);
	   p2 = removeChampion(p2);
	   length1--;
	   length2--;
	}	

        Champion* champ = createChampion();
        
        //Starts 16 permutations of Champion roles------------------------------
        //If player 1 is a mage and player 2 is a mage
        if(cRole1 == MAGE && cRole2 == MAGE){
            printf("Player 1 is a MAGE and Player 2 is a MAGE\n");
            if(level1 > level2){
                printf("Player 1 (MAGE) wins and gains one new champion.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
                p1 = addChampion(p1, champ);
		length1++;
                p2 = removeChampion(p2);
		length2--;
            }
            else if(level1 < level2){
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (MAGE) wins and gains one new champion.\n");
                p1 = removeChampion(p1);
		length1--;
                p2 = addChampion(p2, champ);
		length2++;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
        
        //If player 1 is a mage and player 2 is a fighter
        else if(cRole1 == MAGE && cRole2 == FIGHTER){
            printf("Player 1 is a MAGE and Player 2 is a FIGHTER\n");
            if(level1 > level2){
                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                p1 = addChampion(p1, champ);
		length1++;
            }
            else if(level1 < level2){
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                p1 = removeChampion(p1);
		length1--;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
        
        //If player 1 is a mage and player 2 is a support
        else if(cRole1 == MAGE && cRole2 == SUPPORT){
            printf("Player 1 is a MAGE and Player 2 is a SUPPORT\n");
            if(level1 > level2){
                printf("Player 1 (MAGE) wins and gains a new champion.\n");
                printf("Player 2 (SUPPORT) loses two champions.\n");
                p1 = addChampion(p1, champ);
		length1++;
                p2 = removeChampion(p2);
		length2--;
                p2 = removeChampion(p2);
		length2--;
            }
            else if(level1 < level2){
                printf("Player 1 (MAGE) loses one champion.\n");
                printf("Player 2 (SUPPORT) wins and gains two new champions.\n");
                p1 = removeChampion(p1);
		length1--;
                p2 = addChampion(p2, champ);
		length2++;
                p2 = addChampion(p2, champ);
		length2++;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
            
        }
        
        //If player 1 is a mage and player 2 is a tank
        else if(cRole1 == MAGE && cRole2 == TANK){
            printf("Player 1 is a MAGE and Player 2 is a TANK\n");
            printf("Player 1 (MAGE) wins and gains a new champion.\n");
            printf("Player 2 (TANK) loses one champion.\n");
            p1 = addChampion(p1, champ);
	    length1++;
            p2 = removeChampion(p2);
	    length2--;
        }
        
        //If player 1 is a fighter and player 2 is a mage
        else if(cRole1 == FIGHTER && cRole2 == MAGE){
            printf("Player 1 is a FIGHTER and Player 2 is a MAGE\n");
            if(level1 > level2){
                printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
                p2 = removeChampion(p2);
	        length2--;
            }
            else if(level1 < level2){
                printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                printf("Player 2 (MAGE) wins and gains a champion.\n");
                p2 = addChampion(p2, champ);
		length2++;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
            
        }
        
        //If player 1 is a fighter and player 2 is a fighter
        else if(cRole1 == FIGHTER && cRole2 == FIGHTER){
            printf("Player 1 is a FIGHTER and Player 2 is a FIGHTER\n");
            printf("Both players win one new champion.\n");
            p1 = addChampion(p1, champ);
	    length1++;
            p2 = addChampion(p2, champ);
	    length2++;
        }
        
        //If player 1 is a fighter and player 2 is a support 
        else if(cRole1 == FIGHTER && cRole2 == SUPPORT){
            printf("Player 1 is a FIGHTER and Player 2 is a SUPPORT\n");
            if(level1 > level2){
                printf("Player 1 (FIGHTER) wins but gains no reward.\n");
                printf("Player 2 (SUPPORT) loses one champion.\n");
                p2 = removeChampion(p2);
		length2--;
            }
            else if(level1 < level2){
                printf("Player 1 (FIGHTER) loses but with no penalty.\n");
                printf("Player 2 (SUPPORT) wins and gains a champion.\n");
                p2 = addChampion(p2, champ);
		length2++;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
        
        
        //If player 1 is a fighter and player 2 is a tank 
        else if(cRole1 == FIGHTER && cRole2 == TANK){
            printf("Player 1 is a FIGHTER and Player 2 is a TANK\n");
            printf("Player 1 (FIGHTER) wins and gains a new champion.\n");
            printf("Player 2 (TANK) loses but with no penalty.\n");
            p1 = addChampion(p1, champ);
	    length1++;
        }
        
        //If player 1 is a support and player 2 is a mage
        else if(cRole1 == SUPPORT && cRole2 == MAGE){
            printf("Player 1 is a SUPPORT and Player 2 is a MAGE\n");
            if(level1 > level2){
                printf("Player 1 (SUPPORT) wins and gains two new champions.\n");
                printf("Player 2 (MAGE) loses one champion.\n");
                p1 = addChampion(p1, champ);
                length1++;
		p1 = addChampion(p1, champ);
		length1++;
                p2 = removeChampion(p2);
		length2--;
            }
            else if(level1 < level2){
                printf("Player 1 (SUPPORT) loses two champions.\n");
                printf("Player 2 (MAGE) wins and gains a new champion.\n");
                p1 = removeChampion(p1);
		length1--;
                p1 = removeChampion(p1);
		length1--;
                p2 = addChampion(p2, champ);
		length2++;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
            
        }
        
        
        //If player 1 is a support and player 2 is a fighter
        else if(cRole1 == SUPPORT && cRole2 == FIGHTER){
            printf("Player 1 is a SUPPORT and Player 2 is a FIGHTER\n");
            if(level1 > level2){
                printf("Player 1 (SUPPORT) wins and gains a new champion.\n");
                printf("Player 2 (FIGHTER) loses but with no penalty.\n");
                p1 = addChampion(p1, champ);
		length1++;
            }
            else if(level1 < level2){
                printf("Player 1 (SUPPORT) loses one champion.\n");
                printf("Player 2 (FIGHTER) wins but gains no reward.\n");
                p1 = removeChampion(p1);
		length1--;
            }
            else{
                printf("Nothing happens - no penalty or reward.\n");
            }
        }
        
        
        
        //If player 1 is a support and player 2 is a support
        else if(cRole1 == SUPPORT && cRole2 == SUPPORT){
            printf("Player 1 is a SUPPORT and Player 2 is a SUPPORT\n");
            printf("Both players lose the next champion.\n");
            p1 = removeChampion(p1);
	    length1--;
            p2 = removeChampion(p2);
	    length2--;
        }
        
        
        
        //If player 1 is a support and player 2 is a tank  
        else if(cRole1 == SUPPORT && cRole2 == TANK){
            printf("Player 1 is a SUPPORT and Player 2 is a TANK\n");
            printf("Player 1 (SUPPORT) loses but with no penalty.\n");
            printf("Player 2 (TANK) wins and gains a new champion.\n");
            p2 = addChampion(p2, champ);
	    length2++;
        }
        
        
        
        //If player 1 is a tank and player 2 is a mage
        else if(cRole1 == TANK && cRole2 == MAGE){
            printf("Player 1 is a TANK and Player 2 is a MAGE\n");
            printf("Player 1 (TANK) loses one champion.\n");
            printf("Player 2 (MAGE) wins and gains a new champion.\n");
            p1 = removeChampion(p1);
	    length1--;
            p2 = addChampion(p2, champ);
	    length2++;
        }
        
        
        
        //If player 1 is a tank and player 2 is a fighter 
        else if(cRole1 == TANK && cRole2 == FIGHTER){
            printf("Player 1 is a TANK and Player 2 is a FIGHTER\n");
            printf("Player 1 (TANK) loses but with no penalty.\n");
            printf("Player 2 (FIGHTER) wins and gains a new champion.\n");
            p2 = addChampion(p2, champ);
            length2++;
        }
        
        
        //If player 1 is a tank and player 2 is a support 
        else if(cRole1 == TANK && cRole2 == SUPPORT){
            printf("Player 1 is a TANK and Player 2 is a SUPPORT\n");
            printf("Player 1 (TANK) wins and gains a new champion.\n");
            printf("Player 2 (SUPPORT) loses but with no penalty.\n");
            p1 = addChampion(p1, champ);
            length1++;
	}
        
        
        //If player 1 is a tank and player 2 is a tank
        else if(cRole1 == TANK && cRole2 == TANK){
            printf("Player 1 is a TANK and Player 2 is a TANK\n");
            printf("Nothing happens - no penalty or reward.\n");
        }
	
	printf("\n");

	//Checking length of each player's list of champions. If they reach 0, break out of the loop
/*	while(p1len != NULL){
	    length1++;
	    p1len = p1len->next;
	   
	}

	while(p2len != NULL){
	    length2++;
	    p2len = p2len->next;
	}
*/	
   //TEST	printf("%d ", length1);
   //TEST	printf("%d ", length2);
	
//	if(length1 == 0 || length2 == 0){
//	    loopVal = 0;
//	}


	if(length1 == 0 ||length2 == 0){
	    loopVal = 0;
	}
	

}//End while	
        //---------------------------------------------------------------
/*    
        int length1 = 0;
        int length2 = 0;
        
	Champion* p1len = p1;
	Champion* p2len = p2;

        //keeps track of the length of each linked list
        while(p1len != NULL){
            length1++;
            p1len = p1len->next;
        }
        
        while(p2len != NULL){
            length2++;
            p2len = p2len->next;
        }
*/

//Prints end of game protocol
	printf("=========== GAME OVER ============\n\n");
	printf("Player 1 ending champion list: ");
	printChampionList(p1);
	printf("Player 2 ending champion list: ");
	printChampionList(p2);	        



        //Printing out ending stats
        if(length1 == 0 && length2 == 0){  //Both players lost
            printf("\nTIE -- both players ran out of champions.\n");
        }
        else if(length1 == 0){  //Player 1 lost
            printf("\nPlayer 1 ran out of champions. Player 2 wins.\n");
            
        }
        else{
	    printf("\nPlayer 2 ran out of champions. Player 1 wins.\n");
        }
  
      
   
   destroyChampionList(p1);
   destroyChampionList(p2);
    return 0;
}
