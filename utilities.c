#include<stdio.h>
#include"utilities.h"


/* Function Description: test all test cases of win (row, col, zigzag)
 *      parameters: playerID ('X' or 'O') 
 *      return: playerID if win    0 if no winner
 */
static char checkWinCases(char playground[3][3], char playerID) {
    // sum of all values in the current row
    int sumOfRow = playground[row-1][0] + playground[row-1][1] + playground[row-1][2];
    // sum of all values in the current col
    int sumOfCol = playground[0][col-1] + playground[1][col-1] + playground[2][col-1];
    // sum of all values in the first zigzag from 0 0 to 2 2
    int sumOfEqualIndecies = playground[0][0] + playground[1][1] + playground[2][2];
    // sum of all values in the second zigzag from 0 2 to 2 0
    int theLastWinCase = playground[0][2] + playground[1][1] + playground[2][0];
    // all row are X or O
    if (sumOfRow == (int)playerID * 3)
    {
        return playerID;
    }
    // all col are X or O
    else if (sumOfCol == (int)playerID * 3)
    {
        return playerID;
    }
    else
    {
        // first zigzag are Xs or Os
        if (row == col && (sumOfEqualIndecies == (int)playerID*3) ) {
            return playerID;
        }
        // second zigzag are Xs or Os
        else if ( (row != col || col == 1) && (sumOfEqualIndecies == (int)playerID*3) )
        {
            return playerID;
        }
    }
    return 0;
}


/*  function description: End the program with a messsage if someone won
 *  parameters: winnerID  X or O
 *  return: none
 */
static void EndGame(char winnerID)
{
   /* End infinite loop in main */
   infiniteLoopState = 0;

   /* Print a message to the winner */
    printf("The Winner is player %c \n",winnerID);
}


/* Function description: update "playerTurn" which indicate which player has the turn
 * parameters: none
 * return: playerTurn -> char
 */ 
static char changePlayerTurn(void)
{
    if (playerTurn == 'X')
    {
        playerTurn = 'O';
    }
    else
    {
        playerTurn = 'X';
    }
    return playerTurn;
}


/* Function description: draw the playground
 * parameters: playground "char array[3][3]"
 * return: none
 */ 
void print_playground(char playground[3][3]) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (playground[i][j] == 'X' || playground[i][j] == 'O')
            {
                printf("%c",playground[i][j]);
            }
            else
            {
                printf(" ");
            }
            
            printf("|");
        }
        printf("\n");
    }
    
}


/* Function description: take data from user, validate it then update the array
 * parameters: playground "array[3][3]"
 * return: none
 */ 
void handleData(char playground[3][3]) {
    int state = 1;
    while(state) {
        scanf("%d %d",&row,&col);
        /* prevent player to overwrite a segment 
         * assure that row and col are in the allowed range
         */
        if (playground[row-1][col-1] == '\0' && (row<4 && row>0 && col<4 && col>0) )
        {
            playground[row-1][col-1] = playerTurn;
            break;
        }
        else {
            printf("Enter a Valid input \n");
            continue; 
        }

    }
    
}


/* Function description: 
    test win cases using "checkWinCases" static function and print a message if somebody won
 * parameters: playground "array[3][3]"
 * return: none
 */ 
void check_playCondition(char playground[3][3]) {
    static int count = 0;
    count++;
    /* 1 for X and 2 for O */
    char winnerID ;
    if (count < 5)
    {
        changePlayerTurn();
        return;
    }
    winnerID = checkWinCases(playground, playerTurn);
    /* if no winner */
    if (winnerID == 0) {
        changePlayerTurn();
    }
    else {
        /* if a winner exist */
        EndGame(winnerID);
    }
}
