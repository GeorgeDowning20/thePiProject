//-------------------------------------------------------------
//@path: main.h
//@author: G. Downing
//@created on: 10-10-2022
//@last modified: 10-10-2022
//@version: 1.0
//@language: c
//@Copyright (c) 2022 G. Downing
//@Description: Header file for function to estimate to value of pi using the monte carlo method
//-------------------------------------------------------------

//-------------------------------------------------------------
//              Preprocessor directives
//-------------------------------------------------------------

#pragma once // include guard

#include <stdio.h>  // printf and friends
#include <stdlib.h> // access to rand functions

//-------------------------------------------------------------
//              data types and structures
//-------------------------------------------------------------

enum status // create an enum called status
{
    SUCCESS, // set SUCCESS to 0
    FAILURE, // set FAILURE to 1
    ERROR    // set ERROR to 2
};

//-------------------------------------------------------------
//              Function prototypes
//-------------------------------------------------------------

// @function: get_monte_carlo_pi
// @purpose: estimate pi using monte carlo method (https://en.wikipedia.org/wiki/Monte_Carlo_method)
// @input: number of iterations and pointer to pi
// @output: estimated value of pi
// @return: status of function (SUCCESS or ERROR)
// @author: G. Downing
// @date: 10-10-2022
// @requires: stdio.h, stdlib.h and main.h
static enum status get_monte_carlo_pi(const int n, double *const pi); // function prototype