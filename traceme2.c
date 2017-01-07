#include <stdio.h>
#include <sys/ptrace.h>

int main()
{
    int offset = 0;

    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == 0)
    {
        offset = 2;
    }

    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
    {
        offset = offset * 3;
    }

    if (offset == 2 * 3)
    {
        printf("normal execution\n");
    }
    else
    {
        printf("don't trace me !!\n");
    }

    return 0;
}
