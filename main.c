#include "students.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Student *students = NULL;
    int studentsNum = 0;
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Get Student by RA\n");
        printf("4. Update Student Grades\n");
        printf("5. Exit\n");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    free(students);  
    return 0;
}
