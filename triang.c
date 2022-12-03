#include <stdio.h>

int get_side()
{
    int side = 0;
    if (scanf("%d%*c", &side) == 1)
    {
        return side;
    }
    return 0;
}

char *get_triangle_type(int a, int b, int c)
{
    char *equilateral = "Equilateral", *isosceles = "Isosceles",
            *scalene = "Scalene";
    if (a == b && a == c && b == c)
    {
        return equilateral;
    }
    else
    {
        if (a == b || a == c || b == c)
        {
            return isosceles;
        }
        else
        {
            return scalene;
        }
    }
}

int is_valid_triangle(int a, int b, int c)
{
    char *ERR01 = "No side length may be zero",
            *ERR02 = "No side length may be negative", *ERR03 =
            "The sum of length of any two sides must be greater than length of third side";
    if (a == 0 || b == 0 || c == 0)
    {
        fprintf(stderr, "ERR-01: Invalid triangle! %s.\n\n", ERR01);
        return 0;
    }
    if (a < 0 || b < 0 || c < 0)
    {
        fprintf(stderr, "ERR-02: Invalid triangle! %s.\n\n", ERR02);
        return 0;
    }
    if ((a < b + c && b < a + c && c < a + b) < 1)
    {
        fprintf(stderr, "ERR-03: Invalid triangle! %s.\n\n", ERR03);
        return 0;
    }
    return 1;
}

int main()
{
    int a, b, c;
    do
    {
        printf("Enter triangle sides:\n");
        printf("a = ");
        a = get_side();
        printf("b = ");
        b = get_side();
        printf("c = ");
        c = get_side();
    }
    while (!is_valid_triangle(a, b, c));
    printf("Triangle Type: %s.\n", get_triangle_type(a, b, c));
    return 0;
}
