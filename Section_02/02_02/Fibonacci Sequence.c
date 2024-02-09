// Chapter 02. 재귀 (Recursion)
// 02-2. 재귀의 활용
/*
    피보나치 수열 (Fibonacci Sequence)
    f(n+2) = f(n+1) + f(n)
    0, 1, 1, 2, 3, 5, 8, 13, ...
*/

int fibonacci(int n)
{
    // 1번째 항과 2번째 항의 값은 정해져 있음
    if(n == 1) 
        return 0;
    else if(n == 2) 
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

#include <stdio.h>
int main()
{
    int num = 10;
    int result;

    // 피보나치 함수 호출
    result = fibonacci(num);

    // 결과
    printf("Fibonacci of %d : %d", num, result);
}