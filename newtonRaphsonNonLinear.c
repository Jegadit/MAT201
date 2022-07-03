#include <stdio.h>
#include <conio.h>
#include <math.h>

#define error 0.00001

#define X(x, y) ((x * y) + pow(x, 2) − pow(y, 3) − 1);

#define F1(x, y) ((2 * x) + y);
#define F2(x, y) (3 * pow(y, 2) + x);

#define Y(x, y) (x + (2 * y)−(x * pow(y, 2))−2);

#define G1(x, y) (1 - pow(y, 2));
#define G2(x, y) (2 - (2 * x * y));

void main()
{
    double x1, y1, y2, x2, x, y, f, g, f1, f2, g1, g2;
    int i = 1;
    printf("\nEnter the value of x: ");
    scanf("%lf", &x);
    printf("\nEnter the value of y: ");
    scanf("%lf", &y);
    f = X(x, y);
    g = Y(x, y);
    printf("\n\nf = %lf", f);
    printf("\n\ng = %lf", g);

    f1 = F1(x, y);
    f2 = F2(x, y);
    g1 = G1(x, y);
    g2 = G2(x, y);
    printf("\n\nf1 = %lf", f1);
    printf("\n\ng1 = %lf", g1);
    printf("\n\nf2 = %lf", f2);
    printf("\n\ng2 = %lf", g2);

    x1 = x - ((f * g2 - g * f2) / (f1 * g2 - f2 * g1));
    y1 = y - ((g * f1 - f * g1) / (f1 * g2 - f2 * g1));
    printf("\n\nx = %lf", x1);
    printf("\n\ny = %lf", y1);

    printf("\n\n");
    do
    {
        f = X(x1, y1);
        g = Y(x1, y1);
        printf("\n\nf = %lf", f);
        printf("\n\ng = %lf", g);

        f1 = F1(x1, y1);
        f2 = F2(x1, y1);
        g1 = G1(x1, y1);
        g2 = G2(x1, y1);
        printf("\n\nf1 = %lf", f1);
        printf("\n\ng1 = %lf", g1);
        printf("\n\nf2 = %lf", f2);
        printf("\n\ng2 = %lf", g2);

        x2 = x1 - ((f * g2 - g * f2) / (f1 * g2 - f2 * g1));
        y2 = y1 - ((g * f1 - f * g1) / (f1 * g2 - f2 * g1));
        printf("\n\n x = %lf ", x2);
        printf("\n\n y = %lf ", y2);
        printf("\n\n");

        if (fabs(x1 - x2) < error && fabs(y1 - y2) < error)
        {
            printf("\n\nREAL ROOT1 = %lf", x1);
            printf("\n\nREAL ROOT2 = %lf", y1);
            i = 0;
        }
        else
        {
            x1 = x2;
            y1 = y2;
        }
    } while (i != 0);
}