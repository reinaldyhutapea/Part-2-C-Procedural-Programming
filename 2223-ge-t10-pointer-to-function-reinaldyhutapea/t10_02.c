// 12S22010 - Reinaldy Hutapea
// 12S22048 - Ira Wianda Sari Silalahi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int argc, char **argv) {
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char data[100];
    char id[10];
    char name[25];
    char year[5];
    char dorm_name[10];
    unsigned short capacity;
    char *kata;
    int std = 0, dr = 0;
    int indexStud, indexDorm = 0;

    while (1) {
    data[0] = '\0';
    int k = 0;
    while (1) {
        char i = getchar();
        if (i == '\n') {
            data[k] = '\0';
            break;
        }
        if (i == '\r') {
            continue;
        }
        data[k] = i;
        k++;
        if (k >= 100) {
            printf("Error: buffer overflow");
            exit(1);
        }
    }

    if (strcmp(data, "---") == 0) {
        break;
    }

    kata = strtok(data, "#");
    if (strcmp(kata, "student-add") == 0) {
        kata = strtok(NULL, "#");
        strcpy(id, kata);
        kata = strtok(NULL, "#");
        strcpy(name, kata);
        kata = strtok(NULL, "#");
        strcpy(year, kata);
        kata = strtok(NULL, "#");
        if (strcmp(kata, "male") == 0) {
            students[std] = create_student(id, name, year, GENDER_MALE);
        } else if (strcmp(kata, "female") == 0) {
            students[std] = create_student(id, name, year, GENDER_FEMALE);
        }
        std++;
    } else if (strcmp(kata, "dorm-add") == 0) {
        kata = strtok(NULL, "#");
        strcpy(dorm_name, kata);
        kata = strtok(NULL, "#");
        capacity = atoi(kata);
        kata = strtok(NULL, "#");
        if (strcmp(kata, "male") == 0) {
            dorms[dr] = create_dorm(dorm_name, capacity, GENDER_MALE);
        } else if (strcmp(kata, "female") == 0) {
            dorms[dr] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
        }
        dr++;
    }  else if (strcmp(kata, "student-print-all") == 0) {
        void (*pf)(struct student_t *, int) = print_student;
        pf(students, std);
    } else if (strcmp(kata, "student-print-all-detail") == 0) {
        void (*pf)(struct student_t *, int) = print_student_detail;
        pf(students, std);
    } else if (strcmp(kata, "dorm-print-all") == 0) {
        void (*pf)(struct dorm_t *, int) = print_dorm;
        pf(dorms, dr);
    } else if (strcmp(kata,"dorm-print-all-detail") == 0) {
            void (*pf)(struct dorm_t *, int) = print_dorm_detail;
            pf(dorms, dr);        
}else if (strcmp(kata, "assign-student") == 0) {
        kata = strtok(NULL, "#");
        strcpy(id, kata);
        kata = strtok(NULL, "#");
        strcpy(dorm_name, kata);
        for (int i = 0; i < std; i++) {
            if (strcmp(students[i].id, id) == 0) {
                indexStud = i;
            }
        }
        for (int j = 0; j < std; j++) {
            if (strcmp(dorms[j].name, dorm_name) == 0) {
                indexDorm = j;
            }
        }
        assign_student(&students[indexStud], &dorms[indexDorm], id, dorm_name);
        }
    
    }
    free(students);
    free(dorms);
    
    return 0;
}
