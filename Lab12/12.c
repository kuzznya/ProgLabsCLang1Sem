#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    int cur_arg = 1;
    if (argc <= 1) {
        printf("Not enough arguments");
        return 0;
    }

    FILE* dir_info = fopen("dir_info.txt", "w");
    while (cur_arg < argc) {
        mkdir(argv[cur_arg]);
        fputs("/", dir_info);
        fputs(argv[cur_arg++], dir_info);
        fputs("\n", dir_info);
    }
    fclose(dir_info);
    return 0;
}
