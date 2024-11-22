#include <stdio.h>
#define N 20
#define M 3
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int n, m;
int map[N + 2][N + 2];
int visit[N + 2][N + 2];
int startY[M], startX[M];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int max;

void move(int order, int id, int y, int x, int sum) {
  visit[y][x] = 1;
  sum += map[y][x];

  if (order < 3) {
    for (int i = 0; i < 4; i++) {
      int nextY = y + dy[i];
      int nextX = x + dx[i];

      if ((nextY == startY[1] && nextX == startX[1]) ||
          (nextY == startY[2] && nextX == startX[2])) {
        continue;
      }

      if (map[nextY][nextX] && !visit[nextY][nextX]) {
        move(order + 1, id, nextY, nextX, sum);
      }
    }
  } else {
    if (id == 0 && m > 1) {
      move(0, 1, startY[1], startX[1], sum);
    } else if (id == 1 && m > 2) {
      move(0, 2, startY[2], startX[2], sum);
    } else {
      max = MAX(max, sum);
    }
  }

  visit[y][x] = 0;
}

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &map[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &startY[i], &startX[i]);
  }

  move(0, 0, startY[0], startX[0], 0);
  printf("%d\n", max);

  return 0;
}