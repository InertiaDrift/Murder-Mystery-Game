using namespace std;
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "C:\Users\owais\Downloads\minigames\NumberGuess.cpp"
#include "C:\Users\owais\Downloads\minigames\quiz.cpp"
#include "C:\Users\owais\Downloads\minigames\RPSS.cpp"
#include "C:\Users\owais\Downloads\minigames\Inventory.cpp"
#include "C:\Users\owais\Downloads\minigames\witness.cpp"


bool miniGame(string room)
{
    bool win;
    win = false;


    if (room == "Kitchen")
    {
        win = (guessNumber());
    }

    if (room == "Bedroom")
    {
        win = (quiz());
    }

    if (room == "Guest Room")
    {
        win = (RPSgame());
    }

    if (room == "Garden")
    {
        win = (guessNumber());
    }

    if (room == "Wine Cellar")
    {
        win = (guessNumber());
    }

    return win;
}


string changeRoom(string room)
{
    array<string, 6> roomList{"Living Room", "Kitchen", "Bedroom", "Guest Room", "Garden", "Wine Cellar"};
    string newRoom = room;
    int map;
    
    while (true)
    {
        cout << "You are currently in the " << room;
        cout << "\n";
        cout << "Please select a room from the following:\n";
        
        for (int i = 0; i <= roomList.size() - 1; i++)
        {
            cout << i << "." << roomList[i];
            cout << "\n";
        }
        
        cin >> map;
        
        if (map < roomList.size() && map>=0)
        {
            newRoom = roomList[map];
            cout << "You have moved to a new room";
            cout << endl;
            return newRoom;

        }
        else
        {
            cout << "Invalid entry. Please enter a number between 0 and " << roomList.size() - 1;
        }
        
    }
    }
    
    
void conclusion(const vector<string>& roomSolves) {
    string murderer;

    cout << "After all this investigation, it's time for a conclusion." << endl;
    cout << "Who is the murderer? Enter the name: ";
    cin >> murderer;

    if (murderer != "correct_culprit") {
        cout << "Incorrect culprit. The investigation continues." << endl;
    }
    else if (roomSolves.size() < 3) {
        cout << "Correct culprit, but you haven't solved enough rooms yet." << endl;
    }
    else {
        cout << "Congratulations! You've identified the correct culprit and solved enough rooms. Case closed!" << endl;
    }
}



int actionMenu(string room)
{
    int ans;
    vector <string> roomSolves {};
    inventory inv;
    while (true)
    {
        cout << "You are currently in the " + room;
        cout << "\n";
        cout << "Would you like to: \n 1.Investigate the current room \n 2.Interrogate the witness \n 3.Change rooms \n 4.Check your progress \n 5.Check Inventory \n";
        cin >> ans;

        if (ans == 1)
        {
            
            if (room == "Living Room")
            {
                string check;
                cout << "Are you sure you want to end the game? Y/N ";
                cin >> check;
                if (check == "Y")
                {
                    conclusion(roomSolves);
                }
            }

            else 
            
            {
                cout << "Game time \n";
                if (miniGame(room))
                {
                    if (find(roomSolves.begin(), roomSolves.end(), room) == roomSolves.end())
                    {
                        roomSolves.push_back(room);
                        inv.addItem("clue");
                    }
                }
            }           

        }

        if (ans == 2)
        {
            witness(room);
        }

        if (ans == 3)
        {
            room = (changeRoom(room));
        }

        if (ans == 4)
        {
            cout << "You have solved the following rooms: \n";
            for (int i = 0; i < roomSolves.size(); i++)
            {
                cout << (i + 1) << roomSolves[i] << "\n";
            }
            cout << "Your total solves are " << roomSolves.size() << " room(s) \n";
        }

        if (ans == 5)
        {
            cout << "Work in progres check back later";
            inv.displayInv();
        }
        
    }
}
   

    


int main()
{
    char name[50];
    cout << "Welcome! What is your name? ";
    cin >> name;
    cout << "Hello, " << name << "! Welcome to our Murder Mystery game, \"The murder of Mr.Murhan Uhri\" Let's begin.\n";
    cout << "The story takes place in Mordopfer manor. Work in Progress \n";
    cout << "You start in the Living Room.\nWhen you're ready to solve the mystery, return to the living room and declare the end. Good Luck!\n";

    string currentRoom;
    currentRoom = "Living Room";


    actionMenu(currentRoom);




    return 0;

}

