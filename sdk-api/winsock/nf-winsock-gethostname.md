# gethostname function

## Description

The
**gethostname** function retrieves the standard host name for the local computer.

## Parameters

### `name` [out]

A pointer to a buffer that receives the local host name.

### `namelen` [in]

The length, in bytes, of the buffer pointed to by the *name* parameter.

## Return value

If no error occurs,
**gethostname** returns zero. Otherwise, it returns SOCKET_ERROR and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* parameter is a **NULL** pointer or is not a valid part of the user address space. This error is also returned if the buffer size specified by *namelen* parameter is too small to hold the complete host name. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |

## Remarks

The
**gethostname** function returns the name of the local host into the buffer specified by the *name* parameter. The host name is returned as a **null**-terminated string. The form of the host name is dependent on the Windows Sockets provider—it can be a simple host name, or it can be a fully qualified domain name. However, it is guaranteed that the name returned will be successfully parsed by
[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) and
[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname).

The maximum length of the name returned in the buffer pointed to by the *name* parameter is dependent on the namespace provider.

If the
**gethostname** function is used on a cluster resource on Windows Server 2008, Windows Server 2003, or
Windows 2000 Server and the _CLUSTER_NETWORK_NAME_ environment variable is defined, then the value in this environment variable overrides the actual hostname and is returned. On a cluster resource, the _CLUSTER_NETWORK_NAME_ environment variable contains the name of the cluster.

The
**gethostname** function queries namespace providers to determine the local host name using the SVCID_HOSTNAME GUID defined in the *Svgguid.h* header file. If no namespace provider responds, then the
**gethostname** function returns the NetBIOS name of the local computer.

The maximum length, in bytes, of the string returned in the buffer pointed to by the *name* parameter is dependent on the namespace provider, but this string must be 256 bytes or less. So if a buffer of 256 bytes is passed in the *name* parameter and the *namelen* parameter is set to 256, the buffer size will always be adequate.

**Note** If no local host name has been configured,
**gethostname** must succeed and return a token host name that
[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname) or
[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname) can resolve.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[WSAAsyncGetHostByName](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-wsaasyncgethostbyname)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[gethostbyname](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-gethostbyname)