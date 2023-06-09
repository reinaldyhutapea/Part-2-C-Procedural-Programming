// 12S22010 - Reinaldy Hutapea
// 12S22048 - Ira Wianda Sari
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/todo.h"
#include "./libs/repository.h"

#define MAX_INPUT_LENGTH 101

int main(int argc, char **argv)
{
    struct todo_t *todos = malloc(120 * sizeof(struct todo_t));
    FILE *todo_file = fopen("./storage/todo-repository.txt", "r");

    int std = 0;
    char id[10];
    char name[25];
    char time[6];
    char status[10];
    int last_id = 0;

    while (std < 120 && fscanf(todo_file, "%[^|]|%[^|]|%[^|]|%[^|\n]%*c", id, time, name, status) == 4)
    {
        if (strcmp(status, "none") == 0)
        {
            todos[std] = create_todo(id, time, name, STATUS_NONE);
        }
        else if (strcmp(status, "canceled") == 0)
        {
            todos[std] = create_todo(id, time, name, STATUS_CANCELED);
        }
        else if (strcmp(status, "done") == 0)
        {
            todos[std] = create_todo(id, time, name, STATUS_DONE);
        }

        std++;
        int current_id = atoi(id);
        if (current_id > last_id)
        {
            last_id = current_id;
        }
    }

    fclose(todo_file);

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
        if (strcmp(word, "todo-add") == 0)
        {
            word = strtok(NULL, "#");
            strcpy(time, word);
            word = strtok(NULL, "#");
            strcpy(name, word);

            last_id++;
            sprintf(id, "%d", last_id);
            todos[std] = create_todo(id, time, name, STATUS_NONE);
            std++;

            todo_file = fopen("./storage/todo-repository.txt", "a");
            fprintf(todo_file, "%s|%s|%s|none\n", id, time, name);
            fclose(todo_file);
        }

        else if (strcmp(word, "todo-print-all") == 0)
        {
            print_todo(todos, std);
        }

        else if (strcmp(word, "todo-status") == 0)
{
    word = strtok(NULL, "#");
    strcpy(id, word);
    word = strtok(NULL, "#");
    strcpy(status, word);

    for (int i = 0; i < std; i++)
    {
        if (strcmp(todos[i].id, id) == 0)
        {
            if (strcmp(status, "none") == 0 && todos[i].status != STATUS_DONE)
            {
                todos[i].status = STATUS_NONE;
            }
            else if (strcmp(status, "canceled") == 0 && todos[i].status != STATUS_DONE)
            {
                todos[i].status = STATUS_CANCELED;
            }
            else if (strcmp(status, "done") == 0)
            {
                if (todos[i].status != STATUS_DONE)
                {
                    todos[i].status = STATUS_DONE;
                }
            }

            todo_file = fopen("./storage/todo-repository.txt", "w");
            for (int j = 0; j < std; j++)
            {
                fprintf(todo_file, "%s|%s|%s|%s\n", todos[j].id, todos[j].time, todos[j].name, get_status_string(todos[j].status));
            }
            fclose(todo_file);

            break;
        }
    }
}

    }

    free(todos);

    return 0;
}
