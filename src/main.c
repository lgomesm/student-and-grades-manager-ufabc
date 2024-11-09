#include "../include/students.h"
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "data/students_data.bin"

int main() {
    Student *students = NULL;
    int studentsNum = 0;
    int option;

    loadData(&students, &studentsNum, FILE_NAME);
    printf("Student data loaded from file.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Get Student by RA\n");
        printf("4. Update Student Grades\n");
        printf("5. List All Students\n");
        printf("6. Calculate Student Statistics\n"); 
        printf("7. Save Data\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addStudent(&students, &studentsNum);
                break;
            case 2: {
                int ra;
                printf("Enter RA of the student to delete: ");
                scanf("%d", &ra);
                deleteStudent(&students, &studentsNum, ra);
                break;
            }
            case 3: {
                int ra;
                printf("Enter RA of the student to get: ");
                scanf("%d", &ra);
                Student *student = getStudent(students, studentsNum, ra);
                if (student) {
                    printf("Student found: %s, RA: %d, Grades: ", student->name, student->ra);
                    for (int i = 0; i < student->disciplinesNum; i++) {
                        printf("%.2f ", student->grades[i]);
                    }
                    printf("\n");
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 4: {
                int ra;
                printf("Enter RA of the student to update grades: ");
                scanf("%d", &ra);
                Student *student = getStudent(students, studentsNum, ra);
                if (student) {
                    updateGrades(student);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 5:
                findAllStudents(students, studentsNum);
                break;
            case 6: { 
                int ra;
                printf("Enter RA of the student to calculate statistics: ");
                scanf("%d", &ra);
                Student *student = getStudent(students, studentsNum, ra);
                if (student) {
                    float average = calculateAverage(student);
                    float min = findMinGrade(student);
                    float max = findMaxGrade(student);
                    printf("Statistics for %s (RA: %d):\n", student->name, student->ra);
                    printf("Average Grade: %.2f\n", average);
                    printf("Minimum Grade: %.2f\n", min);
                    printf("Maximum Grade: %.2f\n", max);
                } else {
                    printf("Student not found.\n");
                }
                break;
            }
            case 7:
                saveData(students, studentsNum, FILE_NAME);
                printf("Data saved to file.\n");
                break;
            case 8:
                printf("Exiting the program and saving data...\n");
                saveData(students, studentsNum, FILE_NAME); 
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 8);

    free(students);  
    return 0;
}
