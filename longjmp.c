#include <setjmp.h>
#include <stdio.h>


jmp_buf jb;

void func1()
{
    int ret;
    printf("func1, in\n");
    ret = setjmp(jb);
    printf("func1, out, ret=%d\n");
}

void func2()
{
    printf("func2, in\n");
    longjmp(jb, 5);
    printf("func2, out\n");
}

int main()
{
    printf("before func\n");
    func1();
    printf("in func\n");
    func2();
    printf("after func\n");
	return 0;
}
