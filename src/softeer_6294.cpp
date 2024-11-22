#include <stdio.h>
#define N 1000000
#define K 10000

int n, k;
int scores[N + 1];
int sum[N + 1];
int start[K], end[K];

int main() {
  // freopen("input.txt", "r", stdin);

  scanf("%d %d", &n, &k);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &scores[i]);
    sum[i] = sum[i - 1] + scores[i];
  }
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &start[i], &end[i]);
  }

  for (int i = 0; i < k; i++) {
    double averageScore = ((double)(sum[end[i]] - sum[start[i] - 1])) /
                          ((double)(end[i] - start[i] + 1));
    printf("%.2f\n", averageScore);
  }

  return 0;
}