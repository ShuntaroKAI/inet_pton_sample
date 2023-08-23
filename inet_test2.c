#include <arpa/inet.h>
#include <stdio.h>

void check_ipv6_address(const char* addr)
{
    unsigned char bin_ipv6[sizeof(struct in6_addr)];

    printf("%sは", addr);
    if (0 < inet_pton(AF_INET6, addr, &bin_ipv6) )
    {
        printf("IPv6アドレスです。\n");
    }
    else
    {
        printf("IPv6アドレスではありません。\n");
    }
}

int main(int argc, char *argv[]) {
    check_ipv6_address("1:2:3:4:A:B:C:D");
    check_ipv6_address("0001:0002:0003:0004:000A:000B:000C:000D");
    check_ipv6_address("::");
    check_ipv6_address("127.0.0.1");
    check_ipv6_address("1::2::3");
    
    return 0;
}