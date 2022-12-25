#include <stdio.h>
#include <stdlib.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void selectionsort(int *a, int n)
{
    int indexofmin, temp;
    printf("running selection sort...\n");
    {
        for (int i = 0; i < n - 1; i++)
        {
            indexofmin = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[indexofmin])
                {
                    indexofmin = j;
                }
                // swap a[j] and a[indexofmin]
                temp = a[i];
                a[i] = a[indexofmin];
                a[indexofmin] = temp;
            }
        }
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int a[] = {3, 5, 2, 13, 12};
    int n = 5;
    printarray(a, n);
    selectionsort(a, n);
    printarray(a, n);

    return 0;
}