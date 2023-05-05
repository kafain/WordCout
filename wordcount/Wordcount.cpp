#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    char *control_param = argv[1]; // 控制参数
    char *filename = argv[2]; // 输入文件名
    if (argc != 3) {
        printf("参数有误！应为 [parameter] [input_file_name]\n");
        return -1;
    }
    if (strcmp(control_param, "-c") != 0 && strcmp(control_param, "-w") != 0) {
        printf("控制参数有误！应为 -c 或 -w\n");
        return -1;
    }
    FILE *fp; // 文件指针
    char buffer[MAX_LEN];
    int char_count = 0; // 统计字符数
    int word_count = 0; // 统计单词数
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", filename);
        return -1;
    }
    while (fgets(buffer, MAX_LEN, fp)) { // 一行一行地读取文件内容
        int len = strlen(buffer);
        char_count += len; // 统计字符数
        for (int i = 0; i < len; i++) {
            if (buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '\n' || buffer[i] == '\t') {
                word_count++; // 统计单词数
            }
        }
    }
    fclose(fp);
    if (strcmp(control_param, "-c") == 0) {
        printf("字符数：%d\n", char_count);
    } else {
        printf("单词数：%d\n", word_count);
    }
    return 0;
}
