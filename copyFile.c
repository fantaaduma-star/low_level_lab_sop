//
// Created by Natan on 10/25/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ERR(source) (perror(source), fprintf(stderr, "%s:%d\n", __FILE__, __LINE__), exit(EXIT_FAILURE))
#define FILE_BUF_LEN 256
void usage(const char *const pname)
{
    fprintf(stderr, "USAGE:%s path_1 path_2\n", pname);
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]) {
    if (argc != 3) { //poprawna ilość argumentów
        usage(argv[0]);
    }
    int sourceFile = open(argv[1], O_RDONLY);
    if (sourceFile == -1) {
        ERR("open");
    }
    int destinationFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (destinationFile == -1) {
        ERR("open");
    }
    char buffer[FILE_BUF_LEN];
    while (1) {
        ssize_t bytesRead = read(sourceFile, buffer, FILE_BUF_LEN);
        if (bytesRead == -1) {
            ERR("read");
        }
        if (bytesRead == 0) { //jeżeli nie przeczytał nic to wychodzimy
            break;
        }
        ssize_t bytesWritten = write(destinationFile, buffer, bytesRead);
        if (bytesWritten == -1) {
            ERR("write");
        }
    }
    int retClose1 = close(sourceFile); //zamykamy żródło
    if (retClose1 == -1) {
        ERR("close");
    }
    int retClose2 = close(destinationFile); //zamykamy Docelowy
    if (retClose2 == -1) {
        ERR("close");
    }
    return EXIT_SUCCESS;
}