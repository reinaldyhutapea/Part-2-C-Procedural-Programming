#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender)
{
    struct student_t stud;

    strcpy(stud.id, _id);
    strcpy(stud.name, _name);
    strcpy(stud.year, _year);
    stud.gender = _gender;
    stud.dorm = NULL;

    return stud;
}

void print_student(struct student_t *_student, int quant)
{
    for (int i = 0; i < quant; i++)
    {
        if(_student[i].gender == GENDER_MALE)
        {
            printf("%s|%s|%s|male\n", _student[i].id, _student[i].name, _student[i].year);
        }
        else {
            printf("%s|%s|%s|female\n", _student[i].id, _student[i].name, _student[i].year);
        }
    }
}

void print_student_detail(struct student_t *_student, int quant)
{
    for (int i = 0; i < quant; ++i)
    {
        if (_student[i].gender == GENDER_MALE && _student[i].dorm == NULL)
        {
            printf("%s|%s|%s|male|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
        } 
        else if (_student[i].gender == GENDER_FEMALE && _student[i].dorm == NULL)
        {
            printf("%s|%s|%s|female|unassigned\n", _student[i].id, _student[i].name, _student[i].year);
        }
        else{
            printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, (_student[i].gender == GENDER_MALE ? "male" : "female"), _student[i].dorm->name);
        }
    }
}




void assign_student(struct student_t *_student, struct dorm_t *_dorm, char *id, char *dorm_name)
{
    if (_dorm->capacity > _dorm->residents_num)
    {
        if (_dorm->gender == _student->gender)
        {
            _student->dorm = _dorm;
            _dorm->residents_num++;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_dorm->gender== _student->gender)
        {
            _student->dorm = _dorm;
            old_dorm->residents_num--;
            _dorm->residents_num++;
        }
    }
}