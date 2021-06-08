    /* C Program to sort an array in ascending order using Insertion Sort */
    #include <stdio.h>
    int main()
    {
        int n, i, hole, temp;
        int arr[100];
        printf("Enter number of elements\n");
        scanf("%d", &n);
        printf("Enter %d integers\n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (i = 1 ; i <= n - 1; i++)
        {
    	   hole = i;
                while ( hole > 0 && arr[hole-1] > arr[hole])
                {	        
                    temp     = arr[hole];
                    arr[hole]   = arr[hole-1];
                    arr[hole-1] = temp;
                    hole--;
                }
        }
        printf("Sorted list in ascending order:\n");
        for (i = 0; i <= n - 1; i++)
        {
            printf("%d\n", arr[i]);
        }
        return 0;
    }
