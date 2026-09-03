/*
 * StudentTypeDriver.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: igt88
 */
#include "unsorted.h"
#include <iostream>
using namespace std;

int main()
{
	StudentType student1, student2, student3;		// Student Type contains PersonType(name, DateType DOB) and enrollment status
	DateType student1DOB, student2DOB, student3DOB; // Date type contains month, day, year

	student1DOB.Initialize(7, 15, 1978); // (Month, Day, Year): July 15, 1978
	student2DOB.Initialize(6, 23, 1980); // June 23, 1980
	student3DOB.Initialize(3, 4, 1945);	 // March 4, 1945

	student1.Initialize("Ivan", student1DOB, ENROLLED); // PersonType (Name, DateType, Status)
	student2.Initialize("Jim", student2DOB, GRADUATED);
	student3.Initialize("Billy", student3DOB, NON_ATTENDING);

	UnsortedType classList; // Creates list

	classList.PutItem(student1); // classList.PutItem -> Adds item to list
	classList.PutItem(student2);
	// classList.PutItem(student3);

	// NON_ATTENDING = 0, ENROLLED = 1, GRADUATED = 2
	//  cout << "Compare student1 to student1: " << student1.ComparedTo(student1) << endl;  //expect 1 for same status // Enrolled == Enrolled
	//  cout << "Compare student1 to student2: " << student1.ComparedTo(student2) << endl;  //expect 0 when status is not the same // Enrolled != Graduated

	cout << "Print list 0:\n"; // student1, student2
	classList.ResetList();	   // reset the current position to NULL
	classList.Print();
	cout << "Print list 1:\n"; // student2
	classList.DeleteItem(student1);
	classList.ResetList(); // this must be reset before printing the list everytime
	classList.Print();
	cout << "Print list 2:\n"; // student2 and student3
	classList.PutItem(student3);
	classList.ResetList(); // this must be reset before printing the list everytime
	classList.Print();
	cout << "Print list 3:\n";
	classList.DeleteItem(student2);
	classList.DeleteItem(student3);
	classList.ResetList();
	classList.Print();
}
