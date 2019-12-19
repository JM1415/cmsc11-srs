#Student's Registration

MAIN FUNCTIONS:

#1 Create a Student record - allows the user to create student record manually or import a file ".txt"
	#1A Create a Student Record Manually - enables the user to create a student record through keyboard input
	#1B Read a File ".txt" - this allows the user to read a file with extension ".txt"
		NOTE:
			* the data must be in the format of (student ID, First Name, Last Name, CMSC11Section, Hands-On Exam 1, Hands-On Exam 2, Hands-On Exam 3, Subject 1, Subject 2, Subject 3)
				Example:
					 123, ABC, DEF, A, 43, 45, 45, CMSC11, CMSC123, none
					 124, GHI, JKL, A1, 45, 45, 45, CMSC11, MATH53, MATH54

#2 Update a student Record - allows the user to update parts of a student record given the Student ID number

#3 Delete a student Record - allows the user to delete a student record given the student ID number.

#4 Search a student Record - allows the user to Search student records given the student's surname.

#5 Display all student Records - allows the user to Display all student records, this includes to display some computed values (e.g. highest scores of all exams, average, and standard deviaton)

#6 Create a Subject record - allows the user to create subject record manually or import a file ".txt"
	#6A Create a Subject Record Manually - enables the user to create a subject record through keyboard input
	#6B Read a File ".txt" - this allows the user to read a file with extension ".txt"
		NOTE:
			*the data to be read must be in the format (Subject ID, Subject Code, Subject Title)
				Example: 
					 11, CMSC11, Introduction to Computer Science
					 21, CMSC21, Fundamentals of Programming
			

#7 Update a subject record - allows the user to update a subject record given the subject code

#8 Delete a subject record - allows the user to delete a subject record given the subject code

#9 Search a subject record - allows the user to search a subject record given the subject code

#10 Display all subject records - allows the user to display all subject records

#11 Enroll a student to a subject - allows the user to enroll a student to a subject given the student's ID number and the subject code

#12 Drop a subject - allows the user to drop a subject from a student's enrolled subjects given the student's ID number and the subject code

FEATURES:

*Students can only enrolled in 3 subjects
*There is a default subject "CMSC11" the students must be enrolled.
	-After creating a student record manually he/she will automatically enrolled to "CMSC11"
	-In reading  a text file for student record; students that are not enrolled to "CMSC11" will be enrolled to the subject with or without the user's permission, 
	 and if a student is already enrolled to 3 subjects and none of those subject is CMSC11 the first subject he enrolled in will be replaced by CMSC11
*#11 and #12 is programmed to ask for the user's permission to display all student records if the user's inputed student ID is not in the database
*It has the ability to export the masterlist in ".csv" file format (this is a fixed command when the user decides to exit the program)
*It will ask wether the user wants to save the student records in ".txt" file in a format(student ID, First Name, Last Name, CMSC11Section, Hands-On Exam 1, Hands-On Exam 2, Hands-On Exam 3, Subject 1, Subject 2, Subject 3)
	so that it can be read again
*It will ask wether the user wants to save the subject records in ".txt" file in a format(Subject ID, Subject Code, Subject Title) so that is can be read again.
