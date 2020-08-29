#include <stdio.h>
#include <math.h>
#include <assert.h>


#define INF_NUM_ROOTS -1

int SolveQuadratic(double a, double b, double c, double* x1, double* x2);

void test_SolveQuadratic();

int main()
    {
    printf("# Solver Quadratic Equation\n"
           "# by Dolotova Uliana\n"
           "# from the 27th of August\n\n");
           
            test_SolveQuadratic(); 
           
    printf("\n\n# Put in the coefficients of the Quadratic Equation:\n");

    double a = 0, 
	       b = 0, 
		   c = 0;

    printf ("# a = ");
    scanf  ("%lg", &a);

    printf ("# b = ");
    scanf  ("%lg", &b);

    printf ("# c = ");
    scanf  ("%lg", &c);

    double x1 = 0, 
	       x2 = 0;
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
    


//-----------------------------------------------------------------------
//! This function looks for the roots of a quadratic equation.
//!
//! @param [in]  a  coefficient at x ^ 2
//! @param [in]  b  coefficient at x ^ 1
//! @param [in]  c  coefficient at x ^ 0
//! @param [out] x1 pointer to the 1-st root
//! @param [out] x2 pointer to the 2-nd root
//!
//! @return Number of roots
//!
//! @note   If the equation contains an infinite number of roots, 
//!         the function returns INF_NUM_ROOTS.

//------------------------------------------------------------------------- 
int SolveQuadratic(double a, double b, double c, double* x1, double* x2)
    {
    
	assert (x1 != NULL);
	assert (x2 != NULL);
	assert (x1 != x2);
    	
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

void test_SolveQuadratic()
{   
	double x1 = 0,
	       x2 = 0;
	    
	double res = 0,
		   exp = 0;
	
	int num = 0;
	
	#define TEST_ROUTINE \
	if (res == exp) \
		printf("\n# test %d is OK", num); \
	else \
		printf("\n# test %d is BAD", num); \
		
	{
		num = 1;
		res = SolveQuadratic(0, 0, 0, &x1, &x2);
		exp = INF_NUM_ROOTS;
		
		TEST_ROUTINE;
	}
	
	{
		num = 2;
		res = SolveQuadratic(0, 0, 1, &x1, &x2);
		exp = 0;
		
		TEST_ROUTINE;
	}
	
	{
		num = 3;
		res = SolveQuadratic(1, 2, 1, &x1, &x2);
		exp = 1;
		
		TEST_ROUTINE;
	}
	
	{
		num = 4;
		res = SolveQuadratic(1, -2, 1, &x1, &x2);
		exp = 1;
		
		TEST_ROUTINE;
	}
	
	{
		num = 5;
		res = SolveQuadratic(1, 4, 1, &x1, &x2);
		exp = 2;
		
		TEST_ROUTINE;
	}
	
		
	#undef TEST_ROUTINE
}
