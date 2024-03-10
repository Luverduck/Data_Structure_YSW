// Chapter 11. 탐색 (Search)
// 11-2. 이진 탐색 트리

#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
    // 변수 선언
    BTreeNode* bstRoot;
    BTreeNode* sNode;

    // 이진 탐색 트리 초기화
    BSTMakeAndInit(&bstRoot);

    // 이진 팀색 트리에 데이터 저장
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    // 이진 탐색 트리에서 데이터 탐색
    sNode = BSTSearch(bstRoot, 1);
    if (sNode == NULL)
        printf("탐색 실패\n");
    else
        printf("탐색에 성공한 키의 값 : %d\n", BSTGetNodeData(sNode));

    return 0;
}