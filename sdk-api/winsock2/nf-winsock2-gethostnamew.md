# GetHostNameW function

## Description

The
**GetHostNameW** function retrieves the standard host name for the local computer as a Unicode string.

## Parameters

### `name` [out]

A pointer to a buffer that receives the local host name as a **null**-terminated Unicode string.

### `namelen` [in]

The length, in wide characters, of the buffer pointed to by the *name* parameter.

## Return value

If no error occurs,
**GetHostNameW** returns zero. Otherwise, it returns **SOCKET_ERROR** and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* parameter is a **NULL** pointer or is not a valid part of the user address space. This error is also returned if the buffer size specified by *namelen* parameter is too small to hold the complete host name. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |

## Remarks

The
**GetHostNameW** function returns the name of the local host into the buffer specified by the *name* parameter in Unicode (UTF-16). The host name is returned as a **null**-terminated Unicode string. The form of the host name is dependent on the Windows Sockets provider—it can be a simple host name, or it can be a fully qualified domain name. However, it is guaranteed that the name returned will be successfully parsed by
[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow).

With the growth of the Internet, there is a growing need to identify Internet host names for other languages not represented by the ASCII character set. Identifiers which facilitate this need and allow non-ASCII characters (Unicode) to be represented as special ASCII character strings (Punycode) are known as Internationalized Domain Names (IDNs). A mechanism called
Internationalizing Domain Names in Applications (IDNA) is used to handle
IDNs in a standard fashion. The **GetHostNameW** function does not convert the local hostname between Punycode and Unicode. The [GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) function provides support for Internationalized Domain Name (IDN) parsing and performs Punycode/IDN encoding and conversion.

If the
**GetHostNameW** function is used on a cluster resource on Windows Server 2012 and the _CLUSTER_NETWORK_NAME_ environment variable is defined, then the value in this environment variable overrides the actual hostname and is returned. On a cluster resource, the _CLUSTER_NETWORK_NAME_ environment variable contains the name of the cluster.

The
**GetHostNameW** function queries namespace providers to determine the local host name using the SVCID_HOSTNAME GUID defined in the *Svgguid.h* header file. If no namespace provider responds, then the
**GetHostNameW** function returns the NetBIOS name of the local computer in Unicode.

The maximum length, in wide characters, of the string returned in the buffer pointed to by the *name* parameter is dependent on the namespace provider, but this string must be 256 wide characters or less. So if a buffer of 256 wide characters is passed in the *name* parameter and the *namelen* parameter is set to 256, the buffer size will always be adequate.

**Note** If no local host name has been configured,
**GetHostNameW** must succeed and return a token host name that
[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow) can resolve.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[GetAddrInfoW](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfow)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[gethostname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-gethostname)