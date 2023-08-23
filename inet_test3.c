#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

void is_same_ipv6_address(const char* addr1, const char* addr2)
{
    unsigned char bin_addr1[sizeof(struct in6_addr)];
    unsigned char bin_addr2[sizeof(struct in6_addr)];

    inet_pton(AF_INET6, addr1, &bin_addr1);
    inet_pton(AF_INET6, addr2, &bin_addr2);

    printf("%sと%sは", addr1, addr2);
    if (0 == memcmp(bin_addr1, bin_addr2, 16) )
    {
        printf("同じアドレスです。\n");
    }
    else
    {
        printf("同じアドレスではありません。\n");
    }
}

int main(int argc, char *argv[]) {

    is_same_ipv6_address("2001:db8:0:0:1:0:0:1", "2001:DB8:0:0:1::1");
    is_same_ipv6_address("2001:db8:0:0:1:0:0:1", "2001:0db8::1:0:0:1");
    is_same_ipv6_address("::", "0:0:0:0:0:0:0:0");
    is_same_ipv6_address("1:2:3:4:5:6:7:8", "9:a:b:c:d:e:f:1");

    return 0;
}