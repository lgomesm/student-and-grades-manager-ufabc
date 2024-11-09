#include "../include/students.h"
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

void findAllStudents(Student *students, int studentsNum) {
    if (studentsNum == 0) {
        printf("No students registered.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < studentsNum; i++) {
        printf("Name: %s, RA: %d, Grades: ", students[i].name, students[i].ra);
        for (int j = 0; j < students[i].disciplinesNum; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n");
    }
}

void saveData(Student *students, int studentsNum, const char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fwrite(&studentsNum, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentsNum, file);
    fclose(file);
}

void loadData(Student **students, int *studentsNum, const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return;  
    }
    fread(studentsNum, sizeof(int), 1, file);
    *students = malloc(*studentsNum * sizeof(Student));
    if (*students == NULL) {
        perror("Memory allocation error");
        exit(1);
    }
    fread(*students, sizeof(Student), *studentsNum, file);
    fclose(file);
}

float calculateAverage(Student *student) {
    float sum = 0.0;
    for (int i = 0; i < student->disciplinesNum; i++) {
        sum += student->grades[i];
    }
    return sum / student->disciplinesNum;
}

float findMinGrade(Student *student) {
    float min = student->grades[0];
    for (int i = 1; i < student->disciplinesNum; i++) {
        if (student->grades[i] < min) {
            min = student->grades[i];
        }
    }
    return min;
}

float findMaxGrade(Student *student) {
    float max = student->grades[0];
    for (int i = 1; i < student->disciplinesNum; i++) {
        if (student->grades[i] > max) {
            max = student->grades[i];
        }
    }
    return max;
}