// 12S22010 - Reinaldy Hutapea
// 12S22048 - Ira Wianda Sari

#ifndef TODO_H
#define TODO_H
#include "repository.h"


struct todo_t
{
    char id[12];
    char name[40];
    char time[6];
    enum status_t status;
    
};

struct todo_t create_todo(char *_id,char *_time, char *_name , enum status_t _status);
void print_todo(struct todo_t *_todo, int quant);
char* get_status_string(enum status_t status);
#endif
