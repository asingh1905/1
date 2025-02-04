#include <stdio.h>
void array_print(int m, int n, int arr[m][n])
{
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
    int rowA, rowB, colA, colB;
    printf("Enter size of Array A :\n");
    printf("\tRow :");
    scanf("%d", &rowA);
    printf("\tColumn :");
    scanf("%d", &colA);
    printf("Enter size of Array B :\n");
    printf("\tRow :");
    scanf("%d", &rowB);
    printf("\tColumn :");
    scanf("%d", &colB);
    int arrA[rowA][colA], arrB[rowB][colB];
    printf("Enter the values of first array : \n");
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            printf("arrA[%d][%d] : ", i, j);
            scanf("%d", &arrA[i][j]);
        }
    }
    printf("Enter the values of second array : \n");
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < colB; j++)
        {
            printf("arrB[%d][%d] : ", i, j);
            scanf("%d", &arrB[i][j]);
        }
    }
    // printing both arrays
    printf("Array A :\n");
    array_print(rowA, colA, arrA);
    printf("Array B :\n");
    array_print(rowB, colB, arrB);
    // addition and subtraction of the matrices
    if (rowA == rowB && colA == colB)
    {
        int add[rowA][colA], sub[rowB][colB];
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)
            {
                add[i][j] = arrA[i][j] + arrB[i][j];
                sub[i][j] = arrA[i][j] - arrB[i][j];
            }
        }
        printf("Array A + Array B :\n");
        array_print(rowA, colA, add);
        printf("Array A - Array B :\n");
        array_print(rowA, colA, sub);
    }
    else
    {
        printf("Array operation cannot be done as they're not similar.");
    }
    // multiplication of arrays
    if (colA == rowB)
    {
        int mult[rowA][colB];
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colB; j++)
            {
                mult[i][j]=0;
                for (int k = 0; k < colA; k++)
                {
                    mult[i][j]+=arrA[i][k]*arrB[k][j];
                }
                
            }
        }
        printf("Array A * Array B : \n");
        array_print(rowA,colB,mult);
    }
    else{
        printf("\nMultiplication cannot be done since comumn of first matrix is not equal to row of second matrix.");
    }
}


 