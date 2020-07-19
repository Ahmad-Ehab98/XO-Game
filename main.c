#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void select_user(void);   // Responsible for user selection, called once at the beginning
int get_place(char c,char xo_arr[9]);  // Responsible for making the play
void print_xo_grid (char xo_arr[9]);  // Responsible for printing the grid
bool winner (char xo_arr[9]); // Responsible for determining if there is a winner or not
char u1,u2; // global variables for user 1 letter & user 2 letter
int main()
{
    int count = 0; // counter for number of plays in the game
    char xo_arr[9] = {'1','2','3','4','5','6','7','8','9'};  // grid array
    char again = 'y';  // while loop parameter
    select_user();
    print_xo_grid(xo_arr);

    while(again == 'y')
    {
        char y_n; // condition variable to determine if playing again or not
        printf("User 1 play\n");
        count += get_place(u1,xo_arr);
        print_xo_grid(xo_arr);
        if (winner(xo_arr))
        {
            printf("User 1 is the Winner!\nPlay Again? (y/n)\n");
            scanf("%*c%c",&y_n);
            if (again != y_n)
                {
                    again = 'n';
                    continue;
                }
            else if (again == y_n)
            {
                strncpy(xo_arr,"123456789",9);
                count = 0;
                print_xo_grid(xo_arr);
                continue;
            }
        }
        else if (count == 9 && !winner(xo_arr))
        {
            printf("Draw!\nPlay Again? (y/n)\n");
            scanf("%*c%c",&y_n);
            if (again != y_n)
                {
                    again = 'n';
                    continue;
                }
            else if (again == y_n)
            {
                strncpy(xo_arr,"123456789",9);
                count = 0;
                print_xo_grid(xo_arr);
                continue;
            }
        }
        printf("User 2 play\n");
        count += get_place(u2,xo_arr);
        print_xo_grid(xo_arr);
        if (winner(xo_arr))
        {
            printf("User 2 is the Winner!\nPlay Again? (y/n)\n");
            scanf("%*c%c",&y_n);
            if (again != y_n)
                {
                    again = 'n';
                    continue;
                }
            else if (again == y_n)
            {
                strncpy(xo_arr,"123456789",9);
                count = 0;
                print_xo_grid(xo_arr);
                continue;
            }
        }
        else if (count == 9 && !winner(xo_arr))
        {
            printf("Draw!\nPlay Again? (y/n)\n");
            scanf("%*c%c",&y_n);
            if (again != y_n)
                {
                    again = 'n';
                    continue;
                }
            else if (again == y_n)
            {
                strncpy(xo_arr,"123456789",9);
                count = 0;
                print_xo_grid(xo_arr);
                continue;
            }
        }
    }

}
void select_user(void)
{
    // asking user 1 to choose a letter , then user 2 is given the other one
    printf("User 1 : Choose X or O\n");
    scanf("%c%*c",&u1);
    /*handling lower and upper case letters*/
    if (u1=='x'||u1=='X')
    {
        printf("User 1 is X\n");
        printf("User 2 is O\n");
        u1 = 'X';
        u2 = 'O';
    }
    else if (u1=='o'||u1=='O')
    {
        printf("User 1 is O\n");
        printf("User 2 is X\n");
        u1 = 'O';
        u2 = 'X';
    }
    /*handling if user inputs a wrong value*/
    else
    {
        printf("error .. enter X or O\n");
        select_user();

    }
}

int get_place(char c,char xo_arr[9])
{
    /*function make changes to grid array according
    to user inputs then return a count in correct input case which is
    always equal to 1, the count is added to the plays counter in main*/
    int place,count=0;
    char input;
    if (c == u1)
        input = u1;
    else if (c == u2)
        input = u2;
    printf("Choose a place from 1 to 9 to put %c \n",c);
    scanf("%d",&place);
    // handling entering wrong place
    if (place > 9)
    {
      get_place(input,xo_arr);
    }
    else if (xo_arr[place-1]!=u1 && xo_arr[place-1]!=u2)
    {
       xo_arr[place-1] = c;
       count++;
    }
    // handling entering taken place
    else
    {
        printf("taken place .. choose another\n");
        get_place(input,xo_arr);
    }
return count;
}

void print_xo_grid (char xo_arr[9])
{
    for (int i = 0; i < 9; i++)
    {
        printf("\t %c \t",xo_arr[i]);
        if (i==2||i==5||i==8)
            printf("\n\n");
    }
}

bool winner (char xo_arr[9])
{
    // checks all XO game winning conditions
    // returns 1 in winning case & 0 else
    if (xo_arr[0]==xo_arr[1] && xo_arr[0]==xo_arr[2])
        return 1;
    if (xo_arr[0]==xo_arr[3] && xo_arr[0]==xo_arr[6])
        return 1;
    if (xo_arr[0]==xo_arr[4] && xo_arr[0]==xo_arr[8])
        return 1;
    if (xo_arr[1]==xo_arr[4] && xo_arr[1]==xo_arr[7])
        return 1;
    if (xo_arr[3]==xo_arr[4] && xo_arr[3]==xo_arr[5])
        return 1;
    if (xo_arr[2]==xo_arr[5] && xo_arr[2]==xo_arr[8])
        return 1;
    if (xo_arr[2]==xo_arr[4] && xo_arr[2]==xo_arr[6])
        return 1;
    if (xo_arr[6]==xo_arr[7] && xo_arr[6]==xo_arr[8])
        return 1;
    else
        return 0;
}
