/**
 * @file div_test.c
 * @author Damjan Belavic (damjan.belavic@vuka.hr)
 * @brief GlobalLogic Embedded Software Engineer in C / Task2
 * @version 1.0
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "div_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ┌───────────────────────────────────────────────────────────────────────────┐
// │ Enums, Variables, Structures, Typedefs                                    │
// └───────────────────────────────────────────────────────────────────────────┘

typedef enum DIVISIBILITY_SCORE
{
    NEGATIVE = -1,
    NOT_DIVISIBLE = 0,
    DIVISIBLE_BY_FIRST = 1U << 0,
    DIVISIBLE_BY_SECOND = 1U << 1,
    DIVISIBLE_BY_BOTH = DIVISIBLE_BY_FIRST | DIVISIBLE_BY_SECOND
} dv_score_t;

// ┌───────────────────────────────────────────────────────────────────────────┐
// │ Divisible with following numbers                                          │
// └───────────────────────────────────────────────────────────────────────────┘

const int32_t FIRST_DIVIDER = 3;
const int32_t SECOND_DIVIDER = 5;

// ┌───────────────────────────────────────────────────────────────────────────┐
// │ Response messages                                                         │
// └───────────────────────────────────────────────────────────────────────────┘

const char *const DIV_BY_FIRST_MSG = "Global";
const char *const DIV_BY_SECOND_MSG = "Logic";

/**
 * @brief Checks divisibility by FIRST_DIVIDER and SECOND_DIVDER number
 * 
 * @param number Any positive integer number
 * @return char* First message if divisible by first number, seccond message if 
 * divisible by second number, concatenated message if divisible by both numbers
 * Returns NULL if input is negative.
 */
char *check_divisibility(int32_t number)
{
    dv_score_t score = NOT_DIVISIBLE;
    static char *message = NULL;

    if (message == NULL)
    {
        size_t max_len;
        max_len = strlen(DIV_BY_FIRST_MSG) + strlen(DIV_BY_SECOND_MSG) + 1;
        message = (char *)malloc(max_len);
    }

    if (number % FIRST_DIVIDER == 0)
    {
        score |= DIVISIBLE_BY_FIRST;
    }

    if (number % SECOND_DIVIDER == 0)
    {
        score |= DIVISIBLE_BY_SECOND;
    }

    // Consider some special cases
    if (number == 0)
    {
        score = NOT_DIVISIBLE;
    }

    if (number < 0)
    {
        score = NEGATIVE;
    }

    switch (score)
    {
    case NEGATIVE:
        message = NULL;
        break;
    case NOT_DIVISIBLE:
        sprintf(message, "%d", number);
        break;
    case DIVISIBLE_BY_FIRST:
        sprintf(message, "%s", DIV_BY_FIRST_MSG);
        break;
    case DIVISIBLE_BY_SECOND:
        sprintf(message, "%s", DIV_BY_SECOND_MSG);
        break;
    case DIVISIBLE_BY_BOTH:
        sprintf(message, "%s%s", DIV_BY_FIRST_MSG, DIV_BY_SECOND_MSG);
        break;
    default:
        break;
    }

    return message;
}
