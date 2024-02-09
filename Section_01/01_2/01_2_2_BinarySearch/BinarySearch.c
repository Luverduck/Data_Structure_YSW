#include <stdio.h>

// 이진 탐색 (Binary Search)
int BinarySearch(int* arr, int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;
    while (first <= last)
    {
        mid = (first + last) / 2;   // 현재 루프에서 탐색 대상의 중앙 index

        if (target == arr[mid])      // 대상을 발견하면
        {
            return mid;             // 현재 루프에서 중앙 index 반환
        }
        else if (target < arr[mid]) // 중앙 index의 값이 대상보다 값이 크다면
        {
            last = mid - 1;
        }
        else                        // 중앙 index의 값이 대상보다 값이 작다면
        {
            first = mid + 1;
        }
    }
    return -1;                  // 그 외 -1 반환
}

int main()
{
    int arr[] = { 3, 5, 2, 4, 9 };
    int target = 9;
    int idx;

    idx = BinarySearch(arr, sizeof(arr) / sizeof(int) , target);

    if(idx == -1)
        printf("탐색 실패\n");
    else
        printf("발견한 요소의 인덱스 : %d\n", idx);

    return 0;
}