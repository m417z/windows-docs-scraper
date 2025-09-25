# RtlIpv6AddressToStringExA function

## Description

The **RtlIpv6AddressToStringEx** function converts an IPv6 address, scope ID, and port number to a string.

## Parameters

### `Address` [in]

The IPv6 address in network byte order.

### `ScopeId` [in]

The scope ID of the IPv6 address in network byte order. This parameter is optional.

### `Port` [in]

The port number in network byte order format. This parameter is optional.

### `AddressString` [out]

A pointer to the buffer to receive the **NULL**-terminated string representation of the IP address, scope ID, and port. This buffer should be large enough to hold at least INET6_ADDRSTRLEN characters. The INET6_ADDRSTRLEN value is defined in the *Ws2ipdef.h* header file.

### `AddressStringLength` [in, out]

On input, the number of characters that fit in the buffer pointed to by the *AddressString* parameter, including the NULL terminator.

On output, this parameter contains the number of characters actually written to the buffer pointed to by the *AddressString* parameter.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *AddressString* or *AddressStringLength* parameter. This error is also returned if the length of the buffer pointed to by the *AddressString* parameter is not large enough to receive the string representation of the IPv6 address, scope ID, and port. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv6AddressToStringEx** function is used to convert an IPv6 address, scope ID, and port number to the string representation of the IPv6 address in Internet format followed by a string representation of the scope ID followed by a string representation of the port. The scope ID and port number are optional parameters.

The basic string representation of the IPv6 address returned consists of 8 hexadecimal numbers separated by colons. A string of consecutive zero hexadecimal numbers is replaced with a double colon. There can only be one double colon in the string representation of the IPv6 address. The last 32 bits are represented in IPv4-style dotted-octet notation if the address is an IPv4-compatible address, an IPv4-mapped IPv6 address, or an ISATAP address. For more information, see section 5 of [RFC 5942](http://tools.ietf.org/html/rfc5952) published by the IETF.

If a scope ID is provided, the string representation of the scope ID is separated from the string representation of the IPv6 address by a percent character ('%'). If a port number is provided, the string representation of the IPv6 address and the scope ID are surrounded by square braces (a leading '[' character followed by the IPv6 address followed by a '% character followed by the scope ID with a trailing ']' character). The port number is represented as a colon following the right square brace character followed by the string representation of the port number in decimal.

**RtlIpv6AddressToStringEx** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform IP address to string conversion.

If the length of the buffer pointed to by the *AddressString* parameter is not large enough to receive the string representation of the IP address, scope ID, and port, **RtlIpv6AddressToStringEx** returns **ERROR_INVALID_PARAMETER** and sets the *AddressStringLength* parameter to the buffer length required.

When either UNICODE or _UNICODE is defined, **RtlIpv6AddressToStringEx** is defined to **RtlIpv6AddressToStringExW**, the Unicode version of this function. The *AddressString* parameter is defined to the PWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv6AddressToStringEx** is defined to **RtlIpv6AddressToStringExA**, the ANSI version of this function. The *AddressString* parameter is defined to the PSTR data type.

The **IN6_ADDR** structure is defined in the *In6addr.h* header file.

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)
[InetNtop](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_ntop)
[InetPton](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_pton)
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)
[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)
[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexa)
[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)
[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexa)
[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)
[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)
[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexa)
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)