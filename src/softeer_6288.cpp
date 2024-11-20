#include <stdio.h>
#define N 1000000

int bagWeight;
int n;
int weight[N];
int price[N];
int temp1[N];
int temp2[N];
int result;

void merge(int* arr1, int* arr2, int firstIndex, int lastIndex) {
  int midIndex = (firstIndex + lastIndex) / 2;
  int leftIndex = firstIndex;
  int rightIndex = midIndex + 1;
  int index = leftIndex;

  while (leftIndex <= midIndex && rightIndex <= lastIndex) {
    if (arr1[leftIndex] >= arr1[rightIndex]) {
      temp1[index] = arr1[leftIndex];
      temp2[index++] = arr2[leftIndex++];
    } else {
      temp1[index] = arr1[rightIndex];
      temp2[index++] = arr2[rightIndex++];
    }
  }

  while (leftIndex <= midIndex) {
    temp1[index] = arr1[leftIndex];
    temp2[index++] = arr2[leftIndex++];
  }

  while (rightIndex <= lastIndex) {
    temp1[index] = arr1[rightIndex];
    temp2[index++] = arr2[rightIndex++];
  }

  for (int i = firstIndex; i <= lastIndex; i++) {
    arr1[i] = temp1[i];
    arr2[i] = temp2[i];
  }
}

void mergeSort(int* arr1, int* arr2, int firstIndex, int lastIndex) {
  if (firstIndex < lastIndex) {
    int midIndex = (firstIndex + lastIndex) / 2;
    mergeSort(arr1, arr2, firstIndex, midIndex);
    mergeSort(arr1, arr2, midIndex + 1, lastIndex);
    merge(arr1, arr2, firstIndex, lastIndex);
  }
}

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d %d", &bagWeight, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &weight[i], &price[i]);
  }

  mergeSort(price, weight, 0, n - 1);

  // for (int i = 0; i < n; i++) {
  //   printf("%d %d\n", weight[i], price[i]);
  // }

  for (int i = 0; i < n; i++) {
    if (weight[i] >= bagWeight) {
      result += bagWeight * price[i];
      break;
    } else {
      result += weight[i] * price[i];
      bagWeight -= weight[i];
    }
  }

  printf("%d\n", result);

  return 0;
}
