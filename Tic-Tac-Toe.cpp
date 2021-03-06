#include <stdio.h>

char elements[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player, choice, returnvalue, returnValue;
void drawBoard();
int markBoard(int mark);
int checkForWin();



int main()
{
    drawBoard();
    for(player=1; ; player++)
    {
        player = (player % 2 != 0)? 1 : 2;

        printf("\n\nPlayer %d : ", player);
        scanf("%d", &choice);
        markBoard(choice);
        drawBoard();
        checkForWin();
        if(returnValue == 1 || returnValue == 0)
            break;



    }
    if(returnValue == 1)
        printf("\n\n\t!!Player %d won!!\n\n", player);
    else if(returnValue == 0)
        printf("\n\n\t       Nobody won!\n       It's a draw!!\n\n");

    return 0;
}

/* making board*/
void drawBoard()
{
    system("clear");
    printf("\t   Tic-Tac-Toe\n");
    printf("\n  Player 1 (X)  -  Player 2 (O)\n\n\n");

    for(int i =1; i<=7; i+=3){
        printf("\n\t     |     |     ");
        printf("\n\t  %c  |  %c  |  %c"  , elements[i], elements[i+1], elements[i+2]);
        if(i==1 || i==4)
            printf("\n\t_____|_____|_____");
    }
    printf("\n\t     |     |     ");

    if(returnvalue == -1)
    {
        printf("\nInvalid move\nPlease enter correct number.\n");

        getchar();
        player--;
    }
    else if (returnvalue == 1)
    {
        printf("\nInvalid move\nPlease enter correct number.\n");
        getchar();
        player--;
    }
}

/* Markin board*/
int markBoard(int mark)
{
    if(mark > 9)
    {
        returnvalue = 1;
    }
    else if(elements[mark]=='X' || elements[mark]=='O')
        returnvalue = -1;
    else if(elements[mark]!='X' && elements[mark]!='O')
        returnvalue = 0;

    if(returnvalue==0 && player==1)
    elements[mark] = 'X';
    else if(returnvalue==0 && player==2)
    elements[mark] = 'O';

    return returnvalue;
}

/* Checking for win*/

int checkForWin()
{



    if(elements[1]==elements[2] && elements[2]==elements[3])
        returnValue = 1;
    else if(elements[4]==elements[5] && elements[5]==elements[6])
        returnValue = 1;
    else if(elements[7]==elements[8] && elements[7]==elements[9])
        returnValue = 1;
    else if(elements[1]==elements[4] && elements[4]==elements[7])
        returnValue = 1;
    else if(elements[2]==elements[5] && elements[5]==elements[8])
        returnValue = 1;
    else if(elements[3]==elements[6] && elements[6]==elements[9])
        returnValue = 1;
    else if(elements[1]==elements[5] && elements[5]==elements[9])
        returnValue = 1;
    else if(elements[3]==elements[5] && elements[5]==elements[7])
        returnValue = 1;

    else if(elements[1] != '1' && elements[2] != '2' && elements[3] != '3' && elements[4] != '4' && elements[5] != '5' && elements[6] != '6' && elements[7] != '7' && elements[8] != '8' && elements[9] != '9')
        returnValue = 0;

    else
        returnValue = -1;

    return returnValue;
}