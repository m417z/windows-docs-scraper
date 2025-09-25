# InetPtonW function

## Description

The
**InetPton** function converts an IPv4 or IPv6 Internet network address in its standard text presentation form into its numeric binary form. The ANSI version of this function is **inet_pton**.

## Parameters

### `Family` [in]

The address family.

Possible values for the address family are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

The values currently supported are **AF_INET** and **AF_INET6**.

| Value | Meaning |
| --- | --- |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, the *pszAddrString* parameter must point to a text representation of an IPv4 address and the *pAddrBuf* parameter returns a pointer to an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure that represents the IPv4 address. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, the *pszAddrString* parameter must point to a text representation of an IPv6 address and the *pAddrBuf* parameter returns a pointer to an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure that represents the IPv6 address. |

### `pszAddrString` [in]

A pointer to the **NULL**-terminated string that contains the text representation of the IP address to convert to numeric binary form.

When the *Family* parameter is **AF_INET**, then the *pszAddrString* parameter must point to a text representation of an IPv4 address in standard dotted-decimal notation.

When the *Family* parameter is **AF_INET6**, then the *pszAddrString* parameter must point to a text representation of an IPv6 address in standard notation.

### `pAddrBuf` [out]

A pointer to a buffer in which to store the numeric binary representation of the IP address. The IP address is returned in network byte order.

When the *Family* parameter is **AF_INET**, this buffer should be large enough to hold an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure.

When the *Family* parameter is **AF_INET6**, this buffer should be large enough to hold an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure.

## Return value

If no error occurs,
the **InetPton** function returns a value of 1 and the buffer pointed to by the *pAddrBuf* parameter contains the binary numeric IP address in network byte order.

The **InetPton** function returns a value of 0 if the *pAddrBuf* parameter points to a string that is not a valid IPv4 dotted-decimal string or a valid IPv6 address string. Otherwise, a value of -1 is returned, and a specific error code can be retrieved by calling the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) for extended error information.

If the function has an error, the extended error code returned by [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) can be one of the following values.

| Error code | Meaning |
| --- | --- |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The address family specified in the *Family* parameter is not supported. This error is returned if the *Family* parameter specified was not **AF_INET** or **AF_INET6**. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *pszAddrString* or *pAddrBuf* parameters are **NULL** or are not part of the user address space. |

## Remarks

The
**InetPton** function is supported on Windows Vista and later.

The
**InetPton** function provides a protocol-independent conversion of an Internet network address in its standard text presentation form into its numeric binary form. The
**InetPton** function takes a text representation of an Internet address pointed to by the *pszAddrString* parameter and returns a pointer to the numeric binary IP address in the *pAddrBuf* parameter. While the [inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr) function works only with IPv4 address strings, the **InetPton** function works with either IPv4 or IPv6 address strings.

The ANSI version of this function is **inet_pton** as defined in RFC 2553. For more information, see RFC 2553 available at the [IETF website](http://tools.ietf.org/html/rfc2553).

The
**InetPton** function does not require that the Windows Sockets DLL be loaded to perform conversion of a text string that represents an IP address to a numeric binary IP address.

If the *Family* parameter specified is **AF_INET**, then the *pszAddrString* parameter must point a text string of an IPv4 address in dotted-decimal notation as in "192.168.16.0", an example of an IPv4 address in dotted-decimal notation.

If the *Family* parameter specified is **AF_INET6**, then the *pszAddrString* parameter must point a text string of an IPv6 address in Internet standard format. The basic string representation consists of 8 hexadecimal numbers separated by colons. A string of consecutive zero numbers may be replaced with a double-colon. There can only be one double-colon in the string representation of the IPv6 address. The last 32 bits may be represented in IPv4-style dotted-octet notation if the address is a IPv4-compatible address.

When UNICODE or _UNICODE is defined, **InetPton** is defined to **InetPtonW**, the Unicode version of this function. The *pszAddrString* parameter is defined to the **PCWSTR** data type.

When UNICODE or _UNICODE is not defined, **InetPton** is defined to **InetPtonA**, the ANSI version of this function. The ANSI version of this function is always defined as [inet_pton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw). The *pszAddrString* parameter is defined to the **PCSTR** data type.

The [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure is defined in the *Inaddr.h* header file.

The [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure is defined in the *In6addr.h* header file.

On Windows Vista and later, the [RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa) and [RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw) functions can be used to convert a text representation of an IPv4 address in Internet standard dotted-decimal notation to a numeric binary address represented as an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure. On Windows Vista and later, the [RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa) and [RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw) functions can be used to convert a string representation of an IPv6 address to a numeric binary IPv6 address represented as an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure. The **RtlIpv6StringToAddressEx** function is more flexible since it also converts a string representation of an IPv6 address that can include a scope ID and port in standard notation to a numeric binary form.

**Windows 8.1** and **Windows Server 2012 R2**: The **InetPtonW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))

[IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)