#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t dorm_;

    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = _gender;
    dorm_.residents_num = 0;

    return dorm_;
}

void print_dorm(struct dorm_t *_dorm, int quant)
{
    for(int i = 0; i < quant; ++i)
    {
        
        printf("%s|%d|%s\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].gender == 0 ? "male" : "female");
    }
}

void print_dorm_detail(struct dorm_t *_dorm, int quant)
{
    for (int i = 0; i < quant; ++i)
    {
        printf("%s|%d|%s|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].gender == 0 ? "male" : "female", _dorm[i].residents_num);
    }
}
