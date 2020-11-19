/*
** EPITECH PROJECT, 2019
** transfer
** File description:
** transfer
*/

#include "trigo.h"

operations_t *init_struct(operations_t *op)
{
    op = malloc(sizeof(operations_t));
    op->exp = false;
    op->cos = false;
    op->sin = false;
    op->cosh = false;
    op->sinh = false;
    op->reci = false;
    op->ln = false;
    op->arc = false;
    op->argth = false;
    op->calc = true;
    return (op);
}

int display_usage(char *filepath, int ret)
{
    int fd = open(filepath, O_RDONLY);
    char *str;

    if (fd < 0)
        return (EXIT_ERROR);
    str = get_next_line(fd);
    while (str) {
        printf("%s\n", str);
        free(str);
        str = get_next_line(fd);
    }
    return (ret);
}

bool check_arg(char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '.' &&
        str[i] != '+')
            return (false);
    }
    return (true);
}

bool check_operation(char *str, operations_t *op)
{
    if (strcmp(str, "EXP") == 0)
        op->exp = true;
    else if (strcmp(str, "COS") == 0)
        op->cos = true;
    else if (strcmp(str, "SIN") == 0)
        op->sin = true;
    else if (strcmp(str, "COSH") == 0)
        op->cosh = true;
    else if (strcmp(str, "SINH") == 0)
        op->sinh = true;
    else if (strcmp(str, "RECI") == 0)
        op->sinh = true;
    else if (strcmp(str, "LN") == 0)
        op->sinh = true;
    else if (strcmp(str, "ARGTH") == 0)
        op->sinh = true;
    else if (strcmp(str, "L") == 0)
        op->sinh = true;
    else
        return (false);
    return (true);
}

bool parser(int ac, char **av, operations_t *op)
{
    if (ac < 3 || (int)(pow(((int)(sqrt(ac - 2))), 2)) != ac - 2)
        return (false);
    if (check_operation(av[1], op) == false)
        return (false);
    for (int i = 2; av[i]; i++)
        if (!check_arg(av[i]))
            return (false);
    return (true);
}

int trigo(int ac, char **av)
{
    operations_t *op = NULL;
    double **matrix = NULL;

    if (ac == 2)
        if (av[1] && strcmp(av[1], "-h") == 0)
            return (display_usage("README", EXIT_SUCCESS));
    op = init_struct(op);
    if (!parser(ac, av, op))
        return (EXIT_ERROR);
    choose_operation(ac, av, matrix, op);
    return (EXIT_SUCCESS);
}
