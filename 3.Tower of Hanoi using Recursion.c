// C program for Tower of Hanoi using Recursion

    #include <stdio.h>
    
    void towers(int num, char source, char destination, char auxiliary)
    {
        if (num == 1)
        {
            printf("\n Move disk 1 from peg %c to peg %c", source, destination);
            return;
        }
        towers(num - 1, source, auxiliary, destination);
        printf("\n Move disk %d from peg %c to peg %c", num, source, destination);
        towers(num - 1, auxiliary, destination, source);
    }
	int main()
    {
		int num;
        printf("Enter the number of disks : ");
        scanf("%d", &num);
        printf("The algorithm to transfer disks from A to C in the  Tower of Hanoi are :\n");
        towers(num, 'A', 'C', 'B');//in the form of source,destination and auxiliary
        return 0;
    }

