////////////////////////////////////////////////////////////////////////////////// 
// Author: Ashraf Ahmed Abdallah 
// Create Date: 13/5/2018 
// project Name: Tic-Tac-Toe 5x5 game
//  
// Revision 1.00 - File Created
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdlib.h>

using namespace std;

bool win=true,check =true;     ///gobale variable
int cot,r,d,i,j;

///Functions Declarations
void check_rows             (char (&arr1)[5][5],char );
void check_columns          (char (&arr2)[5][5],char );
void check_diagonal         (char (&arr3)[5][5],char );
void implement_table        (char (&arr)[5][5]);
void computer_check_rows    (char (&arr1)[5][5],char );
void computer_check_columns (char (&arr2)[5][5],char );
void computer_check_diagonal(char (&arr3)[5][5],char );



/***************************************************************************/


int main()
{
    int row,col,x=0,counter=0,counter_1=0;
    char arr [5][5]= {0};
    cout <<"\t\t\t\t\tWelcome to Tic-Tac-Toe Game\n\t\t\t\t\t--------------------------\n";
    cout <<"\t\t\t\t\tplease choose mode of game:\n";
    cout <<"\t\t\t\t\t1-Vs Computer\n\t\t\t\t\t2-Vs Friend\nEnter the number here (1 or 2) --> ";
    cin>>x;
    if (x==1)
    {
        cout <<"****************** You (x)..... VS ..... Computer (o)*************************\n\n";
        cout <<"press (0) if you want to start or press (1) if you want computer starts --> ";
        cin>>counter;
        cout<<"\n\n";
        implement_table(arr);

        while (counter <= 25)
        {
            if (counter%2==0)
            {
                cout<<"Your turn\nEnter number of row  = ";
                cin>>row;
                cout<<"Enter number of column  = ";
                cin>>col;
                if (arr[row-1][col-1] == 'x' || arr[row-1][col-1] == 'o' || (row-1) > 4 || (col-1) > 4)
                {
                    cout<<"\n*******This place is already taken or out of range please redo this process*********\n";
                    continue;
                }
                else
                {
                    arr[row-1][col-1]='x';
                }
                implement_table(arr);

                check_rows (arr,'x');         ///look for complete row of 'x' to win
                check_columns(arr,'x');
                check_diagonal(arr,'x');

                if (!win) break;
                counter_1 ++;
            }

            /*******************************************************************/
            else
            {
                // if (counter ==25) break;
                if (check) computer_check_rows    (arr,'o');   ///computer looks for 1 free space in row to win
                if (check) computer_check_columns (arr,'o');   ///computer looks for 1 free space in column to win
                if (check) computer_check_diagonal(arr,'o');

                if (check) computer_check_rows    (arr,'x');   ///computer looks for 1 free space in raw to prevent human player to win
                if (check) computer_check_columns (arr,'x');   ///computer looks for 1 free space in column to prevent human player to win
                if (check) computer_check_diagonal(arr,'x');


                if (check)
                {
                    row= rand() % 5;                             ///enter place of element randomly
                    col= rand() % 5;
                    if (arr[row][col] == 'x' || arr[row][col] == 'o')
                    {
                        continue;
                    }
                    else
                    {
                        arr[row][col]='o';
                    }

                }
                cout<<"Computer Turn\n";
                implement_table(arr);


                check_rows    (arr,'o');           ///look for complete row of 'o'
                check_columns (arr,'o');
                check_diagonal(arr,'o');

                if (!win) break;
                check =true;

                // counter ++;
            }
            if (counter_1 == 13) break;
            counter++;
        }
        if (win)
        {
            cout<<"\n**********The Game Is Draw*************"<<endl;
        }

        /*********************************************************************************************************************/

    else if (x==2)
    {
        cout <<"********************* You (x)..... VS ..... human (o) ************************\n\n";
        implement_table(arr);
        counter=0;
        while (counter < 25)
        {
            if (counter%2==0)
            {
                cout<<"Your Turn\nEnter number of row  = ";
                cin>>row;
                cout<<"Enter number of column  = ";
                cin>>col;
                if (arr[row-1][col-1] == 'x' || arr[row-1][col-1] == 'o' || (row-1) > 4 || (col-1) > 4)
                {
                    cout<<"\n********This place is already taken please redo this process*********\n";
                    continue;

                }
                else
                {
                    arr[row-1][col-1]='x';
                }
                implement_table(arr);
                check_rows (arr,'x');
                check_columns(arr,'x');
                check_diagonal(arr,'x');

                if (!win) break;
                counter++;
                if (counter ==25) break;
            }


            else
            {
                cout<<"Second player Turn\nEnter number of row  = ";
                cin>>row;
                cout<<"Enter number of column  = ";
                cin>>col;
                if (arr[row-1][col-1] == 'x' || arr[row-1][col-1] == 'o' || (row-1) > 4 || (col-1) > 4)
                {
                    cout<<"\n*******This place is already taken please redo this process*********\n";
                    continue;

                }
                else
                {
                    arr[row-1][col-1]='o';
                }

                implement_table(arr);
                check_rows    (arr,'o');
                check_columns (arr,'o');
                check_diagonal(arr,'o');

                if (!win) break;
                counter ++;
            }
        }

        if (win)
        {
            cout<<"\nThe Game Is Draw"<<endl;
        }
    }
    return 0;
}
}



void check_rows (char (&arr1)[5][5],char s)                  ///this function check row to decide if player wins or not
{
    cot=0;
    for (i=0; i<5; i++)
    {
        for (j=1; j<=4; j++)
        {
            if (arr1[i][0] == s && arr1 [i][j] == s )
            {
                cot++;
                if (cot==4)
                {
                    cout <<"\n\nthe winner is \""<<s<<"\" player\n\n";
                    win = false;
                    break;
                }
            }
            else
            {
                cot=0;
                break;
            }
        }
    }
}

void check_columns (char (&arr2)[5][5],char s)               ///this function check column to decide if player wins or not
{
    cot=0;
    for (i=0; i<5; i++)
    {
        for (j=1; j<=4; j++)
        {
            if (arr2[0][i] == s && arr2 [j][i] == s )
            {
                cot++;
                if (cot==4)
                {
                    cout <<"\n\nthe winner is \""<<s<<"\" player\n\n";
                    win = false;
                    break;
                }
            }
            else
            {
                cot=0;
                break;
            }
        }
    }

}

void check_diagonal (char (&arr3)[5][5], char s)                ///this function check the two diagonals to decide if player wins or not
{
    cot=0;
    int x=0;
    for (i=0; i<=4; i+=4)
    {
        x=i;
        for (j=1; j<=4; j++)
        {
            if (i==0)
            {
                x++;
            }
            else
            {
                x--;
            }
            if (arr3[0][i] == s && arr3 [j][x] == s )
            {
                cot++;
                if (cot==4)
                {
                    cout <<"\n\nthe winner is \""<<s<<"\" player\n\n";
                    win = false;
                    break;
                }
            }
            else
            {
                cot=0;
                break;
            }
        }
    }

}
void implement_table (char (&arr)[5][5])                      ///this function draws the table of game
{
    cout << "       1     2     3     4     5\n";
    for (i=1 ; i<=5 ; i++)
    {
        cout << "    +-----+-----+-----+-----+-----+\n";
        cout <<"    |     |     |     |     |     |\n";
        cout<<" "<<i;
        cout <<"  |  "<<arr[i-1][0] <<"  |  "<<arr[i-1][1]<<"  |  "<<arr[i-1][2]<<"  |  "<<arr[i-1][3]<<"  |  "<<arr[i-1][4]<<"  |  "<<"\n";
        cout <<"    |     |     |     |     |     |\n";
    }
    cout << "    +-----+-----+-----+-----+-----+\n";
}


void computer_check_rows (char (&arr1)[5][5],char s)      ///this function tells computer if the row has 1 free space to win (for computer) or to block (for human player)
{
    for ( i=0; i<5; i++)
    {
        cot=0,d=0;
        for ( j=0; j<5; j++)
        {
            if (arr1[i][j] == s)
            {
                cot++;
            }
            else if(arr1 [i][j] == '\0')
            {
                d++;
                r=j;
            }
        }
        if (cot == 4 && d == 1)
        {
            arr1[i][r]='o';
            check =false;
        }
    }
}


void computer_check_columns (char (&arr2)[5][5],char s)      ///this function tells computer if the column has 1 free space to win (for computer) or to block (for human player)
{

    for ( i=0; i<5; i++)
    {
        cot=0,d=0;
        for ( j=0; j<5; j++)
        {
            if (arr2[j][i] == s)
            {
                cot++;
            }
            else if(arr2 [j][i] == '\0')
            {
                d++;
                r=j;
            }
        }
        if (cot == 4 && d == 1)
        {
            arr2[r][i]='o';
            check=false;
        }
    }
}

void computer_check_diagonal (char (&arr3)[5][5], char s)             ///this function tells computer if the diagonal has 1 free space to win (for computer) or to block (for human player)
{
    int t;
    cot=0,d=0;

    for (j=0 ; j<5 ; j++)
    {
        if (arr3[j][j] == s)
        {
            cot++;
        }
        else if(arr3 [j][j] == '\0')
        {
            d++;
            r=j;
            // t=i;
        }
    }
    if (cot == 4 && d == 1)
    {
        arr3[r][r]= 'o';
        check=false;
    }


    cot=0,d=0;
    for (i=0 ; i<5 ; i++)
    {
        j--;
        if (arr3[i][j] == s)
        {
            cot++;
        }
        else if(arr3 [i][j] == '\0')
        {
            d++;
            r=j;
            t=i;
        }
    }
    if (cot == 4 && d == 1)
    {
        arr3[t][r]= 'o';
        check=false;
    }
}

