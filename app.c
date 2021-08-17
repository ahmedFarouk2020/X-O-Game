#include<stdio.h>
#include"utilities.h"

int main ()
{
    /* initialize global variables*/
    infiniteLoopState = 9;
    playerTurn = 'X';

    /* allocate array[3][3] to be the playgroud */
    char playground[3][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'} };

    /* print game instructions */
    printf("How to play? \n");
    delay(1);
    printf("There are 2 players Player X and Player O \n");
    delay(2);
    printf("Each player Choose the position to put the Letter in \n");
    delay(2);
    printf("Like \"1 1\" to put the letter in the first row and first column \n");
    delay(2);
    printf("If one of the player won, congratulation message will be printed\n");
    delay(2);
    printf("If nobody won, nothing will be printed\n");
    delay(2);
    printf("Let's get started.... \n");
    delay(1);

    /* print playground */
    print_playground(playground);

    while (infiniteLoopState) {
        infiniteLoopState--;
        printf("Player %c's turn..\n",playerTurn);
        handleData(playground);
        print_playground(playground);
        check_playCondition(playground);
    }
    return 0;
}
