#include <iostream>	//library for input/output 
#include <string>	//library for strings
#include <fstream>	//for the file opening
#include <iomanip>	//library for setw

using namespace std;
//Identifiers for the value returning fuction and the void function
int get_lab_data();
int get_assignment_data();
int get_quiz_data();
int get_test();
char compute_quiz_grade(int quiz_score);
char compute_lab_grade(int lab_score);
char compute_assignment_grade(int assignment_score);
char compute_test_grade(int test_score);
char final_average_grade(float final_average);
float grade_calc_lab(char lab_grade);
float grade_calc_test(char test_grade);
float grade_calc_assignment(char assignment_grade);
float grade_calc_quiz(char quiz_grade);
void class_heading();
ifstream myfile; //file into code (made global)
int main()
{
	
	int lab_score, assignment_score, quiz_score, test_score; //declaring interger values
	char lab_grade, assignment_grade, quiz_grade, test_grade; //declaring character value
	float final_average; //declaring float vlaues
	class_heading();//calls the class heading
	myfile.open("infile.txt");
	myfile.ignore(133); //ignore function that ignores the title
	int count = 0;
	while (count < 20)	//while loop for the 20 students
	{
		count++; //count increment
		cout << "Student " << count << endl; //displays the student number
		lab_score = get_lab_data(); 
		assignment_score = get_assignment_data();
		quiz_score = get_quiz_data();
		test_score = get_test();
		lab_grade = compute_lab_grade(lab_score);
		assignment_grade = compute_assignment_grade(assignment_score);
		quiz_grade = compute_quiz_grade(quiz_score);
		test_grade = compute_test_grade(test_score);
		// Displays the grades 
		cout << "Students Lab Grade is : " << lab_grade << endl;
		cout <<  "Students Assignment Grade is : " << assignment_grade << endl;
		cout << "Students Quiz Grade is : " << quiz_grade << endl;
		cout << "Students Exam Grade is : " << test_grade << endl;
		final_average = ((10 * grade_calc_quiz(quiz_grade)) + (25 * grade_calc_assignment(assignment_grade)) + (30 * grade_calc_lab(lab_grade)) + (35 * grade_calc_test(test_grade))) / 100;
		cout << "Students Final Grade is : " << final_average_grade(final_average) << "\n" << endl;
	}
	system("pause");
}


int get_lab_data() //value returning function that returns the lab data
{
	int lab1, lab2, lab3, lab4, lab5;
	myfile >> lab1 >> lab2 >> lab3 >> lab4 >> lab5;
	return lab1 + lab2 + lab3 + lab4 + lab5;
}
int get_assignment_data() //value returning function that returns the sum of assignment data
{
	int asgn1, asgn2, asgn3, asgn4, asgn5, asgn6, asgn7;
	myfile >> asgn1 >> asgn2 >> asgn3 >> asgn4 >> asgn5 >> asgn6 >> asgn7;
	return asgn1 + asgn2 + asgn3 + asgn4 + asgn5 + asgn6 + asgn7;
}

int get_quiz_data()	//value returning function that returns sum of the quiz data
{
	int qz1, qz2, qz3, qz4, qz5, qz6, qz7, qz8, qz9, qz10, qz11, qz12;
	myfile >> qz1 >> qz2 >> qz3 >> qz4 >> qz5 >> qz6 >> qz7 >> qz8 >> qz9 >> qz10 >> qz11 >> qz12;
	return qz1 + qz2 + qz3 + qz4 + qz5 + qz6 + qz7 + qz8 + qz9 + qz10 + qz11 + qz12;
}

int get_test()	//Value returning function that returns the sum of the test
{
	int tst1, tst2, finals;
	myfile >> tst1 >> tst2 >> finals;
	return tst1 + tst2 + finals;
}


char compute_quiz_grade(int quiz_score)	//Value returning function that returns the quiz grade characters
{
	if (quiz_score > 100)
		return 'A';
			else if (quiz_score >= 85 && quiz_score <= 100)
				return 'B';
					else if (quiz_score >= 70 && quiz_score <= 84)
						return 'C';
							else if (quiz_score >= 60 &&  quiz_score <= 69)
								return 'D';
									else
										return 'F';
	

}

char compute_assignment_grade(int assignment_score) //Value returning function to return the assignment grade characters
{
	if (assignment_score > 130)
		return 'A';
			else if (assignment_score >= 112 &&  assignment_score <= 130)
				return 'B';
					else if (assignment_score >= 100 && assignment_score <= 111)
						return 'C';
							else if (assignment_score >= 88 && assignment_score <= 99)
								return 'D';
									else
										return 'F';
	

}
char compute_lab_grade(int lab_score) // Value returning function that returns the lab score grade character
{
	if (lab_score > 60)
		return 'A';
			else if (lab_score >= 50 && lab_score <= 60)
				return 'B';
					else if (lab_score >= 40 && lab_score <= 49)
						return 'C';
							else if (lab_score >= 30 && lab_score <= 39)
								return 'D';
									else
										return 'F';
	
}

char compute_test_grade(int test_score) //Value returning function that returns the test score grade character
{
	if (test_score > 360)
		return 'A';
			else if (test_score >= 210 && test_score <= 360)
				return 'B';
					else if (test_score >= 180 && test_score <= 209)
						return 'C';
							else if (test_score >= 150 && test_score <= 179)
								return 'D';
									else
										return 'F';
	
}

float grade_calc_lab(char lab_grade) // Value returning function that returns the GPA for the lab
{
	if (lab_grade == 'A')
		return 4.0;
			else if (lab_grade == 'B')
				return 3.0;
					else if (lab_grade == 'C')
						return 2.0;
							else if (lab_grade == 'D')
								return 1.0;
									else
										return 0.0;
}
float grade_calc_quiz(char quiz_grade) // value returning function that returns the GPA for the quiz
{
	if (quiz_grade == 'A')
		return 4.0;
			else if (quiz_grade == 'B')
				return 3.0;
					else if (quiz_grade == 'C')
						return 2.0;
							else if (quiz_grade == 'D')
								return 1.0;
									else
										return 0.0;
}
float grade_calc_assignment(char assignment_grade) // Value returning that returns the returns the GPA for the assignment
{
	if (assignment_grade == 'A')
		return 4.0;
			else if (assignment_grade == 'B')
				return 3.0;
					else if (assignment_grade == 'C')
						return 2.0;
							else if (assignment_grade == 'D')
								return 1.0;
									else
										return 0.0;
}

float grade_calc_test(char test_grade)
{
	if (test_grade == 'A')
		return 4.0;
			else if (test_grade == 'B')
				return 3.0;
					else if (test_grade == 'C')
						return 2.0;
							else if (test_grade == 'D')
								return 1.0;
									else
										return 0.0;
}
char final_average_grade(float final_average)
{
	if (final_average > 3.49)
		return 'A';
			else if (final_average >= 2.7 && final_average <= 3.48)
				return 'B';
					else if (final_average >= 1.7 && final_average <= 2.69)
						return 'C';
							else if (final_average >= 0.7 && final_average <= 1.69)
								return 'D';
									else
										return 'F';
}
void class_heading()	// declaring class heading
{
	cout << "******************************************************\n";
	cout << "Harold Lomotey\n"
		"@02732375\n"
		"SYCS-135 Computer Science I \n"
		"November 3, 2015\n"
		"Assignment 8\n"
		"*****************************************************\n" << endl;
}

//******************************************************
//Harold Lomotey
//@02732375
//SYCS - 135 Computer Science I
//November 3, 2015
//Assignment 8
//* ****************************************************
//
//Student 1
//Students Lab Grade is : F
//Students Assignment Grade is : D
//Students Quiz Grade is : F
//Students Exam Grade is : B
//Students Final Grade is : D
//
//Student 2
//Students Lab Grade is : B
//Students Assignment Grade is : C
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 3
//Students Lab Grade is : C
//Students Assignment Grade is : B
//Students Quiz Grade is : F
//Students Exam Grade is : B
//Students Final Grade is : C
//
//Student 4
//Students Lab Grade is : C
//Students Assignment Grade is : F
//Students Quiz Grade is : F
//Students Exam Grade is : B
//Students Final Grade is : D
//
//Student 5
//Students Lab Grade is : C
//Students Assignment Grade is : F
//Students Quiz Grade is : D
//Students Exam Grade is : B
//Students Final Grade is : C
//
//Student 6
//Students Lab Grade is : B
//Students Assignment Grade is : B
//Students Quiz Grade is : C
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 7
//Students Lab Grade is : C
//Students Assignment Grade is : F
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : C
//
//Student 8
//Students Lab Grade is : A
//Students Assignment Grade is : B
//Students Quiz Grade is : C
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 9
//Students Lab Grade is : B
//Students Assignment Grade is : D
//Students Quiz Grade is : B
//Students Exam Grade is : C
//Students Final Grade is : C
//
//Student 10
//Students Lab Grade is : F
//Students Assignment Grade is : C
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : C
//
//Student 11
//Students Lab Grade is : F
//Students Assignment Grade is : F
//Students Quiz Grade is : F
//Students Exam Grade is : D
//Students Final Grade is : F
//
//Student 12
//Students Lab Grade is : B
//Students Assignment Grade is : B
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 13
//Students Lab Grade is : A
//Students Assignment Grade is : D
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 14
//Students Lab Grade is : B
//Students Assignment Grade is : B
//Students Quiz Grade is : C
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 15
//Students Lab Grade is : B
//Students Assignment Grade is : B
//Students Quiz Grade is : B
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 16
//Students Lab Grade is : F
//Students Assignment Grade is : F
//Students Quiz Grade is : F
//Students Exam Grade is : B
//Students Final Grade is : D
//
//Student 17
//Students Lab Grade is : A
//Students Assignment Grade is : F
//Students Quiz Grade is : F
//Students Exam Grade is : B
//Students Final Grade is : C
//
//Student 18
//Students Lab Grade is : F
//Students Assignment Grade is : B
//Students Quiz Grade is : B
//Students Exam Grade is : C
//Students Final Grade is : C
//
//Student 19
//Students Lab Grade is : A
//Students Assignment Grade is : C
//Students Quiz Grade is : C
//Students Exam Grade is : B
//Students Final Grade is : B
//
//Student 20
//Students Lab Grade is : A
//Students Assignment Grade is : A
//Students Quiz Grade is : A
//Students Exam Grade is : B
//Students Final Grade is : A

