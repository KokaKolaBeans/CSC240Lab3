/*
 * StudentTypeDriver.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: igt88
 */
#include "unsorted.h"
#include <iostream>
#include <array>
using namespace std;

int main()
{
	StudentType student1, student2, student3;
	DateType student1DOB, student2DOB, student3DOB;

	// StudentType number5, numbern12, number34, number34_2, number5_2, number45, number8, numbern6, number15, number40, number20, number2, number1, number12_2;
	// DateType dob5, dobn12, dob34, dob34_2, dob5_2, dob45, dob8, dobn6, dob15, dob40, dob20, dob2, dob1, dob12_2;

	// dob5.Initialize(5, 5, 5);
	// dobn12.Initialize(-12, -12, -12);
	// dob34.Initialize(34, 34, 34);
	// dob34_2.Initialize(34, 34, 34);
	// dob5.Initialize(5, 5, 5);
	// dob45.Initialize(45, 45, 45);
	// dob8.Initialize(8, 8, 8);
	// dobn6.Initialize(-6, -6, -6);
	// dob15.Initialize(15, 15, 15);
	// dob40.Initialize(40, 40, 40);
	// dob20.Initialize(20, 20, 20);
	// dob2.Initialize(2, 2, 2);
	// dob1.Initialize(1, 1, 1);
	// dob12_2.Initialize(12, 12, 12);

	// number5.Initialize("George", dob5, ENROLLED);
	// numbern12.Initialize("George", dobn12, GRADUATED);
	// number34.Initialize("George", dob34, NON_ATTENDING);
	// number34.Initialize("George", dob34, ENROLLED);
	// number5.Initialize("George", dob5, GRADUATED);
	// number45.Initialize("George", dob45, NON_ATTENDING);
	// number8.Initialize("George", dob8, GRADUATED);
	// numbern6.Initialize("George", dobn6, ENROLLED);
	// number15.Initialize("George", dob15, NON_ATTENDING);
	// number40.Initialize("George", dob40, GRADUATED);
	// number20.Initialize("George", dob20, ENROLLED);
	// number2.Initialize("George", dob2, NON_ATTENDING);
	// number1.Initialize("George", dob1, GRADUATED);
	// number12_2.Initialize("George", dob12_2, ENROLLED);

	// UnsortedType ClassOfKids;

	// std::array<StudentType, 14> kids = {number5, numbern12, number34, number34, number5, number45, number8, numbern6, number15, number40, number20, number2, number1, number12};

	// for (int k = 0; k < sizeof(kids); k++)
	// {
	// 	ClassOfKids.PutItem(kids[k]);
	// }

	UnsortedType kids1;
	UnsortedType kids2;
	// ClassOfKids.SplitLists(ClassOfKids, number15, kids1, kids2);

	kids1.Print();
	kids2.Print();

	student1DOB.Initialize(7, 15, 1978);
	student2DOB.Initialize(6, 23, 1980);
	student3DOB.Initialize(3, 4, 1945);

	student1.Initialize("Ivan", student1DOB, ENROLLED);
	student2.Initialize("Jim", student2DOB, GRADUATED);
	student3.Initialize("Billy", student3DOB, NON_ATTENDING);

	UnsortedType classList;

	classList.PutItem(student1);
	classList.PutItem(student2);

	// NON_ATTENDING = 0, ENROLLED = 1, GRADUATED = 2
	cout << "Compare student1 to student1: " << student1.ComparedTo(student1) << endl; // expect 1 for same status
	cout << "Compare student1 to student2: " << student1.ComparedTo(student2) << endl; // expect 0 when status is not the same

	cout << "Print list 0:\n";
	classList.ResetList(); // reset the current position to NULL
	classList.Print();
	cout << "Print list 1:\n";
	classList.DeleteItem(student1);
	classList.ResetList(); // this must be reset before printing the list everytime
	classList.Print();
	cout << "Print list 2:\n";
	classList.PutItem(student3);
	classList.ResetList(); // this must be reset before printing the list everytime
	classList.Print();
	cout << "Print list 3:\n";
	classList.DeleteItem(student2);
	classList.DeleteItem(student3);
	classList.ResetList();
	classList.Print();
}
// g++ *.cpp -o lab3 && ./lab3
