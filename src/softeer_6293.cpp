#include <stdio.h>
#define N 3000
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int n;
int height[N];
int len[N];
int max;

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &height[i]);
  }

  len[0] = 1;
  max = 1;

  for (int i = 1; i < n; i++) {
    len[i] = 1;
    for (int j = 0; j < i; j++) {
      if (height[i] > height[j]) {
        len[i] = MAX(len[i], len[j] + 1);
      }
    }
    max = MAX(max, len[i]);
  }

  printf("%d\n", max);
  return 0;
}