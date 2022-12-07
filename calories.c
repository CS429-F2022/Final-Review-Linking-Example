#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

extern char printbuf[];

const int buf_size = 8;
int page_size = 4096;

void *data;
size_t len = 0;

size_t data_preprocess(void *data, size_t len) {
    size_t idx = 0, n_entries = 0;
    char buf[buf_size];
    while (idx < len) {
        buf[idx % 2] = ((char *)data)[idx];
        if (buf[0] == '\n' && buf[1] == '\n') {
            n_entries++;
        }
        idx++;
    }
    return n_entries;
}

int part1(void *data, size_t len, int *calorie_totals) {
    snprintf(printbuf, page_size, "----- Part 1 -----\n");
    printf("%s", printbuf);
    size_t idx = 0, cur_entry = 0;
    int max = 0;
    while (idx < len) {
        char line[8] = {0};
        idx = read_line(data, idx, line);
        int num = atoi(line);
        if (!num) {
            if (calorie_totals[cur_entry] > max) {
                max = calorie_totals[cur_entry];
            }
            cur_entry++;
        }
        else {
            calorie_totals[cur_entry] += atoi(line);
        }
    }
    snprintf(printbuf, page_size, "The highest number of calories is %d.\n", max);
    printf("%s", printbuf);
    return 0;
}

int part2(int *calorie_totals, size_t n_entries) {
    snprintf(printbuf, page_size, "----- Part 2 -----\n");
    printf("%s", printbuf);
    int top1 = 0, top2 = 0, top3 = 0, sum = 0;

    for (int i = 0; i < n_entries; i++) {
        if (calorie_totals[i] > top3) {
            if (calorie_totals[i] > top2) {
                if (calorie_totals[i] > top1) {
                    top3 = top2;
                    top2 = top1;
                    top1 = calorie_totals[i];
                }
                else {
                    top3 = top2;
                    top2 = calorie_totals[i];
                }
            }
            else {
                top3 = calorie_totals[i];
            }
        }
    }

    sum = top1 + top2 + top3;
    snprintf(printbuf, page_size, "The top 3 calorie totals are %d, %d, and %d.\n", top1, top2, top3);
    printf("%s", printbuf);
    snprintf(printbuf, page_size, "Their sum is %d.\n", sum);
    printf("%s", printbuf);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) printf("Usage: ./calories <file>\n");
    char *path = argv[1];
    len = read_data(path, &data);

    size_t n_entries = data_preprocess(data, len);
    int calorie_totals[n_entries];
    for (int i = 0; i < n_entries; i++) {
        calorie_totals[i] = 0;
    }

    part1(data, len, calorie_totals);
    part2(calorie_totals, n_entries);

    return EXIT_SUCCESS;
}
