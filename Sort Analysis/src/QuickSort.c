/*
 * QuickSort.c
 *
 *  Created on: 17-Apr-2015
 *      Author: aditya
 */

#include <stdio.h>

void swap ( int *a, int *b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition (int *arr, int l, int h)
{
    int x = *(arr + h);
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (*(arr + j) <= x)
        {
            i++;
            swap ((arr + i), (arr + j));
        }
    }
    swap ((arr + i + 1), (arr + h));
    return (i + 1);
}

double quicksort(int *arr,int l, int h)
{
	// Create an auxiliary stack
	int *stack = malloc(sizeof(int)*(h - l + 1));

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	*(stack + ++top) = l;
	*(stack + ++top) = h;

	// Keep popping from stack while is not empty
	while ( top >= 0 )
	{
		// Pop h and l
	    h = *(stack + top--);
	    l = *(stack + top--);

	    // Set pivot element at its correct position in sorted array
	    int p = partition( arr, l, h );

	    /* If there are elements on left side of pivot, then push left
	     side to stack */
	    if ( p-1 > l )
	    {
	    	*(stack + ++top) = l;
	    	*(stack + ++top) = p - 1;
	    }

	    /* If there are elements on right side of pivot, then push right
	     side to stack */
	    if ( p+1 < h )
	    {
	    	*(stack + ++top) = p + 1;
	    	*(stack + ++top) = h;
	    }
	}
}
