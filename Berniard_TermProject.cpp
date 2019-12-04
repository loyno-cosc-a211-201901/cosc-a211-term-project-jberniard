// Program Name: "Diggy," The Digital Clock 
// Purpose: Final Project (A digital clock that displays the date and time, with basic timer and stopwatch functions.)
// Author: Jabez Berniard
// Due Date: [December 2019]

#include <stdio.h> 
#include <time.h> 
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;

//function for clock
void digitalClock()
{
time_t now = time(0);
char* dt = ctime(&now);
cout << "The local date and time is:\n" << dt;
}

//function for timer 
void timer(int minute,int second)
{
    while(minute>0 || second>0)
        {while(second>0)
            {Sleep(1000); 
            cout<<"Time left: " << minute << " Minutes " << second<< " Seconds" <<"\n"; second--;}

            {Sleep(1000);
            cout<<"Time left: " << minute << " Minutes " << second << " Seconds" <<"\n"; second=59; minute--;}

        if(minute<0)
        second=0;

        }
}

//function for stopwatch
void stopWatch(int hr, int min, int sec)
{
    _getch();
    cout << hr << " : "<< min << " : "<< sec << endl;
    while(!_kbhit())
        {sec++;
            Sleep(1000);
        if(sec>59)
            {
                min++;
                sec=0;
            }
        if(min>59)
            { 
                hr++;
                min=0;
            }
    cout << hr <<" : "<< min <<" : "<< sec << endl;
        }
}

//run the program
int main()
{  
    const int x=0;
    char function;
    int minute, second;
    int hr, min, sec;

  //loop to run digital clock
    do
    {       //main menu
            cout << "Hi, I'm 'DIGGY,' your digital clock!\n"; 
            cout << "Here's a list of my basic functions.\n";
            cout << "-----------------------------------\n";
            cout << "1.Clock\n";
            cout << "2.Timer\n";
            cout << "3.Stopwatch\n";
            cout << "4.Exit because you bought a physical watch and no longer need me\n ";
            cout << "-----------------------------------\n";
            cout << "Pick a function (1-4): ";
            cin >> function;
            
            //user decides what function to use
            switch (function)
            {
                //clock with date and time
                case '1':
                cout << "You chose the 'Clock' Function\n";
                    digitalClock();
                    cout << "Press any key to go back to the 'Main Menu'\n";
                    cout << endl;
                    _getch();
                break; 


                //personalized timer
                case '2':
                cout << "You chose the 'Timer' Function\n";
                    cout << "Set your timer now!\n";
                    cout << "How many minutes : ";
                    cin >> minute;
                    cout << "How many seconds : ";
                    cin >> second;
                    cout << "Press any key to start.\n";
                   _getch();
                        timer(minute,second);
                        cout<<"YOUR TIME IS UP!\n";
                            Beep(784,500);
                            Beep(784,500);
                            Beep(784,500);
                            Beep(784,500);
                            cin.get(); 
                                cout << "Press any key to go back to the 'Main Menu'\n";
                                cout << endl;
                                _getch();
                break; 


                //stopwatch 
                case '3':
                cout << "You chose the 'Stopwatch' Function\n";
                    cout << "Press any key to start. Then press again to stop.\n";
                        stopWatch(hr,min,sec);
                        cout << "YOU STOPPED THE CLOCK!\n";
                            cout << "Press any key to go back to the 'Main Menu'\n";
                            cout << endl;
                            _getch();
                break; 


                //quit
                case '4':
                cout << "You chose to 'Exit' the program.\n";
                exit (0);
                break; 


                //bad input, try again
                default:
                cout << "Invalid imput. Press any key and I'll bring you back to the 'Main Menu'!\n";
                cout << endl;
                _getch();
            }
    }
    //loop until user chooses to exit
    while ((x>0) | (x<3));

}
