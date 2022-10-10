//-------------------------------------------------------------
//path: main.c
//author: G. Downing
//created on: 10-10-2022
//last modified: 10-10-2022
//version: 1.0
//language: c
//Copyright (c) 2022 G. Downing
//Description: function to estimate to value of pi using the monte carlo method
//-------------------------------------------------------------

#include <stdio.h>  // printf and friends
#include <stdlib.h> // access to rand functions

#ifndef STATUS_E // if STATUS_E is not defined
#define STATUS_E // define it
enum status      // create an enum called status
{
    SUCCESS, // set SUCCESS to 0
    FAILURE, // set FAILURE to 1
    ERROR    // set ERROR to 2
};
#endif // end if

// function: get_monte_carlo_pi
// purpose: estimate pi using monte carlo method (https://en.wikipedia.org/wiki/Monte_Carlo_method)
// input: number of iterations and pointer to pi
// output: estimated value of pi
// return: status of function (SUCCESS or ERROR)
// author: G. Downing
// date: 10-10-2022
// version: 1.0
// language: c
// requires: stdio.h, stdlib.h and status enum
enum status get_monte_carlo_pi(int n, double *pi); // function prototype

enum status get_monte_carlo_pi(int n, double *pi) // task B
{
    // reject invalid arguments
    if (n < 100)        // if n is less than 100
        return ERROR;   // return ERROR code to be handled in main

    // initialize local variables
    int count = 0;  // initialize count to 0
    double x, y, z; // initialize x, y, and z to 0

    // generate n random points and count how many are inside the circle
    for (int idx = 0; idx < n; idx++) // loop n times
    {
        x = (double)rand() / RAND_MAX; // generate random x coordinate
        y = (double)rand() / RAND_MAX; // generate random y coordinate
        z = x * x + y * y;             // calculate distance from origin based on pythagorean theorem (x^2 + y^2 = z^2)
        if (z <= 1)                    // if the point is inside the circle (distance to origin is less than 1)
            count++;                   // increment count
    }

    // calculate pi
    *pi = (double)count / n * 4; // pi is the ratio of points inside the circle to total points times 4
    return SUCCESS;              // return SUCCESS code to be handled in main
}

// function: main
// purpose: tests get_monte_carlo_pi function
// input: gets number of iterations from command line
// output: prints estimated value of pi
// return: 0
// author: G. Downing
// date: 10-10-2022
// version: 1.0
// language: c
// requires: stdio.h, stdlib.h and status enum
int main(void)
{
    // initialize local variables
    int n = 0; // number of points
    double pi; // estimate of pi

    printf("Enter the number of points to use in the monte carlo method: \r\n"); // prompt user for number of points
    scanf("%d", &n);                                                             // read number of points

    if (get_monte_carlo_pi(n, &pi) != SUCCESS) // if monte_carlo_pi does not return SUCCESS, print error message
    {
        printf("Error: number of points must be greater than 100\r\n"); // print error message
    }
    else // if monte_carlo_pi returns SUCCESS print estimation of pi.
    {
        printf("The estimate of pi is %f\r\n", pi); // print estimation of pi
    }

    return 0;
}
