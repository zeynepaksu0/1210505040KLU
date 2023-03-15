#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000
#define RAND_MAX_NUM 1000000

//dev c ile acýldýgýnda kod bazen calýsmayabiliyor, eger böyle bir durumla karsýlasýrsanýz online c compilerda denemenizi rica ederim.
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[MAX_NUM];
    srand(time(0));
    for (int i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % RAND_MAX_NUM;
    }

    clock_t start_time = clock();

    int left = 0, right = MAX_NUM - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    int max_index = left;
    printf("Maximum deger: %d\n", arr[max_index]);
    printf("Calisma zamani: %f saniye", ((double) (clock() - start_time)) / CLOCKS_PER_SEC);
    return 0;
}
