#ifndef UTILITIES_H_
#define UTILITIES_H_


/****************************************************/
/***           Function Declarations              ***/
/***************************************************/
static char checkWinCases(char playground[3][3], char playerID);
static char changePlayerTurn(void);
static void EndGame(char winnerID);

/* print the current playground array */
void print_playground(char playground[3][3]);

/* get data from player and update the array */
void handleData(char playground[3][3]);

/* check for win or draw game sitiuation */
void check_playCondition(char playground[3][3]);

/* delay to be placed among instructions */
void delay(int count);


#endif