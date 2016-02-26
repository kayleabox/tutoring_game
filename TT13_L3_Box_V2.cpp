// Author: Kaylea Box;  Course: COSC 1337 Spring 2016 TT13;  Instructor: Thayer
// Lab: 3 Purpose: this program will act as s tutor for basic math problems
//the program will use a sentinel to allow the student to exit the program at any time.
//the result of the calcultations will not be negative or exceed 100.
//the program will keep a running total of the number of questions answered
//correctly and incorrectly

#include <iostream>
#include<ctime>
#include <typeinfo>
#include<cstdlib>
#include <string>
using namespace std;

void menu();
char get_choice();
int result_fun();
int num_two_add(int result);
int num_two_sub(int result);
int num_two_mult(int result);
int num_two_div(int result);
int exit(int correct, int incorrect, int total, string skill);
void correct_fun();
void incorrect_fun();
void invalid();

int main()
{
	//greet user and find out if they are interested in playing
	cout<<"Salutations! What is your name?\n";
	string name; cin>>name;
	cout<<"Hello "<<name<<"!\n";
	cout<<"This program will help you get better at addition, ";
	cout<<"subtraction, multiplication and division.\n";
	cout<<"Would you like to practice with me? ";
	cout<<"Press any letter to continue and q to quit.\n";
	char choice; cin>>choice;
	choice = tolower(choice);
		
		
		//loop for the whole program
		//if the user exits this loop they exit the program	
		while (choice != 'q')
		{
			//if user enters q the program terminates
			//this a repeat but I had issues until I put it up here
			if (choice == 'q')
				break;
			
			//call menu option to find out what type of problem the user wants
			menu();		
			//get the user menu choice 
			choice = get_choice();
			choice = tolower(choice);
			
			// initiate counters for correct, incorrect 
			//and total to calculate the percent correct
			double correct= 0; 
			int incorrect= 0;
			int total= 0;
			
			cout<<"Once you start, enter -1 to return to the menu or quit."<<endl;//this is still printing out more than I want
			//I tried moving it in and out of different loops, but I cannot get it to behave how I want.
			
			
			//initiate answer variable to use in the generating problems loop
			//if answer is -1 the user returns to the menu to select a new option
			auto answer = 0;
			while (answer!= -1)
			{	

				//get a random number with seed time to start the game with
				int seed= time(0);
				srand(seed);

				int result = result_fun();	
			
				
				if (choice=='a')
				{	
					//this loop will ensure that the result is <= 100 and give the user feedback 
					while (answer!= result)
					{
						int num_two = num_two_add(result);
						int num_one = result-num_two;
						
						cout<<num_one<<" + "<<num_two<<" = ";
						cin>>answer;

						if (answer==result)
						{
							correct_fun();
							correct++;
							total++;
						}				
						else if (answer==-1)
						{
							string skill = "addition";
							exit(correct, incorrect, total, skill);
							break;
					
						}	
						else if (answer!=result)
						{
							incorrect_fun();
							incorrect++;
							total++;
						}
						else
						{
							invalid();
						}
					}
						
				}
				else if (choice=='b')
				{
					//this loop will ensure that the result is <= 100 and >= 0 and give the user feedback 
					while (answer!=result)
					{
						int num_two = num_two_sub(result);
						int num_one = result+num_two;
						
						cout<<num_one<<" - "<<num_two<<" = ";
						cin>>answer;

						if (answer==result)
						{
							correct_fun();
							correct++;
							total++;
						}
						else if (answer==-1)
						{
							string skill = "subtraction";
							exit(correct, incorrect, total, skill);
							break;
						}
						else if (answer!=result and answer >=0)
						{
							incorrect_fun();
							incorrect++;
							total++;
						}
						else
						{
							invalid();
						}
					}
				}
				else if (choice=='c')
				{									
					
					//this loop will ensure that the result is <= 100 and give the user feedback 
					while (answer!= result)
					{
						int num_two = num_two_mult(result);
						int num_one = result/num_two;
						
						cout<<num_one<<" * "<<num_two<<" = ";
						cin>>answer;
						if (answer==result)
						{
							correct_fun();
							correct++;
							total++;
						}
						else if (answer=-1)
						{
							string skill = "multiplication";
							exit(correct, incorrect, total, skill);
							break;
						}
						else if (answer!=result and answer>=0)
						{
							incorrect_fun();
							incorrect++;
							total++;
						}
						else
						{
							invalid();
						}
					}
				}
				else if (choice=='d')
				{
					//this loop will ensure that the result is <= 100 and that it is an integer
					//and give the user feedback 
					while ( answer!= result)
					{
						int num_two = num_two_div(result);
						int num_one = result*num_two;

						cout<<num_one<<" / "<<num_two<<" = ";
						cin>>answer;
						if (answer==result)
						{
							correct_fun();
							correct++;
							total++;
						}
						else if (answer==-1)
						{
							string skill = "division";
							exit(correct, incorrect, total, skill);
							break;
						}		
						else if (answer!=result and answer>=0)
						{
							incorrect_fun();
							incorrect++;
							total++;
						}				
						else
						{
							invalid();
						}
					}
				}	

				else if (choice=='q')
				{
					break;	
				}			
				else
				{
					cout<<"I did not understand your input. Please choose a menu option."<<endl;
					cin>>choice;
					choice = tolower(choice);
				}
						
			}
		}
	
	cout<<"Great work!"<<endl;
	
	return 0;
}

//functions!!!!!	
void menu()
{
	
	cout<<"\t\tMENU\n";
	cout<<"\t___________________\n";
	cout<<"\ta. addition\n";
	cout<<"\tb. subtraction\n";
	cout<<"\tc. multiplication\n";
	cout<<"\td. division\n";
	cout<<"\tq. quit\n";
	cout<<endl;
	
}
		
char get_choice()
{
	cout<<"What would you like to practice?\n";
	cout<<"Please select an option from the menu.\n"; 
	cout<<"Enter q to quit.\n";
	char choice; cin>>choice;
	choice = tolower(choice);
		
	return choice;	
}

int  result_fun()	
{
	int result = (rand() % (100-1))+1;
	return result;
}

int num_two_add(int result)
{
	int num_two = rand() % (result-1) +1;
	return num_two;
}

int num_two_sub(int result)
{	
	int num_two;
	//I am still not sure about how I am generating the numbers for sub, mult, div... it seems bulky and awkward to me.
	while(result+num_two>=100)
	{
		num_two = rand() % (result-1) +1;
	}
	return num_two; 
}

int num_two_mult(int result)
{
	int num_two;
	while (result%num_two!=0 or result==num_two)
	{
		num_two = rand() % (result-1) +1;
	}
	return num_two;
}

int num_two_div(int result)
{
	int num_two;
	while (result*num_two >=100 or result==0 or num_two==0)
	{
		num_two = rand() % (100-1) +1;
	}
	return num_two;
}

int exit(int correct, int incorrect, int total, string skill)
{
	cout<<"It was nice working with you on "<<skill<<".\n";
	cout<<"You got "<<correct<<" answers correct and "<<incorrect<<" incorrect."<<endl;
	double percent_correct= (static_cast<double>(correct)/total)*100;
	cout<<"You got "<<percent_correct<<" percent correct."<<endl;
	if (percent_correct>=90)
		cout<<"You are great at "<<skill<<" !\n";
	else
		cout<<"Keep working on "<<skill<<" and you will be a rock star!\n";
		
	return 0;
}

void correct_fun()
{
	cout<<"You got it right!"<<endl;
}

void incorrect_fun()
{
	cout<<"Nice try but that is not correct."<<endl;
}

void invalid()
{
	cout<<"Invalid input. Please try again."<<endl;
}			

/*
Salutations! What is your name?
box
Hello box!
This program will help you get better at addition, subtraction, multiplication and division.
Would you like to practice with me? Press any letter to continue and q to quit.
y
                MENU
        ___________________
        a. addition
        b. subtraction
        c. multiplication
        d. division
        q. quit

What would you like to practice?
Please select an option from the menu.
Enter q to quit.
j
Once you start, enter -1 to return to the menu or quit.
I did not understand your input. Please choose a menu option.
A
3 + 4 = 7
You got it right!
6 + 7 = 13
You got it right!
4 + 16 = 20
You got it right!
4 + 26 = 7
Nice try but that is not correct.
6 + 24 = 4
Nice try but that is not correct.
18 + 12 = -1
It was nice working with you on addition.
You got 3 answers correct and 2 incorrect.
You got 60 percent correct.
Keep working on addition and you will be a rock star!
                MENU
        ___________________
        a. addition
        b. subtraction
        c. multiplication
        d. division
        q. quit

What would you like to practice?
Please select an option from the menu.
Enter q to quit.
b
Once you start, enter -1 to return to the menu or quit.
70 - 35 = 35
You got it right!
88 - 30 = 9
Nice try but that is not correct.
58 - 0 = 58
You got it right!
93 - 19 = 74
You got it right!
10 - 5 = 5
You got it right!
30 - 15 = -1
It was nice working with you on subtraction.
You got 4 answers correct and 1 incorrect.
You got 80 percent correct.
Keep working on subtraction and you will be a rock star!
                MENU
        ___________________
        a. addition
        b. subtraction
        c. multiplication
        d. division
        q. quit

What would you like to practice?
Please select an option from the menu.
Enter q to quit.
c
Once you start, enter -1 to return to the menu or quit.
22 * 2 = 44
You got it right!
2 * 27 = 54
You got it right!
73 * 1 = 73
You got it right!
20 * 4 = -1
It was nice working with you on multiplication.
You got 3 answers correct and 0 incorrect.
You got 100 percent correct.
You are great at multiplication!
                MENU
        ___________________
        a. addition
        b. subtraction
        c. multiplication
        d. division
        q. quit

What would you like to practice?
Please select an option from the menu.
Enter q to quit.
d
Once you start, enter -1 to return to the menu or quit.
16 / 4 = 4
You got it right!
56 / 4 = 7
Nice try but that is not correct.
42 / 3 = 6
Nice try but that is not correct.
28 / 2 = 14
You got it right!
49 / 1 = 49
You got it right!
63 / 1 = -1
It was nice working with you on division.
You got 3 answers correct and 2 incorrect.
You got 60 percent correct.
Keep working on division and you will be a rock star!
                MENU
        ___________________
        a. addition
        b. subtraction
        c. multiplication
        d. division
        q. quit

What would you like to practice?
Please select an option from the menu.
Enter q to quit.
Q
Once you start, enter -1 to return to the menu or quit.
Great work!

--------------------------------
Process exited after 132.6 seconds with return value 0
Press any key to continue . . .
*/
