#include <stdio.h>

void array_print(int m,int n,int arr[m][n]){
        for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    // array creation
    int m, n;
    printf("Enter number of rows :");
    scanf("%d", &m);
    printf("Enter number of columns :");
    scanf("%d", &n);
    int arr[m][n];
    printf("Enter the array values : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    // to Find the element at position [X][Y],
    int r, c;
    printf("Enter the position to find  : \n");
    printf("    Row (0 to %d) : ", m - 1);
    scanf("%d", &r);
    printf("    Column (0 to %d) : ", n - 1);
    scanf("%d", &c);
    printf("The element at arr[%d][%d] is : %d ", r, c, arr[r][c]);
    // to subtract K from each of the elements of the matrix
    int new_arr[m][n],k;
    printf("\nEnter the value to be subtracted : ");
    scanf("%d",&k);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            new_arr[i][j] = arr[i][j] - k;
        }
    }
    array_print(m,n,new_arr);
    // sum and average of the array 
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum+= arr[i][j];
        }
    }
    printf("\nSum of the array is %d",sum);
    printf("\naverage of the array is %.2f",(float)sum/(m*n));
}