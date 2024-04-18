#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate(const char *file_name);
int check_is_correct_f(char *buf);
int check_is_correct_v(char *buf);
int check_is_correct_digits_in_f_var1(char input_string[]);
int check_is_correct_digits_in_f_var2(char input_string[]);
int check_is_correct_digits_(char input_string[]);

#endif  // VALIDATE_H

// возвращаемые коды

// 0 - все ок
// 1 - есть строки, начинающиеся НЕ с "#", "o ", "v ", "f ", "vt ", "vn ", "vp
// ", "g " или внутри строк с правильным началом есть ошибки (буквы среди цифр,
// неправильный формат) 2 - нет строк с вершинами ("v ") 3 - нет файла
