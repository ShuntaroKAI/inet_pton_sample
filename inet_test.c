#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char bin_ipv4[sizeof(struct in_addr)];

    inet_pton(AF_INET, "127.0.0.1", &bin_ipv4);

    printf("127.0.0.1\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\t%dバイト目:%d\n", i, bin_ipv4[i]);
    }
    
    unsigned char bin_ipv6[sizeof(struct in6_addr)];
    inet_pton(AF_INET6, "1:2:3:4:5:6:7:8", &bin_ipv6);

    printf("1:2:3:4:5:6:7:8\n");
    for (int i = 0; i < 16; i++)
    {
        printf("\t%dバイト目:%d\n", i, bin_ipv6[i]);
    }
    
    return 0;
}