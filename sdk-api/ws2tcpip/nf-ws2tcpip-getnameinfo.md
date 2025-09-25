# getnameinfo function

## Description

The
**getnameinfo** function provides protocol-independent name resolution from an address to an ANSI host name and from a port number to the ANSI service name.

## Parameters

### `pSockaddr` [in]

A pointer to a socket address structure that contains the address and port number of the socket. For IPv4, the *sa* parameter points to a
[sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. For IPv6, the *sa* parameter points to a **sockaddr_in6** structure.

### `SockaddrLength` [in]

The length, in bytes, of the structure pointed to by the *sa* parameter.

### `pNodeBuffer` [out]

A pointer to an ANSI string used to hold the host name. On success, the host name is returned as a Fully Qualified Domain Name (FQDN) by default. If the *host* parameter is **NULL**, this indicates the caller does not want to receive a host name string.

### `NodeBufferSize` [in]

The length, in bytes, of the buffer pointed to by the *host* parameter. The caller must provide a buffer large enough to hold the host name, including the terminating **NULL** character.

### `pServiceBuffer` [out]

A pointer to an ANSI string to hold the service name. On success, an ANSI string that represents the service name associated with the port number is returned. If the *serv* parameter is **NULL**, this indicates the caller does not want to receive a service name string.

### `ServiceBufferSize` [in]

The length, in bytes, of the buffer pointed to by the *serv* parameter. The caller must provide a buffer large enough to hold the service name, including the terminating **NULL** character.

### `Flags` [in]

A value used to customize processing of the
**getnameinfo** function. See the Remarks section.

## Return value

On success, **getnameinfo** returns zero. Any nonzero return value indicates failure and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

Nonzero error codes returned by the
**getnameinfo** function also map to the set of errors outlined by Internet Engineering Task Force (IETF) recommendations. The following table lists these error codes and their WSA equivalents. It is recommended that the WSA error codes be used, as they offer familiar and comprehensive error information for Winsock programmers.

| Error value | WSA equivalent | Description |
| --- | --- | --- |
| EAI_AGAIN | [WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A temporary failure in name resolution occurred. |
| EAI_BADFLAGS | [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | One or more invalid parameters was passed to the **getnameinfo** function. This error is returned if a host name was requested but the *hostlen* parameter was zero or if a service name was requested, but the *servlen* parameter was zero. |
| EAI_FAIL | [WSANO_RECOVERY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A nonrecoverable failure in name resolution occurred. |
| EAI_FAMILY | [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The **sa_family** member of socket address structure pointed to by the *sa* parameter is not supported. |
| EAI_MEMORY | [WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A memory allocation failure occurred. |
| EAI_NONAME | [WSAHOST_NOT_FOUND](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | A service name was requested, but no port number was found in the structure pointed to by the *sa* parameter or no service name matching the port number was found. NI_NAMEREQD is set and the host name cannot be located, or both the *host* and *serv* parameters were **NULL**. |

Use the
[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora) function to print error messages based on the EAI codes returned by the
**getnameinfo** function. The
**gai_strerror** function is provided for compliance with IETF recommendations, but it is not thread safe. Therefore, use of traditional Windows Sockets functions such as
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) is recommended.

In addition, the following error codes can be returned.

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This error is returned if the *sa* parameter is **NULL** or the *salen* parameter is less than the length required for the size of [sockaddr_in](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for IPv4 or the **sockaddr_in6** structure for IPv6. |

## Remarks

The **getnameinfo** function is the ANSI version of a function that provides protocol-independent name resolution. The **getnameinfo** function is used to translate the contents of a socket address structure to a node name and/or a service name.

For IPv6 and IPv4 protocols, Name resolution can be by the Domain Name System (DNS), a local *hosts* file, or by other naming mechanisms. This function can be used to determine the host name for an IPv4 or IPv6 address, a reverse DNS lookup, or determine the service name for a port number. The **getnameinfo** function can also be used to convert an IP address or a port number in a **sockaddr** structure to an ANSI string. This function can also be used to determine the IP address for a host name.

Another name that can be used for the **getnameinfo** function is **GetNameInfoA**. Macros in the *Ws2tcpip.h* header file define **GetNameInfoA** to **getnameinfo**.

The Unicode version of this function available on Windows XP with Service Pack 2 (SP2) and later is [GetNameInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfow).

Macros in the Winsock header file define a mixed-case function name of **GetNameInfo** that can be used when the application is targeted for Windows XP with SP2 and later (_WIN32_WINNT >= 0x0502). This **GetNameInfo** function should be called with the *host* and *serv* parameters of a pointer of type **TCHAR**. When UNICODE or _UNICODE is not defined, **GetNameInfo** is defined to the ANSI version and **getnameinfo** is called with the *host* and *serv* parameters of a pointer of type **char**. When UNICODE or _UNICODE is defined, **GetNameInfo** is defined to the Unicode version and [GetNameInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfow) is called with the *pNodeBuffer* and *pServiceBuffer* parameters of a pointer of type **PWCHAR**.

To simplify determining buffer requirements for the *host* and *serv* parameters, the following values for maximum host name length and maximum service name are defined in the *Ws2tcpip.h* header file.

```cpp
#define NI_MAXSERV    32
#define NI_MAXHOST  1025

```

The *flags* parameter can be used to customize processing of the
**getnameinfo** function. The following flags are available:

* NI_NOFQDN
* NI_NUMERICHOST
* NI_NAMEREQD
* NI_NUMERICSERV
* NI_DGRAM

When the **NI_NAMEREQD** flag is set, a host name that cannot be resolved by DNS results in an error.

Setting the **NI_NOFQDN** flag results in local hosts having only their Relative Distinguished Name (RDN) returned in the *host* parameter.

Setting the **NI_NUMERICHOST** flag returns the numeric form of the host name instead of its name. The numeric form of the host name is also returned if the host name cannot be resolved by DNS.

Setting the **NI_NUMERICSERV** flag returns the port number of the service instead of its name. Also, if a host name is not found for an IP address (127.0.0.2, for example), the hostname is returned as the IP address.

On Windows Vista and later, if **NI_NUMERICSERV** is not specified in the *flags* parameter and the port number contained in sockaddr structure pointed to by the *sa* parameter does not resolve to a well known service, the **getnameinfo** function returns the numeric form of the
service address (the port number) as a numeric string. When **NI_NUMERICSERV** is specified, the port number is returned as a numeric string. This behavior is specified in section 6.2 of RFC 3493. For more information, see [www.ietf.org/rfc3493.txt](https://www.ietf.org/rfc/rfc3493.txt)

On Windows Server 2003 and earlier, if **NI_NUMERICSERV** is not specified in the *flags* parameter, and the port number contained in the **sockaddr** structure pointed to by the *sa* parameter does not resolve to a well known service, the **getnameinfo** function fails. When **NI_NUMERICSERV** is specified, the port number is returned as a numeric string.

Setting the **NI_DGRAM** flag indicates that the service is a datagram service. This flag is necessary for the few services that provide different port numbers for UDP and TCP service.

**Note** The ability to perform reverse DNS lookups using the **getnameinfo** function is convenient, but such lookups are considered inherently unreliable, and should be used only as a hint.

**Note** The **getnameinfo** function cannot be used to resolve alias names.

### Example Code

The following code example shows how to use the **getnameinfo** function.

```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

// link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int __cdecl main(int argc, char **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData = {0};
    int iResult = 0;

    DWORD dwRetval;

    struct sockaddr_in saGNI;
    char hostname[NI_MAXHOST];
    char servInfo[NI_MAXSERV];
    u_short port = 27015;

    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s IPv4 address\n", argv[0]);
        printf("  to return hostname\n");
        printf("       %s 127.0.0.1\n", argv[0]);
        return 1;
    }
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }
    //-----------------------------------------
    // Set up sockaddr_in structure which is passed
    // to the getnameinfo function
    saGNI.sin_family = AF_INET;
    saGNI.sin_addr.s_addr = inet_addr(argv[1]);
    saGNI.sin_port = htons(port);

    //-----------------------------------------
    // Call getnameinfo
    dwRetval = getnameinfo((struct sockaddr *) &saGNI,
                           sizeof (struct sockaddr),
                           hostname,
                           NI_MAXHOST, servInfo, NI_MAXSERV, NI_NUMERICSERV);

    if (dwRetval != 0) {
        printf("getnameinfo failed with error # %ld\n", WSAGetLastError());
        return 1;
    } else {
        printf("getnameinfo returned hostname = %s\n", hostname);
        return 0;
    }
}

```

### Support for getnameinfo on older versions of Windows

The **getnameinfo** function was added to the *Ws2_32.dll* on Windows XP and later. If you want to execute an application using this function on earlier versions of Windows (Windows 2000, Windows NT, and Windows Me/98/95), then you need to include the *Ws2tcpip.h* file and also include the *Wspiapi.h* file. When the *Wspiapi.h* include file is added, the **getnameinfo** function is defined to the WspiapiGetNameInfo inline function in the *Wspiapi.h* file. At runtime, the WspiapiGetNameInfo function is implemented in such a way that if the *Ws2_32.dll* or the *Wship6.dll* (the file containing **getnameinfo** in the IPv6 Technology Preview for Windows 2000) does not include **getnameinfo**, then a version of **getnameinfo** is implemented inline based on code in the *Wspiapi.h* header file. This inline code will be used on older Windows platforms that do not natively support the **getnameinfo** function.

The IPv6 protocol is supported on Windows 2000 when the IPv6 Technology Preview for Windows 2000 is installed. Otherwise **getnameinfo** support on versions of Windows earlier than Windows XP is limited to handling IPv4 name resolution.

The [GetNameInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfow) function is the Unicode version of **getnameinfo**. The **GetNameInfoW** function was added to the *Ws2_32.dll* in Windows XP with SP2. The **GetNameInfoW** function cannot be used on versions of Windows earlier than Windows XP with SP2.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetNameInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getnameinfow)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[gai_strerror](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-gai_strerrora)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)