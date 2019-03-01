#include <stdio.h>
int checkerArray[9]={0,0,0,0,0,0,0,0,0};
char xoRay[9] ={'1','2','3','4','5','6','7','8','9'};

int getChoice(int count)
{
    int turn;

    if(count%2 == 0)
        turn = 1;
    else
        turn = 2;
    
    int choice;                 
    printf("Player %i, Choose a space: ",turn);
    scanf("%i", &choice);

    while(((1>choice)||(choice>9)) ||(checkerArray[choice-1] == 1))
    {
        printf("Try again Player %i: ",turn);
        scanf("%i", &choice);
    }
    checkerArray[choice-1] = 1;
    return(choice);
}

int symbol(int count)
{
    int playerSym;
    if(count%2 == 0)
        return(playerSym = 0);
    else
        return(playerSym = 1);
}


int drawBoard(int choice2, int symbol)
{
    printf("\033[2J\033[;H");
    printf("\tTick Tack Toe\n   Player 1 (X)\tPlayer 2 (0)\n\n\t");
            if(choice2 != 69)
    {
        if(symbol==0){
            xoRay[choice2] = 'X';
        }
        else
            xoRay[choice2] = 'O';
    }
    for(int k =0;k<3;++k)
        printf("  %c",xoRay[k]);
   
    printf("\n\t");
    
    for(int k =3;k<6;++k)
            printf("  %c",xoRay[k]);
    
    printf("\n\t");
    
    for(int k =6;k<9;++k)
            printf("  %c",xoRay[k]);
    printf("\n\n");
    
    return 0;
}
int checkForWin(counter)
{
    if((xoRay[1] && xoRay[2]) == 'X')
        return(0);
    if(xoRay[8] =='O')
        return(1);
    else if(counter > 9)
        return(2);
    else
        return(3);
}
int winTell(winDraw)
{
    if(winDraw == 0)
        printf("Player 1 wins.");
    else if(winDraw == 1)
        printf("Player 2 wins.");
    else
        printf("Its a draw.");
}
int main()
{
    drawBoard(69,0);
    int count = 0;
    int userChoice;
    int userSym;
    int winDraw;
    while(count < 9)
    {
        userChoice = getChoice(count);
        userSym = symbol(count);
        drawBoard(userChoice-1, userSym);
        winDraw = checkForWin(count);
        count += 1;
        if(winDraw == (0||1||2))
            break;
        
            
    }
    winTell(winDraw);
    return 0;
}
