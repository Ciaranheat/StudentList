//Ciaran McErlean
//Project: Student List 
//10/12/22
//Period 6
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

struct student { //Array for student name, id and GPA
  char firstname[50];
  char lastname[50];
  int id;
  float GPA;
};

void addStudent(vector<student*>*);
void printStudent(vector<student*>*);
void deleteStudent(vector<student*>*);

int main() {

  string in;
  int running = 1; //Lets the program run until told not to 


  vector<student*>* studentList = NULL; //Insilizes the list of Students 
  studentList = new vector<student*>;

  while(running == 1) {//While loop for the add,print,delete, and quit 

    cout << "enter command:[ADD,PRINT,DELETE,QUIT]" << endl;
    cin >> in;
    if(in == "ADD" || in == "Add" || in == "add" || in == "a" || in == "A") {
      addStudent(studentList);
  }
    if(in == "PRINT" || in == "Print" || in == "print" || in == "p" || in == "P") {
      printStudent(studentList);
    }
    if(in == "DELETE" || in == "Delete" || in == "delete" || in == "d" || in == "D") {
      deleteStudent(studentList);
    }

    if(in == "QUIT" || in == "Quit" || in == "quit" || in == "q" || in == "Q") {
      running = 0;
    }

  }
}

void addStudent(vector<student*>*studentList) { //Runs the add student function 

  student* oneStudent;
  oneStudent = new(student);

  cout << "Enter student's first name: "; //Asks user for their first name
  cin  >> oneStudent -> firstname;

  cout << "Enter student's last name: "; //Asks user for their second name 
  cin >> oneStudent -> lastname;

  cout << "Enter student ID: "; //Asks user for the ID
  cin >> oneStudent -> id;
  cin.ignore();

  cout << "Enter student GPA."; //Asks user for GPA
  cin >> oneStudent -> GPA;
  cin.ignore();

  studentList -> push_back(oneStudent);
  cout << "Student has been added" << endl << endl; //Tells user that a student was added to the list 
  
}


void printStudent(vector<student*>*studentList) { //Function to print out the student when asked

  cout << "The total number of students: " << studentList -> size() << endl; //Tells user the amount of students 

  if(studentList -> size() == 0) {
    return;
  }
  
  for (vector<student*>::iterator v = studentList -> begin(); v < studentList -> end(); v++) {//Prints out the student's info with 
    cout << (*v) -> firstname << " " << (*v) -> lastname << ",";// commmans inbetween each piece of info 
    cout << (*v) -> id << ",";

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << (*v) -> GPA << endl;
  }

  cout << endl;
}

void deleteStudent(vector<student*>*studentList) { //Delete's student from the list baised on the id number 
  int input;
  cout << "Which Student id do you want to delete?" << endl;
  cin >> input;
  cin.ignore();
  for(vector<student*>::iterator i = studentList -> begin(); i<studentList->end(); i++) {
    if((*i) -> id == input) {
      delete(*i);
      studentList -> erase(i);
      cout << "Student deleted." << endl << endl;
      break;
    }
    
  }
}
 
