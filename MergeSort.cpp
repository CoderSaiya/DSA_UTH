#include <iostream>

using namespace std;

void merge(int a[], int left, int mid, int right) {
    int len_la = mid - left + 1, len_ra = right - mid;
    int* left_a = new int[len_la];
    int* right_a = new int[len_ra];

    for (int i = 0; i < len_la; i++)left_a[i] = a[left + i];
    for (int i = 0; i < len_ra; i++)right_a[i] = a[mid + 1 + i];

    int left_index = 0; int right_index = 0, sortArray_index = left;
    while (left_index < len_la && right_index < len_ra) {
        if (left_a[left_index] <= right_a[right_index]) a[sortArray_index++] = left_a[left_index++];
        else a[sortArray_index++] = right_a[right_index++];
    }

    while (left_index < len_la) a[sortArray_index++] = left_a[left_index++];
    while (right_index < len_ra) a[sortArray_index++] = right_a[right_index++];

    delete[] left_a;
    delete[] right_a;

}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}