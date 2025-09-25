# gethostbyaddr macro

## Description

[**gethostbyaddr** is no longer recommended for use as of Windows Sockets 2. Instead, use [getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo).]

The
**gethostbyaddr** function retrieves the host information corresponding to a network address.

## Parameters

### `a` [in]

A pointer to an address in network byte order.

### `b` [in]

The length, in bytes, of the address.

### `c` [in]

The type of the address, such as the AF_INET address family type (used with TCP, UDP, and other associated Internet protocols). Possible values for the address family are defined in the Winsock2.h header file.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the possible values for the address family are defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Winsock2.h, and should never be used directly.

Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

The table below lists the possible values for address family that are supported.

| Value | Meaning |
| --- | --- |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_NETBIOS**<br><br>17 | The NetBIOS address family. This address family is only supported if a Windows Sockets provider for NetBIOS is installed. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |

## Remarks

The
**gethostbyaddr** function returns a pointer to the
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure that contains the name and address corresponding to the given network address.

The memory for the [hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure returned by the **gethostbyaddr** function is allocated internally by the Winsock DLL from thread local storage. Only a single **hostent** structure is allocated and used, no matter how many times the **gethostbyaddr** or [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) functions are called on the thread. The returned **hostent** structure must be copied to an application buffer if additional calls are to be made to the **gethostbyaddr** or **gethostbyname** functions on the same thread. Otherwise, the return value will be overwritten by subsequent **gethostbyaddr** or **gethostbyname** calls on the same thread. The internal memory allocated for the returned **hostent** structure is released by the Winsock DLL when the thread exits.

An application should not try to release the memory used by the returned [hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure. The application must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, so the application should copy any information it needs before issuing any other function calls to **gethostbyaddr** or [gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname).

Although
**gethostbyaddr** no longer recommended for use as of Windows Sockets 2 and the [getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo) function should be used,
**gethostbyaddr** is capable of returning a NetBIOS name;
**getnameinfo** is not. Developers requiring NetBIOS name resolution may need to use **gethostbyaddr** until their applications are completely independent of NetBIOS names.

**Note** The capability to perform reverse lookups using the **gethostbyaddr** function is convenient, but such lookups are considered inherently unreliable, and should be used only as a hint.

### Example Code

The following example demonstrates the use of the **gethostbyaddr** function.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwError;
    int i = 0;
    int bIpv6 = 0;

    struct hostent *remoteHost;
    char *host_addr;
    struct in_addr addr = { 0 };
    IN6_ADDR addr6;

    char **pAlias;

    // Validate the parameters
    if (argc < 2) {
        printf("usage: %s 4 ipv4address\n", argv[0]);
        printf(" or\n");
        printf("usage: %s 6 ipv6address\n", argv[0]);
        printf("  to return the hostname\n");
        printf("       %s 4 127.0.0.1\n", argv[0]);
        printf("       %s 6 0::1\n", argv[0]);
        return 1;
    }
    // Validate parameters
    if (atoi(argv[1]) == 4)
        bIpv6 = 0;
    else if (atoi(argv[1]) == 6)
        bIpv6 = 1;
    else {
        printf("usage: %s 4 ipv4address\n", argv[0]);
        printf(" or\n");
        printf("usage: %s 6 ipv6address\n", argv[0]);
        printf("  to return the hostname\n");
        printf("       %s 4 127.0.0.1\n", argv[0]);
        printf("       %s 6 0::1\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    host_addr = argv[2];

    printf("Calling gethostbyaddr with %s\n", host_addr);
    if (bIpv6 == 1) {
        {
            iResult = inet_pton(AF_INET6, host_addr, &addr6);
            if (iResult == 0) {
                printf("The IPv6 address entered must be a legal address\n");
                return 1;
            } else
                remoteHost = gethostbyaddr((char *) &addr6, 16, AF_INET6);
        }
    } else {
        addr.s_addr = inet_addr(host_addr);
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

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAAsyncGetHostByAddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyaddr)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname)

[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent)