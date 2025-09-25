# HOSTENT structure

## Description

The
**hostent** structure is used by functions to store information about a given host, such as host name, IPv4 address, and so forth. An application should never attempt to modify this structure or to free any of its components. Furthermore, only one copy of the
**hostent** structure is allocated per thread, and an application should therefore copy any information that it needs before issuing any other Windows Sockets API calls.

## Members

### `h_name`

The official name of the host (PC). If using the DNS or similar resolution system, it is the Fully Qualified Domain Name (FQDN) that caused the server to return a reply. If using a local hosts file, it is the first entry after the IPv4 address.

### `h_aliases`

A **NULL**-terminated array of alternate names.

### `h_addrtype`

The type of address being returned.

### `h_length`

The length, in bytes, of each address.

### `h_addr_list`

A **NULL**-terminated list of addresses for the host. Addresses are returned in network byte order. The macro **h_addr** is defined to be `h_addr_list[0]` for compatibility with older software.

## Remarks

The
[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr) and [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) functions returns a pointer to a
**hostent** structure—a structure allocated by Windows Sockets. The
**hostent** structure contains the results of a successful search for the host specified in the *name* parameter.

The memory for the **hostent** structure returned by the [gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr) and [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) functions is allocated internally by the Winsock DLL from thread local storage. Only a single **hostent** structure is allocated and used, no matter how many times the **gethostbyaddr** or **gethostbyname** functions are called on the thread. The returned **hostent** structure must be copied to an application buffer if additional calls are to be made to the **gethostbyaddr** or **gethostbyname** functions on the same thread. Otherwise, the return value will be overwritten by subsequent **gethostbyaddr** or **gethostbyname** calls on the same thread. The internal memory allocated for the returned **hostent** structure is released by the Winsock DLL when the thread exits.

An application should not try to release the memory used by the returned **hostent** structure. The application must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, so the application should copy any information it needs before issuing any other function calls to [gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr) or [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname).

#### Examples

The following examples demonstrates the use of the **hostent** structure with the [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) function.

```cpp
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment(lib, "ws2_32.lib")

int main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwError;
    int i = 0;

    struct hostent *remoteHost;
    char *host_name;
    struct in_addr addr;

    char **pAlias;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s ipv4address\n", argv[0]);
        printf(" or\n");
        printf("       %s hostname\n", argv[0]);
        printf("  to return the host\n");
        printf("       %s 127.0.0.1\n", argv[0]);
        printf("  to return the IP addresses for a host\n");
        printf("       %s www.contoso.com\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    host_name = argv[1];

// If the user input is an alpha name for the host, use gethostbyname()
// If not, get host by addr (assume IPv4)
    if (isalpha(host_name[0])) {        /* host address is a name */
        printf("Calling gethostbyname with %s\n", host_name);
        remoteHost = gethostbyname(host_name);
    } else {
        printf("Calling gethostbyaddr with %s\n", host_name);
        addr.s_addr = inet_addr(host_name);
        if (addr.s_addr == INADDR_NONE) {
            printf("The IPv4 address entered must be a legal address\n");
            return 1;
        } else
            remoteHost = gethostbyaddr((char *) &addr, 4, AF_INET);
    }

    if (remoteHost == NULL) {
        dwError = WSAGetLastError();
        if (dwError != 0) {
            if (dwError == WSAHOST_NOT_FOUND) {
                printf("Host not found\n");
                return 1;
            } else if (dwError == WSANO_DATA) {
                printf("No data record found\n");
                return 1;
            } else {
                printf("Function failed with error: %ld\n", dwError);
                return 1;
            }
        }
    } else {
        printf("Function returned:\n");
        printf("\tOfficial name: %s\n", remoteHost->h_name);
        for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++) {
            printf("\tAlternate name #%d: %s\n", ++i, *pAlias);
        }
        printf("\tAddress type: ");
        switch (remoteHost->h_addrtype) {
        case AF_INET:
            printf("AF_INET\n");
            break;
        case AF_INET6:
            printf("AF_INET6\n");
            break;
        case AF_NETBIOS:
            printf("AF_NETBIOS\n");
            break;
        default:
            printf(" %d\n", remoteHost->h_addrtype);
            break;
        }
        printf("\tAddress length: %d\n", remoteHost->h_length);

        if (remoteHost->h_addrtype == AF_INET) {
            while (remoteHost->h_addr_list[i] != 0) {
                addr.s_addr = *(u_long *) remoteHost->h_addr_list[i++];
                printf("\tIPv4 Address #%d: %s\n", i, inet_ntoa(addr));
            }
        } else if (remoteHost->h_addrtype == AF_INET6)
            printf("\tRemotehost is an IPv6 address\n");
    }

    return 0;
}

```

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr)

[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname)