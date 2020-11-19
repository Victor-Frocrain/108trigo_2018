/*
** EPITECH PROJECT, 2018
** 107transfer.h
** File description:
** 107transfer.h
*/

#ifndef TRANSFER_H_
#define TRANSFER_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

#define USAGE ("README")
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

typedef struct operations_s {
    bool exp;
    bool cos;
    bool sin;
    bool cosh;
    bool sinh;
    bool reci;
    bool ln;
    bool arc;
    bool calc;
    bool argth;
} operations_t;

int trigo(int ac, char **av);
bool parser(int ac, char **av, operations_t *op);
char *my_revstr(char *str);
int compute_simple(int ac, char **av);
char *my_revstr(char *str);
void compute(int ac, char **av, double **matrix);
double **add_matrix(double **matrix, double **matrix2, int len);
double **mult_matrix(double **matrix, double **matrix2, int len);
void copy_matrix(double **result, double **matrix2, int len);
double **pow_matrix(double **matrix, int nb, int len);
double **div_matrix(double **matrix, double nb, int len, operations_t *op);
void choose_operation(int ac, char **av, double **matrix, operations_t *op);
double **sub_matrix(double **matrix, double **matrix2, int len);
void matrix_zero(double **matrix, int len, double nb);
double **init_matrix(double **matrix, int len);
void display_result(double **result, int len);

#endif /* TRANSFER_H_ */
