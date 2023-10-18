//
//  main.cpp
//  Files C++
//
//  Created by Zaida on 28.08.2023.
//



#include <iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces,char Player);
void ComputerMove(char *spaces,char Computer);
bool CheckWinner(char *spaces,char Player, char Computer);
bool CheckTie (char *spaces);

int main()
{
    char spaces [9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char Player ='X';
    char Computer ='O';
    bool running = true;
    drawBoard (spaces);
    while(running)
    {
        playerMove(spaces, Player);
        drawBoard (spaces);
        if(CheckWinner(spaces, Computer, Player))
        {
            running = false;
            break;
        }
        
        else if(CheckTie(spaces))
        {
            running = false;
            break;
        }
        
        ComputerMove(spaces, Computer);
        drawBoard (spaces);
        if(CheckWinner(spaces, Computer, Player))
        {
            running = false;
            break;
        }
        else if(CheckTie(spaces))
        {
            running = false;
            break;
        }
        
    }
    cout << "Thanks for playing! \n" << endl;
    return 0;
}
void drawBoard(char *spaces)
{
   cout<< '\n';
   cout<<"  " << spaces[0] << "   |   " << spaces[1] << "    |   " << spaces[2] << "   "<< '\n';
   cout<<"______|________|_____"<< '\n';
   cout<<"  " << spaces[3] << "   |   " << spaces[4] << "    |   " << spaces[5] << "   "<< '\n';
   cout<<"______|________|_____"<< '\n';
   cout<<"  " << spaces[6] << "   |   " << spaces[7] << "    |   " << spaces[8] << "   "<< '\n';
   cout<< '\n';
    
}
void playerMove(char*spaces,char Player)
{
    int number;
        do
        {
            cout << "Enter a number to mark a space from 1-9: ";
            cin >> number;
            number--;
            if(spaces [number] == ' ')
            {
                spaces[number] = Player;
                break;
            }
        } while (number <= 0 || number > 9);
    
}
void ComputerMove(char* spaces, char Computer)
{ 
    int number;
    srand(static_cast<unsigned int>(time(NULL)));
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = Computer;
            break;
        }
    }
}
    

bool CheckWinner(char* spaces, char Player, char Computer)
{
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        if (spaces[0] == Player)
        {
            cout << "Wow! You Win!" << endl;
        }
        else
        {
            cout << "Um..you lose" << endl;
        }
        return true;
    }
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        if (spaces[3] == Player)
        {
            cout << "Wow! You Win!" << endl;
        }
        else
        {
            cout << "Um..you lose" << endl;
        }
        return true;
    }
    // ... (similar code for other winning conditions)
    
    return false; // No win condition met
}

bool CheckTie (char* spaces)
{
    for (int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "IT`s a T I E \n";
    return true;
    
    
    return 0;
}

