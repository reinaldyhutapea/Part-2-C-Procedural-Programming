// 12S22010 - Reinaldy Hutapea
// 12S22048 - Ira Wianda Sari

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "todo.h"

struct todo_t create_todo(char *_id,char *_time , char *_name, enum status_t _status)
{
    struct todo_t todo;

    strcpy(todo.id, _id);
    strcpy(todo.time, _time);
    strcpy(todo.name, _name);
    todo.status = _status;

    return todo;
}

void print_todo(struct todo_t *_todo, int quant)
{

    for (int i = 0; i < quant; ++i)
    {
        if (_todo[i].status == STATUS_NONE )
        {
            printf("%s|%s|%s|none\n", _todo[i].id, _todo[i].time, _todo[i].name );
        } 
        else if (_todo[i].status == STATUS_CANCELED)
        {
            printf("%s|%s|%s|canceled\n", _todo[i].id, _todo[i].time, _todo[i].name);
        }
        else if(_todo[i].status == STATUS_DONE )
        {
            printf("%s|%s|%s|done\n", _todo[i].id,_todo[i].time, _todo[i].name);
        }
    }
}

char* get_status_string(enum status_t status)
{
    switch (status)
    {
        case STATUS_NONE:
            return "none";
        case STATUS_CANCELED:
            return "canceled";
        case STATUS_DONE:
            return "done";
        default:
            return "unknown";
    }
}

