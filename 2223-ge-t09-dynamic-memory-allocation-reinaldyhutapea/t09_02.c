#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100

int main() {
    struct student_t students[MAX_STUDENTS];
    struct course_t courses[MAX_COURSES];
    int num_students = 0;
    int num_courses = 0;
    char input[100];
    char *token;
    int start = 1;

    while (start != 0) {
        input[0] = '\0';
        int k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            input[k] = i;
            input[++k] = '\0';
        }
        token = strtok(input, "#");

        if (strcmp(token, "create-student") == 0) {
            char id[10], year[10];
            char name[50], study_program[50];

            // Parse student data from input
            token = strtok(NULL, "#");
            strcpy(id, token);
            token = strtok(NULL, "#");
            strcpy(name, token);
            token = strtok(NULL, "#");
            strcpy(year, token);
            token = strtok(NULL, "#");
            strcpy(study_program, token);

            // Create new student
            students[num_students] = create_student(id, name, year, study_program);
            num_students++;
        }
        else if (strcmp(token, "print-students") == 0) {
            // Print all students
            for (int i = 0; i < num_students; i++) {
                print_student(students[i]);
            }
        }
        else if (strcmp(token, "create-course") == 0) {
            char code[10], name[50];
            int credit;
            char passing_grade;

            // Parse course data from input
            token = strtok(NULL, "#");
            strcpy(code, token);
            token = strtok(NULL, "#");
            strcpy(name, token);
            token = strtok(NULL, "#");
            credit = atoi(token);
            token = strtok(NULL, "#");
            passing_grade = token[0];

            // Create new course
            courses[num_courses] = create_course(code, name, credit, passing_grade);
            num_courses++;
        }
        else if (strcmp(token, "print-courses") == 0) {
            // Print all courses
            for (int i = 0; i < num_courses; i++) {
                printf("%s|%s|%d|%c\n", courses[i].code, courses[i].name, courses[i].credit, courses[i].passing_grade);
            }
        }
        else if (strcmp(token, "---") == 0) {
            start = 0;
        }
    }

    return 0;
}
