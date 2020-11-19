/*
** EPITECH PROJECT, 2019
** matrix
** File description:
** matrix
*/

#include "trigo.h"

double **init_matrix(double **matrix, int len)
{
    int i = 0;

    matrix = malloc(sizeof(double *) * (len + 1));
    for (i = 0; i < len; i++)
        matrix[i] = malloc(sizeof(double) * len);
    matrix[i] = NULL;
    return (matrix);
}

void destroy_matrix(double **matrix, int len)
{
    for (int i = len - 1; i >= 0; i--) {
        if (matrix && matrix[i])
            free(matrix[i]);
    }
    if (matrix)
        free(matrix);
}

void matrix_zero(double **matrix, int len, double nb)
{
    int j = 0;

    for (int i = 0; i < len;) {
        matrix[i][j] = nb;
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
}

double **add_matrix(double **matrix, double **matrix2, int len)
{
    int j = 0;
    double **result = NULL;

    result = init_matrix(result, len);
    copy_matrix(matrix, result, len);
    for (int i = 0; i < len;) {
        result[i][j] += matrix2[i][j];
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    return (result);
}

double **sub_matrix(double **matrix, double **matrix2, int len)
{
    int j = 0;
    double **result = NULL;

    result = init_matrix(result, len);
    copy_matrix(matrix, result, len);
    for (int i = 0; i < len;) {
        result[i][j] -= matrix2[i][j];
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    return (result);
}

double **mult_matrix(double **matrix, double **matrix2, int len)
{
    int j = 0;
    double **result = NULL;

    result = init_matrix(result, len);
    matrix_zero(result, len, 0);
    for (int i = 0; i < len;) {
        for (int k = 0; k < len; k++)
            result[i][j] += matrix[i][k] * matrix2[k][j];
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    return (result);
}

double **pow_matrix(double **matrix, int nb, int len)
{
    double **result = NULL;

    result = init_matrix(result, len);
    copy_matrix(matrix, result, len);
    for (int i = 0; i < nb; i++) {
        result = mult_matrix(matrix, result, len);
    }
    return (result);
}

double **div_matrix(double **matrix, double nb, int len, operations_t *op)
{
    int j = 0;
    double **result = NULL;

    op->calc = false;
    if (nb == 0)
        return (matrix);
    result = init_matrix(result, len);
    copy_matrix(matrix, result, len);
    for (int i = 0; i < len;) {
        result[i][j] = matrix[i][j] / nb;
        if (result[i][j] > 0)
            op->calc = true;
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
    return (result);
}
