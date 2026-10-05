//Chaston Davis
//Candy Database Program
// A program that keeps track of a candy inventory using a menu-driven interface.

#include <iostream>
#include <fstream>
using namespace std;

char menu();
void find(int candyarray[]);
void eatCandy(int candyarray[]);
void inventoryListing(int candyarray[]);
void candyTypes(int candyarray[]);
void saveToFile(int candyarray[]);
void loadFromFile(int candyarray[]);


int main(){
   int candyarray[7] = {0,0,0,0,0,0,0};
   char option;

   // Main loop: show menu each iteration and handle choice, keeping
   do {
      option = menu();
      if (option == 'E') {
         eatCandy(candyarray);
      } else if (option == 'F') {
         find(candyarray);
      } else if (option == 'I') {
         inventoryListing(candyarray);
      } else if (option == 'C') {
         candyTypes(candyarray);
      } else if (option == 'S') {
         saveToFile(candyarray);
      } else if (option == 'L') {
         loadFromFile(candyarray);
      } else if (option == 'Q') {
         cout << "Enjoy your trip to the dentist!" << endl;
      } else if (option == 'M') {
         // menu already shown at top of loop
      } else {
         cout << "Invalid option, try again." << endl;
      }
   } while (option != 'Q');

  return 0;
}

// Function to display menu and get user choice
char menu(){
    char option;

    cout<<"**Welcome to the Candy Database Program!**"<<endl;
    cout<<"Here is a list of commands:"<<endl;
    cout<<"E - Eat a piece of candy"<<endl;
    cout<<"F - Find a piece of candy"<<endl;
    cout<<"I - Inventory listing"<<endl;
    cout<<"C- List candy types"<<endl;
    cout<<"M - Print this menu of commands"<<endl;
    cout<<"S- Save to the file candy.dat"<<endl;
    cout<<"L - Load from the file candy.dat"<<endl;
    cout<<"Q - Quit this program"<<endl;
    cin>>option;

  return option;

}
// Function to list candy types
void candyTypes(int candyarray[]){
    cout<<"Candy Types:"<<endl;
    cout<<"1 - Chocolate Eggs"<<endl;
    cout<<"2 - Marshmallow Chicks"<<endl;
    cout<<"3 - Snickers Bars"<<endl;
    cout<<"4 - Peanutbutter Cups"<<endl;
    cout<<"5 - M&Ms"<<endl;
    cout<<"6 - Other"<<endl;
}
// Function to find candy and update inventory
void find(int candyarray[])
{ int candytype;

  do{
   cout<<"Please enter the candy type (1-6)"<<endl;
   cin>>candytype;
   
      if (candytype > 6 || candytype < 1)
         cout << "You cannot have such kind of candy" << endl;
   }
    while (candytype > 6 || candytype < 1);

   candyarray[candytype]++;
   candyarray[0]++;

}
// Function to display inventory listing
void inventoryListing(int candyarray[]){
cout<<"Candy Inventory:"<<endl;
cout<<"Chocolate Eggs: "<<candyarray[1]<<endl;
cout<<"Marshmallow Chicks:" <<candyarray[2]<<endl;
cout<<"Snickers Bars:" <<candyarray[3]<<endl;
cout<<"Peanutbutter Cups:" <<candyarray[4]<<endl;
cout<<"M&Ms:" <<candyarray[5]<<endl;
cout<<"Other:"<<candyarray[6]<<endl;
cout<<"Total Candies:"<<candyarray[0]<<endl;
}
// Function to eat candy and update inventory
void eatCandy(int candyarray[])
{ int candytype;
do{
 cout<<"Please enter the candy type (1-6)"<<endl;
  cin>>candytype;

   if (candytype > 6 || candytype < 1)
       cout << "No Candy!" << endl;
 } while (candytype > 6 || candytype < 1);
     
 if (candyarray[candytype]>0)  
   {   candyarray[candytype]--;
       candyarray[0]--;
   }
 else 
    cout<<"No Candy!"<<endl;
}

// Function to save candy inventory to file
void saveToFile(int candyarray[]){
    ofstream outfile("candy.dat");
for (int i = 0; i < 7; i++){
   outfile << candyarray[i] << endl;
}
cout<<"Candy Database saved to candy.dat"<<endl;
outfile.close();
}
// Function to load candy inventory from file
void loadFromFile(int candyarray[]){
    ifstream infile("candy.dat");
for (int i = 0; i < 7; i++){
   infile >> candyarray[i];
}
cout<<"Candy Database loaded from candy.dat"<<endl;
infile.close();
}

/* Sample Run
**Welcome to the Candy Database Program!**
Here is a list of commands:
E - Eat a piece of candy
F - Find a piece of candy
I - Inventory listing
C- List candy types
M - Print this menu of commands
S- Save to the file candy.dat
L - Load from the file candy.dat
Q - Quit this program
F
Please enter the candy type (1-6)
2
**Welcome to the Candy Database Program!**
Here is a list of commands:
E - Eat a piece of candy
F - Find a piece of candy
I - Inventory listing
C- List candy types
M - Print this menu of commands
S- Save to the file candy.dat
L - Load from the file candy.dat
Q - Quit this program
I
Candy Inventory:
Chocolate Eggs: 0
Marshmallow Chicks:1
Snickers Bars:0
Peanutbutter Cups:0
M&Ms:0
Other:0
Total Candies:1
**Welcome to the Candy Database Program!**
Here is a list of commands:
E - Eat a piece of candy
F - Find a piece of candy
I - Inventory listing
C- List candy types
M - Print this menu of commands
S- Save to the file candy.dat
L - Load from the file candy.dat
Q - Quit this program