#include <stdlib.h>

#define PAGE 4096

size_t read_data(char *path, void **dest);
size_t read_line(void *_data, size_t idx, char *dest);