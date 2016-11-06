//Insertion Sort ( Ascending Order )
#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct timeval begin, end;

int gettimeofday(struct timeval *tv, void *);

int main()
{
	srand(time(NULL));

	FILE *fp;
	fp = fopen("InSort.txt", "w+");

	double elapsed;

	int n, i, j, temp, I, array[1000];

	for(I = 0; I < 20; I++){

		n = 20 + rand() % 100;

		for (i = 0; i < n; i++) {
			array[i] = 1 + rand() % 100;
		}

		gettimeofday(&begin, NULL);

		for (i = 1 ; i <= n - 1; i++) {
			j = i;

			while ( j > 0 && array[j] < array[j-1]) {
				temp       = array[j];
				array[j]   = array[j-1];
				array[j-1] = temp;

				j--;
			}
		}

		gettimeofday(&end, NULL);

		double elapsed = (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)/1000000.0);

		fprintf(fp, "%d\t%f\n", n, elapsed);
	}

	return 0;
}
