//Student list - user can add or delete a student pointer from a vector of pointers. The pointer points to a student struct that contains first name, last name, ID, and GPA. User can print all students and their info. 
//Emily MacPherson, 10/21/21

#include <iostream>
#include <cctype>
#include <string.h>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student
{
  char firstname[100];
  char lastname[100];
  int id;
  float gpa;
};

void add(vector<Student*> &pointers);
void print(vector<Student*> &pointers);
void remove(vector<Student*> &pointers, char input[]);

int main()
{ 
  char input[100];
  vector <Student*> pointers;
  bool running = true;
  while(running == true)
  {   
    cout << "Type ADD, DELETE, PRINT, or QUIT" << endl;    
    cin >> input;
    for(int i = 0; i < strlen(input); i++)//convert to all-uppercase to avoid caps sensitivity 
    {
      input[i] = toupper(input[i]);
    }   

    if(strcmp(input, "ADD") == 0)
    {
      add(pointers);
    }
    else if(strcmp(input, "PRINT") == 0)
    {
      if(pointers.size() > 0)
      {
        print(pointers);
      }
      else
      {
        cout << "There are no students in the database" << endl;
      }
    }
    else if(strcmp(input, "DELETE") == 0)
    {
      remove(pointers, input);
    }
    else if(strcmp(input, "QUIT") == 0)
    {
      running = false;
    }
    else
    {
      cout << "Invalid input" << endl;
    }
  }
}

//creats new student, adds its pointer to the pointer vector
void add(vector<Student*> &pointers)
{
  Student *pStudent = new Student; //creates pointer to a new student
  cout << "Enter first name:" << endl;
  cin >> pStudent->firstname;
  cout << "Enter last name:" << endl;
  cin >> pStudent->lastname;
  cout << "Enter ID:" << endl;
  cin >> pStudent->id;
  cout << "Enter GPA:" << endl;
  cin >> pStudent->gpa;
  pointers.push_back(pStudent); //add pointer to pointer vector
  cout << "Student added" << endl;
}

//prints out all students and their info 
void print(vector<Student*> &pointers)
{
  for(int i = 0; i < pointers.size(); i++)
  {
    cout << fixed << setprecision(2); //so gpa float will round to the 100ths or print 2 trailing 0s
    cout << pointers[i]->firstname << " " << pointers[i]->lastname << ", " << pointers[i]->id << ", " <<  pointers[i]->gpa << endl;      
  }
}

//deletes a student pointer from the vector of pointers
void remove(vector<Student*> &pointers, char input[])
{ 
  cout << "Enter student ID" << endl;
  cin >> input;
  for(int i = 0; i < pointers.size(); i++)
  {
    char temp[100];
    sprintf(temp, "%d", pointers[i]->id);
    if(strcmp(input, temp) == 0)
    {
      delete pointers[i];
      pointers.erase(pointers.begin() + i);
      cout << "Student deleted" << endl;
      return;
    }
  }
  cout << "There is no student with this ID in the database." << endl;
}


       
       
