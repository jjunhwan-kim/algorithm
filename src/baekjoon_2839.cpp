#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int n;
int sugar[5001];

int main() {
  scanf("%d", &n);

  sugar[1] = -1;
  sugar[2] = -1;
  sugar[3] = 1;
  sugar[4] = -1;
  sugar[5] = 1;

  for (int i = 6; i <= n; i++) {
    if (sugar[i - 3] == -1 && sugar[i - 5] == -1) {
      sugar[i] = -1;
    } else if (sugar[i - 3] != -1 && sugar[i - 5] == -1) {
      sugar[i] = sugar[i - 3] + 1;
    } else if (sugar[i - 3] == -1 && sugar[i - 5] != -1) {
      sugar[i] = sugar[i - 5] + 1;
    } else {
      sugar[i] = MIN(sugar[i - 3], sugar[i - 5]) + 1;
    }
  }

  if (sugar[n] == -1) {
    printf("-1\n");
  } else {
    printf("%d\n", sugar[n]);
  }

  return 0;
}