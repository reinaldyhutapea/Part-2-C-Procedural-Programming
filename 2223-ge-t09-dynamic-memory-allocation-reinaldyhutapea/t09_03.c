#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100

int main() {
    struct student_t* students = malloc(MAX_STUDENTS * sizeof(struct student_t));
    struct course_t* courses = malloc(MAX_COURSES * sizeof(struct course_t));
    int num_students = 0;
    int num_courses = 0;
    char input[100];
    char *token;
    int start = 1;

    while (start != 0) {
        input[0] = '\0';
        int k = 0;
        while (1) {
            char i = getchar();
            if (i == '\n') {
                break;
            }
            if (i == '\r') {
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
            struct student_t new_student = create_student(id, name, year, study_program);
            students[num_students] = new_student;
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
            // passing_grade = token[0];

            if (strcmp(token, "A") == 0) {
                passing_grade = 8;
            }

            if (strcmp(token, "AB") == 0) {
                passing_grade = 7;
            }

            if (strcmp(token, "B") == 0) {
                passing_grade = 6;
            }

            if (strcmp(token, "BC") == 0) {
                passing_grade = 5;
            }

            if (strcmp(token, "C") == 0) {
                passing_grade = 4;
            }

            if (strcmp(token, "D") == 0) {
                passing_grade = 3;
            }

            if (strcmp(token, "E") == 0) {
                passing_grade = 2;
            }

            if (strcmp(token, "T") == 0) {
                passing_grade = 1;
            }

            if (strcmp(token, "None") == 0) {
                passing_grade = 0;
            }

            // Create new course
            struct course_t new_course = create_course(code, name, credit, passing_grade);
            courses[num_courses] = new_course;
            num_courses++;
        }
        
        else if (strcmp(token, "find-student-by-id") == 0) {
            // Find student by id
            token = strtok(NULL, "#");
            char id[10];
            strcpy(id, token);
            int found = 0;
            
            for (int i = 0; i < num_students; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    print_student(students[i]);
                    found = 1;
                    break;
                }
            }
        }
        
else if (strcmp(token, "print-courses") == 0) {
            // Print all courses
            for (int i = 0; i < num_courses; i++) {
                print_course(courses[i]);
                
            }
        }
        else if (strcmp(token, "---") == 0) {
            start = 0;
        }
    }
    return 0;
}
