#include <stdio.h>
#include <conio.h>

void linear_search(int a[], int n, int key);

int main()
{
    int n;
    printf("Enter size of array :- ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int k;
        printf("Enter the value : ");
        scanf("%d", &k);
        a[i] = k;
    }

    int key;
    printf("Enter the key : ");
    scanf("%d", &key);

    linear_search(a, n, key);

    return 0;
}

void linear_search(int a[], int n, int key)
{
    int cnt = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            pos = i;
            cnt++;
        }
    }
    if (cnt > 0)
    {
        printf("your element position is %d ", pos + 1);
    }
    else
    {
        printf("element not found");
    }
}
