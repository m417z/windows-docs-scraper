# InetNtopW function

## Description

The
**InetNtop** function converts an IPv4 or IPv6 Internet network address into a string in Internet standard format. The ANSI version of this function is **inet_ntop**.

## Parameters

### `Family` [in]

The address family.

Possible values for the address family are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

The values currently supported are **AF_INET** and **AF_INET6**.

| Value | Meaning |
| --- | --- |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. When this parameter is specified, this function returns an IPv4 address string. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. When this parameter is specified, this function returns an IPv6 address string. |

### `pAddr` [in]

A pointer to the IP address in network byte to convert to a string.

When the *Family* parameter is **AF_INET**, then the *pAddr* parameter must point to an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure with the IPv4 address to convert.

When the *Family* parameter is **AF_INET6**, then the *pAddr* parameter must point to an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure with the IPv6 address to convert.

### `pStringBuf` [out]

A pointer to a buffer in which to store the **NULL**-terminated string representation of the IP address.

For an IPv4 address, this buffer should be large enough to hold at least 16 characters.

For an IPv6 address, this buffer should be large enough to hold at least 46 characters.

### `StringBufSize` [in]

On input, the length, in characters, of the buffer pointed to by the *pStringBuf* parameter.

## Return value

If no error occurs,
**InetNtop** function returns a pointer to a buffer containing the string representation of IP address in standard format.

Otherwise, a value of **NULL** is returned, and a specific error code can be retrieved by calling the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) for extended error information.

If the function fails, the extended error code returned by [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) can be one of the following values.

| Error code | Meaning |
| --- | --- |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The address family specified in the *Family* parameter is not supported. This error is returned if the *Family* parameter specified was not **AF_INET** or **AF_INET6**. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *pStringBuf* or the *StringBufSize* parameter is zero. This error is also returned if the length of the buffer pointed to by the *pStringBuf* parameter is not large enough to receive the string representation of the IP address. |

## Remarks

The
**InetNtop** function is supported on Windows Vista and later.

The
**InetNtop** function provides a protocol-independent address-to-string translation. The
**InetNtop** function takes an Internet address structure specified by the *pAddr* parameter and returns a **NULL**-terminated string that represents the IP address. While the [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) function works only with IPv4 addresses, the **InetNtop** function works with either IPv4 or IPv6 addresses.

The ANSI version of this function is **inet_ntop** as defined in RFC 2553. For more information, see RFC 2553 available at the [IETF website](http://tools.ietf.org/html/rfc2553).

The
**InetNtop** function does not require that the Windows Sockets DLL be loaded to perform IP address to string conversion.

If the *Family* parameter specified is **AF_INET**, then the *pAddr* parameter must point to an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure with the IPv4 address to convert. The address string returned in the buffer pointed to by the *pStringBuf* parameter is in dotted-decimal notation as in "192.168.16.0", an example of an IPv4 address in dotted-decimal notation.

If the *Family* parameter specified is **AF_INET6**, then the *pAddr* parameter must point to an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure with the IPv6 address to convert. The address string returned in the buffer pointed to by the *pStringBuf* parameter is in Internet standard format. The basic string representation consists of 8 hexadecimal numbers separated by colons. A string of consecutive zero numbers is replaced with a double-colon. There can only be one double-colon in the string representation of the IPv6 address. The last 32 bits are represented in IPv4-style dotted-octet notation if the address is a IPv4-compatible address.

If the length of the buffer pointed to by the *pStringBuf* parameter is not large enough to receive the string representation of the IP address, **InetNtop** returns ERROR_INVALID_PARAMETER.

When UNICODE or _UNICODE is defined, **InetNtop** is defined to **InetNtopW**, the Unicode version of this function. The *pStringBuf* parameter is defined to the **PWSTR** data type.

When UNICODE or _UNICODE is not defined, **InetNtop** is defined to **InetNtopA**, the ANSI version of this function. The ANSI version of this function is always defined as **inet_ntop**. The *pStringBuf* parameter is defined to the **PSTR** data type.

The [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure is defined in the *Inaddr.h* header file.

The [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure is defined in the *In6addr.h* header file.

On Windows Vista and later, the [RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa) and [RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw) functions can be used to convert an IPv4 address represented as an [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure to a string representation of an IPv4 address in Internet standard dotted-decimal notation. On Windows Vista and later, the [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) and [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions can be used to convert an IPv6 address represented as an [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure to a string representation of an IPv6 address. The **RtlIpv6AddressToStringEx** function is more flexible since it also converts an IPv6 address, scope ID, and port to a IPv6 string in standard format.

**Windows 8.1** and **Windows Server 2012 R2**: The **InetNtopW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))

[IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

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