/*
** EPITECH PROJECT, 2019
** compute
** File description:
** compute
*/

#include "trigo.h"

void display_result(double **result, int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%.2f", result[i][j]);
            if (j < len - 1)
                printf("\t");
        }
        printf("\n");
    }
}

double factor(double nb)
{
    if (nb <= 0)
        return (1);
    for (double tour = nb - 1; tour > 0; tour--)
        nb *= tour;
    return (nb);
}

double add(double nb)
{
    for (double i = 0; i < nb; i++)
        nb += i;
    return (nb);
}

double **fill_matrix(int ac, char **av, double **matrix)
{
    int i = 0;
    int j = 0;
    int len = (int)(sqrt(ac - 2));

    if ((matrix = malloc(sizeof(double *) * (len + 1))) == NULL)
        return (NULL);
    if ((matrix[0] = malloc(sizeof(double) * len)) == NULL)
        return (NULL);
    for (int k = 2; k < ac && av[k]; k++) {
        matrix[i][j] = strtod(av[k], NULL);
        j++;
        if (j >= len) {
            j = 0;
            i++;
            if ((matrix[i] = malloc(sizeof(double) * len)) == NULL)
                return (NULL);
        }
    }
    matrix[len] = NULL;
    return (matrix);
}

void copy_matrix(double **result, double **matrix2, int len)
{
    int j = 0;

    for (int i = 0; i < len;) {
        matrix2[i][j] = result[i][j];
        j++;
        if (j >= len) {
            j = 0;
            i++;
        }
    }
}

void comp_cos(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    for (double n = 1; op->calc; n++) {
        if (pow(-1, n) > 0)
            matrix2 = add_matrix
            (matrix2, div_matrix(pow_matrix(matrix, 2 * (n) - 1, len), factor
            (2 * (n)), len, op), len);
        else
            matrix2 = sub_matrix
            (matrix2, div_matrix(pow_matrix(matrix, 2 * (n) - 1, len), factor
            (2 * (n)), len, op), len);
    }
    display_result(matrix2, len);
}

void comp_exp(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
            (matrix2, div_matrix(pow_matrix(matrix, n, len), factor(n + 1), len, op), len);
    }
    display_result(matrix2, len);
}

void comp_sinh(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix2 = fill_matrix(ac, av, matrix2);
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
        (matrix2, div_matrix(pow_matrix(matrix, 2 * n + 1, len), factor
        (2 * n + 3), len, op), len);
    }
    display_result(matrix2, len);
}

void comp_cosh(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
        (matrix2, div_matrix(pow_matrix(matrix, 2 * n, len), factor
        (2 * n), len, op), len);
    }
    display_result(matrix2, len);
}

void comp_sin(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix2 = fill_matrix(ac, av, matrix2);
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 1; op->calc; n++) {
        if (pow(-1, n) > 0)
            matrix2 = add_matrix
            (matrix2, div_matrix(pow_matrix(matrix, 2 * (n), len), factor
            (2 * (n) + 1), len, op), len);
        else
            matrix2 = sub_matrix
            (matrix2, div_matrix(pow_matrix(matrix, 2 * (n), len), factor
            (2 * (n) + 1), len, op), len);
    }
    display_result(matrix2, len);
}

void comp_reci(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
            (matrix2, pow_matrix(matrix, n, len) , len);
    }
    display_result(matrix2, len);
}

void comp_ln(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
            (matrix2, div_matrix(pow_matrix(matrix, n * (-1), len), add(n),len, op), len);
    }
    display_result(matrix2, len);
}

void comp_argth(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 0; op->calc; n++) {
        matrix2 = add_matrix
            (matrix2, div_matrix(pow_matrix(matrix, ((2 * n) + 1) , len), ((2 * n) + 1) ,len, op), len);
    }
    display_result(matrix2, len);
}

void comp_arc(int ac, char **av, double **matrix, operations_t *op)
{
    int len = (int)(sqrt(ac - 2));
    double **matrix2 = NULL;
    int j = 0;

    matrix = fill_matrix(ac, av, matrix);
    matrix2 = init_matrix(matrix2, len);
    matrix_zero(matrix2, len, 0);
    for (int i = 0; i < len; i++) {
        matrix2[i][j] = 1;
        j++;
    }
    if (matrix == NULL || matrix2 == NULL)
        return;
    for (double n = 1; op->calc; n++) {
        if (pow(-1, n) > 0)
            matrix2 = add_matrix
                (matrix2, div_matrix(pow_matrix(matrix, (2 * (n) + 1), len), (2 * (n) + 1), len, op), len);
        else
            matrix2 = sub_matrix
            (matrix2, div_matrix(pow_matrix(matrix, 2 * (n), len), (2 * (n) + 1), len, op), len);
    }
    display_result(matrix2, len);
}

void choose_operation(int ac, char **av, double **matrix, operations_t *op)
{
    if (op->exp)
        comp_exp(ac, av, matrix, op);
    if (op->cos)
        comp_cos(ac, av, matrix, op);
    if (op->sinh)
        comp_sinh(ac, av, matrix, op);
    if (op->sin)
        comp_sin(ac, av, matrix, op);
    if (op->cosh)
        comp_cosh(ac, av, matrix, op);
    if (op->reci)
        comp_reci(ac, av, matrix, op);
    if (op->ln)
        comp_ln(ac, av, matrix, op);
    if (op->arc)
        comp_arc(ac, av, matrix, op);
    if (op->argth)
        comp_argth(ac, av, matrix, op);
}
