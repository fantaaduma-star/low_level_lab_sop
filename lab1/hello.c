#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))

int main(void)
{
    pid_t pid = getpid();
    if (printf("Hello z SOP, PID = %d\n", pid) < 0)
        ERR("printf");
    return EXIT_SUCCESS;
}
