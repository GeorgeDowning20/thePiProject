#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
    double pi = 0;
    for(int i = 0; i < n; i++){
        pi += 4.0 * (pow(-1, i) / (2 * i + 1));
    }
    return pi;
}

//function to approximate the value of pi using the monte carlo method with n points
double monte_carlo_pi(int n) //task B 
{
    int i;
    int count = 0;
    double x, y, z, pi;
    for (i = 0; i < n; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1)
            count++;
    }
    pi = (double)count / n * 4;
    return pi;
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
