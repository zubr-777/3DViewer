#include "validate.h"

int validate(const char *f_name) {
  int is_err = 0;
  FILE *file;
  char buffer[1000];
  int v_count = 0;

  file = fopen(f_name, "r");

  if (file) {
    while (fgets(buffer, sizeof(buffer), file)) {
      // if (strncmp(buffer, "f ", 2) && strncmp(buffer, "v ", 2) &&
      //     strncmp(buffer, "o ", 2) && strncmp(buffer, "vt ", 3) &&
      //     strncmp(buffer, "vp ", 2) && strncmp(buffer, "vn ", 2) &&
      //     strncmp(buffer, "#", 1) && strncmp(buffer, "g ", 2) &&
      //     strncmp(buffer, "\n", 1)) {
      //   // printf("FILE IS NOT CORRECT BECAUSE STRING STARTS NOT WITH '\\n',
      //   // 'f', 'v', 'o', 'vt', 'vp', 'vn', 'g', '#' \n");
      //   is_err = 1;
      // }
      // else if (buffer[0] == 'f' && is_correct)
      //   is_correct = check_is_correct_f(buffer);
      if (!strncmp(buffer, "f ", 2) && !is_err)
        is_err = !check_is_correct_f(buffer);
      // else if (buffer[0] == 'v' && is_correct)
      //   is_correct = check_is_correct_v(buffer);
      else if (!strncmp(buffer, "v ", 2) && !is_err) {
        v_count++;
        is_err = !check_is_correct_v(buffer);
      }
    }
    fclose(file);
  } else {
    // printf("FILE NOT EXISTS\n");
    is_err = 3;
  }
  if (v_count == 0 && !is_err) {
    // printf("FILE IS NOT CORRECT BECAUSE NOT V STRINGS\n");
    is_err = 2;
  }
  return is_err;
}

int check_is_correct_f(char *buf) {
  // проверка корректности строки, начинающейся с f
  int is_correct = 1;

  char row_splitted_by_space[10][100] = {};
  int i = 0, j = 0;
  char current_string[100];

  while (sscanf(&buf[i], "%s ", current_string) == 1) {
    strcpy(row_splitted_by_space[j], current_string);
    i += strlen(current_string) + 1;
    j++;
  }

  if (j > 5) {
    is_correct = 0;
    // printf("STR F: TOO MANY ARGUMENTS ERROR\n");
    // printf("%s\n", buf);
  } else {
    for (int idx = 1; idx < j; idx++) {
      is_correct =
          check_is_correct_digits_in_f_var1(row_splitted_by_space[idx]) ||
          check_is_correct_digits_in_f_var2(row_splitted_by_space[idx]);
      if (!is_correct) break;
    }
  }

  return is_correct;
}

int check_is_correct_v(char *buf) {
  // проверка корректности строки, начинающейся с v
  int is_correct = 1;

  char row_splitted_by_space[10][100] = {};
  int i = 0, j = 0;
  char current_string[100];

  for (size_t i1 = 0; i1 <= strlen(buf); i1++)
    if ((buf[i1] == ' ') && (buf[i1 + 1] == ' ')) {
      for (size_t j1 = i1; j1 <= strlen(buf); j1++) buf[j1] = buf[j1 + 1];
      i1 = i1 - 1;
    }

  while (sscanf(&buf[i], "%s ", current_string) == 1) {
    strcpy(row_splitted_by_space[j], current_string);
    i += strlen(current_string) + 1;
    j++;
  }
  if (j > 5) {
    is_correct = 0;
    // printf("STR V: TOO MANY ARGUMENTS ERROR\n");
  } else {
    for (int idx = 1; idx < j; idx++) {
      is_correct = check_is_correct_digits_(row_splitted_by_space[idx]);
      if (!is_correct) break;
    }
  }

  return is_correct;
}

int check_is_correct_digits_in_f_var1(char input_string[]) {
  int is_correct = 1;

  char *istr;
  char sep[2] = "/";
  istr = strtok(input_string, sep);
  int j = 0;

  while (istr != NULL) {
    char current_string[100];
    strcpy(current_string, istr);
    size_t i = 0;
    int point_count = 0;
    while (strchr("-0123456789.", current_string[i]) &&
           i < strlen(current_string)) {
      if ((current_string[i] == '.')) {
        point_count++;
      }
      i++;
    }
    if (point_count > 0) {
      // printf("STR F: POINT CURRENT ERROR\n");
      is_correct = 0;
      break;
    } else if (strlen(current_string) > i) {
      // printf("STR F: NOT DIGIT ERROR\n");
      is_correct = 0;
      break;
    } else if (j > 2) {
      // printf("STR F: TOO MANY ARGS '/' \n");
      is_correct = 0;
      break;
    } else {
      istr = strtok(NULL, sep);
      j++;
    }
  }
  return is_correct;
}

int check_is_correct_digits_in_f_var2(char input_string[]) {
  int is_correct = 1;
  char current_string[100];
  strcpy(current_string, input_string);
  size_t i = 0;
  int point_count = 0;
  while (strchr("-0123456789.", current_string[i]) &&
         i < strlen(current_string)) {
    if ((current_string[i] == '.')) {
      point_count++;
    }
    i++;
  }
  if (point_count > 0) {
    // printf("STR F: POINT CURRENT ERROR\n");
    is_correct = 0;
  } else if (strlen(current_string) > i) {
    // printf("STR F: NOT DIGIT ERROR\n");
    is_correct = 0;
  }
  return is_correct;
}

int check_is_correct_digits_(char input_string[]) {
  int is_correct = 1;
  char current_string[100];
  strcpy(current_string, input_string);
  size_t i = 0;
  int point_count = 0;
  while (strchr("-0123456789.", current_string[i]) &&
         i < strlen(current_string)) {
    if ((current_string[i] == '.')) {
      point_count++;
    }
    i++;
  }
  if (point_count > 1) {
    // printf("STR V: POINT CURRENT ERROR\n");
    is_correct = 0;
  } else if (strlen(current_string) > i) {
    // printf("STR V: NOT DIGIT ERROR\n");
    is_correct = 0;
  }
  return is_correct;
}
