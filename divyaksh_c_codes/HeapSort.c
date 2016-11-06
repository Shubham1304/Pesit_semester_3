#include <stdio.h>
#include <stdlib.h>
#define MAX 500

int a[MAX];

void heapify(int, int);
void swap(int, int);

void heapify(int n, int i) {
        int largest, l, r;
        largest = i;
        l = 2 * i + 1;
        r = 2 * i + 2;

        if(a[largest] < a[l] && l < n)
                largest = l;

        if(a[largest] < a[r] && r < n)
                largest = r;

        if(largest != i) {
                swap(largest, i);
                heapify(n, largest);
        }
}

void sort() {
        int i;

        for(i = MAX / 2 - 1; i >= 0; i--) {
                heapify(MAX, i);
        }

        for(i = MAX - 1; i >= 0; i--) {
                swap(i, 0);
                heapify(i, 0);
        }
}

void swap(int i, int j) {
        int temp;

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
}

void main() {
        int i;
        
        for(i = 0; i < MAX; i++) {
                a[i] = rand() % 1000;
              //  printf("%d\t", a[i]);
        }
        printf("\n");

        sort();

        for(i = 0; i < MAX; i++) {
                printf("%d\t%d\n",(i+1),a[i]);
        }
        printf("\n");
}
