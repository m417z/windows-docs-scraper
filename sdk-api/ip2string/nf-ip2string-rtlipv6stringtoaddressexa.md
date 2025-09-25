# RtlIpv6StringToAddressExA function

## Description

The **RtlIpv6StringToAddressEx** function converts a string representation of an IPv6 address, scope ID, and port number to a binary IPv6 address, scope ID, and port.

## Parameters

### `AddressString` [in]

A pointer to a buffer containing the **NULL**-terminated string representation of the IPv6 address, scope ID, and port number.

### `Address` [out]

A pointer where the binary representation of the IPv6 address is to be stored.

### `ScopeId` [out]

A pointer to where scope ID of the IPv6 address is stored. If *AddressString* parameter does not contain the string representation of a scope ID, then zero is returned in this parameter.

### `Port` [out]

A pointer where the port number is stored. The port number is in network byte order format. If *AddressString* parameter does not contain the string representation of a port number, then zero is returned in this parameter.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the string pointed to by the *AddressString* parameter did not contain a proper string representation of an IPv6 address.<br><br>This error code is defined in the Ntstatus.h header file. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv6StringToAddressEx** function is used to convert a string representation of the IPv6 address, scope ID, and port number to a binary IPv6 address, scope ID, and port number. The IPv6 address is returned in network order (bytes ordered from left to right). The port number and scope ID are returned in network order.

**RtlIpv6StringToAddressEx** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to IP address conversion.

The string pointed to by the *AddressString* parameter must be represented in the form for an IPv6 address string followed by an optional percent character and scope ID string. The IPv6 address and scope ID string must be enclosed in square brackets. The right square bracket after the IPv6 address and scope ID string may be followed by an optional colon and a string representation of a port number. The basic string representation of an IPv6 address consists of 8 hexadecimal numbers separated by colons. A string of consecutive zero numbers may be replaced with a double-colon. There can only be one double-colon in the string representation of the IPv6 address. The last 32 bits may be represented in IPv4-style dotted-octet notation if the address is an IPv4-compatible address, an IPv4-mapped IPv6 address, or an ISATAP address. For more information, see section 5 of [RFC 5942](http://tools.ietf.org/html/rfc5952) published by the IETF.

When either UNICODE or _UNICODE is defined, **RtlIpv6StringToAddressEx** is defined to **RtlIpv6StringToAddressExW**, the Unicode version of this function. The *AddressString* parameter is defined to the PCWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv6StringToAddressEx** is defined to **RtlIpv6StringToAddressExA**, the ANSI version of this function. The *AddressString* parameter is defined to the PCSTR data type.

The [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure is defined in the In6addr.h header file.

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)
[IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))
[InetNtop](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_ntop)
[InetPton](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_pton)
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)
[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)
[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexa)
[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)
[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexa)
[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)
[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexa)
[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)