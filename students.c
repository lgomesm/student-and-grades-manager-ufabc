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