#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

#define MAX_INPUT_LENGTH 100

int main(int argc, char **argv)
{
    struct dorm_t *dorms = malloc(120 * sizeof(struct dorm_t));
    struct student_t *students = malloc(120 * sizeof(struct student_t));

    FILE *student_file;
    FILE *dorm_file;

    student_file = fopen("./storage/student-repository.txt", "r");
    dorm_file = fopen("./storage/dorm-repository.txt", "r");

    int std = 0, dr = 0;
    char id[10];
    char name[25];
    char year[5];
    char dorm_name[10];
    char gender[10];
    unsigned short capacity;

    while (std < 120 && fscanf(student_file, "%[^|]|%[^|]|%[^|]|%[^|\n]%*c", id, name, year, gender) == 4)
    {
        if (strcmp(gender, "male") == 0)
        {
            students[std] = create_student(id, name, year, GENDER_MALE);
        }
        else if (strcmp(gender, "female") == 0)
        {
            students[std] = create_student(id, name, year, GENDER_FEMALE);
        }
        std++;
    }

    while (dr < 120 && fscanf(dorm_file, "%[^|]|%hu|%[^|\n]%*c", dorm_name, &capacity, gender) == 3)
    {
        if (strcmp(gender, "male") == 0)
        {
            dorms[dr] = create_dorm(dorm_name, capacity, GENDER_MALE);
        }
        else if (strcmp(gender, "female") == 0)
        {
            dorms[dr] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
        }
        dr++;
    }

    fclose(student_file);
    fclose(dorm_file);

    student_file = fopen("./storage/student-repository.txt", "a");
    dorm_file = fopen("./storage/dorm-repository.txt", "a");

    char kata[MAX_INPUT_LENGTH];
    char *word;

    while (1)
    {
        kata[0] = '\0';
        short k = 0;
        while (1)
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

            kata[k] = i;
            kata[++k] = '\0';
        }
        
        if (strcmp(kata, "---") == 0)
        {
            break;
        }

        word = strtok(kata, "#");
        if (strcmp(word, "student-add") == 0)
        {
            word = strtok(NULL, "#");
            strcpy(id, word);
            word = strtok(NULL, "#");
            strcpy(name, word);
            word = strtok(NULL, "#");
            strcpy(year, word);
            word = strtok(NULL, "#");
            if (strcmp(word, "male") == 0)
            {
                students[std] = create_student(id, name, year, GENDER_MALE);
            }
            else if (strcmp(word, "female") == 0)
            {
                students[std] = create_student(id, name, year, GENDER_FEMALE);
            }
            std++;

            fprintf(student_file, "%s|%s|%s|%s\n", id, name, year, word);
        }
        else if (strcmp(word, "dorm-add") == 0)
        {
            word = strtok(NULL, "#");
            strcpy(dorm_name, word);
            word = strtok(NULL, "#");
            capacity = atoi(word);
            word = strtok(NULL, "#");
            if (strcmp(word, "male") == 0)
            {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_MALE);
            }
            else if (strcmp(word, "female") == 0)
            {
                dorms[dr] = create_dorm(dorm_name, capacity, GENDER_FEMALE);
            }
            dr++;

            fprintf(dorm_file, "%s|%hu|%s\n", dorm_name, capacity, word);
        }
        else if (strcmp(kata, "student-print-all") == 0)
        {
            print_student(students, std);
        }
        else if (strcmp(kata, "dorm-print-all") == 0)
        {
            print_dorm(dorms, dr);
        }
        else if (strcmp(kata, "student-print-all-detail") == 0)
        {
            print_student_detail(students, std);
        }
        else if (strcmp(kata, "dorm-print-all-detail") == 0)
        {
            print_dorm_detail(dorms, dr);
        }
        else if (strcmp(kata, "assign-student") == 0)
        {
            word = strtok(NULL, "#");
            strcpy(id, word);
            word = strtok(NULL, "#");
            strcpy(dorm_name, word);
            int student_index = -1;
            int dorm_index = -1;
            for (int i = 0; i < std; i++)
            {
                if (strcmp(students[i].id, id) == 0)
                {
                    student_index = i;
                    break;
                }
            }
            for (int j = 0; j < dr; j++)
            {
                if (strcmp(dorms[j].name, dorm_name) == 0)
                {
                    dorm_index = j;
                    break;
                }
            }
            if (student_index != -1 && dorm_index != -1)
            {
                assign_student(&students[student_index], &dorms[dorm_index], id, dorm_name);
            }
        }
    }

    fclose(dorm_file);
    fclose(student_file);
    free(dorms);
    free(students);

    return 0;
}
