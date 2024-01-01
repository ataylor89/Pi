#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(int n)
{
    double lsum, usum, y, x, width;
    lsum = 0.0;
    usum = 0.0;
    width = 1.0 / n;

    // Upper sum
    x = 0.0;
    for (int i = 0; i < n; i++)
    {
        y = sqrt(1.0 - x * x);
        usum += y * width;

        // printf("n = %d, y = %f, x = %f, usum = %f\n", n, y, x, usum);

        x += width;
    }
    usum *= 4;

    // Lower sum
    x = width;
    for (int i = 0; i < n; i++)
    {   
        y = sqrt(1.0 - x * x);
        lsum += y * width;

        // printf("n = %d, y = %f, x = %f, lsum = %f\n", n, y, x, lsum);

        x += width;

        if (x > 1.0)
        {
            x = 1.0;
        }
    }
    lsum *= 4;

    printf("%f < PI < %f\n", lsum, usum);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: pi <number_of_rectangles>\n");
        return 0;
    }

    int n;
    n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("Usage: pi <number_of_rectangles>\n");
        return 0;
    }

    printf("Computing lower sum and upper sum for %d rectangles...\n", n);

    compute(n);

    return 0;
}