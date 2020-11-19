/*
** EPITECH PROJECT, 2019
** compute_simple
** File description:
** compute_simple
*/

#include "transfer.h"

double **fill_doubles(int ac, char **av, int begin, numbers_t *n)
{
    int k = 0;
    int l = 0;
    int m = 0;
    double **nb = malloc(sizeof(double *) * ((ac - 1) / 2));
    char *temp = NULL;
    int occ = 0;

    for (int i = begin; av && av[i]; i += 2) {
        occ = 0;
        if (begin == 1)
            n->occ1[k] = 0;
        else if (begin == 2)
            n->occ2[k] = 0;
        for (int j = 0; av[i] && av[i][j]; j++) {
            if (av[i][j] == '*') {
                occ++;
                if (begin == 1)
                    n->occ1[k]++;
                else if (begin == 2)
                    n->occ2[k]++;
            }
        }
        nb[k] = malloc(sizeof(double) * (occ + 1));
        temp = malloc(sizeof(char) * (strlen(av[i]) + 1));
        m = 0;
        l = 0;
        for (int j = 0; av[i] && av[i][j]; j++) {
            if (av[i][j] == '*') {
                temp[m] = 0;
                m = 0;
                nb[k][l] = strtod(temp, NULL);
                l++;
            }
            else {
                temp[m] = av[i][j];
                m++;
            }
            if (!av[i][j + 1]) {
                temp[m] = 0;
                nb[k][l] = strtod(temp, NULL);
                m = 0;
            }
        }
        k++;
        free(temp);
        if (!av[i + 1])
            break;
    }
    return (nb);
}

int compute_simple(int ac, char **av)
{
    double result = 1;
    numbers_t *n = malloc(sizeof(numbers_t));
    double num1 = 0;
    double num2 = 0;

    n->occ1 = malloc(sizeof(int) * ((ac - 1) / 2));
    n->occ2 = malloc(sizeof(int) * ((ac - 1) / 2));
    if (ac < 3)
        return (EXIT_ERROR);
    n->nb1 = fill_doubles(ac, av, 1, n);
    n->nb2 = fill_doubles(ac, av, 2, n);
    for (double path = 0; path <= 1.001; path += 0.001) {
        result = 1;
        for (int i = 0; n->nb1 && n->nb2 && n->nb1[i] &&
        n->nb2[i] && i < (ac - 1) / 2; i++) {
            num1 = n->nb1[i][0];
            num2 = n->nb2[i][0];
            for (int j = 1; j <= n->occ1[i]; j++)
                num1 += pow(path, j) * n->nb1[i][j];
            for (int j = 1; j <= n->occ2[i]; j++)
                num2 += pow(path, j) * n->nb2[i][j];
            if (num1 == 0 && num2 == 0)
                result = 1;
            else if (num2 == 0)
                result = 0;
            else
                result *= (num1 / num2);
        }
        printf("%.3f -> %.5f\n", path, result);
    }
    return (EXIT_SUCCESS);
}
