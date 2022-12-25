#include <stdio.h>
#include <conio.h>

increment(int arr1[]){
    for (int i = 0; i < arr1; i++)
    {
        arr1[i] = arr1[i] + 5;
        printf("%d",arr1[i]);
    }
    
}

int main()
{
    int n;
    int arr[n];

    printf("Enter the number you want to make this size of array : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        arr[i] = a; 
    }
    

    increment(n);

    return 0;
}

