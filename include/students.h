#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct {
    char name[100];
    int ra;
    float grades[5];
    int disciplinesNum;
} Student;

void addStudent(Student **students, int *studentsNum);
void deleteStudent(Student **students, int *studentsNum, int ra);
Student* getStudent(Student *students, int studentsNum, int ra);
void updateGrades(Student *student);
void findAllStudents(Student *students, int studentsNum);
void saveData(Student *students, int studentsNum, const char *fileName);
void loadData(Student **students, int *studentsNum, const char *fileName);
float calculateAverage(Student *student);
float findMinGrade(Student *student);
float findMaxGrade(Student *student);


#endif
