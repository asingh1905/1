#include <stdio.h>
void main()
{
    // array creation
    int arr[10];
    printf("Enter the array values : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Value %d :", i + 1);
        scanf("%d", &arr[i]);
    }

    // biggest number
    int biggest_num = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (biggest_num < arr[i])
        {
            biggest_num = arr[i];
        }
    }
    printf("biggest number is %d\n",biggest_num);
    // smallest number
    int smallest_num = arr[0];
    for (int i = 1; i < 10; i++)
    {
        if (smallest_num > arr[i])
        {
            smallest_num = arr[i];
        }
    }
    printf("smallest number is %d\n",smallest_num);
    // sum
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += arr[i];
    }
    printf("sum is %d\n",sum);

    // average
    int average = sum / 10;
    printf("average is %d\n",average);

    // multiply array by n
    int n,new_arr[10];
    printf("Enter any number to multiply with array : ");
    scanf("%d",&n);
    for (int i = 0; i < 10; i++)
    {
        new_arr[i] = n * arr[i];
    }
        printf("Array * %d : ",n);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",new_arr[i]);
    }

    //to check whether the element X is present in the array
    int x,found = 0;
    printf("\nEnter any number to check in the array : ");
    scanf("%d",&x);
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]==x)
        {
            printf("\n%d is element-%d of the array",x,i);
            found = 1;
        }
    }
    if(!found){
        printf("\n%d is not present in the array",x);
    }
    //to find the element at position Y
    int y;
    printf("\nEnter the position: ");
    scanf("%d",&y);
    printf("Element at %d position of the array is %d",y,arr[y]);
}