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
// @version: 1.0
// @language: c
// @requires: stdio.h, stdlib.h and status enum
enum status get_monte_carlo_pi(int n, double *pi); // function prototype