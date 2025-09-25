# WSAAddressToStringW function

## Description

The
**WSAAddressToString** function converts all components of a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure into a human-readable string representation of the address.

This is intended to be used mainly for display purposes. If the caller requires that the translation to be performed by a particular provider, it should supply the corresponding
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure in the *lpProtocolInfo* parameter.

## Parameters

### `lpsaAddress` [in]

A pointer to the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure to translate into a string.

### `dwAddressLength` [in]

The length, in bytes, of the address in the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *lpsaAddress* parameter. The *dwAddressLength* parameter may vary in size with different protocols.

### `lpProtocolInfo` [in, optional]

A pointer to the
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for a particular provider. If this is parameter is **NULL**, the call is routed to the provider of the first protocol supporting the address family indicated in the *lpsaAddress* parameter.

### `lpszAddressString` [in, out]

A pointer to the buffer that receives the human-readable address string.

### `lpdwAddressStringLength` [in, out]

On input, this parameter specifies the length of the buffer pointed to by the *lpszAddressString* parameter. The length is represented in bytes for ANSI strings, and in WCHARs for Unicode strings. On output, this parameter returns the length of the string including the **NULL** terminator actually copied into the buffer pointed to by the *lpszAddressString* parameter. If the specified buffer is not large enough, the function fails with a specific error of
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and this parameter is updated with the required size.

## Return value

If no error occurs,
**WSAAddressToString** returns a value of zero. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified *lpcsAddress*, *lpProtocolInfo*, and *lpszAddressString* parameters point to memory that is not all in the address space of the process, or the buffer pointed to by the *lpszAddressString* parameter is too small. Pass in a larger buffer. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid parameter was passed. This error is returned if the *lpsaAddress*, *dwAddressLength*, or *lpdwAddressStringLength* parameter are **NULL**. This error is also returned if the specified address is not a valid socket address, or no transport provider supports the indicated address family. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The Winsock 2 DLL has not been initialized. The application must first call [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) before calling any Windows Sockets functions. |

## Remarks

The
**WSAAddressToString** function provides a protocol-independent address-to-string translation. The
**WSAAddressToString** function takes a socket address structure pointed to by the *lpsaAddress* parameter and returns a pointer to **NULL**-terminated string that represents the socket address in the *lpszAddressString* parameter. While the [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) function works only with IPv4 addresses, the **WSAAddressToString** function works with any socket address supported by a Winsock provider on the local computer including IPv6 addresses.

If the *lpsaAddress* parameter points to an IPv4 socket address (the address family is **AF_INET**), then the address string returned in the buffer pointed to by the *lpszAddressString* parameter is in dotted-decimal notation as in "192.168.16.0", an example of an IPv4 address in dotted-decimal notation.

If the *lpsaAddress* parameter points to an IPv6 socket address (the address family is **AF_INET6**), then the address string returned in the buffer pointed to by the *lpszAddressString* parameter is in Internet standard format. The basic string representation consists of 8 hexadecimal numbers separated by colons. A string of consecutive zero numbers is replaced with a double-colon. There can only be one double-colon in the string representation of the IPv6 address.

If the length of the buffer pointed to by the *lpszAddressString* parameter is not large enough to receive the string representation of the socket address, **WSAAddressToString** returns
[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Support for IPv6 addresses using the **WSAAddressToString** function was added on Windows XP with Service Pack 1 (SP1) and later. IPv6 must also be installed on the local computer for the **WSAAddressToString** function to support IPv6 addresses.

**Windows Phone 8:** The **WSAAddressToStringW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSAAddressToStringW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSAAddressToString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

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

[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa)

[WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup)

[WSAStringToAddress](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsastringtoaddressa)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)