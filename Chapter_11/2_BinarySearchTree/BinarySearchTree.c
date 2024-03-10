#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <stdio.h>

// 이진 탐색 트리에 저장할 데이터의 자료형
typedef BTData BSTData;

// 이진 탐색 트리 생성 및 초기화
// - pRoot : BTreeNode의 루트 노드 자리를 가리키는 포인터
void BSTMakeAndInit(BTreeNode** pRoot)
{
    *pRoot = NULL;
};

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
    return GetData(bst);
};

// 이진 탐색 트리에 데이터 저장
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
    // 변수 할당
    BTreeNode* pNode = NULL;    // 부모 노드
    BTreeNode* cNode = *pRoot;  // 현재 위치의 노드
    BTreeNode* nNode = NULL;    // 새로 생성한 노드

    // 새로운 노드가 추가될 위치 반환
    while (cNode != NULL) // 현재 위치의 노드가 NULL이 될 때까지 반복
    {
        // 노드에 이미 저장된 데이터(중복 데이터)일 경우 return
        if (data == GetData(cNode))
            return;

        // 현재 노드를 부모 노드로 설정
        pNode = cNode;

        // 조건에 따라 이진 탐색 수행
        if (data < GetData(cNode)) // 현재 노드의 데이터보다 작을 경우
            cNode = GetLeftSubtree(cNode);  // 왼쪽 서브 트리 탐색
        else
            cNode = GetRightSubtree(cNode); // 오른쪽 서브 트리 탐색
    }

    // 새 노드 생성 및 데이터 저장
    nNode = MakeBTreeNode();    // 새 노드 생성
    SetData(nNode, data);       // 새 노드에 데이터 저장

    // pNode에 생성한 노드를 자식 노드로 추가
    if (pNode != NULL) // 새 노드가 루트 노드가 아니라면
    {
        if (data < GetData(pNode)) // 현재 노드의 데이터보다 작을 경우
            MakeLeftSubtree(pNode, nNode);  // 왼쪽에 노드 추가
        else
            MakeRightSubtree(pNode, nNode); // 오른쪽에 노드 추가
    }
    else    // 새 노드가 루트 노드라면
    {
        *pRoot = nNode; // 생성한 노드를 루트 노드로 설정
    }
};

// 이진 탐색 트리에서 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
    // 변수 할당
    BTreeNode* cNode = bst; // 현재 노드
    BSTData cdata;          // 현재 노드의 데이터

    // 말단 노드의 하위 노드에 도달할 때까지 반복
    while (cNode != NULL) // 현재 위치의 노드가 NULL이 될 때까지 반복
    {
        // 현재 노드의 데이터
        cdata = GetData(cNode);

        // 이진 탐색 트리의 데이터 탐색
        if (target == cdata) // 탐색에 성공할 경우
            return cNode;    // 해당 노드의 데이터 반환
        else if (target < cdata) // 찾을 데이터가 현재 노드의 데이터보다 작은 경우
            return GetLeftSubtree(cNode);   // 왼쪽 서브 트리 탐색
        else // 찾을 데이터가 현재 노드의 데이터보다 작은 경우
            return GetRightSubtree(cNode);  // 오른쪽 서브 트리 탐색
    }

    // 데이터를 발견하지 못한 경우
    return NULL;
};