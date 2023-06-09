#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

int main() {
    struct student_t students[MAX_STUDENTS];
    int num_students = 0;
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
        else if (strcmp(token, "---") == 0) {
            start = 0;
        }
    }

    return 0;
}
