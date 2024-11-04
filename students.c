#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStudent(Student **students, int *studentsNum) {
    *students = realloc(*students, (*studentsNum + 1) * sizeof(Student));
    if (*students == NULL) {
        perror("Memory allocation error");
        exit(1);
    }

    Student *newStudent = &(*students)[*studentsNum];
    printf("Name: ");
    scanf(" %[^\n]s", newStudent->name);
    printf("RA: ");
    scanf("%d", &newStudent->ra);
    newStudent->disciplinesNum = 5;  
    for (int i = 0; i < newStudent->disciplinesNum; i++) {
        printf("Grade %d: ", i + 1);
        scanf("%f", &newStudent->grades[i]);
    }

    (*studentsNum)++;
}

void deleteStudent(Student **students, int *studentsNum, int ra) {
    for (int i = 0; i < *studentsNum; i++) {
        if ((*students)[i].ra == ra) {
            for (int j = i; j < *studentsNum - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*studentsNum)--;
            *students = realloc(*students, (*studentsNum) * sizeof(Student));
            if (*students == NULL && *studentsNum > 0) {
                perror("Memory reallocation error");
                exit(1);
            }
            return;
        }
    }
    printf("Student not found.\n");
}

Student* getStudent(Student *students, int studentsNum, int ra) {
    for (int i = 0; i < studentsNum; i++) {
        if (students[i].ra == ra) {
            return &students[i];
        }
    }
    return NULL;
}

void updateGrades(Student *student) {
    printf("Updating grades for %s:\n", student->name);
    for (int i = 0; i < student->disciplinesNum; i++) {
        printf("Enter new grade for discipline %d: ", i + 1);
        scanf("%f", &student->grades[i]);
    }
}