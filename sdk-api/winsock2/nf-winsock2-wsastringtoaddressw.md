# WSAStringToAddressW function

## Description

The
**WSAStringToAddress** function converts a network address in its standard text presentation form into its numeric binary form in a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure, suitable for passing to Windows Sockets routines that take such a structure.

## Parameters

### `AddressString` [in]

A pointer to the zero-terminated string that contains the network address in standard text form to convert.

### `AddressFamily` [in]

The address family of the network address pointed to by the *AddressString* parameter.

### `lpProtocolInfo` [in, optional]

The
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure associated with the provider to be used. If this is **NULL**, the call is routed to the provider of the first protocol supporting the indicated *AddressFamily*.

### `lpAddress` [out]

A pointer to a buffer that is filled with a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure for the address string if the function succeeds.

### `lpAddressLength` [in, out]

A pointer to the length, in bytes, of the buffer pointed to by the *lpAddress* parameter. If the function call is successful, this parameter returns a pointer to the size of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure returned in the *lpAddress* parameter. If the specified buffer is not large enough, the function fails with a specific error of
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and this parameter is updated with the required size in bytes.

## Return value

The return value for
**WSAStringToAddress** is zero if the operation was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer pointed to by the *lpAddress* parameter is too small. Pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The functions was unable to translate the string into a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2). See the following Remarks section for more information. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The WS2_32.DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Socket functions. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There was insufficient memory to perform the operation. |

## Remarks

The
**WSAStringToAddress** function converts a network address in standard text form into its numeric binary form in a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure.

Any missing components of the address will be defaulted to a reasonable value, if possible. For example, a missing port number will default to zero. If the caller wants the translation to be done by a particular provider, it should supply the corresponding
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure in the *lpProtocolInfo* parameter.

The
**WSAStringToAddress** function fails (and returns WSAEINVAL) if the **sin_family** member of the [SOCKADDR_IN](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure, which is passed in the *lpAddress* parameter in the form of a
**sockaddr** structure, is not set to AF_INET or AF_INET6.

Support for IPv6 addresses using the **WSAStringToAddress** function was added on Windows XP with Service Pack 1 (SP1) and later. IPv6 must also be installed on the local computer for the **WSAStringToAddress** function to support IPv6 addresses.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSAStringToAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[WSAAddressToString](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaddresstostringa)

[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)