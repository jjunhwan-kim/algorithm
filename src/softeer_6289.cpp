#include <stdio.h>
#define N 100000
#define M 100000

int n;
int m;

int weight[N + 1];
int max[N + 1];
int x, y;
int cnt;

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &weight[i]);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    if (weight[x] > weight[y]) {
      if (max[x] != -1) {
        max[x] = weight[x];
      }
      max[y] = -1;
    } else if (weight[y] > weight[x]) {
      if (max[y] != -1) {
        max[y] = weight[y];
      }
      max[x] = -1;
    } else {
      max[x] = max[y] = -1;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (max[i] > 0 || max[i] == 0) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}