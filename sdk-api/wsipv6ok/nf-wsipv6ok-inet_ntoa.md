# inet_ntoa macro

## Description

The
**inet_ntoa** function converts an (Ipv4) Internet network address into an ASCII string in Internet standard dotted-decimal format.

## Parameters

### `a` [in]

An
[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure that represents an Internet host address.

## Remarks

The
**inet_ntoa** function takes an Internet address structure specified by the *in* parameter and returns a **NULL**-terminated ASCII string that represents the address in "." (dot) notation as in "192.168.16.0", an example of an IPv4 address in dotted-decimal notation. The string returned by
**inet_ntoa** resides in memory that is allocated by Windows Sockets. The application should not make any assumptions about the way in which the memory is allocated. The string returned is guaranteed to be valid only until the next Windows Sockets function call is made within the same thread. Therefore, the data should be copied before another Windows Sockets call is made.

The
[WSAAddressToString](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaddresstostringa) function can be used to convert a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure containing an IPv4 address to a string representation of an IPv4 address in Internet standard dotted-decimal notation. The advantage of the **WSAAddressToString** function is that it supports both IPv4 and IPv6 addresses. Another advantage of the **WSAAddressToString** function is that there are both ASCII and Unicode versions of this function.

On Windows Vista and later, the [RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa) function can be used to convert an IPv4 address represented as an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure to a string representation of an IPv4 address in Internet standard dotted-decimal notation. On Windows Vista and later, the [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) function can be used to convert an IPv6 address represented as an **IN6_ADDR** structure to a string representation of an IPv6 address.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

**IN6_ADDR**

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[WSAAddressToString](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaddresstostringa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)