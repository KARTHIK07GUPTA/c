#include <stdio.h>

void main()
{
    int heap[10], no, i, j, c, root, temp;

    printf("\n Enter the number of elements: ");
    scanf("%d", &no);
    printf("\n Enter the numbers: ");
    for (i = 0; i < no; i++)
        scanf("%d", &heap[i]);

    // Build max heap
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (heap[root] < heap[c])
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    printf("Heap array: ");
    for (i = 0; i < no; i++)
        printf("%d\t", heap[i]);

    // Heap sort
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;

        root = 0;
        do
        {
            c = 2 * root + 1;
            if (heap[c] < heap[c + 1] && c < j - 1)
                c++;
            if (heap[root] < heap[c] && c < j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    }

    printf("\n The sorted array is: ");
    for (i = 0; i < no; i++)
        printf("%d\t", heap[i]);

    printf("\n Complexity: Best case = Avg case = Worst case = O(n logn)\n");
}
