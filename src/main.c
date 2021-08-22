/**
 * @file main.c
 * @author Damjan Belavic (damjan.belavic@vuka.hr)
 * @brief GlobalLogic Embedded Software Engineer in C / Task2
 * @version 1.0
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "div_test.h"

int32_t main(void)
{
    char *result = NULL;
    
    printf("|-------+-------------|\n");
    printf("| Input | Output      |\n");
    printf("|-------+-------------|\n");
    for (int32_t n = 0; n <= 100; n++)
    {
        result = check_divisibility(n);
        printf("| %5d | %-11s |\n", n, result);
        printf("|-------+-------------|\n");
    }
    free((void *)result);

    exit(0);
}
