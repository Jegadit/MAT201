#include <stdio.h>
#include <conio.h>
#include <math.h>

#define f(x) (pow(x,3) - pow(2.71828,(-1*2*x)) + 1);
//(3.1*x - cos(x) - 1);

int main()
{

    float x0, x1, x2, f0, f1, f2, e;
    int step = 0;

up:
    printf("\nEnter two initial guesses:  ");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable error:  ");
    scanf("%f", &e);
    /* Calculating Functional Values */
    f0 = f(x0);
    f1 = f(x1);
    /* Checking whether given guesses brackets the root or not. */
    if (f0 * f1 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        goto up;
    }
    /* Implementing Regula Falsi or False Position Method */
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step = step + 1;

    } while (fabs(f2) > e);

    /////////////////
    x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
    f2 = f(x2);
    printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

    /////////////////

    printf("\nRoot is: %f", x2);
    return 0;
}
