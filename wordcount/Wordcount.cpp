#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    char *control_param = argv[1]; // ���Ʋ���
    char *filename = argv[2]; // �����ļ���
    if (argc != 3) {
        printf("��������ӦΪ [parameter] [input_file_name]\n");
        return -1;
    }
    if (strcmp(control_param, "-c") != 0 && strcmp(control_param, "-w") != 0) {
        printf("���Ʋ�������ӦΪ -c �� -w\n");
        return -1;
    }
    FILE *fp; // �ļ�ָ��
    char buffer[MAX_LEN];
    int char_count = 0; // ͳ���ַ���
    int word_count = 0; // ͳ�Ƶ�����
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return -1;
    }
    while (fgets(buffer, MAX_LEN, fp)) { // һ��һ�еض�ȡ�ļ�����
        int len = strlen(buffer);
        char_count += len; // ͳ���ַ���
        for (int i = 0; i < len; i++) {
            if (buffer[i] == ' ' || buffer[i] == ',' || buffer[i] == '\n' || buffer[i] == '\t') {
                word_count++; // ͳ�Ƶ�����
            }
        }
    }
    fclose(fp);
    if (strcmp(control_param, "-c") == 0) {
        printf("�ַ�����%d\n", char_count);
    } else {
        printf("��������%d\n", word_count);
    }
    return 0;
}
