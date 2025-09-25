# gethostbyname function

## Description

The
**gethostbyname** function retrieves host information corresponding to a host name from a host database.

**Note** The
**gethostbyname** function has been deprecated by the introduction of the
[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function. Developers creating Windows Sockets 2 applications are urged to use the
**getaddrinfo** function instead of
**gethostbyname**.

## Parameters

### `name`

TBD

#### - a [in]

A pointer to the **null**-terminated name of the host to resolve.

## Return value

If no error occurs,
**gethostbyname** returns a pointer to the
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure described above. Otherwise, it returns a **null** pointer and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Authoritative answer host not found. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Nonauthoritative host not found, or server failure. |
| **[WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonrecoverable error occurred. |
| **[WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested name is valid, but no data of the requested type was found. This error is also returned if the *name* parameter contains a string representation of an IPv6 address or an illegal IPv4 address. <br><br>This error should not be interpreted to mean that the *name* parameter contains a name string that has been validated for a particular protocol (an IP hostname, for example). Since Winsock supports multiple name service providers, a name may potentially be valid for one provider and not accepted by another provider. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* parameter is not a valid part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |

## Remarks

The
**gethostbyname** function returns a pointer to a
[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure—a structure allocated by Windows Sockets. The
**hostent** structure contains the results of a successful search for the host specified in the *name* parameter.

If the host specified in the *name* parameter has both IPv4 and IPv6 addresses, only the IPv4 addresses will be returned. The **gethostbyname** function can only return IPv4 addresses for the *name* parameter. The [getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo) function and associated [addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa) structure should be used if IPv6 addresses for the host are required or if both IPv4 and IPv6 addresses for the host are required.

If the *name* parameter points to an empty string or *name* is **NULL**, the returned string is the same as the string returned by a successful
[gethostname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-gethostname) function call (the standard host name for the local computer).

If the *name* parameter contains a string representation of a legal IPv4 address, then the binary IPv4 address that represents the string is returned in the [hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure. The **h_name** member of the **hostent** structure contains the string representation of the IPv4 address and the **h_addr_list** contains the binary IPv4 address. If the *name* parameter contains a string representation of an IPv6 address or an illegal IPv4 address, then the **gethostbyname** function will fail and return [WSANO_DATA](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

The memory for the [hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure returned by the **gethostbyname** function is allocated internally by the Winsock DLL from thread local storage. Only a single **hostent** structure is allocated and used, no matter how many times the [gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr)
or **gethostbyname** functions are called on the thread. The returned **hostent** structure must be copied to an application buffer if additional calls are to be made to the **gethostbyname** or **gethostbyaddr** functions on the same thread. Otherwise, the return value will be overwritten by subsequent **gethostbyname** or **gethostbyaddr**
calls on the same thread. The internal memory allocated for the returned **hostent** structure is released by the Winsock DLL when the thread exits.

An application should not try to release the memory used by the returned [hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent) structure. The application must never attempt to modify this structure or to free any of its components. Furthermore, only one copy of this structure is allocated per thread, so the application should copy any information it needs before issuing any other function calls to **gethostbyname** or [gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr)
.

The
**gethostbyname** function cannot take an IP address string as a parameter passed to it in the *name* and resolve it to a host name. Such a request is treated exactly as a string representation of an IPv4 address or an unknown host name were passed. An application can use the [inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) to convert an IPv4 address string to a binary IPv4 address, then use another function,
[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr), to resolve the IPv4 address to a host name.

**Note** The **gethostbyname** function does not check the size of the *name* parameter before passing the buffer. With an improperly sized *name* parameter, heap corruption can occur.

### Example Code

The following examples demonstrates the use of the **gethostbyname** function.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>
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
        printf("usage: %s hostname\n", argv[0]);
        printf("  to return the IP addresses for the host\n");
        printf("       %s www.contoso.com\n", argv[0]);
        printf(" or\n");
        printf("       %s IPv4string\n", argv[0]);
        printf("  to return an IPv4 binary address for an IPv4string\n");
        printf("       %s 127.0.0.1\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }

    host_name = argv[1];

    printf("Calling gethostbyname with %s\n", host_name);
    remoteHost = gethostbyname(host_name);

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
        case AF_NETBIOS:
            printf("AF_NETBIOS\n");
            break;
        default:
            printf(" %d\n", remoteHost->h_addrtype);
            break;
        }
        printf("\tAddress length: %d\n", remoteHost->h_length);

        i = 0;
        if (remoteHost->h_addrtype == AF_INET)
        {
            while (remoteHost->h_addr_list[i] != 0) {
                addr.s_addr = *(u_long *) remoteHost->h_addr_list[i++];
                printf("\tIP Address #%d: %s\n", i, inet_ntoa(addr));
            }
        }
        else if (remoteHost->h_addrtype == AF_NETBIOS)
        {
            printf("NETBIOS address was returned\n");
        }
    }

    return 0;
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoEx](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfoexa)

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[addrinfo](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfoa)

[addrinfoW](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-addrinfow)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[gethostbyaddr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyaddr)

[gethostname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-gethostname)

[hostent](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-hostent)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)