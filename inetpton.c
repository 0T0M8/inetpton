/* 
 * This function converts the character string src into a network
 * address structure in the af address family, then copies the
 * network address structure to dst. af argument must be either
 * AF_INET or AF_INET6.  dst is written in network byte order.

 * program converts presentation(human-readable) -> binary
 * then from binary(network-byte-order) to presentation

 * lawrencelipenga 0ct-2-2026
 */
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct in_addr addr;
    char str[INET_ADDRSTRLEN];

    const char *ip = "192.168.1.10";

    /*
     * Convert IPv4 address from
     * presentation format to network format.
     */
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        perror("inet_pton");
        return 1;
    }

    /*
     * Convert it back from
     * network format to presentation format.
     */
    if (inet_ntop(AF_INET, &addr, str, sizeof(str)) == NULL) {
        perror("inet_ntop");
        return 1;
    }

    printf("IP address: %s\n", str);

    return 0;
}
