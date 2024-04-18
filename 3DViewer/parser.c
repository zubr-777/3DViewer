#include "parser.h"

int parser(const char *filename, shared *model) {
  int flag = 0;
  int error_fscanf = 0;

  FILE *p_file = NULL;

  if ((p_file = fopen(filename, "r")) == NULL) {
    flag++;
  } else {
    setlocale(LC_NUMERIC, "C");
    char char_buffer;  // основной чар, для перебора файла
    double coord_x, coord_y, coord_z;
    char micro_buffer;  // субгеттер для фасетов

    while ((char_buffer = fgetc(p_file)) != EOF) {
      if (char_buffer == 'o') {
        if ((char_buffer = fgetc(p_file)) == ' ') {
          char tmp_var;

          int counter = 2;

          while ((tmp_var = fgetc(p_file)) != '\n') {
            if (model->name == NULL) {
              model->name = (char *)malloc(sizeof(char) * 2);
              model->name[0] = tmp_var;
              model->name[1] = '\0';
            } else {
              model->name =
                  (char *)realloc(model->name, (counter + 1) * sizeof(char));
              model->name[counter - 1] = tmp_var;
              model->name[counter++] = '\0';
            }
          }
        }
      } else if (char_buffer == 'v') {
        if ((char_buffer = fgetc(p_file)) == ' ') {
          error_fscanf = fscanf(p_file, "%lf%lf%lf", &coord_x, &coord_y, &coord_z);
          if (!error_fscanf) flag++;
          model->vertex_amount++;
          add_vertex(model, coord_x, coord_y, coord_z);
        }
      } else if (char_buffer == 'f') {
        int flag_divider =
            0;  // флаг проверяряющий что идет после числа.. разделяет логику
                // считывания фасетов через / и через пробел
        if ((char_buffer = fgetc(p_file)) == ' ') {
          int *tmp_int = NULL;  // массив для сбора интов из строки и передачи в
                                // обработчик фасета
          fseek(p_file, -1, SEEK_CUR);
          int flag_facet = 0;  // определитель пробела
          int digit = 0;  // число для записи в массив интов
          int counter = 0;  // счетчик кол-ва интов в массиве для передачи
          char *tmp_facet =
              NULL;  // массив для считывания инта из файла почарово

          while ((micro_buffer = fgetc(p_file)) != '\n') {
            if (micro_buffer == ' ' || flag_divider) {
              flag_facet = 1;
              flag_divider = 0;
              if ((micro_buffer = fgetc(p_file)) == '\n' ||
                  micro_buffer == ' ' || micro_buffer == '\r') {
                fseek(p_file, -1, SEEK_CUR);
                flag_facet = 0;
                continue;
              } else {
                fseek(p_file, -1, SEEK_CUR);
              }
            }
            if (flag_facet) {
              int size_tmp_facet = 0;  // размер массива чаров, для записи

              while ((micro_buffer = fgetc(p_file)) != '/' &&
                     micro_buffer != ' ' && micro_buffer != '\n' &&
                     micro_buffer != '\r' && micro_buffer != EOF) {
                if (tmp_facet == NULL) {
                  tmp_facet = (char *)malloc(sizeof(char));
                  tmp_facet[size_tmp_facet++] = micro_buffer;
                  flag_facet = 0;
                } else {
                  tmp_facet = (char *)realloc(
                      tmp_facet, sizeof(char) * (size_tmp_facet + 1));
                  tmp_facet[size_tmp_facet++] = micro_buffer;
                  flag_facet = 0;
                }
              }
              if (micro_buffer == ' ')  // считали пробел сразу после числа..
                                        // дальше идет новое значение
              {
                fseek(p_file, -1, SEEK_CUR);
                flag_divider = 1;
              } else if (micro_buffer ==
                         '\n')  // считали \n возвращаем указатель, что бы выйти
                                // из основного цикла
              {
                fseek(p_file, -1, SEEK_CUR);
                flag_divider = 1;
              }
              if (micro_buffer != EOF) {
                tmp_facet = (char *)realloc(
                    tmp_facet, sizeof(char) * (size_tmp_facet + 1));
                tmp_facet[size_tmp_facet] = '\0';
                digit = atoi(tmp_facet);
                if (digit < 0) digit *= -1;
                free(tmp_facet);
                tmp_facet = NULL;
                size_tmp_facet = 0;
                if (tmp_int == NULL) {
                  tmp_int = (int *)malloc(sizeof(int));
                  tmp_int[counter++] = digit;
                } else {
                  tmp_int =
                      (int *)realloc(tmp_int, sizeof(int) * (counter + 1));
                  tmp_int[counter++] = digit;
                }
              }
            }
            if (micro_buffer == EOF) {
              break;
            }
          }
          if (micro_buffer == EOF) {
            break;
          }
          model->facet_amount += (counter * 2);
          add_facet(model, tmp_int, counter);
          free(tmp_int);
          tmp_int = NULL;
          counter = 0;
        }
        if (micro_buffer == EOF) {
          break;
        }
      }
    }
  }

  if (p_file) fclose(p_file);

  return flag;
}

void add_facet(shared *model, int *tmp_int, int counter) {
  if (model->p_facet == NULL) {
    model->p_facet = (int *)malloc(sizeof(int) * (model->facet_amount));
  } else {
    model->p_facet =
        (int *)realloc(model->p_facet, sizeof(int) * (model->facet_amount));
  }
  int flag_first = 0;
  int i = model->facet_amount - counter * 2;
  int j = 0;
  do {
    if (!flag_first) {
      model->p_facet[i++] = tmp_int[j++] - 1;
      flag_first = 1;
    } else if (j == counter) {
      model->p_facet[i++] = tmp_int[0] - 1;
    } else {
      model->p_facet[i++] = tmp_int[j] - 1;
      model->p_facet[i++] = tmp_int[j++] - 1;
    }

  } while (i < (model->facet_amount));
}

void add_vertex(shared *model, double coord_x, double coord_y, double coord_z) {
  if (model->p_vertex == NULL) {
    model->p_vertex = (double *)malloc(sizeof(double) * 3);
    model->p_vertex[0] = coord_x;
    model->p_vertex[1] = coord_y;
    model->p_vertex[2] = coord_z;
  } else {
    model->p_vertex = (double *)realloc(
        model->p_vertex, sizeof(double) * ((model->vertex_amount + 1) * 3));
    model->p_vertex[model->vertex_amount * 3 - 3] = coord_x;
    model->p_vertex[model->vertex_amount * 3 - 2] = coord_y;
    model->p_vertex[model->vertex_amount * 3 - 1] = coord_z;
  }
}
