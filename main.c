#include <stdio.h>
#include <stdlib.h>

void clrscr(void) {
  fprintf(stdout, "\033[2J\033[0;0f");
  fflush(stdout);
}

void Quicksort(int list[], int l, int r) {
    int i,j,t;
    register int p;
    if (l<r) {
        p = list[l];
        i = l, j = r;
        while (i<j) {
            while(list[i]<=p) i++;
            while(list[j]>p) j--;
            //swap A[i]<-->A[j]
            t = list[i];
            list[i] = list[j];
            list[j] = t;
        }
        //undo last swap when i >= j
        t = list[i];
        list[i] = list[j];
        list[j] = t;
        //swap A[l]<-->A[j]
        list[l] = list[j];
        list[j] = p;
        Quicksort(list, l, j-1);
        Quicksort(list, j+1, r);
    }
}

int main()
{
    int list[50];
	int size, i;
	clrscr();
	printf("Enter the number of elements: ");
	scanf("%d", &size);
	printf("Enter the elements to be sorted:\n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &list[i]);
	}
	Quicksort(list, 0, size - 1);
	printf("After applying quick sort\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
	getchar();
	return 0;
    return 0;
}
