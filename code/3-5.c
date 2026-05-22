#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    char bad_input[1024];

    while (!feof(fp)) {
        int res = fscanf(fp, "%d", &num);
        if (res == 1) {
            sum += num;
        }
        else if (res == 0) {
            if (fscanf(fp, "%1023s", bad_input) == 1) {
                fprintf(stderr, "invalid input %s\n", bad_input);
            }
        }
        else {
            break;
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
