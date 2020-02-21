/*
 *  Program Name: COP 2220 Project 2
 *  Description: Rock Papers Scissors
 *  Author: Jacob Wyman
 *  Date: Oct 14th 2019
 */
 #include <stdio.h>
 #include <math.h>
 #include <time.h>
 #include <stdlib.h>
 #include <ctype.h>

// Declaring functions
int Rock();
int Paper();
int Scissor();

// Code to clear scanf
void flushScanf(){
    char c;
    while((c = getchar()) != '\n' && c !=EOF);
}
int main(){
    char userInput;
    int numRan;
    int quit = 0;
    int tie = 0;
    int loss = 0;
    int win = 0;

    srand(time(NULL)); // Makes truly random based on time 
while(quit != 1){
    numRan = (rand() % 3); // Generates random number between 0 and 2 and assignes to numRan
    printf("Let's Play Rock/Paper/Scissors\n");
    printf("Please Enter R,P,S, or Q (for quit): ");
    scanf("%c", &userInput); // Takes user input
        // 0  = Rock; 1 = Paper; 2 = Scissors
    userInput = toupper(userInput); // Makes userinput uppercase
        switch (userInput)
        {
        case 'R':
        Rock(numRan); 
            switch(numRan){ // Adds 1 to either int win, int loss, or int tie
                case 0:
                    tie++;
                break;
                case 1:
                    loss++;
                break;
                case 2:
                    win++;
                break;
            }
            break;
        case 'P':
            Paper(numRan);
            switch(numRan){
                case 0:
                    win++;
                break;
                case 1:
                    tie++;
                break;
                case 2:
                    loss++;
                break;
            }
            break;
        case 'S':
            Scissor(numRan);
            switch(numRan){
                case 0:
                    loss++;
                break;
                case 1:
                    win++;
                break;
                case 2:
                    tie++;
                break;
            }
            break;
        case 'Q':
            quit = 1; // Sets quit equal to 1 and ends while loop
            printf("You have won %d times! The computer has won %d times! \nIt was a tie %d times.\nThank you for playing!\n\n", win, loss, tie);
            break;
            
        default:        // if userInput =/= one of the cases above, then this is the default message.
            printf("That is an invalid key\n\n");
            break;
        }
        flushScanf();
}
        return 0;
}

/*
 *  Function Name: Rock
 *  Input Parameters:  Random integer (numRan) generated in Main
 *  Description: Funciton prints win / loss / tie status
 *  Output: Prints Win / Loss / Tie status 
 */

int Rock(int numRan){
    printf("You chose Rock!");
    if(numRan == 0){ // Compares numRan to either 0, 1 , or 2 
        printf(" The computer chose Rock!\n Its a tie!\n\n");
    }
    else if(numRan == 1){
        printf(" The computer chose Paper!\nPaper Covers Rock! The computer wins!\n\n");
    }
    else if(numRan == 2){
        printf(" The computer chose Scissors!\nRock crushes Scissors! You win!\n\n");   
    }
    return 0;
}

/*
 *  Function Name: Paper
 *  Input Parameters:  Random integer (numRan) generated in Main
 *  Description: Funciton prints win / loss / tie status
 *  Output: Prints Win / Loss / Tie status 
 */

int Paper(int numRan){
    printf("You chose Paper!");
    if(numRan == 0){
        printf(" The computer chose Rock!\nPaper covers Rock! You win!\n\n");
    }
    else if(numRan == 1){
        printf(" The computer chose Paper!\nIts a tie!\n\n");
    }
    else if(numRan == 2){
        printf(" The computer chose Scissors!\nScissors cuts Paper! The computer wins!\n\n");   
    }
    return 0;
}

/*
 *  Function Name: Scissor
 *  Input Parameters:  Random integer (numRan) generated in Main
 *  Description: Funciton prints win / loss / tie status
 *  Output: Prints Win / Loss / Tie status 
 */

int Scissor(int numRan){
    printf("You chose Scissors!");
    if(numRan == 0){
        printf(" The computer chose Rock!\n Rock crushes Scissors! The computer wins!!\n\n");
    }
    else if(numRan == 1){
        printf(" The computer chose Paper!\n Scissors cuts Paper! You win!\n\n");
    }
    else if(numRan == 2){
        printf(" The computer chose Scissors!\nIts a tie!\n\n"); 
    }
    return 0;
}
