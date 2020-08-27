#include <stdio.h>
#include <math.h>

#define INF_NUM_ROOTS -1

int SolveQuadratic(double a, double b, double c, double* x1, double* x2)
    {
    double Discr = 0;

    if (a == 0 && b == 0)
        return (c == 0)? INF_NUM_ROOTS : 0;

    else if (a == 0) /* b != 0 */
        {
        *x1  = -c / b;
        return 1;
        }

    else if ( (Discr = b*b - 4*a*c)  == 0)
        {
        *x1 = *x2 = -b / (2*a);

        return 1;
        }

    else if (Discr > 0)
        {
            double sqrt_Discr = sqrt (Discr);

            *x1 = (-b + sqrt_Discr) / (2*a);
            *x2 = (-b - sqrt_Discr) / (2*a);

            return 2;
        }

    else
        return 0;
    }


int main()
    {
    printf("# Solver Quadratic Equation\n"
           "# by Dolotova Uliana\n"
           "# from the 27th of August\n\n");
    printf("# Put in the coefficients of the Quadratic Equation:\n");

    double a = 0, b = 0, c = 0;

    printf ("# a = ");
    scanf  ("%lg", &a);

    printf ("# b = ");
    scanf  ("%lg", &b);

    printf ("# c = ");
    scanf  ("%lg", &c);

    double x1 = 0, x2 = 0;
    int NumRoots = SolveQuadratic(a, b, c, &x1, &x2);

    printf("\n# The solution is:\n");

    switch (NumRoots)
        {
        case 0:  printf ("no roots\n");
                 break;
        case 1:  printf ("x = %lg\n", x1);
                 break;
        case 2:  printf ("x1 = %lg, x2 = %lg\n", x1, x2);
                 break;
        case INF_NUM_ROOTS: printf ("any number\n");
                 break;
        default: printf ("main(): ERROR: NumRoots = %d\n", NumRoots);
                 return 1;
        }
    return 0;
    }












