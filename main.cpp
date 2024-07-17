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
 cin >> surname >> othername;
 cout << "You are in group:\n" << Student.chosengroup <<endl;
 cout << "Your sports are :\n" << Student.chosensports <<endl;
 cout << "Your clubs are :\n" << Student.chosenclubs << endl;
}
void Viewclubs() {
   ifstream file("projectstudentdata.csv");
 if(!file.is_open()){
 	cout << "The file cannot open\n";
 	exit(0);
 }
 cout << "Enter your student number\n";
 cin >> Student.studentnumber;
   bool studentFound = false;
    while (file >> Student.surname >> Student.othername >> Student.gender >> Student.studentnumber) {
        getline(file, Student.chosengroup);
        getline(file, Student.chosensports);
        getline(file, Student.chosenclubs);
         if (Student.studentnumber = studentnumber) {
            studentFound = true;
            break;
            }
            }
 file.close();
 if (studentFound) {
        cout << "You picked the following clubs:\n";
        cout << "Clubs: " << Student.chosenclubs << "\n";
    } else {
        cout << "Student not found.\n";
    }
}

void Viewsports() {
 ifstream file("projectstudentdata.csv");
 if(!file.is_open()){
 	cout << "The file cannot open\n";
 	exit(0);
 }
cout << "Enter your student number\n";
 cin >> Student.studentnumber;
   bool studentFound = false;
    while (file >> Student.surname >> Student.othername >> Student.gender >> Student.studentnumber) {
        getline(file, Student.chosengroup);
        getline(file, Student.chosensports);
        getline(file, Student.chosenclubs);
         if (Student.studentnumber = studentnumber) {
            studentFound = true;
            break;
            }
            }
 file.close();
 if (studentFound) {
        cout << "You picked the following sports:\n";
        cout << "Sports: " << Student.chosensports << "\n";
    } else {
        cout << "Student not found.\n";
    }
}
void Viewgroups() {
 cout << "Welcome to the group menu \n";
  ifstream file("projectstudentdata.csv");
 if(!file.is_open()){
 	cout << "The file cannot open\n";
 	exit(0);
 }
cout << "Enter your student number\n";
 cin >> Student.studentnumber;
   bool studentFound = false;
    while (file >> Student.surname >> Student.othername >> Student.gender >> Student.studentnumber) {
        getline(file, Student.chosengroup);
        getline(file, Student.chosensports);
        getline(file, Student.chosenclubs);
         if (Student.studentnumber = studentnumber) {
            studentFound = true;
            break;
            }
            }
 file.close();
 if (studentFound) {
        cout << "You have been placed in the following group:\n";
        cout << "Group: " << Student.chosengroup << "\n";
    } else {
        cout << "Student not found.\n";
    }
}
void Savefiles() {
 cout << "Saved\n";
 return;
}
void Exit() {
 cout << "Exited";
    exit(0);
 return;
}
int main() {
    cout << "Hello, welcome to Strathmore University\n";
    cout << "We are glad to have you here on your first day\n";
    while (true) {
        cout << "Please choose from the menu below:\n";
        //The menu
        cout << "Student Menu\n";
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
    return 0;
}




