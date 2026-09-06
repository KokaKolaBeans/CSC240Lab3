#include "StudentType.h"
#include <iostream>
using namespace std;

void StudentType::ItemType(string newName, DateType newBirthdate, int newStatus)
{
  status = newStatus;
  PersonType::Initialize(newName, newBirthdate);
}

void StudentType::Initialize(string newName, DateType newBirthdate, int newStatus)
{
  status = newStatus;
  PersonType::Initialize(newName, newBirthdate);
}

int StudentType::GetStatus() const
{
  return status;
}

RelationType StudentType::ComparedTo(StudentType &someStudent)
{
  // Compare two StudentType objects based on their status here.
  if (status == someStudent.GetStatus())
  {
    return EQUAL;
  }
  else if (someStudent.GetStatus() > status)
  {
    return LESS;
  }
  return GREATER; // (someStudent.GetStatus() < status)
}

DateType StudentType::BirthdateIs()
{
  return PersonType::BirthdateIs(); // notice the use of the scope for PersonType here.
}

void StudentType::Print()
{
  PersonType::Print(); // use the Print function of PersonType here.
  cout << "Status: " << status << endl;
}
