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
    int32_t lower, upper; 

    printf("Enter check range (lower upper): ");
    if (scanf("%d %d", &lower, &upper) != 2)
    {
        printf("Invalid input.\n")
        return (-1);
    }

    printf("Input | Output\n");

    for (int32_t n = lower; n <= upper; n++)
    {
        result = check_divisibility(n);
        if (result != NULL)
        {
            printf("%5d | %-11s\n", n, result);
        }
    }
    free((void *)result);

    return (0);
}
