#include <stdio.h>
#include <conio.h>
#include <math.h>

//e=2.71828;

#define f(x) (cos(x) - x * pow(2.718, -x));
//(x - sin(x) - 0.5);
//(pow(2.71828, -x) *(pow(x, 2) + (5 * x) +2))+1
//(pow(x,2)-3);
//(sin(x) - (1/x));
//(pow(x, 4) + 2 * pow(x, 3) - x - 1);

void main()
{
    float a, b, xn, f0, f1, f2, e;
    int step = 0;
up:
    printf("\nEnter two initial guesses:  ");
    scanf("%f%f", &a, &b);
    printf("Enter tolerable error:  ");
    scanf("%f", &e);

    f0 = f(a);
    f1 = f(b);

    if (f0 * f1 > 0.0)
    {
        printf("Incorrect Initial Guesses.\n");
        goto up;
    }

    printf("\nStep\t\ta\t\tb\t\txn\t\tf(xn)\n");
    do
    {
        xn = (a + b) / 2;
        f2 = f(xn);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, a, b, xn, f2);

        if (f0 * f2 < 0)
        {
            b = xn;
            f1 = f2;
        }
        else
        {
            a = xn;
            f0 = f2;
        }
        step = step + 1;
    } while (fabs(f2) > e);
    //////////////////
    xn = (a + b) / 2;
    f2 = f(xn);

    printf("%d\t\t%f\t%f\t%f\t%f\n", step, a, b, xn, f2);
    //////////////////
    printf("\nRoot is: %f\n\n", xn);
}
