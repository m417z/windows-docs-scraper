# GetNameInfoW function

## Description

The
**GetNameInfoW** function provides protocol-independent name resolution from an address to a Unicode host name and from a port number to the Unicode service name.

## Parameters

### `pSockaddr` [in]

A pointer to a socket address structure containing the IP address and port number of the socket. For IPv4, the *pSockaddr* parameter points to a
[sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. For IPv6, the *pSockaddr* parameter points to a **sockaddr_in6** structure.

### `SockaddrLength` [in]

The length, in bytes, of the structure pointed to by the *pSockaddr* parameter.

### `pNodeBuffer` [out]

A pointer to a Unicode string to hold the host name. On success, a pointer to the Unicode host name is returned as a Fully Qualified Domain Name (FQDN) by default. If the *pNodeBuffer* parameter is **NULL**, this indicates the caller does not want to receive a host name string.

### `NodeBufferSize` [in]

The number of **WCHAR** characters in the buffer pointed to by the *pNodeBuffer* parameter. The caller must provide a buffer large enough to hold the Unicode host name, including the terminating **NULL** character.

### `pServiceBuffer` [out]

A pointer to a Unicode string to hold the service name. On success, a pointer is returned to a Unicode string representing the service name associated with the port number. If the *pServiceBuffer* parameter is **NULL**, this indicates the caller does not want to receive a service name string.

### `ServiceBufferSize` [in]

The number of **WCHAR** characters in the buffer pointed to by the *pServiceBuffer* parameter. The caller must provide a buffer large enough to hold the Unicode service name, including the terminating **NULL** character.

### `Flags` [in]

A value used to customize processing of the
**GetNameInfoW** function. See the Remarks section.

## Return value

On success, **GetNameInfoW** returns zero. Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Nonzero error codes returned by the
**GetNameInfoW** function also map to the set of errors outlined by Internet Engineering Task Force (IETF) recommendations. The following table shows these error codes and their WSA equivalents. It is recommended that the WSA error codes be used, as they offer familiar and comprehensive error information for Winsock programmers.

| Error value | WSA equivalent | Description |
| --- | --- | --- |
| EAI_AGAIN | [WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A temporary failure in name resolution occurred. |
| EAI_BADFLAGS | [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | One or more invalid parameters was passed to the **GetNameInfoW** function. This error is returned if a host name was requested but the *NodeBufferSize* parameter was zero or if a service name was requested but the *ServiceBufferSize* parameter was zero. |
| EAI_FAIL | [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A nonrecoverable failure in name resolution occurred. |
| EAI_FAMILY | [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **sa_family** member of socket address structure pointed to by the *pSockaddr* parameter is not supported. |
| EAI_MEMORY | [WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A memory allocation failure occurred. |
| EAI_NONAME | [WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A service name was requested, but no port number was found in the structure pointed to by the *pSockaddr* parameter or no service name matching the port number was found. NI_NAMEREQD is set and the host's name cannot be located, or both the *pNodeBuffer* and *pServiceBuffer* parameters were **NULL**. |

You can use the
[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora) function to print error messages based on the EAI codes returned by the
**GetNameInfoW** function. The
**gai_strerror** function is provided for compliance with IETF recommendations, but it is not thread safe. Therefore, use of traditional Windows Sockets functions such as
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) is recommended.

In addition, the following error codes can be returned.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This error is returned if the *pSockaddr* parameter is **NULL** or the *SockaddrLength* parameter is less than the length needed for the size of [sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for IPv4 or the **sockaddr_in6** structure for IPv6. |

## Remarks

The **GetNameInfoW** function is the Unicode version of a function that provides protocol-independent name resolution. The **GetNameInfoW** function is used to translate the contents of a socket address structure to a node name and/or a service name.

For the IPv6 and IPv4 protocols, name resolution can be by the Domain Name System (DNS), a local *hosts* file, or by other naming mechanisms. This function can be used to determine the host name for an IPv4 or IPv6 address, a reverse DNS lookup, or determine the service name for a port number. The **GetNameInfoW** function can also be used to convert an IP address or a port number in a **SOCKADDR** structure to an Unicode string. This function can also be used to determine the IP address for a host name.

The ANSI version of this function is [getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo).

Macros in the Winsock header file define a mixed-case function name of **GetNameInfo** that can be used when the application is targeted for Windows XP with Service Pack 2 (SP2) and later (_WIN32_WINNT >= 0x0502). This **GetNameInfo** function should be called with the *pNodeBuffer* and *pServiceBuffer* parameters of a pointer of type **TCHAR**. When UNICODE or _UNICODE is defined, **GetNameInfo** is defined to the Unicode version and **GetNameInfoW** is called with the *host* and *serv* parameters of a pointer of type **char**. When UNICODE or _UNICODE is not defined, **GetNameInfo** is defined to the ANSI version and [getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo) is called with the *pNodeBuffer* and *pServiceBuffer* parameters of a pointer of type **PWCHAR**.

To simplify determining buffer requirements for the *pNodeBuffer* and *pServiceBuffer* parameters, the following values for maximum host name length and maximum service name are defined in the *Ws2tcpip.h* header file:

```cpp
#include <windows.h>

#define NI_MAXSERV    32
#define NI_MAXHOST  1025

```

The *Flags* parameter can be used to customize processing of the
**GetNameInfoW** function. The following flags are available:

* NI_NOFQDN
* NI_NUMERICHOST
* NI_NAMEREQD
* NI_NUMERICSERV
* NI_DGRAM

When the **NI_NAMEREQD** flag is set, a host name that cannot be resolved by the DNS results in an error.

Setting the **NI_NOFQDN** flag results in local hosts having only their Relative Distinguished Name (RDN) returned in the *pNodeBuffer* parameter.

Setting the **NI_NUMERICHOST** flag returns the numeric form of the host name instead of its name. The numeric form of the host name is also returned if the host name cannot be resolved by DNS.

Setting the **NI_NUMERICSERV** flag returns the port number of the service instead of its name. Also, if a host name is not found for an IP address (127.0.0.2, for example), the hostname is returned as the IP address.

On Windows Vista and later, if **NI_NUMERICSERV** is not specified in the *flags* parameter, and the port number contained in **sockaddr** structure pointed to by the *sa* parameter does not resolve to a well known service, the **GetNameInfoW** function returns the numeric form of the
service address (the port number) as a numeric string. When **NI_NUMERICSERV** is specified, the port number is returned as a numeric string. This behavior is specified in section 6.2 of RFC 3493. For more information, see [www.ietf.org/rfc/rfc3493.txt](https://www.ietf.org/rfc/rfc3493.txt)

On Windows Server 2003 and earlier, if **NI_NUMERICSERV** is not specified in the *flags* parameter and the port number contained in sockaddr structure pointed to by the *sa* parameter does not resolve to a well known service, the **GetNameInfoW** function fails. When **NI_NUMERICSERV** is specified, the port number is returned as a numeric string.

Setting the **NI_DGRAM** flag indicates that the service is a datagram service. This flag is necessary for the few services that provide different port numbers for UDP and TCP service.

**Note** The capability to perform reverse DNS lookups using the **GetNameInfoW** function is convenient, but such lookups are considered inherently unreliable, and should be used only as a hint.

**Note** **GetNameInfoW** cannot be used to resolve alias names.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

### Example Code

The following example demonstrates the use of the **GetNameInfoW** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    DWORD dwRetval;

    struct sockaddr_in saGNI;
    WCHAR hostname[NI_MAXHOST];
    WCHAR servInfo[NI_MAXSERV];
    u_short port = 27015;

    // Validate the parameters
    if (argc != 2) {
        wprintf(L"usage: %s IPv4 address\n", argv[0]);
        wprintf(L"  to return hostname\n");
        wprintf(L"       %s 127.0.0.1\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }
    //-----------------------------------------
    // Set up sockaddr_in structure which is passed
    // to the getnameinfo function
    saGNI.sin_family = AF_INET;
    saGNI.sin_addr.s_addr = inet_addr(argv[1]);
    saGNI.sin_port = htons(port);

    //-----------------------------------------
    // Call GetNameInfoW
    dwRetval = GetNameInfoW((struct sockaddr *) &saGNI,
                           sizeof (struct sockaddr),
                           hostname,
                           NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV);

    if (dwRetval != 0) {
        wprintf(L"GetNameInfoW failed with error # %ld\n", WSAGetLastError());
        return 1;
    } else {
        wprintf(L"GetNameInfoW returned hostname = %ws\n", hostname);
        return 0;
    }
}

```

> [!NOTE]
> The ws2tcpip.h header defines GetNameInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[getnameinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfo)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)