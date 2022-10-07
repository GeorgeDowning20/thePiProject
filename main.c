#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mpg(float miles, float liters);   // function prototype
double estimate_pi(int n);  //  function prototype
double monte_carlo_pi(int n);   // function prototype

//function to calulate mile per gallon using miles traveled and liters of gas used
float mpg(float miles, float liters) //task 1
{
    float gallons = liters * 0.264172;  //convert liters to gallons
    float milesPerGallon = miles / gallons; //calculate miles per gallon
    return milesPerGallon;  //return miles per gallon
}

//function to estimate the value of pi using a power series method with n itterations
double estimate_pi(int n)   //task A
{
    double pi = 0;  //initialize pi
    for(int i = 0; i < n; i++){ //itterate n times
        pi += 4.0 * (pow(-1, i) / (2 * i + 1)); //calculate pi using power series method
    }
    return pi;  //return pi
}

//function to approximate the value of pi using the monte carlo method with n points
double monte_carlo_pi(int n) //task B 
{
    //initialize variables
    int count = 0;
    double x, y, z, pi;

    //generate n random points and count how many are inside the circle
    for (int idx = 0; idx < n; idx++)
    {
        x = (double)rand() / RAND_MAX;  ///generate random x coordinate
        y = (double)rand() / RAND_MAX;  //generate random y coordinate
        z = x * x + y * y;  //calculate distance from origin
        if (z <= 1)     //if the point is inside the circle (distance to origin is less than 1)
            count++;    //increment count
    }

    pi = (double)count / n * 4; //pi is the ratio of points inside the circle to total points times 4
    return pi; //return pi
}

int main (void)
{
    //task 1
    float miles = 0;
    float liters = 0;
    printf("Enter the number of miles traveled: ");
    scanf("%f", &miles);
    printf("Enter the number of liters of gas used: ");
    scanf("%f", &liters);
    printf("The car's fuel economy is %.2f miles per gallon.\n", mpg(miles, liters));

    //task A
    int n = 0;
    printf("Enter the number of itterations to use in the power series method: ");
    scanf("%d", &n);
    printf("The estimated value of pi using the power series method is %.10f.\n", estimate_pi(n));

    //task B
    int m = 0;
    printf("Enter the number of points to use in the monte carlo method: ");
    scanf("%d", &m);
    printf("The estimated value of pi using the monte carlo method is %.10f.\n", monte_carlo_pi(m));

    return 0;
}
