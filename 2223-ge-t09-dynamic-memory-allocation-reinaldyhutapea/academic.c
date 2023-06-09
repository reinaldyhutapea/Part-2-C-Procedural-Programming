// 12S22010 - Reinaldy Hutapea
// 12S22048 - Ira Wianda Sari Silalahi

#include "academic.h" // Header untuk file academic.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk mengkonversi enum grade_t menjadi string
char *grade_to_text(enum grade_t _grade) {
    switch (_grade) {
        case GRADE_NONE: return "None";
        case GRADE_T: return "T";
        case GRADE_E: return "E";
        case GRADE_D: return "D";
        case GRADE_C: return "C";
        case GRADE_BC: return "BC";
        case GRADE_B: return "B";
        case GRADE_AB: return "AB";
        case GRADE_A: return "A";
        default: return "";
    } 
}

// Fungsi untuk menghitung performa mahasiswa dalam satu mata kuliah
float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    if (_grade == GRADE_T || _grade == GRADE_E) {
        return 0.0;
    }
    else if (_grade == GRADE_D) {
        return 1.0 * _credit;
    }
    else if (_grade == GRADE_C) {
        return 2.0 * _credit;
    }
    else if (_grade == GRADE_BC) {
        return 2.5 * _credit;
    }
    else if (_grade == GRADE_B) {
        return 3.0 * _credit;
    }
    else if (_grade == GRADE_AB) {
        return 3.5 * _credit;
    }
    else if (_grade == GRADE_A) {
        return 4.0 * _credit;
    }
    else {
        return 0.0;
    
}

}
// Fungsi untuk mencetak informasi satu mata kuliah
void print_course(struct course_t _course) {
printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, grade_to_text(_course.passing_grade));
}

// Fungsi untuk mencetak informasi satu mahasiswa
void print_student(struct student_t _student) {
printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
}

void print_students(struct student_t *_students,
unsigned short int _student_size)
{
for (int i = 0; i < _student_size; i++) {
print_student(_students[i]);
}
}

// Fungsi untuk mencetak informasi satu pendaftaran
void print_enrollment(struct enrollment_t _enrollment) {
printf("%s|%s|%s|%s%.2f\n", _enrollment.course.code, _enrollment.student.id, grade_to_text(_enrollment.grade),_enrollment.year[0] == GRADE_NONE ? grade_to_text(GRADE_NONE) : grade_to_text(_enrollment.grade)
, calculate_performance(_enrollment.grade, _enrollment.course.credit));
}

// Fungsi untuk mencetak informasi seluruh pendaftaran
void print_enrollments(struct enrollment_t *_enrollments, unsigned short int _enrollment_size) {
    for (int i = 0; i < _enrollment_size; i++) {
        print_enrollment(_enrollments[i]);
    }
}

// Fungsi untuk mencetak informasi satu pendaftaran
struct course_t create_course(char *_code, char *_name, unsigned short _credit, enum grade_t _passing_grade)
{
    struct course_t crs;
    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;
    return crs;
}

// Fungsi untuk membuat satu mahasiswa baru
struct student_t create_student(char *_id, char *_name, char *_year, char *_study_program)
{
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);
    std.gpa = 0.0;
    return std;
}

// Fungsi untuk membuat pendaftaran baru
struct enrollment_t create_enrollment(struct course_t _course, struct student_t _student, char *_year, enum semester_t _semester)
{
    struct enrollment_t emt;
    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    emt.grade = GRADE_NONE;
    return emt;
}

// Fungsi untuk menghitung GPA
void calculate_gpa(struct student_t *_student, struct enrollment_t *_enrollments, unsigned short int _enrollment_size)
{
float total_performance = 0.0;
unsigned short total_credit = 0;

for (int i = 0; i < _enrollment_size; i++) {
        if (strcmp(_enrollments[i].student.id, (*_student).id) == 0 && _enrollments[i].grade != GRADE_NONE) {
            float performance = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
            total_performance += performance;
            total_credit += _enrollments[i].course.credit;
        }
    }
    if (total_credit > 0) {
        (*_student).gpa = total_performance / total_credit;
    }

}

// Fungsi ini mengubah nilai grade pada suatu course enrollment tertentu untuk seorang mahasiswa
void set_enrollment_grade(struct course_t _course, struct student_t _student, struct enrollment_t *_enrollments, 
unsigned short int _enrollment_size, enum grade_t _grade)
{
    for (int i = 0; i < _enrollment_size; i++) {
        if (strcmp(_enrollments[i].student.id, _student.id) == 0 && strcmp(_enrollments[i].course.code, _course.code) == 0) {
            _enrollments[i].grade = _grade;
        }
    }
}

struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id)
{
    struct student_t std;
    for (int i = 0; i < _student_size; i++) {
        if (strcmp(_students[i].id, _id) == 0) {
            std = _students[i];
            break;
        }
    }
    return std;
}
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code)
{
    struct course_t crs;
    for (int i = 0; i < _course_size; i++) {
        if (strcmp(_courses[i].code, _code) == 0) {
            print_course(_courses[i]);
        }
    }
    return crs;
}

