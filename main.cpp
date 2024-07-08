//A program the assists new students in selecting co-curricular activities which are divided into 2
 //Clubs;1-Journalism
 //      2-Red cross
 //      3-AISEC
 //      4.Business club
 //    5.Computer science club
 //Sports;1.Rugby
 //       2.Soccer
 //       3.Athletics
 //     4.Swimming
//One can take a maximum of 3 clubs if they are  not in any sport,If they are in a sport,
//they can take 1 sport and not more than two clubs,nd either 1 sport or 1 club is compulsory
//Max num in clubs=60 people, max num in sports = 20 people
//Each club cannot have more than 50% of one gender and each sport cannot have more than 75% of one gender
//EXPECTED OUTPUT:Add student,view student,view clubs,view sports,view groups and save all files//
#include <iostream>
#include <fstream>
using namespace std;
string chosenclubs = "Journalism, Red Cross, AISEC, Business club, Computer science club";
string chosensports = "Rugby, Soccer, Swimming, Athletics";
struct{
 int studentnumber;
 string othername;
 string surname;
 char gender;
 string chosensports;
 string chosenclubs;
 string chosengroup;
}Student;
int studentnumber;
string othername;
string surname;
char M;
char gender = M,F;
int numofclubs = 0;
int numofsports = 0;
int maxnoofsports = 1;
int maxnoofclubs = 3;
int maxnuminsports = 20;
int maxnuminclubs = 60;
int minnumberofsports = 1;
int minnumofclubs = 1;
int maxingroups = 50;
int menu;
void Addstudent() {
 cout << "Enter your Surname:\n";
 cin >> surname;
 cout << "Enter your other name:\n";
 cin >> othername;
    cout << "Enter your student number\n";
    cin >> studentnumber;
 cout << "Enter your gender(M,F):\n";
cin >> gender;
if(gender != 'M' && gender != 'F'){
	cout << "Invalid gender input\n";
	return;
		}
    cout << "Which club(s) do you want to join?(Journalism, Red cross, AISEC, Business club, Computer science club, None)"
            "(If you pick two,input the two then none as the third;Same to picking one)\n";
   cin >> chosenclubs >> chosenclubs >> chosenclubs ;
    if(chosenclubs != "Journalism" && chosenclubs != "Red Cross" && chosenclubs != "AISEC" && chosenclubs != "Business club" && chosenclubs != "Computer science club" && chosenclubs != "None") {
       cout << "Invalid input\n";
        exit(0);
        }
    else {
       cout << "How many clubs have you entered?\n";
       cin >> numofclubs;
       if(numofclubs>3){
       	cout << "You have exceeded the number of clubs\n";
       	exit(0);
	   }
    }
	cout << "Which sports do you want to participate in?(Rugby, Soccer, Swimming, Athletics,None)\n";
	cin >> chosensports;
    if(chosensports == "Rugby" || chosensports== "Soccer" || chosensports== "Swimming" || chosensports== "Athletics" || chosensports == "None") {
        cout << "How many sports did you pick?\n";
        cin >> numofsports;
        if(numofsports >1) {
            cout << "You have exceeded the number of sports";
            exit(0);
        }
    }else {
        cout << "Invalid input";
        exit(0);
    }
//One can take a maximum of 3 clubs if they are  not in any sport,If they are in a sport,
//they can take 1 sport and not more than two clubs,nd either 1 sport or 1 club is compulsory
if(numofsports==0 && numofclubs==0){
cout << "You have to pick atleast one sport or club\n";
exit(0);
}if(numofsports==1 && numofclubs <= 2){
     cout << "Thank you\n";
}else{
	cout << "Invalid club and sports input\n";
	exit(0);
} if(numofsports==0 && numofclubs==3){
	cout<< "Thank you\n";
}if(numofsports>1 && numofclubs>0){
	cout << "You cannot pick more than one sport\n";
	exit(0);
}
    ofstream file("projectstudentdata.csv", ios::app);
    if (file.is_open()) {
        file << surname << "," << othername << "," << gender << "," << chosenclubs << "," << chosenclubs << "," << chosenclubs << "," << chosensports << "," << studentnumber << '\n';
        file.close();
        cout << "Student data saved successfully.\n";
    } else {
        cout << "Failed to open file for writing.\n";
    }

}
void Viewstudent() {
 cout <<  "View student \n";
 cout << "Enter the student's name\n";
 cin >> firstname >> secondname;
 cout << "You are in group:\n" << Student.chosengroup <<endl;
 cout << "Your sports are :\n" << Student.chosensports <<endl;
 cout << "Your clubs are :\n" << Student.chosenclubs << endl;
}
void Viewclubs() {
 cout << "The clubs offered are: \n\t\t\t";
 cout << "1-Journalism \n\t\t\t "
         "2-Red cross \n\t\t\t "
         "3-AISEC \n\t\t\t "
         "4.Business club \n\t\t\t "
         "5.Computer science club \n\n";
 cout << "From the five clubs shown below,you can only take three if you are in a sport\n\t";
 cout << clubs << endl;
 cin >> clubs;
 cout << "How many clubs have you picked? \n ";
 cin >> numofclubs;
 if ( numofclubs > 3) {
  cout << "You have exceeded the number of clubs";
 }else {
  cout <<"Thank you for picking the clubs\n";
 }
}
void Viewsports() {
 cout << " You can only pick one of the following sports if you are  in not more than 2 clubs \n";
 cout << sports << endl;
 cin >> sports;
 cout << "How many sports have you picked?\n";
 cin >> numofsports;
 if ( numofsports > 3) {
  cout << "You have exceeded the number of sports";
 }else {
  cout << "Thank you for picking the sports";
 }
}
void Viewgroups() {
 cout << "Welcome to the group menu \n";
 cout << "You have been placed in group " << group << endl;
}
void Savefiles() {
 cout << "Saved\n";
}
void Exit() {
 cout << "Exited";
}
int main() {
 cout << "Hello, welcome to Strathmore University \n ";
 cout << "We are glad to have you here on your first day,";
 cout << "to help you get up and about,you are going to need to choose a club and  a sport.\n";
 cout << "Note the following when you are selecting the clubs and sports:\n";
 cout << "1.The sports offered are: \n\t\t";
 cout << "1.Rugby \n\t\t2.Soccer \n\t\t3.Athletics\n\t\t4.Swimming\n" ;
 cout << "2.The clubs offered are: \n\t\t";

 cout << "1-Journalism \n\t\t2-Red cross \n\t\t3-AISEC \n\t\t4.Business club \n\t\t5.Computer science club \n\n";
 //The menu
 cout << "Main Menu\n";
 cout << " 1.Add student \n "
         "2.View student \n"
         " 3.View clubs \n"
         " 4.View sports \n"
         " 5.View groups \n"
         " 6.Save all files \n"
         " 7.Exit \n";

 cout << "Enter your choice \n";
 cin >> menu;
 switch (menu) {
  case 1:
   Addstudent();
break;
  case 2:
   Viewstudent();
break;
  case 3:
   Viewclubs();
break;
  case 4:
 Viewsports();
  break;
  case 5:
   Viewgroups();
  break;
  case 6:
   Savefiles();
break;
  case 7:
   Exit();
  break;
  default:
   cout << "Invalid input\n";
  break;
 }

}






