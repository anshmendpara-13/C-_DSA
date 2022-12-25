#include <stdio.h>
typedef struct Complex
{
    float Real_Part;
    float Imaginary_Part;
} complex;

void addNumbers(complex c1, complex c2, complex *result);

int main()
{
    complex c1, c2, result;

    printf("For first number : \n");
    printf("Enter Real_Part part: ");
    scanf("%f", &c1.Real_Part);
    printf("Enter imaginary part: ");
    scanf("%f", &c1.Imaginary_Part);

    printf("First complex number is %.1f + %.1f i \n",c1.Real_Part,c1.Imaginary_Part);

    printf("For second number :  \n");
    printf("Enter Real_Part part: ");
    scanf("%f", &c2.Real_Part);
    printf("Enter imaginary part: ");
    scanf("%f", &c2.Imaginary_Part);

    printf("Second complex number is %.1f + %.1f i \n",c2.Real_Part,c2.Imaginary_Part);

    addNumbers(c1, c2, &result);
    printf("\nSum of Real_Part = %.1f\n", result.Real_Part);
    printf("Sum of Imaginary_Part = %.1f", result.Imaginary_Part);

    return 0;
}
void addNumbers(complex c1, complex c2, complex *result)
{
    result->Real_Part = c1.Real_Part + c2.Real_Part;
    result->Imaginary_Part = c1.Imaginary_Part + c2.Imaginary_Part;
}
