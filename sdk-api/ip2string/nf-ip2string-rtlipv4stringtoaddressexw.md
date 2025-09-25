# RtlIpv4StringToAddressExW function

## Description

The
**RtlIpv4StringToAddressEx** function converts a string representation of an IPv4 address and port number to a binary IPv4 address and port.

## Parameters

### `AddressString` [in]

A pointer to a buffer containing the **NULL**-terminated string representation of the IPv4 address followed by an optional colon and string representation of a port number.

### `Strict` [in]

A value that indicates whether the string must be an IPv4 address represented in strict four-part dotted-decimal notation. If this parameter is **TRUE**, the string must be dotted-decimal with four parts. If this parameter is **FALSE**, any of four forms are allowed for the string representation of the Ipv4 address, with decimal,
octal, or hexadecimal notation. See the Remarks section for details.

### `Address` [out]

A pointer where the binary representation of the IPv4 address is to be stored. The IPv4 address is stored in network byte order.

### `Port` [out]

A pointer where the binary representation of the port number is to be stored. The port number is returned in network byte order. If no port was specified in the string pointed to by the *AddressString* parameter, then the *Port* parameter is set to zero.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Strict* parameter was set to **TRUE**, but the string pointed to by the *AddressString* parameter did not contain a four-part dotted-decimal string representation of an IPv4 address. This error is also returned if the string pointed to by the *AddressString* parameter did not contain a proper string representation of an IPv4 address.<br><br>This error code is defined in the Ntstatus.h header file. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv4StringToAddressEx** function is used to convert a string representation of the IPv4 address and port number to a binary IPv4 address and a port number. The IPv4 address is returned in network order (bytes ordered from
left to right). The port number is returned in network order.

**RtlIpv4StringToAddressEx** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to IP address conversion.

If the *Strict* parameter is set to **TRUE**, then the string pointed to by the *AddressString* parameter must be in strict dotted-decimal notation. This strict format requires that four parts are specified. Each part is interpreted as a decimal byte of data
and assigned, from left to right, to the four bytes of an IPv4
address.

When the *Strict* parameter is set to **FALSE**, the string pointed to by the *AddressString* parameter may be in any of the several possible formats. When the buffer pointed to by *AddressString* parameter contains a three-part address string, the last part is interpreted
as a 16-bit quantity and placed in the right most two bytes of the
network address. This makes the three-part address format
convenient for specifying Class B network addresses as
"128.net.host". When the buffer pointed to by *AddressString* parameter contains a two-part address string, the last part is interpreted
as a 24-bit quantity and placed in the right most three bytes of the
network address. This makes the two part address format convenient
for specifying Class A network addresses as "net.host". When the buffer pointed to by *AddressString* parameter contains only a one-part address string, the value is stored directly in the
network address without any byte rearrangement.

The buffer pointed to by the *AddressString* parameter may contain the IPv4 address string followed by an optional colon and the string representation of a port number. If a port number string is included in the buffer pointed to by *AddressString* parameter, the binary representation of the port number is returned in the *Port* parameter. If the buffer pointed to by *AddressString* parameter does not contain a port number, a zero is returned in the *Port* parameter.

When either UNICODE or _UNICODE is defined, **RtlIpv4StringToAddressEx** is defined to **RtlIpv4StringToAddressExW**, the Unicode version of this function. The *AddressString* parameter is defined to the PCWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv4StringToAddressEx** is defined to **RtlIpv4StringToAddressExA**, the ANSI version of this function. The *AddressString* parameter is defined to the PCSTR data type.

The [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure is defined in the *Inaddr.h* header file.

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)