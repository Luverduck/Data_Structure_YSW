#include "SimpleHeap.h"
#include <stdlib.h>

// 힙 초기화
void HeapInit(Heap* pheap)
{
    // 저장된 데이터 수를 0으로 초기화
    pheap->numOfData = 0;
};

// 힙이 비어있는지 확인
int HIsEmpty(Heap* pheap)
{
    // 저장된 데이터의 수가 0이면 힙이 비어있다.
    if (pheap->numOfData == 0)
        return TRUE;
    else
        return FALSE;
};

// 부모 노드의 인덱스 반환
int GetParentIDX(int idx)
{
    // 부모 노드 인덱스 = 현재 노드 인덱스 / 2
    return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 반환
int GetLChildIDX(int idx)
{
    // 왼쪽 자식 노드 인덱스 = 현재 노드 인덱스 * 2
    return idx * 2;
}

// 오른쪽 자식 노드의 인덱스 반환
int GetRChildIDX(int idx)
{
    // 오른쪽 자식 노드 인덱스 = 왼쪽 자식 노드 인덱스 + 1
    return GetLChildIDX(idx) + 1;
}

// 두 자식 노드 중 우선순위가 높은 자식 노드의 인덱스 반환
int GetHiPriChildIDX(Heap* pheap, int idx)
{
    if (GetLChildIDX(idx) > pheap->numOfData) // 자식 노드가 없는 경우
        return 0;
    else if (GetLChildIDX(idx) == pheap->numOfData) // 왼쪽 자식 노드만 있는 경우
        return GetLChildIDX(idx);
    else
    {
        // 두 자식 노드 중 우선순위가 높은 자식 노드의 인덱스 반환
        if (pheap->heapArr[GetLChildIDX(idx)].priority < pheap->heapArr[GetRChildIDX(idx)].priority)
            return GetLChildIDX(idx);
        else
            return GetRChildIDX(idx);
    }
}

// 힙에 데이터 입력
void HInsert(Heap* pheap, HData data, Priority priority)
{
    // 노드 생성 및 초기화
    HeapElement newElement = {priority, data};
    // 생성한 노드의 인덱스 (삽입 위치)
    int idx = pheap->numOfData + 1;
    // 루트 노드에 도달할 때까지 반복
    while (idx != 1)
    {
        // 생성한 노드의 우선순위와 부모 노드의 우선순위 비교
        if (priority < (pheap->heapArr[GetParentIDX(idx)].priority)) // 생성한 노드의 우선순위가 높을 경우 (값이 작을 경우)
        {
            // 생성한 노드와 부모 노드의 위치 교환
            pheap->heapArr[idx] = pheap->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else // 생성한 노드의 우선순위가 낮을 경우
            break; // 위치 교환 중지
    }
    // 최종적으로 결정된 인덱스에 생성한 노드 저장
    pheap->heapArr[idx] = newElement;
    // 힙에 저장된 데이터의 갯수 증가
    pheap->numOfData++;
};

// 힙에서 데이터 출력
HData HDelete(Heap* pheap);