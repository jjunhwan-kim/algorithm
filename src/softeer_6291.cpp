#include <stdio.h>
#define N 1000000

typedef struct Lecture {
  int start;
  int end;
} Lecture;

int n;
Lecture lectures[N];

Lecture heap[N];
int heapCnt;

int compare(Lecture* a, Lecture* b) {
  if (a->end > b->end) {
    return false;
  } else if (a->end < b->end) {
    return true;
  } else {
    if (a->start > b->start) {
      return true;
    } else if (a->start < b->start) {
      return false;
    } else {
      return true;
    }
  }
}

void push(Lecture lecture) {
  if (heapCnt >= N) {
    printf("Push failed.\n");
    return;
  }

  heap[heapCnt++] = lecture;

  int index = heapCnt - 1;

  while (index > 0 && compare(&heap[index], &heap[(index - 1) / 2])) {
    Lecture temp = heap[index];
    heap[index] = heap[(index - 1) / 2];
    heap[(index - 1) / 2] = temp;
    index = (index - 1) / 2;
  }
}

void pop(Lecture* lecture) {
  if (heapCnt <= 0) {
    printf("Pop failed.\n");
    return;
  }

  (*lecture) = heap[0];
  heap[0] = heap[heapCnt - 1];
  heapCnt--;

  int index = 0;
  while (index * 2 + 1 <= heapCnt - 1) {
    int childIndex;
    if (index * 2 + 1 == heapCnt - 1) {
      childIndex = index * 2 + 1;
    } else {
      childIndex = compare(&heap[index * 2 + 1], &heap[index * 2 + 2])
                       ? index * 2 + 1
                       : index * 2 + 2;
    }

    if (compare(&heap[index], &heap[childIndex])) {
      break;
    }

    Lecture temp = heap[index];
    heap[index] = heap[childIndex];
    heap[childIndex] = temp;
    index = childIndex;
  }
}

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &lectures[i].start, &lectures[i].end);
    push(lectures[i]);
  }

  int end = 0;
  int cnt = 0;
  while (heapCnt) {
    Lecture lecture;
    pop(&lecture);

    if (lecture.start >= end) {
      end = lecture.end;
      cnt++;
    }
  }

  printf("%d\n", cnt);

  return 0;
}