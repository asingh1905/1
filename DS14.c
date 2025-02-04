//bubble
#include <stdio.h>
void main()
{
    // creating an array
    int n, num_1, num_2, num1, num2;
    char operator;
    printf("Enter number of Elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Accessing/traversing the array before sorting
    printf("The array is before sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    //bubble sorting 
    int swap_var;
    for (int i = 0 ; i < n-1;i++){
        for (int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap_var = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap_var;
            }
        }
    }
    // Accessing/traversing the array
    printf("\nThe array is after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    }
