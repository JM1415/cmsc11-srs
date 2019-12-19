#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int subjectIDAvail[10000];
int IDAvail[1000];
struct studentRecord updateRecord(struct studentRecord upRecord);
struct studentRecord createRecord(struct studentRecord newRecord);
void delelteStudentRecord(struct studentRecord deleteS, int index);
void displayRecords(struct studentRecord *printRecord);
int IDCheck(int ID, int check);
int subjectIDcheck(int ID, int check);
struct subjectRecord createSubjectRecord(struct subjectRecord newSubjectRecored);
struct subjectRecord updateSubjectRecord(struct subjectRecord upSubjectRecored);
void deleteSubjectRecord(struct subjectRecord deleteSubject, int index, int x);
void displaySubjectRecord(struct subjectRecord printSubjectRecord);
void displayPtr(struct studentRecord *stud);
char toUpper(char z);
int preEnroll(char z[], struct subjectRecord subjectForEnrolling);
int enrollCheck(char z[], char subjectEnroll[]);
void csvOutput(struct studentRecord studentsDirectory,FILE *n);
void csvOutput2(struct subjectRecord subjectsDirectory,FILE *n);
void outputStudentTxt(struct studentRecord student, FILE *n);
int stringCompare(char s1[], char s2[]);
void sorting(void);
void capitalize(void);
void fileInput(void);
void subjectsFileInput(void);
void displayCalculations(void);
void displayCalculationsCSV(FILE *n);
void dropSubject(struct studentRecord *student);
struct subjectRecord createSubjectRecordDuringFileOpen(struct subjectRecord newSubjectRecord, char c[]);

struct subjectRecord{
    int subjectIDNumber;
    char subjectCode[10];
    char title[50];
} subjectsDirectory[20];

struct studentRecord{
    int IDNumber;
    char lastName[15];
    char firstName[20];
    char lectureSection[10];
    float handsOnExam1;
    float handsOnExam2;
    float handsonExam3;
    struct subjectRecord *enrolledPtr[3];
    int numOfSubjectsEnrolled;
} studentsDirectory[70], diverge;


int element = 0, element2 =0;
int csvCount;

int main(void){
    system("COLOR f1");
    for(int i=0; i<1000; i++){
        IDAvail[i] = 0;
    }
    int studentFileOpen = 0, subjectFileOpen = 0;
    subjectsDirectory[0].subjectIDNumber = 11;
    strcpy(subjectsDirectory[0].subjectCode, "CMSC11");
    strcpy(subjectsDirectory[0].title, "Introduction to Computer Science");

    element2++;
    subjectIDAvail[subjectsDirectory[0].subjectIDNumber] = 1;
    for(int i = 0; i<70; i++){
        studentsDirectory[i].numOfSubjectsEnrolled = 0;
    }

    int choice;
    printf("\n\n\tReminder: ID numbers(both student and subject)\n\t\t  are fixed once inputed, and \n\t\t  cannot be updated anymore.\n\t\t  FOR NOW.");
    do{
        printf("\n\n");
        printf("\n\t_________________________________________________________________________________________");
        printf("\n\t|                        Welcome to Student's Registration Site                         |");
        printf("\n\t|                                           |                                           |");
        printf("\n\t|         Students Record Menu              |         Subjects Record Menu              |");
        printf("\n\t|                                           |                                           |");
        printf("\n\t|   Input 1: Create a student Record        |   Input 6: Create a subject record        |");
        printf("\n\t|   Input 2: Update a student Record        |   Input 7: Update a subject record        |");
        printf("\n\t|   Input 3: Delete a student Record        |   Input 8: Delete a subject record        |");
        printf("\n\t|   Input 4: Search a student Record        |   Input 9: Search a subject record        |");
        printf("\n\t|   Input 5: Display all student Records    |   Input 10: Display all subject records   |");
        printf("\n\t|_______________________________________________________________________________________|");
        printf("\n\t|                                                                                       |");
        printf("\n\t|                                       Other Menu                                      |");
        printf("\n\t|                                                                                       |");
        printf("\n\t|                       Input 11: Enroll a student to a subject                         |");
        printf("\n\t|                       Input 12: Drop a subject                                        |");
        printf("\n\t|                       Input 0: Exit the program                                       |");
        printf("\n\t|_______________________________________________________________________________________|");
        printf("\n\t\t\tProvide Input: ");

        scanf(" %d", &choice);


        if(choice == 1){
            int choice3, done = 0;
            do{
                int choice2;
                printf("\n");
                printf("\n\t\t\t\t\t\t\t______________________________________");
                printf("\n\t\t\t\t\t\t\t|      Create student Record         |");
                printf("\n\t\t\t\t\t\t\t|                                    |");
                printf("\n\t\t\t\t\t\t\t|   Press 1: Manual Input            |");
                printf("\n\t\t\t\t\t\t\t|   Press 2: Read a File %c.txt%c      |", '"', '"');
                printf("\n\t\t\t\t\t\t\t|   Press 0: Return to Previous Menu |");
                printf("\n\t\t\t\t\t\t\t|____________________________________|");
                printf("\n\t\t\t\t\t\t\t\tInput command: ");
                scanf(" %d", &choice2);
                if(choice2 == 1){
                    studentsDirectory[element] = createRecord(studentsDirectory[element]);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|      A New Student Record was Added     |");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   By default Student with ID no. %03d    |", studentsDirectory[element].IDNumber);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|    will be automatically enrolled in    |");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|                  CMSC11                 |");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tRedirecting to the Main Menu...");
                    studentsDirectory[element].enrolledPtr[studentsDirectory[element].numOfSubjectsEnrolled] = &subjectsDirectory[0];
                    done = 1;
                    element++;
                }else if(choice2==2){
                    int initial = element;

                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|            INPUT THROUGH FILE           |");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tScanning Students.txt file...");
                        fileInput();
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tScanning Complete.");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t%d Student Records were added", element-initial);
                        studentFileOpen++;
                        done = 1;

                }else if(choice2 == 0){
                    printf("\n\t\t\t\t\t\t\tReturning to previous menu...");
                    break;
                }else{
                    printf("\n\t\t\t\t\t\t\tInvalid Command");
                }
            }while(done != 1);
        }else if(choice == 2){
            int id, count = 0;

            if(element != 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|       UPDATE A STUDENT RECORD       |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                do{
                    if(count == 0 && element != 0){
                        printf("\n\t\t\t\t\t\t\tEnter ID number: ");
                    }else if(count == 1 && element != 0){
                        printf("\n\t\t\t\t\t\t\tNo such ID exist.\n\t\t\t\t\t\t\tEnter again an ID number: ");
                    }
                    scanf(" %d", &id);
                    count = IDCheck(id, count);
                }while(count == 1);
                for(int i=0; i<70; i++){
                    if(id == studentsDirectory[i].IDNumber){
                        studentsDirectory[i] = updateRecord(studentsDirectory[i]);
                        break;
                    }
                }
            }else{
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|        NO STUDENT RECORD YET        |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            }
        }else if(choice == 3){
            int count = 0, id;
            if(element != 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|       DELETE A STUDENT RECORD       |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                do{
                    if(count == 0 && element != 0){
                        printf("\n\t\t\t\t\t\t\tEnter ID number: ");
                    }else if(count == 1 && element != 0){
                        printf("\n\t\t\t\t\t\t\tNo such ID exist.\n\t\t\t\t\t\t\tEnter again an ID number: ");
                    }
                    scanf(" %d", &id);
                    while(id >= 1000 || id <= 0){
                        printf("\n\t\t\t\t\t\t\tYou've enter a not valid ID number.\n\t\t\t\t\t\t\tEnter again ID number: ");
                        scanf(" %d", &id);
                    }
                    count = IDCheck(id, count);
                }while(count == 1);
                for(int i=0; i<70; i++){
                    if(id == studentsDirectory[i].IDNumber){
                        int des;
                        printf("\n\t\t\t\t\t\t\tYou're about to delete all records of %s %s.", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
                        printf("\n\t\t\t\t\t\t\t\tPress 1: Delete %s's records.\n\t\t\t\t\t\t\t\tPress other numeric keys to cancel.\n\n\t\t\t\t\t\t\tInput: ", studentsDirectory[i].lastName);
                        scanf(" %d", &des);
                        if(des == 1){
                            delelteStudentRecord(studentsDirectory[i], i);
                            printf("\n\t\t\t\t\t\t\t_______________________________________");
                            printf("\n\t\t\t\t\t\t\t|           DELETE COMPLETE           |");
                            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                            printf("\n\t\t\t\t\t\t\tRedirecting to Main Menu...");
                        }else{
                            printf("\n\t\t\t\t\t\t\t%s %s's records were not deleted", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
                        }
                        break;
                    }
                }
            }else{
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|        NO STUDENT RECORD YET        |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            }


        }else if(choice == 4){
            char surname[15];
            if(element != 0){
                int truth, count =0;
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|        SEARCH STUDENT RECORD        |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                printf("\n\t\t\t\t\t\t\tInput surname: ");
                scanf(" %[^\n]", &surname);
                for(int i=0; i<element; i++){
                    truth = stringCompare(surname, studentsDirectory[i].lastName);
                    if(truth == 0){
                        if(count == 0){
                            printf("\n\t\t\t\t\t\t\t_______________________________________");
                            printf("\n\t\t\t\t\t\t\t|   PRINT SPECIFIC STUDENT RECORD/S   |");
                            printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                            printf("\n\t\t\t\t\t\t\tPrinting all student records with surname %s\n", surname);

                            printf("\tID Number");  //9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("First Name"); //10
                            for(int i=1; i<=10; i++){
                                printf(" ");
                            }
                            printf("Last Name"); // 9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("CMSC11 Section"); //14
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("Subject Enrolled");
                            for(int i=1; i<=14; i++){
                                printf(" ");
                            }
                            printf("HEX1 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX2 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX3 Score   "); //10

                            printf("Total");
                            printf("   Grade\n");
                        }
                        printf("\t");
                        displayRecords(&studentsDirectory[i]);
                        printf("\n");
                        count++;
                    }
                }
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\tSurname %s was not found.", surname);
                }
            }else{
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|        NO STUDENT RECORD YET        |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            }
        }else if(choice == 5){
            sorting();
            if(element != 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|      PRINT ALL STUDENT RECORDS      |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
                printf("\tCount   ");
                printf("ID Number");  //9
                for(int i=1; i<=6; i++){
                    printf(" ");
                }
                printf("First Name"); //10
                for(int i=1; i<=10; i++){
                    printf(" ");
                }
                printf("Last Name"); // 9
                for(int i=1; i<=6; i++){
                    printf(" ");
                }
                printf("CMSC11 Section"); //14
                for(int i=1; i<=3; i++){
                    printf(" ");
                }
                printf("Subject Enrolled");
                for(int i=1; i<=14; i++){
                    printf(" ");
                }
                printf("HEX1 Score"); //10
                for(int i=1; i<=3; i++){
                    printf(" ");
                }
                printf("HEX2 Score"); //10
                for(int i=1; i<=3; i++){
                    printf(" ");
                }
                printf("HEX3 Score   "); //10

                printf("Total");//8
                printf("   Grade\n");
                csvCount = 1;
                for(int i=0; i<element; i++){
                    if(csvCount > 0 && csvCount <10){
                        printf("\t%d       ",csvCount);
                    }else{
                        printf("\t%d      ",csvCount);
                    }
                    csvCount++;
                    displayRecords(&studentsDirectory[i]);
                    printf("\n");
                }
                displayCalculations();
            }else{
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|        NO STUDENT RECORD YET        |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            }

        }else if(choice == 6){
            int choice2;
            do{

                printf("\n");
                printf("\n\t\t\t\t\t\t\t______________________________________");
                printf("\n\t\t\t\t\t\t\t|      Create Subject Record         |");
                printf("\n\t\t\t\t\t\t\t|                                    |");
                printf("\n\t\t\t\t\t\t\t|   Press 1: Manual Input            |");
                printf("\n\t\t\t\t\t\t\t|   Press 2: Read a File %c.txt%c      |", '"', '"');
                printf("\n\t\t\t\t\t\t\t|   Press 0: Return to Previous Menu |");
                printf("\n\t\t\t\t\t\t\t|____________________________________|");
                printf("\n\t\t\t\t\t\t\t\tInput command: ");
                scanf("%d", &choice2);
                if(choice2 == 1){
                    subjectsDirectory[element2] = createSubjectRecord(subjectsDirectory[element2]);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|      A New Subject Record was Added     |");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tRedirecting to Main Menu...");
                    element2++;
                    break;
                }else if(choice2 == 2){
                    int initial = element2;

                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|            INPUT THROUGH FILE           |");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tScanning subjects.txt file.\n");
                        subjectsFileInput();
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|             SCANNING COMPLETE           |");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t%d subject records added", element2-initial);
                        subjectFileOpen++;

                    break;
                }

            }while(choice2 != 0);

        }else if(choice == 7){
            char code[10];
            int count, count1=0, index, index1, y;
            printf("\n\t\t\t\t\t\t\t_______________________________________");
            printf("\n\t\t\t\t\t\t\t|       UPDATE A STUDENT RECORD       |");
            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            if(element2 != 0){
                do{

                    if(count1 == 0){
                        printf("\n\t\t\t\t\t\t\tEnter subject code: ");
                        scanf(" %[^\n]", &code);
                    }else{
                        printf("\n\t\t\t\t\t\t\tNo such subject code exist.\n\t\t\t\t\t\t\tEnter again an Existing subject code: ");
                        scanf(" %[^\n]", &code);
                    }
                    for(int i=0; i<element2; i++){
                        count = stringCompare(code, subjectsDirectory[i].subjectCode);
                        if(count == 0){
                            subjectsDirectory[i] = updateSubjectRecord(subjectsDirectory[i]);
                            break;
                        }
                    }
                    count1++;
                }while(count != 0);
            }else{
                printf("\n\t\t\t\t\t\t\t************NO SUBJECT RECORD YET************\n");
            }


        }else if(choice == 8){
            int count = 0;

            printf("\n\t\t\t\t\t\t\t_______________________________________");
            printf("\n\t\t\t\t\t\t\t|           DELETE A SUBJECT          |");
            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            if(element2 == 1){
                printf("\n\t\t\t\t\t\t\tOnly one subject is found. And cannot be deleted.");
            }else{
                int cmsc11, compare, done = 0;
                char code[10];
                printf("\n\t\t\t\t\t\t\tInput subject code: ");
                scanf(" %[^\n]", &code);
                cmsc11 = stringCompare(subjectsDirectory[0].subjectCode, code);
                if(cmsc11 == 0){
                    printf("\n\t\t\t\t\t\t\tCannot Delete Subject CMSC11");
                    done++;
                }else{
                    for(int i=1; i<element2; i++){
                        compare = stringCompare(code, subjectsDirectory[i].subjectCode);
                        if(compare == 0){
                            int des;
                            printf("\n\t\t\t\t\t\t\tAre you sure to delete %s(%d)?\n\t\t\t\t\t\t\tDeleting this subject will affect student record.", subjectsDirectory[i].subjectCode, subjectsDirectory[i].subjectIDNumber);
                            printf("\n\t\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\t\tPress other numeric keys to cancel.\n\t\t\t\t\t\t\tInput: ");
                            scanf(" %d", &des);
                            if(des == 1){
                                deleteSubjectRecord(subjectsDirectory[i], i, 1);
                                element2--;
                                printf("\n\t\t\t\t\t\t\tSubject was deleted");
                                done++;

                            }else{
                                printf("\n\t\t\t\t\t\t\tSubject was not Deleted.");

                            }
                            break;
                        }
                    }
                }
                if(done == 0){
                    printf("\n\t\t\t\t\t\t\tSubject Code not Found");
                }

            }
        }else if(choice ==9){
            char code[10];
            int counter = 0, truth;
            printf("\n\t\t\t\t\t\t\t_______________________________________");
            printf("\n\t\t\t\t\t\t\t|        SEARCH SUBJECT RECORD        |");
            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
            if(element2 != 0){
                do{
                    if(counter == 0){
                        printf("\n\t\t\t\t\t\t\tEnter the subject code: ");
                        scanf(" %9[^\n]s", &code);
                    }else{
                        printf("\nSubject code not found");
                        printf("\nEnter again the subject code: ");
                        scanf(" %9[^\n]s", &code);
                    }
                    for(int i=0; i<element2; i++){
                        truth = stringCompare(code, subjectsDirectory[i].subjectCode);
                        if(truth == 0){
                            printf("\n\t\t\t\t\t\t\t_______________________________________");
                            printf("\n\t\t\t\t\t\t\t|    PRINT SPECIFIC SUBJECT RECORD    |");
                            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                            printf("\n\t\t\t\t\t\tSubject ID Number  "); //19
                            printf("Subject Code  "); //14
                            printf("Subject Title\n\t\t\t\t\t\t");
                            displaySubjectRecord(subjectsDirectory[i]);
                            break;
                        }
                    }
                    counter++;

                }while(truth != 0);
            }else{
                printf("\n\t\t\t\t\t\t\t************NO SUBJECT RECORD YET************\n");
            }
        }else if(choice == 10){
            if(element2 != 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|      PRINT ALL SUBJECT RECORDS      |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
                printf("\t\t\t\t\t\tSubject ID Number  "); //19
                printf("Subject Code  "); //14
                printf("Subject Title\n");
                for(int i = 0; i<element2; i++){
                    printf("\t\t\t\t\t\t");
                    displaySubjectRecord(subjectsDirectory[i]);
                    printf("\n");
                }
            }else{
                printf("\n\t\t\t\t\t\t\t************NO SUBJECT RECORD YET************\n");
            }
        }else if(choice == 11){
            if(element2 == 1){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|      ONLY DEFAULT SUBJECT FOUND     |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|");
            }
            if(element == 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|    NO STUDENT RECORDS WERE FOUND    |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|");

            }
            if((element2 == 1) || (element == 0)){
                printf("\n\t\t\t\t\t\t\tRedirecting to Main Menu..." );
            }else{
                int ID, truth = 1, studendTrue = 0, studentCount = 0;
                char x[10];
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|           ENROLL A STUDENT          |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
                do{

                    if(studentCount == 0){
                        printf("\n\t\t\t\t\t\t\tEnter ID number of a student: ");
                        scanf(" %d", &ID);
                        studentCount++;
                    }else{
                        int des;
                        printf("\n\t\t\t\t\t\t\tEither input is invalid or inputed ID number does not exist.");
                        printf("\n\t\t\t\t\t\t\tDo you want to show the list of all student records? ");
                        printf("\n\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\tPress other Numeric key to neglect.\n\t\t\t\t\t\t\tInput: ");
                        scanf(" %d", &des);
                        if(des == 1){
                            printf("\n\t\t\t\t\t\t\t************Please Refer to the guide below************\n");
                            printf("\tID Number");  //9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("First Name"); //10
                            for(int i=1; i<=10; i++){
                                printf(" ");
                            }
                            printf("Last Name"); // 9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("CMSC11 Section"); //14
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("Subject Enrolled");
                            for(int i=1; i<=14; i++){
                                printf(" ");
                            }
                            printf("HEX1 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX2 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX3 Score   "); //10

                            printf("Total");//8
                            printf("   Grade\n");
                            for(int i=0; i<element; i++){
                                printf("\t");
                                displayRecords(&studentsDirectory[i]);
                                printf("\n");
                            }
                        }
                        printf("\n\t\t\t\t\t\t\tEnter Again ID number of a student: ");
                        scanf(" %d", &ID);
                    }
                    studendTrue = IDCheck(ID, studendTrue);

                }while(studendTrue == 1);
                int count = 0;
                do{
                    int des;
                    for(int i=0; i<element; i++){
                        if(ID == studentsDirectory[i].IDNumber){
                            if(studentsDirectory[i].numOfSubjectsEnrolled == 3){
                                printf("\n\t\t\t\t\t\t\t_______________________________________");
                                printf("\n\t\t\t\t\t\t\t|    STUDENT IS ALREADY OVERLOADED    |");
                                printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                                truth = 0;
                                break;
                            }else{
                                if(count != 0){
                                    printf("\n\t\t\t\t\t\t\tDo you want to show all the list of subject records?\n\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\tPress other numeric keys to neglect.\n\t\t\t\t\t\t\tInput: ");
                                    scanf(" %d", &des);
                                    if(des == 1){
                                        printf("\n\t\t\t\t\t\t\tGUIDE FOR SUBJECT CODE: \n");
                                        printf("\t\t\t\t\t\t\tSubject ID Number  "); //19
                                        printf("Subject Code  "); //14
                                        printf("Subject Title\n");
                                        for(int h=0; h<element2; h++){
                                            printf("\t\t\t\t\t\t\t");
                                            displaySubjectRecord(subjectsDirectory[h]);
                                            printf("\n");
                                        }
                                    }
                                }

                                printf("\n\t\t\t\t\t\t\tEnter Subject Code: ");
                                scanf(" %9[^\n]s", &x);
                                for(int j=0; j<element2; j++){
                                    int truth2;
                                    truth = stringCompare(x, subjectsDirectory[j].subjectCode);
                                    if(truth == 0){
                                        for(int k=0; k<studentsDirectory[i].numOfSubjectsEnrolled; k++){
                                            truth2 = stringCompare(x, studentsDirectory[i].enrolledPtr[k]->subjectCode);
                                            if(truth2 == 0){
                                                printf("\n\t\t\t\t\t\t\tStudent was already enrolled in the subject");
                                                break;
                                            }
                                        }
                                        if(truth2 != 0){
                                            studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled] = &subjectsDirectory[j];
                                            printf("\n\t\t\t\t\t\t\t_______________________________________");
                                            printf("\n\t\t\t\t\t\t\t|        SUCCESSFULLY ENROLLED        |");
                                            printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                                            studentsDirectory[i].numOfSubjectsEnrolled++;
                                            break;
                                        }
                                        break;
                                    }
                                }
                            }
                            if(truth != 0 ){
                                printf("\n\t\t\t\t\t\t\t_______________________________________");
                                printf("\n\t\t\t\t\t\t\t|         INVALID SUBJECT CODE        |");
                                printf("\n\t\t\t\t\t\t\t|_____________________________________|\n");
                                count++;
                            }
                            if(truth ==0){
                                break;
                            }
                        }

                    }
                }while(truth !=0);


            }
        }else if(choice == 12){
            int ID;
            if(element == 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|    NO STUDENT RECORDS WERE FOUND    |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                printf("\n\t\t\t\t\t\t\tRedirecting to Main Menu..." );
            }
            if(element2 == 1 && element != 0){
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|    ONLY DEFAULT SUBJECT IS FOUND    |");
                printf("\n\t\t\t\t\t\t\t|  DEFAULT SUBJECT CANNOT BE DROPPED  |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                printf("\n\t\t\t\t\t\t\tRedirecting to Main Menu..." );
            }
            if(element2 >1 && element != 0){
                int studentCount = 0, studentTrue = 0;
                printf("\n\t\t\t\t\t\t\t_______________________________________");
                printf("\n\t\t\t\t\t\t\t|             DROP A SUBJECT          |");
                printf("\n\t\t\t\t\t\t\t|_____________________________________|");
                do{

                    if(studentCount == 0){
                        printf("\n\t\t\t\t\t\t\tEnter ID number of a student: ");
                        scanf(" %d", &ID);
                        studentCount++;
                    }else{
                        int des;
                        printf("\n\t\t\t\t\t\t\tEither input is invalid or inputed ID number does not exist.");
                        printf("\n\t\t\t\t\t\t\tDo you want to show the list of all student records? ");
                        printf("\n\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\tPress other Numeric key to neglect.\n\t\t\t\t\t\t\tInput: ");
                        scanf(" %d", &des);
                        if(des == 1){
                            printf("\n\t\t\t\t\t\t\t************Please Refer to the guide below************\n");
                            printf("\tID Number");  //9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("First Name"); //10
                            for(int i=1; i<=10; i++){
                                printf(" ");
                            }
                            printf("Last Name"); // 9
                            for(int i=1; i<=6; i++){
                                printf(" ");
                            }
                            printf("CMSC11 Section"); //14
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("Subject Enrolled");
                            for(int i=1; i<=14; i++){
                                printf(" ");
                            }
                            printf("HEX1 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX2 Score"); //10
                            for(int i=1; i<=3; i++){
                                printf(" ");
                            }
                            printf("HEX3 Score   "); //10

                            printf("Total");//8
                            printf("   Grade\n");
                            for(int i=0; i<element; i++){
                                printf("\t");
                                displayRecords(&studentsDirectory[i]);
                                printf("\n");
                            }
                        }
                        printf("\n\t\t\t\t\t\t\tEnter Again ID number of a student: ");
                        scanf(" %d", &ID);
                    }
                    studentTrue = IDCheck(ID, studentTrue);

                }while(studentTrue == 1);
                for(int i = 0; i<element; i++){
                    if(ID == studentsDirectory[i].IDNumber){
                        if(studentsDirectory[i].numOfSubjectsEnrolled == 1){
                            printf("\n\t\t\t\t\t\t\tStudent was enrolled only to default subject CMSC11.\n\t\t\t\t\t\t\tRedirecting to Main Menu.");
                        }else{
                            dropSubject(&studentsDirectory[i]);
                        }
                        break;
                    }
                }
            }
        }else if(choice==0){
            printf("\n\t\t\t\t\t\t\t_______________________________________");
            printf("\n\t\t\t\t\t\t\t|          PROGRAM TERMINATED...      |");
            printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
        }else{
            printf("\n\t\t\t\t\t\t\t_______________________________________");
            printf("\n\t\t\t\t\t\t\t|            INVALID COMMAD           |");
            printf("\n\t\t\t\t\t\t\t|_____________________________________|");
        }
    }while(choice != 0);
    FILE *fPtr;
    int des;
    if(element != 0){
        printf("\n\t\t\t\t\t\t\t_______________________________________");
        printf("\n\t\t\t\t\t\t\t|   By default, student records will  |");
        printf("\n\t\t\t\t\t\t\t|    automatically be saved in CSV    |");
        printf("\n\t\t\t\t\t\t\t|    format but you have to provide   |");
        printf("\n\t\t\t\t\t\t\t|           the file address          |");
        printf("\n\t\t\t\t\t\t\t|_____________________________________|");
        sorting();
        char path[50];
        printf("\n\t\t\t\t\t\t\t\tProvide Address(e.g. masterlist.csv): ", '\0');
        scanf(" %[^\n]", &path);
        fPtr = fopen(path , "w+");
        fprintf(fPtr,"Count, ID number, First Name, Last Name, CMSC11Section, Subjects Enrolled, HEX1 Score, HEX2 Score, HEX3 Score, Total, Grade\n");
        csvCount = 1;
        for(int i=0; i<element; i++){
            csvOutput(studentsDirectory[i], fPtr);
        }
        displayCalculationsCSV(fPtr);
        fclose(fPtr);


    printf("\n\t\t\t\t\t\t\t_______________________________________");
    printf("\n\t\t\t\t\t\t\t|           Do you want to            |");
    printf("\n\t\t\t\t\t\t\t|   save all student records in txt   |");
    printf("\n\t\t\t\t\t\t\t|               format?               |");
    printf("\n\t\t\t\t\t\t\t|_____________________________________|");
    printf("\n\t\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\t\tPress other numeric keys to neglect.");
    printf("\n\t\t\t\t\t\t\tInput: ");
    scanf(" %d", &des);
    if(des == 1){

        char path[50];
        printf("\n\t\t\t\t\t\t\t\tProvide Address(e.g. students.txt): ");
        scanf(" %[^\n]", &path);
        fPtr = fopen(path,"w+");

        //fPtr = fopen("D:\\students.txt", "w");
        for(int i=0; i<element; i++){
            outputStudentTxt(studentsDirectory[i], fPtr);
        }
        fclose(fPtr);

    }else{
        printf("\n\t\t\t\t\t\t\t_______________________________________");
        printf("\n\t\t\t\t\t\t\t|   Student Records were not save     |");
        printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
    }
    }



    printf("\n\t\t\t\t\t\t\t_______________________________________");
    printf("\n\t\t\t\t\t\t\t|  On the other hand, do you want to  |");
    printf("\n\t\t\t\t\t\t\t|   save all subject records in txt   |");
    printf("\n\t\t\t\t\t\t\t|               format?               |");
    printf("\n\t\t\t\t\t\t\t|_____________________________________|");
    printf("\n\t\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\t\tPress other numeric keys to neglect.");
    printf("\n\t\t\t\t\t\t\tInput: ");
    scanf(" %d", &des);
    if(des == 1){
        char path[50];
        printf("\n\t\t\t\t\t\t\t\tProvide Address(e.g. subjects.txt): ");
        scanf(" %[^\n]", &path);
        fPtr = fopen(path,"w+");
        //fPtr = fopen("D:\\subjects.txt", "w+");
        for(int i=0; i<element2; i++){
            csvOutput2(subjectsDirectory[i], fPtr);
        }
        fclose(fPtr);
    }else{
        printf("\n\t\t\t\t\t\t\t_______________________________________");
        printf("\n\t\t\t\t\t\t\t|   Subject Records were not save     |");
        printf("\n\t\t\t\t\t\t\t|_____________________________________|\n\n");
    }
    return 0;
}

struct studentRecord createRecord(struct studentRecord newRecord){
    int count = 1;
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|          CREATE A STUDENT RECORD        |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
    do{
        if(count == 1){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput 3-digit student ID number   : ");
        }else if(count == 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tID number already taken. \n\t\t\t\t\t\t\t\t\t\t\t\tPleas input other 3-digit ID number: ");
        }
        scanf(" %d", &newRecord.IDNumber);
        while(newRecord.IDNumber >= 1000 || newRecord.IDNumber <= 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tYou've enter either non 3 digit or nonpositive digit number.\n\t\t\t\t\t\t\t\t\t\t\t\tPlease enter again a 3-digit ID number: ");
            scanf(" %d", &newRecord.IDNumber);
        }
        count = IDCheck(newRecord.IDNumber, count);

    }while(count == 0);
    IDAvail[newRecord.IDNumber] = 1;
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput last name                   : ");
    scanf(" %14[^\n]s", &newRecord.lastName);
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput first name                  : ");
    scanf(" %19[^\n]s", &newRecord.firstName);
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput CMSC11 Lecture Section      : ");
    scanf(" %9[^\n]s", &newRecord.lectureSection);
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput first hands on exam score   : ");
    scanf(" %f", &newRecord.handsOnExam1);
    count = 0;
    if(newRecord.handsOnExam1 < 0 || newRecord.handsOnExam1 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX1 score of %s %s", newRecord.firstName, newRecord.lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &newRecord.handsOnExam1);
                count++;
            }while(newRecord.handsOnExam1 < 0 || newRecord.handsOnExam1 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX1 SUCCESFULLY CHANGE!\n");
        }
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput second hands on exam score  : ");
    scanf(" %f", &newRecord.handsOnExam2);
    count = 0;
    if(newRecord.handsOnExam2 < 0 || newRecord.handsOnExam2 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX2 score of %s %s", newRecord.firstName, newRecord.lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &newRecord.handsOnExam2);
                count++;
            }while(newRecord.handsOnExam2 < 0 ||  newRecord.handsOnExam2 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX2 SUCCESFULLY CHANGE!\n");
        }
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput third hands on exam score   : ");
    scanf(" %f", &newRecord.handsonExam3);
    count = 0;
    if(newRecord.handsonExam3 < 0 || newRecord.handsonExam3 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX3 score of %s %s", newRecord.firstName, newRecord.lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &newRecord.handsonExam3);
                count++;
            }while(newRecord.handsonExam3 < 0 || newRecord.handsonExam3 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX3 SUCCESFULLY CHANGE!\n");
        }
    return newRecord;
};

int IDCheck(int ID, int check){
    if(IDAvail[ID] == 0){
        check =1;
    }else {
        check = 0;
    }
    return check;

};

struct studentRecord updateRecord(struct studentRecord upRecord){
    int choice2;
    int count = 0;
    do{
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t_____________________________________________");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|***********UPDATE STUDENT RECORD***********|\n\t\t\t\t\t\t\t\t\t\t\t\t|\t\t\t\t\t    |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 1: Update last name.              |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 2: Update first name.             |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 3: Update CMSC11 Lecture Sectio.  |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 4: Update HEX1 score.             |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 5: Update HEX2 score.             |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 6: Update Hes3 score.             |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|   Press 0: Return to previous menu.       |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|___________________________________________|");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tEnter Command: ");
        scanf(" %d", &choice2);

        if(choice2 == 1){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated last name: ");
            scanf(" %14[^\n]s", &upRecord.lastName);
        }else if(choice2 == 2){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated first name: ");
            scanf(" %19[^\n]s", &upRecord.firstName);
        }else if(choice2 == 3){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated CMSC11 Lecture Section: ");
            scanf(" %9[^\n]s", &upRecord.lectureSection);
        }else if(choice2 == 4){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated first hands on exam score: ");
            scanf(" %f", &upRecord.handsOnExam1);
            count = 0;
            if(upRecord.handsOnExam1 < 0 || upRecord.handsOnExam1 > 50){
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX1 score of %s %s", upRecord.firstName, upRecord.lastName);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
                do{
                    if(count == 0){
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }else{
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }
                    scanf(" %f", &upRecord.handsOnExam1);
                    count++;
                }while(upRecord.handsOnExam1 < 0 || upRecord.handsOnExam1 > 50);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX1 SUCCESFULLY CHANGE!\n");
            }
        }else if(choice2 == 5){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated second hands on exam score: ");
            scanf(" %f", &upRecord.handsOnExam2);
            count = 0;
            if(upRecord.handsOnExam2 < 0 || upRecord.handsOnExam2 > 50){
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX2 score of %s %s", upRecord.firstName, upRecord.lastName);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
                do{
                    if(count == 0){
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }else{
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }
                    scanf(" %f", &upRecord.handsOnExam2);
                    count++;
                }while(upRecord.handsOnExam2 < 0 ||  upRecord.handsOnExam2 > 50);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX2 SUCCESFULLY CHANGE!\n");
            }
        }else if(choice2 == 6){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput updated third hands on exam score: ");
            scanf(" %f", &upRecord.handsonExam3);
            count = 0;
            if(upRecord.handsonExam3 < 0 || upRecord.handsonExam3 > 50){
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX3 score of %s %s", upRecord.firstName, upRecord.lastName);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
                do{
                    if(count == 0){
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }else{
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                    }
                    scanf(" %f", &upRecord.handsonExam3);
                    count++;

                }while(upRecord.handsonExam3 < 0 || upRecord.handsonExam3 > 50);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX3 SUCCESFULLY CHANGE!\n");
            }
        }else if(choice2 == 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|        REDIRECTING TO MAIN MENU         |");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
        }else{
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|              INVALID COMMAND            |");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
        }

    }while(choice2 != 0);
    return upRecord;
};

void delelteStudentRecord(struct studentRecord deleteS, int index){
    IDAvail[deleteS.IDNumber] = 0;
    for(int i= index; i<element; i++){
        studentsDirectory[i] = studentsDirectory[i+1];
    }
    element--;
}

void displayRecords(struct studentRecord *printRecord){
    int lastNameIndex, firstNameIndex, sectionIndex, enrollIndex, subjectIndex = 0, sub;
    float total = 0;
    if(printRecord->IDNumber>= 0 && printRecord->IDNumber <= 9){
        printf("00%d", printRecord->IDNumber);
        for(int i=1; i<=12; i++){
            printf(" ");
        }
    }else if(printRecord->IDNumber>=10 && printRecord->IDNumber<=99){
        printf("0%d", printRecord->IDNumber);
        for(int i=1; i<=12; i++){
            printf(" ");
        }
    }else{
        printf("%d", printRecord->IDNumber);
        for(int i=1; i<=12; i++){
            printf(" ");
        }
    }
    firstNameIndex = strcspn(printRecord->firstName, "\n");
    printf("%s", printRecord->firstName);
    for(int i=1; i<= 20-firstNameIndex; i++){
        printf(" ");
    }
    lastNameIndex = strcspn(printRecord->lastName, "\n");
    printf("%s", printRecord->lastName);
    for(int i=1; i<= 15-lastNameIndex; i++){
        printf(" ");
    }

    sectionIndex = strcspn(printRecord->lectureSection, "\n");
    printf("%s", printRecord->lectureSection);
    for(int i=1; i<=17-sectionIndex; i++){
        printf(" ");
    }
    for(int i = 0; i<3; i++){
        if(i == 2){
            if(printRecord->enrolledPtr[i] == NULL || printRecord->enrolledPtr[i] == '\0' || printRecord->enrolledPtr[i] == 0){
                printf("none");
                subjectIndex += 4;
            }else{
                printf("%s", printRecord->enrolledPtr[i]->subjectCode);
                sub = strcspn(printRecord->enrolledPtr[i]->subjectCode, "\n");
                subjectIndex += sub;
            }
        }else{
            if(printRecord->enrolledPtr[i] == NULL){
                printf("none,");
                subjectIndex += 5;
            }else{
                printf("%s,", printRecord->enrolledPtr[i]->subjectCode);
                sub = strcspn(printRecord->enrolledPtr[i]->subjectCode, "\n");
                subjectIndex += sub;
                subjectIndex++;
            }
        }

    }
    for(int i = 1; i<=30-subjectIndex; i++){
        printf(" ");
    }
    if(printRecord->handsOnExam1 >= 0 &&  printRecord->handsOnExam1 <= 9){
        printf("%.1f", printRecord->handsOnExam1);
        for(int i=1; i<= 10; i++){
            printf(" ");
        }
    }else if(printRecord->handsOnExam1 >= 10 && printRecord->handsOnExam1 <=99){
        printf("%.1f", printRecord->handsOnExam1);
        for(int i = 1; i<= 9; i++){
            printf(" ");
        }
    }else{
        printf("%.1f", printRecord->handsOnExam1);
        for(int i = 1; i<= 8; i++){
            printf(" ");
        }
    }
    if(printRecord->handsOnExam2>=0 && printRecord->handsOnExam2 <=9){
        printf("%.1f", printRecord->handsOnExam2);
        for(int i = 1; i<= 10; i++){
            printf(" ");
        }
    }else if(printRecord->handsOnExam2 >= 10 && printRecord->handsOnExam2 <=99){
        printf("%.1f", printRecord->handsOnExam2);
        for(int i = 1; i<= 9; i++){
            printf(" ");
        }
    }else{
        printf("%.1f", printRecord->handsOnExam2);
        for(int i = 1; i<= 8; i++){
            printf(" ");
        }
    }
    if(printRecord->handsonExam3 >= 0 && printRecord->handsonExam3 <=9){
        printf("%.1f", printRecord->handsonExam3);
        for(int i = 1; i<= 10; i++){
            printf(" ");
        }
    }else if(printRecord->handsonExam3 >= 10 && printRecord->handsonExam3 <=99){
        printf("%.1f", printRecord->handsonExam3);
        for(int i = 1; i<= 9; i++){
            printf(" ");
        }
    }else{
        printf("%.1f", printRecord->handsonExam3);
        for(int i = 1; i<= 8; i++){
            printf(" ");
        }
    }

    total = printRecord->handsOnExam1 + printRecord->handsOnExam2 + printRecord->handsonExam3;
    if(total >= 0 && total < 10){
        printf("%.1f", total);
        printf("     ");
    }else if(total >=10 && total < 100){
        printf("%.1f", total);
        printf("    ");
    }else{
        printf("%.1f", total);
        printf("   ");
    }
    if(total >= 135){
        printf("HD");
    }else if(total >= 120 && total <134){
        printf("D");
    }else if(total >= 100 && total <120){
        printf("P");
    }else if(total >= 75 && total < 100){
        printf("C");
    }else{
        printf("F");
    }

};
void displayCalculations(void){
    float hex1Low, hex1High, hex1Sum = 0.0, hex2Low, hex2High, hex2Sum = 0.0, hex3Low, hex3High, hex3Sum, hex1Ave, hex2Ave, hex3Ave;
    float differ1, sumOfDiffer1 = 0, differ2, sumOfDiffer2 = 0, differ3, sumOfDiffer3 = 0, differAve, sumOfDifferAve = 0;
    for(int i=0; i<element; i++){
        if(i == 0){
            hex1Low = studentsDirectory[i].handsOnExam1;
            hex1High = studentsDirectory[i].handsOnExam1;
            hex2Low = studentsDirectory[i].handsOnExam2;
            hex2High = studentsDirectory[i].handsOnExam2;
            hex3Low = studentsDirectory[i].handsonExam3;
            hex3High = studentsDirectory[i].handsonExam3;
        }else{
            if(studentsDirectory[i].handsOnExam1 < hex1Low){
                hex1Low = studentsDirectory[i].handsOnExam1;
            }else if(studentsDirectory[i].handsOnExam1 > hex1High){
                hex1High = studentsDirectory[i].handsOnExam1;
            }
            if(studentsDirectory[i].handsOnExam2 < hex2Low){
                hex2Low = studentsDirectory[i].handsOnExam2;
            }else if(studentsDirectory[i].handsOnExam2 > hex2High){
                hex2High = studentsDirectory[i].handsOnExam2;
            }
            if(studentsDirectory[i].handsonExam3 < hex3Low){
                hex3Low = studentsDirectory[i].handsonExam3;
            }else if(studentsDirectory[i].handsonExam3 > hex3High){
                hex3High = studentsDirectory[i].handsonExam3;
            }
        }
        hex1Sum += studentsDirectory[i].handsOnExam1;
        hex2Sum += studentsDirectory[i].handsOnExam2;
        hex3Sum += studentsDirectory[i].handsonExam3;
    }
    printf("\n\n");
    printf("\t");
    for(int i = 1; i<= 15; i++){
        printf("     ");
    }
    printf("Lowest");
    for(int i =1; i<=4; i++){
        printf("      ");
    }
    if(hex1Low >=0 && hex1Low<10){
        printf("%.1f          ", hex1Low);
    }else if(hex1Low >=10 && hex1Low <100){
        printf("%.1f         ", hex1Low);
    }else{
        printf("%.1f        ", hex1Low);
    }
    if(hex2Low >=0 && hex2Low<10){
        printf("%.1f          ", hex2Low);
    }else if(hex2Low >=10 && hex2Low <100){
        printf("%.1f         ", hex2Low);
    }else{
        printf("%.1f        ", hex2Low);
    }
    if(hex3Low >=0 && hex3Low<10){
        printf("%.1f          ", hex3Low);
    }else if(hex3Low >=10 && hex3Low <100){
        printf("%.1f         ", hex3Low);
    }else{
        printf("%.1f        ", hex3Low);
    }
    printf("%.1f\n", hex1Low + hex2Low + hex3Low);
    printf("\t");
    for(int i = 1; i<= 15; i++){
        printf("     ");
    }
    printf("Highest ");
    for(int i =1; i<=11; i++){
        printf("  ");
    }
    if(hex1High >=0 && hex1High<10){
        printf("%.1f          ", hex1High);
    }else if(hex1High >=10 && hex1High <100){
        printf("%.1f         ", hex1High);
    }else{
        printf("%.1f        ", hex1High);
    }
    if(hex2High >=0 && hex2High<10){
        printf("%.1f          ", hex2High);
    }else if(hex2High >=10 && hex2High <100){
        printf("%.1f         ", hex2High);
    }else{
        printf("%.1f        ", hex2High);
    }
    if(hex3High >=0 && hex3High<10){
        printf("%.1f          ", hex3High);
    }else if(hex3High >=10 && hex3High <100){
        printf("%.1f         ", hex3High);
    }else{
        printf("%.1f        ", hex3High);
    }
    printf("%.1f\n", hex1High + hex2High + hex3High);
    hex1Ave = hex1Sum/element;
    hex2Ave = hex2Sum/element;
    hex3Ave = hex3Sum/element;
    printf("\t");
    for(int i = 1; i<= 15; i++){
        printf("     ");
    }
    printf("Average ");
    for(int i =1; i<=11; i++){
        printf("  ");
    }
    if(hex1Ave >=0 && hex1Ave<10){
        printf("%.3f        ", hex1Ave);
    }else if(hex1Ave >=10 && hex1Ave <100){
        printf("%.3f       ", hex1Ave);
    }else{
        printf("%.3f      ", hex1Ave);
    }
    if(hex2Ave >=0 && hex2Ave<10){
        printf("%.3f        ", hex2Ave);
    }else if(hex2Ave >=10 && hex2Ave <100){
        printf("%.3f       ", hex2Ave);
    }else{
        printf("%.3f      ", hex2Ave);
    }
    if(hex3Ave >=0 && hex3Ave<10){
        printf("%.3f        ", hex3Ave);
    }else if(hex3Ave >=10 && hex3Ave <100){
        printf("%.3f       ", hex3Ave);
    }else{
        printf("%.3f      ", hex3Ave);
    }
    printf("%.3f\n", hex1Ave + hex2Ave + hex3Ave);
    printf("\t");
    for(int i = 1; i<= 15; i++){
        printf("     ");
    }
    printf("Standard Deviation");
    for(int i =1; i<=6; i++){
        printf("  ");
    }
    for(int i=0; i<element; i++){
        differ1 = pow(studentsDirectory[i].handsOnExam1-hex1Ave, 2);
        differ2 = pow(studentsDirectory[i].handsOnExam2-hex2Ave, 2);
        differ3 = pow(studentsDirectory[i].handsonExam3-hex3Ave, 2);
        differAve = pow(((studentsDirectory[i].handsOnExam1+studentsDirectory[i].handsOnExam2+studentsDirectory[i].handsonExam3)/3), 2);
        sumOfDiffer1 += differ1;
        sumOfDiffer2 += differ2;
        sumOfDiffer3 += differ3;
        sumOfDifferAve += differAve;
    }
    if(sqrt(sumOfDiffer1/(element-1)) >= 0 && sqrt(sumOfDiffer1/(element-1)) <10){
        printf("%.3f        ", sqrt(sumOfDiffer1/(element-1)));
    }else{
        printf("%.3f       ", sqrt(sumOfDiffer1/(element-1)));
    }
    if(sqrt(sumOfDiffer2/(element-1)) >= 0 && sqrt(sumOfDiffer2/(element-1)) <10){
        printf("%.3f        ", sqrt(sumOfDiffer2/(element-1)));
    }else{
        printf("%.3f       ", sqrt(sumOfDiffer2/(element-1)));
    }
    if(sqrt(sumOfDiffer3/(element-1)) >= 0 && sqrt(sumOfDiffer3/(element-1)) <10){
        printf("%.3f        ", sqrt(sumOfDiffer3/(element-1)));
    }else{
        printf("%.3f       ", sqrt(sumOfDiffer3/(element-1)));
    }
    printf("%.3f\n", sqrt(sumOfDifferAve/(element-1)));
}


struct subjectRecord createSubjectRecord(struct subjectRecord newSubjectRecord){
    int count = 1;
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|          CREATE A SUBJECT RECORD        |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
    do{
        if(count == 1){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput 2-digit subject ID number: ");
        }else if(count == 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tID number already taken. \n\t\t\t\t\t\t\t\t\t\t\t\tPleas input other 2-digit Subject ID number: ");
        }
        scanf(" %d", &newSubjectRecord.subjectIDNumber);
        while(newSubjectRecord.subjectIDNumber >= 100 || newSubjectRecord.subjectIDNumber <= 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tYou've enter a not valid subject ID number.\n\t\t\t\t\t\t\t\t\t\t\t\tPlease enter again a 2-digit ID number: ");
            scanf(" %d", &newSubjectRecord.subjectIDNumber);
        }
        count = subjectIDcheck(newSubjectRecord.subjectIDNumber, count);

    }while(count == 0);
    subjectIDAvail[newSubjectRecord.subjectIDNumber] = 1;
    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput Subject Code\t       : ");
    scanf(" %9[^\n]s", &newSubjectRecord.subjectCode);
    int found;
    do{
        for(int i=0; i<element2; i++){
            found = stringCompare(newSubjectRecord.subjectCode, subjectsDirectory[i].subjectCode);
            if(found == 0){
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSubject Code was already in used.\n\t\t\t\t\t\t\t\t\t\t\t\tTry again other subject codes.");
                break;
            }
        }
        if(found == 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput again Subject Code: ");
            scanf(" %9[^\n]s", &newSubjectRecord.subjectCode);
        }
    }while(found == 0);
    for(int i = 0; i<10; i++){
        newSubjectRecord.subjectCode[i] = toUpper(newSubjectRecord.subjectCode[i]);
    }

    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput Title of the Subject     : ");
    scanf(" %49[^\n]s", &newSubjectRecord.title);

    return newSubjectRecord;

};
int subjectIDcheck(int ID, int check){
  if(subjectIDAvail[ID] != 1){
    check = 1;
  }else{
    check = 0;
  }
  return check;
};

struct subjectRecord updateSubjectRecord(struct subjectRecord upSubjectRecored){
    int choice2;
    do{
        printf("\n\t\t\t\t\t\t\t_____________________________________________");
        printf("\n\t\t\t\t\t\t\t|***********UPDATE SUBJECT RECORD***********|\n\t\t\t\t\t\t\t|\t\t\t\t\t    |");
        printf("\n\t\t\t\t\t\t\t|   Press 1: Update Subject Code.           |");
        printf("\n\t\t\t\t\t\t\t|   Press 2: Update Subject Title.          |");
        printf("\n\t\t\t\t\t\t\t|   Press 0: Return to previous menu.       |");
        printf("\n\t\t\t\t\t\t\t|___________________________________________|");
        printf("\n\t\t\t\t\t\t\t\tEnter Command: ");
        scanf(" %d", &choice2);
        int exist;
        if(choice2== 1){
            if(subjectsDirectory[0].subjectIDNumber != upSubjectRecored.subjectIDNumber){
                printf("\n\t\t\t\t\t\t\tEnter Updated Subject Code: ");
                scanf(" %9[^\n]s", &upSubjectRecored.subjectCode);
                do{
                    for(int i=0; i<element2; i++){
                        exist = stringCompare(upSubjectRecored.subjectCode, subjectsDirectory[i].subjectCode);
                        if(exist == 0 && upSubjectRecored.subjectIDNumber != subjectsDirectory[i].subjectIDNumber){
                            printf("\n\t\t\t\t\t\t\tSubject code already in use.");
                            printf("\n\t\t\t\t\t\t\tEnter Again Updated Subject Code: ");
                            scanf(" %[^\n]", &upSubjectRecored.subjectCode);
                            break;
                        }

                    }
                }while(exist == 0);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|           SUBJECT CODE UPDATED          |");
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|\n");
                for(int i=0; i<10;i++){
                    upSubjectRecored.subjectCode[i] = toUpper(upSubjectRecored.subjectCode[i]);
                }
            }else{
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tYou cannot update Subject Code of %s", upSubjectRecored.subjectCode);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBut you can change its tittle.");
            }
        }else if(choice2 == 2){
            printf("\n\t\t\t\t\t\t\tEnter Updated Subject Title: ");
            scanf(" %49[^\n]s", &upSubjectRecored.title);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|          SUBJECT TITLE UPDATED          |");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|\n");
        }else if(choice2 == 0){
            printf("\n\t\t\t\t\t\t\t***************REDIRECTING TO PREVIOUS MENU***************");
        }else{
            printf("\n\t\t\t\t\t\t\t***************INVALID COMMAND***************");
        }
    }while(choice2 != 0);
    return upSubjectRecored;
} ;
void deleteSubjectRecord(struct subjectRecord deleteSubject, int index, int x){
    int compare, compare2, represent[70];
    char sub[10];
    if(x == 1){
    for(int i= 0; i<70; i++){
        represent[i] = 0;
    }
    for(int i=0; i<element; i++){
        //printf("\nDidto");
        for(int j = 0; j<studentsDirectory[i].numOfSubjectsEnrolled; j++){
            compare = stringCompare(deleteSubject.subjectCode, studentsDirectory[i].enrolledPtr[j]->subjectCode);
            //printf("\nDiri");
            if(compare == 0){
                represent[i] = 1;
                if(j != 2){
                    //printf("\nDili");
                    if(j+1 != studentsDirectory[i].numOfSubjectsEnrolled){
                        strcpy(sub, studentsDirectory[i].enrolledPtr[j+1]->subjectCode);
                        //printf("\nHaist");
                        for(int k=0; k<element2; k++){

                            compare2 = stringCompare(sub, subjectsDirectory[k].subjectCode);
                            if(compare2 == 0){
                                if(k < index){
                                    studentsDirectory[i].enrolledPtr[j] = &subjectsDirectory[k];
                                }else if(k > index){
                                    studentsDirectory[i].enrolledPtr[j] = &subjectsDirectory[k-1];
                                }
                                break;
                            }
                        }
                    }else{
                        studentsDirectory[i].enrolledPtr[j] = NULL;
                    }
                }
                studentsDirectory[i].enrolledPtr[2] = NULL;
                studentsDirectory[i].numOfSubjectsEnrolled--;
                break;
            }
        }
    }
    }
    subjectIDAvail[deleteSubject.subjectIDNumber] = 0;

    for(int i=index; i<element2; i++){
        if(x == 1){
        for(int j = 0; j<element; j++){
            for(int k = 0; k<studentsDirectory[j].numOfSubjectsEnrolled; k++){
                if(represent[j] == 0){
                    if(stringCompare(subjectsDirectory[i+1].subjectCode, studentsDirectory[j].enrolledPtr[k]->subjectCode) == 0){
                        studentsDirectory[j].enrolledPtr[k] = &subjectsDirectory[i];
                    }
                }
            }
        }
        }
        subjectsDirectory[i] = subjectsDirectory[i+1];
    }
}

void displaySubjectRecord(struct subjectRecord printSubjectRecord){
    int codeIndex;
    codeIndex = strcspn(printSubjectRecord.subjectCode, "\n");
    if(printSubjectRecord.subjectIDNumber >=0 && printSubjectRecord.subjectIDNumber <=9){
        printf("0%d", printSubjectRecord.subjectIDNumber);
        printf("                 ");
    }else{
        printf("%d", printSubjectRecord.subjectIDNumber);
        printf("                 ");
    }
    printf("%s", printSubjectRecord.subjectCode);
    for(int i=1; i<=14-codeIndex; i++){
        printf(" ");
    }
    printf("%s", printSubjectRecord.title);
}

char toUpper(char z){
    char c;
    if(z >= 'a' && z<='z'){
        c = z - 32;
    }else{
        c = z;
    }
    return c;
}

int preEnroll(char z[], struct subjectRecord subjectForEnrolling){
    int gotIt, count = 0, count1, newLineIndex, newLineIndex1;
    newLineIndex1 = strcspn(z, "\n");
    newLineIndex = strcspn(subjectForEnrolling.subjectCode, "\n");
    if(newLineIndex1 == newLineIndex){
        for(int i=0; i<newLineIndex1; i++){
            count1 = 0;
            if(z[i] == subjectForEnrolling.subjectCode[i]){
                count++;
                count1 = 1;
            }
            if((count1 == 0) && (z[i]+32 == subjectForEnrolling.subjectCode[i])){
                count++;
                count1=1;
            }
            if((count1 == 0) && (z[i]-32 == subjectForEnrolling.subjectCode[i])){
                count++;
            }
            if(count == newLineIndex1){
                gotIt = 1;
                break;
            }else{
                gotIt = 0;
            }

        }

    }else{
        gotIt = 0;
    }
    return gotIt;
}

int enrollCheck(char z[], char subjectEnroll[]){
    int gotIt, lineIndex, lineIndex2 = 0, count = 0;
    lineIndex = strcspn(z, "\n");
    for(int i = 0; i<lineIndex; i++){
        z[i] = toUpper(z[i]);
    }
    for(int i=0; i<lineIndex; i++){
        if(z[i] == subjectEnroll[i]){
            count++;
        }
    }
    if(count == lineIndex){
        gotIt = 1;
    }else{
        gotIt = 0;
    }
    return gotIt;
}

void csvOutput(struct studentRecord studentsDirectory,FILE *n){
    float total;
    fprintf(n, "%d, %d, %s, %s, %s, ", csvCount,studentsDirectory.IDNumber, studentsDirectory.firstName, studentsDirectory.lastName, studentsDirectory.lectureSection);
    csvCount++;
    for(int i = 0; i<3; i++){
        if(i == 2){
            if(studentsDirectory.enrolledPtr[i] == NULL){
                fprintf(n,",");
            }else{
                fprintf(n," %c%s%c,", '[',studentsDirectory.enrolledPtr[i]->subjectCode, ']');
            }
        }else{
            if(studentsDirectory.enrolledPtr[i] == NULL){
                fprintf(n, " ");
            }else{
                fprintf(n," %c%s%c", '[',studentsDirectory.enrolledPtr[i]->subjectCode, ']');
            }
        }
    }
    fprintf(n, " %.1f, %.1f, %.1f,", studentsDirectory.handsOnExam1, studentsDirectory.handsOnExam2, studentsDirectory.handsonExam3);
    total = studentsDirectory.handsOnExam1 + studentsDirectory.handsOnExam2 + studentsDirectory.handsonExam3;
    fprintf(n, " %.1f,", total);
    if(total >= 135){
        fprintf(n,"HD\n");
    }else if(total >= 120 && total <134){
        fprintf(n, "D\n");
    }else if(total >= 100 && total <120){
        fprintf(n, "P\n");
    }else if(total >= 75 && total < 100){
        fprintf(n, "C\n");
    }else{
        fprintf(n, "F\n");
    }
}

void displayCalculationsCSV(FILE *n){
    float hex1Low, hex1High, hex1Sum = 0.0, hex2Low, hex2High, hex2Sum = 0.0, hex3Low, hex3High, hex3Sum = 0.0, hex1Ave, hex2Ave, hex3Ave;
    for(int i=0; i<element; i++){
        if(i == 0){
            hex1Low = studentsDirectory[i].handsOnExam1;
            hex1High = studentsDirectory[i].handsOnExam1;
            hex2Low = studentsDirectory[i].handsOnExam2;
            hex2High = studentsDirectory[i].handsOnExam2;
            hex3Low = studentsDirectory[i].handsonExam3;
            hex3High = studentsDirectory[i].handsonExam3;
        }else{
            if(studentsDirectory[i].handsOnExam1 < hex1Low){
                hex1Low = studentsDirectory[i].handsOnExam1;
            }else if(studentsDirectory[i].handsOnExam1 > hex1High){
                hex1High = studentsDirectory[i].handsOnExam1;
            }
            if(studentsDirectory[i].handsOnExam2 < hex2Low){
                hex2Low = studentsDirectory[i].handsOnExam2;
            }else if(studentsDirectory[i].handsOnExam2 > hex2High){
                hex2High = studentsDirectory[i].handsOnExam2;
            }
            if(studentsDirectory[i].handsonExam3 < hex3Low){
                hex3Low = studentsDirectory[i].handsonExam3;
            }else if(studentsDirectory[i].handsonExam3 > hex3High){
                hex3High = studentsDirectory[i].handsonExam3;
            }
        }
        hex1Sum += studentsDirectory[i].handsOnExam1;
        hex2Sum += studentsDirectory[i].handsOnExam2;
        hex3Sum += studentsDirectory[i].handsonExam3;
    }
    fprintf(n, "\n\n");
    fprintf(n, ",,,,,Lowest,");
    fprintf(n, "%.1f,", hex1Low);
    fprintf(n, "%.1f,", hex2Low);
    fprintf(n, "%.1f,", hex3Low);
    fprintf(n, "%.1f\n", hex1Low + hex2Low + hex3Low);

    fprintf(n, ",,,,,Highest,");
    fprintf(n, "%.1f,", hex1High);
    fprintf(n, "%.1f,", hex2High);
    fprintf(n, "%.1f,", hex3High);
    fprintf(n, "%.1f\n", hex1High + hex2High + hex3High);
    hex1Ave = hex1Sum/element;
    hex2Ave = hex2Sum/element;
    hex3Ave = hex3Sum/element;
    fprintf(n, ",,,,,Average,");
    fprintf(n, " %.3f,", hex1Ave);
    fprintf(n, " %.3f,", hex2Ave);
    fprintf(n, " %.3f,", hex3Ave);
    fprintf(n, " %.3f\n", hex1Ave + hex2Ave + hex3Ave);
    fprintf(n, ",,,,,Standard Deviation,");
    float differ1, differ2, differ3, differAve, sumOfDiffer1 = 0, sumOfDiffer2 = 0, sumOfDiffer3 = 0, sumOfDifferAve = 0;
    for(int i=0; i<element; i++){
        differ1 = pow(studentsDirectory[i].handsOnExam1-hex1Ave, 2);
        differ2 = pow(studentsDirectory[i].handsOnExam2-hex2Ave, 2);
        differ3 = (studentsDirectory[i].handsonExam3-hex3Ave)*(studentsDirectory[i].handsonExam3 -hex3Ave);
        differAve = pow(((studentsDirectory[i].handsOnExam1+studentsDirectory[i].handsOnExam2+studentsDirectory[i].handsonExam3)/3), 2);
        sumOfDiffer1 += differ1;
        sumOfDiffer2 += differ2;
        sumOfDiffer3 += differ3;
        sumOfDifferAve += differAve;
    }
    fprintf(n, "%.3f,", sqrt(sumOfDiffer1/(element-1)));
    fprintf(n, "%.3f,", sqrt(sumOfDiffer2/(element-1)));
    fprintf(n, "%.3f,", sqrt(sumOfDiffer3/(element-1)));
    fprintf(n, "%.3f\n", sqrt(sumOfDifferAve/(element-1)));
}

void csvOutput2(struct subjectRecord subjectsDirectory,FILE *n){
    if(subjectsDirectory.subjectIDNumber >=0 && subjectsDirectory.subjectIDNumber <= 9){
        fprintf(n, "0%d,", subjectsDirectory.subjectIDNumber);
    }else{
        fprintf(n, "%d,", subjectsDirectory.subjectIDNumber);
    }
    fprintf(n, " %s, %s\n", subjectsDirectory.subjectCode, subjectsDirectory.title);
}
void outputStudentTxt(struct studentRecord student, FILE *n){
    fprintf(n, " %03d, %s, %s, %s, %.1f, %.1f, %.1f,", student.IDNumber, student.firstName, student.lastName, student.lectureSection, student.handsOnExam1, student.handsOnExam2, student.handsonExam3);
    for(int i=0; i<3; i++){
        if(i==2){
            if(student.enrolledPtr[i] == NULL){
                fprintf(n, " none\n");
            }else{
                fprintf(n, " %s\n", student.enrolledPtr[i]->subjectCode);
            }
        }else{
            if(student.enrolledPtr[i] == NULL){
                fprintf(n, " none,");
            }else{
                fprintf(n, " %s,", student.enrolledPtr[i]->subjectCode);
            }
        }
    }
}

int stringCompare(char s1[], char s2[]){
    int newLineIndex1, newLineIndex2, x, y;
    char copy1[20], copy2[20];
    strcpy(copy1, s1);
    strcpy(copy2, s2);
    newLineIndex1 = strcspn(copy1, "\n");
    newLineIndex2 = strcspn(copy2, "\n");
    if(newLineIndex1 > newLineIndex2){
        y = newLineIndex1;
    }else{
        y = newLineIndex2;
    }
    for(int i = 0; i<newLineIndex1; i++){
        if(copy1[i] >= 'A' && copy1[i] <= 'Z'){
            copy1[i] = copy1[i] + 32;
        }
    }
    for(int i = 0; i<newLineIndex2; i++){
        if(copy2[i] >= 'A' && copy2[i] <= 'Z'){
            copy2[i] = copy2[i] + 32;
        }
    }
    for(int i = 0; i < y; i++){
        if(copy1[i] > copy2[i]){
            x = 1;
            break;
        }else if(copy1[i] < copy2[i]){
            x = -1;
            break;
        }else{
            x = 0;
        }
    }

    return x;
}

void sorting(void){
    char copy1[15], copy2[15];
    int truth, count;
    for(int i=0; i<element; i++){
        for(int j=0; j<i; j++){
            count = i;
            strcpy(copy1, studentsDirectory[i].lastName);
            strcpy(copy2, studentsDirectory[j].lastName);
            truth = stringCompare(copy1,copy2);
            if(truth == -1){
                diverge = studentsDirectory[i];
                for(int h=i; h>j; h--){
                    studentsDirectory[h] = studentsDirectory[h-1];

                }
                studentsDirectory[j] = diverge;
                break;
            }

        }
    }
}

void fileInput(void){
    FILE *fPtr;
    int ID2[1000];
    for(int i= 0; i<1000; i++){
        ID2[i] = 0;
    }
    char path[50];
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tProvide Address: ");
    scanf(" %[^\n]", &path);
    fPtr = fopen(path,"r");
    //fPtr = fopen("D:\\students.txt","r");
    fscanf(fPtr,"\n");
    for(int i =element; i<70; i++){
        char c[10];
        int newLineIndex1, newLineIndex, count;
        if(fPtr == NULL){
            printf("Invalid");
            exit(1);
        }
        fscanf(fPtr, " %d,", &studentsDirectory[i].IDNumber);
        if(studentsDirectory[i].IDNumber != 0){
        fscanf(fPtr, " %[^,], %[^,], %[^,], %f, %f, %f,", &studentsDirectory[i].firstName, &studentsDirectory[i].lastName, &studentsDirectory[i].lectureSection, &studentsDirectory[i].handsOnExam1, &studentsDirectory[i].handsOnExam2, &studentsDirectory[i].handsonExam3);

        for(int j = 0; j<3; j++){
            int alreadyEnroll = 0;
            if(j==2){
                fscanf(fPtr, " %[^\n]\n", &c);
                newLineIndex1 = strcspn(c, "\n");
            }else{
                fscanf(fPtr, " %[^,],", &c);
                newLineIndex1 = strcspn(c, ",");

            }
            for(int h = 0; h<newLineIndex1; h++){
                c[h] = toUpper(c[h]);
            }
            for(int n=0; n<studentsDirectory[i].numOfSubjectsEnrolled; n++){
                if(stringCompare(c, studentsDirectory[i].enrolledPtr[n]->subjectCode) == 0){
                    alreadyEnroll = 1;
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t%s %s is already enrolled in %s", studentsDirectory[i].firstName, studentsDirectory[i].lastName ,studentsDirectory[i].enrolledPtr[n]->subjectCode);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThus he/she will not be enrolled again.\n");
                    break;
                }
            }
            if(alreadyEnroll != 1){
                for(int n = 0; n<element2; n++){
                    newLineIndex = strcspn(subjectsDirectory[n].subjectCode, ",");
                    int found = 0;
                    if(stringCompare(c, subjectsDirectory[n].subjectCode) == 0){

                        studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled] = &subjectsDirectory[n];
                        studentsDirectory[i].numOfSubjectsEnrolled += 1;
                        found = 1;
                        break;

                    }else{
                        studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled] = NULL;
                        found = 0;
                        int des;
                        if(found == 0 && stringCompare(c, "none") != 0 && n == element2-1){
                            printf("\n");
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThere is no subject %s exist in the subjects database.", c);
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThus, %s %s won't gonna be enrolled in such subject.", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBut with your permission do you want to create a subject?");
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress 1: Yes.\n\t\t\t\t\t\t\t\t\t\t\t\t\tPress other numeric keys to neglect.\n\t\t\t\t\t\t\t\t\t\t\t\tInput: ");
                            scanf(" %d", &des);
                            if(des == 1){
                                subjectsDirectory[element2] = createSubjectRecordDuringFileOpen(subjectsDirectory[element2], c);
                                studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled] = &subjectsDirectory[element2];
                                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
                                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|      A New Subject Record was Added     |");
                                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
                                printf("\n\t\t\t\t\t\t\t\t\t\t\t\t%s %s will be automatically enrolled to %s.\n", studentsDirectory[i].firstName, studentsDirectory[i].lastName, studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled]->subjectCode);
                                element2++;
                                studentsDirectory[i].numOfSubjectsEnrolled += 1;
                            }else{
                                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSubject %s was not created.\n", c);
                            }
                            break;
                        }
                    }
                }
            }
        }
        while(studentsDirectory[i].IDNumber > 999){
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tID number of %s(%d) is non 3-digit number.\n\t\t\t\t\t\t\t\t\t\t\t\tInput Again ID number: ", studentsDirectory[i].lastName, studentsDirectory[i].IDNumber);
            scanf(" %d", &studentsDirectory[i].IDNumber);
        }
        if(studentsDirectory[i].IDNumber != 0){
            for(int j= 0; j<i; j++){
                int ID, truth;
                count = 0;
                if(studentsDirectory[j].IDNumber == studentsDirectory[i].IDNumber || ID2[studentsDirectory[i].IDNumber] == 1){
                    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tID number %03d is already taken.\n\t\t\t\t\t\t\t\t\t\t\t\tPlease input again ID number for %s %s: ", studentsDirectory[i].IDNumber, studentsDirectory[i].firstName, studentsDirectory[i].lastName);
                    do{
                        if(count != 0){
                            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInputed ID number already taken.\n\t\t\t\t\t\t\t\t\t\t\t\tPlease input again other ID number: ");
                        }
                        scanf(" %d", &ID);
                        truth = IDCheck(ID, truth);
                        if(truth == 1 && ID2[ID] == 0){
                            studentsDirectory[i].IDNumber = ID;
                            ID2[ID] = 1;
                            break;
                        }
                        count++;
                    }while(truth == 0);
                }
                if(truth == 1){
                    break;
                }
            }
            IDAvail[studentsDirectory[i].IDNumber] = 1;
        }
        if(studentsDirectory[i].IDNumber==0){
            break;
        }
        int cmsc11Enrolled = 0;
        for(int j = 0; j<studentsDirectory[i].numOfSubjectsEnrolled; j++){
            if(stringCompare(subjectsDirectory[0].subjectCode, studentsDirectory[i].enrolledPtr[j]->subjectCode) == 0){
                cmsc11Enrolled = 1;
                break;
            }
        }

        if(cmsc11Enrolled == 0 && studentsDirectory[i].numOfSubjectsEnrolled != 3){
            printf("\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tStudent %s %s was not Enrolled to subject CMSC11.", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBy default he/she will be enrolled to CMSC11 with or\n\t\t\t\t\t\t\t\t\t\t\t\twithout your permission.\n");
            studentsDirectory[i].enrolledPtr[studentsDirectory[i].numOfSubjectsEnrolled] = studentsDirectory[i].enrolledPtr[1];
            studentsDirectory[i].enrolledPtr[1] = studentsDirectory[i].enrolledPtr[0];
            studentsDirectory[i].enrolledPtr[0] = &subjectsDirectory[0];
            studentsDirectory[i].numOfSubjectsEnrolled++;
        }else if(cmsc11Enrolled == 0 && studentsDirectory[i].numOfSubjectsEnrolled == 3){
            printf("\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tStudent %s %s was not Enrolled to subject CMSC11.", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tAnd he is already enrolled to 3 subjects.");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tBy default he/she will be enrolled to CMSC11 with or\n\t\t\t\t\t\t\t\t\t\t\t\twithout your permission.\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tIn order for this to happen First Subject will be replaced with CMSC11.");
            studentsDirectory[i].enrolledPtr[0] = &subjectsDirectory[0];
        }
        count = 0;
        if(studentsDirectory[i].handsOnExam1 < 0 || studentsDirectory[i].handsOnExam1 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX1 score of %s %s", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &studentsDirectory[i].handsOnExam1);
                count++;
            }while(studentsDirectory[i].handsOnExam1 < 0 || studentsDirectory[i].handsOnExam1 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX1 SUCCESFULLY CHANGE!\n");
        }
        count =0;
        if(studentsDirectory[i].handsOnExam2 < 0 || studentsDirectory[i].handsOnExam2 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX2 score of %s %s", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &studentsDirectory[i].handsOnExam2);
                count++;
            }while(studentsDirectory[i].handsOnExam2 < 0 || studentsDirectory[i].handsOnExam2 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX2 SUCCESFULLY CHANGE!\n");
        }
        count = 0;
        if(studentsDirectory[i].handsonExam3 < 0 || studentsDirectory[i].handsonExam3 > 50){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe scanned HEX3 score of %s %s", studentsDirectory[i].firstName, studentsDirectory[i].lastName);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tseems to be invalid.");
            do{
                if(count == 0){
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }else{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tThe inputed score is not valid.");
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput score(0-50):");
                }
                scanf(" %f", &studentsDirectory[i].handsonExam3);
                count++;
            }while(studentsDirectory[i].handsonExam3 < 0 || studentsDirectory[i].handsonExam3 > 50);
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tHEX3 SUCCESFULLY CHANGE!\n");
        }
        element++;
        }
    }
    fclose(fPtr);

}


struct subjectRecord createSubjectRecordDuringFileOpen(struct subjectRecord newSubjectRecord, char c[]){
    int count = 1;
    strcpy(newSubjectRecord.subjectCode, c);
    for(int i = 0; i<10; i++){
        newSubjectRecord.subjectCode[i] = toUpper(newSubjectRecord.subjectCode[i]);
    }
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t___________________________________________");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tCREATE A SUBJECT RECORD %s       ", c);
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t|_________________________________________|");
    do{
        if(count == 1){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput 2-digit subject ID number: ");
        }else if(count == 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tID number already taken. \n\t\t\t\t\t\t\t\t\t\t\t\tPleas input other 2-digit Subject ID number: ");
        }
        scanf(" %d", &newSubjectRecord.subjectIDNumber);
        while(newSubjectRecord.subjectIDNumber >= 100 || newSubjectRecord.subjectIDNumber <= 0){
            printf("\n\t\t\t\t\t\t\t\t\t\t\t\tYou've enter a not valid subject ID number.\n\t\t\t\t\t\t\t\t\t\t\t\tPlease enter again a 2-digit ID number: ");
            scanf(" %d", &newSubjectRecord.subjectIDNumber);
        }
        count = subjectIDcheck(newSubjectRecord.subjectIDNumber, count);
        if(newSubjectRecord.subjectIDNumber == 11){
            count = 0;
        }

    }while(count == 0);
    subjectIDAvail[newSubjectRecord.subjectIDNumber] = 1;


    printf("\t\t\t\t\t\t\t\t\t\t\t\tInput Title of the Subject     : ");
    scanf(" %49[^\n]s", &newSubjectRecord.title);

    return newSubjectRecord;

};

void subjectsFileInput(void){
    FILE *fPtr;
    char path[50];
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tProvide Address: ");
    scanf(" %[^\n]", &path);
    fPtr = fopen(path,"r");
    subjectIDAvail[subjectsDirectory[0].subjectIDNumber] = 1;
    //fPtr = fopen("D:\\subjects.txt", "r");
    for(int i=element2; i<20; i++){
        int lineIndex, truth;
        if(fPtr == NULL){
            printf("Invalid");
            exit(1);
        }
        fscanf(fPtr, "%d, %[^,], %[^\n]\n", &subjectsDirectory[i].subjectIDNumber, &subjectsDirectory[i].subjectCode, &subjectsDirectory[i].title);
        lineIndex = strcspn(subjectsDirectory[i].subjectCode, "\n");
        for(int j= 0; j<lineIndex; j++){
            subjectsDirectory[i].subjectCode[j] = toUpper(subjectsDirectory[i].subjectCode[j]);
        }
        if(subjectsDirectory[i].subjectIDNumber != 0){
            subjectIDAvail[subjectsDirectory[i].subjectIDNumber] = 1;
        }
        if(subjectsDirectory[i].subjectIDNumber == 0){
            break;
        }
        element2++;

    }
    for(int i=0; i<element2; i++){
        for(int j=0; j<10; j++){
            subjectsDirectory[i].subjectCode[j] = toUpper(subjectsDirectory[i].subjectCode[j]);
        }
    }
    for(int i = 0; i<element2; i++){
        for(int j = i; j<element2; j++){
            if(i != j && stringCompare(subjectsDirectory[i].subjectCode, subjectsDirectory[j].subjectCode) == 0){
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSubject %s(ID %d) is already in the database.", subjectsDirectory[j].subjectCode, subjectsDirectory[j].subjectIDNumber);
                printf("\n\t\t\t\t\t\t\t\t\t\t\t\tIt won't gonna be saved rater be deleted.\n");
                deleteSubjectRecord(subjectsDirectory[j], j, 0);
                element2--;
            }

        }
    }
    int ID, check;

    for(int i = 0; i<element2; i++){
        for(int j = i; j<element2; j++){
            if(i != j && subjectsDirectory[i].subjectIDNumber == subjectsDirectory[j].subjectIDNumber){
                do{
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tID number %d for %s is already taken.", subjectsDirectory[j].subjectIDNumber, subjectsDirectory[j].subjectCode);
                    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tProvide other ID number: ");
                    scanf(" %d", &ID);
                    while(ID >= 100 || ID <= 0){
                        printf("\n\t\t\t\t\t\t\t\t\t\t\t\tInput only nonnegative 2 digit number: ");
                        scanf(" %d", &ID);
                    }
                    subjectsDirectory[j].subjectIDNumber = ID;
                    check = subjectIDcheck(ID, check);
                    if(check == 1){
                        subjectsDirectory[j].subjectIDNumber = ID;
                        subjectIDAvail[subjectsDirectory[j].subjectIDNumber] = 1;
                        if(ID == subjectsDirectory[0].subjectIDNumber){
                            check = 0;
                        }
                    }
                    if(ID == 11){
                        check = 0;
                    }

                }while(check == 0);
            }
        }
    }
    fclose(fPtr);
}
void dropSubject(struct studentRecord *student){
    char s1[10];
    int found, count = 0, cmsc11;
    printf("\n\t\t\t\t\t\t\tHere are the list of %s %s's Enrolled Subjects: \n", student->firstName, student->lastName);
    for(int i=0; i<student->numOfSubjectsEnrolled; i++){
        printf("\n\t\t\t\t\t\t\t\tSubject Code  : %s", student->enrolledPtr[i]->subjectCode);
        printf("\n\t\t\t\t\t\t\t\tSubject Title : %s", student->enrolledPtr[i]->title);
        printf("\n\t\t\t\t\t\t\t\tSubject ID    : %d\n", student->enrolledPtr[i]->subjectIDNumber);
    }
    do{
        if(count == 0){
            printf("\n\t\t\t\t\t\t\tInput subject code to drop: ");
        }else if(count == 1){
            printf("\n\t\t\t\t\t\t\tInvalid Subject code!\n\t\t\t\t\t\t\tThis is your second attempt.\n\t\t\t\t\t\t\tInput subject code again: ");
        }else if(count == 2){
            printf("\n\t\t\t\t\t\t\tInvalid Subject code!\n\t\t\t\t\t\t\tThis is your last attempt.\n\t\t\t\t\t\t\tFailure to meet the requirements will redirect you to the previous menu.\n\t\t\t\t\t\t\tInput subject code once again: ");
        }
        scanf(" %[^\n]", &s1);
        cmsc11 = stringCompare(s1, student->enrolledPtr[0]->subjectCode);
        if(cmsc11 == 0){
            break;
        }
        for(int i=0; i<student->numOfSubjectsEnrolled; i++){
            found = stringCompare(s1, student->enrolledPtr[i]->subjectCode);
            if(found == 0){
                student->enrolledPtr[i] = NULL;
                if(i != student->numOfSubjectsEnrolled - 1){
                    for(int j = i; j<student->numOfSubjectsEnrolled; j++){
                        student->enrolledPtr[j] = student->enrolledPtr[j+1];
                    }
                    student->enrolledPtr[2] = NULL;
                }
                printf("\n\t\t\t\t\t\t\tSubject was drop");
                student->numOfSubjectsEnrolled--;
                break;
            }
        }
        count++;
    }while(found != 0 && count !=3);
    if(count == 3){
        printf("\n\t\t\t\t\t\t\tRedirecting to previous menu...");
    }
    if(cmsc11 == 0){
        printf("\n\t\t\t\t\t\t\tBy default, CMSC11 cannot be drop.");
        printf("\n\t\t\t\t\t\t\tRedirecting to previous menu...");
    }
}
