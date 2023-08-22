#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //変換後のバイナリ、16バイト
    unsigned char buf[16];
    int domain, s;

    // ipv6を指定
    domain = AF_INET6;

    // 戻り値が
    // 正:正常終了
    // その他:エラー
    s = inet_pton(domain, "1:2:3:4:5:6:7:8", buf);
    if (s <= 0) {
        if (s == 0)
            fprintf(stderr, "Not in presentation format");
        else
            perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    printf("1:2:3:4:5:6:7:8\n");
    for (int i = 0; i < 8; i++)
    {
        printf("\t%d番目上位バイト:%d\n", i, buf[i*2]);
        printf("\t%d番目下位バイト:%d\n", i, buf[i*2+1]);
    }
    
    /*
    1:2:3:4:5:6:7:8
        0番目上位バイト:0
        0番目下位バイト:1
        1番目上位バイト:0
        1番目下位バイト:2
        2番目上位バイト:0
        2番目下位バイト:3
        3番目上位バイト:0
        3番目下位バイト:4
        4番目上位バイト:0
        4番目下位バイト:5
        5番目上位バイト:0
        5番目下位バイト:6
        6番目上位バイト:0
        6番目下位バイト:7
        7番目上位バイト:0
        7番目下位バイト:8
    */

    inet_pton(domain, "::1", buf);
    printf("::1\n");
    for (int i = 0; i < 8; i++)
    {
        printf("\t%d番目上位バイト:%d\n", i, buf[i*2]);
        printf("\t%d番目下位バイト:%d\n", i, buf[i*2+1]);
    }
    /*
    ::1
        0番目上位バイト:0
        0番目下位バイト:0
        1番目上位バイト:0
        1番目下位バイト:0
        2番目上位バイト:0
        2番目下位バイト:0
        3番目上位バイト:0
        3番目下位バイト:0
        4番目上位バイト:0
        4番目下位バイト:0
        5番目上位バイト:0
        5番目下位バイト:0
        6番目上位バイト:0
        6番目下位バイト:0
        7番目上位バイト:0
        7番目下位バイト:1
    */
    
    exit(EXIT_SUCCESS);
}