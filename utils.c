#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "utils.h"

char printbuf[PAGE];

size_t read_data(char *path, void **dest) {
    int ret;
    struct stat stbuf;
    size_t len;

    int fd = open(path, S_IRUSR);
    ret = fstat(fd, &stbuf);
    len = stbuf.st_size;
    void *ptr = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
    ret = close(fd);

    *dest = ptr;
    return len;
}

size_t read_line(void *_data, size_t idx, char *dest) {
    char *data = (char*) _data;
    char byte;

    while ((byte = data[idx++]) != '\n') {
        *dest = byte;
        dest++;
    }

    return idx;
}

