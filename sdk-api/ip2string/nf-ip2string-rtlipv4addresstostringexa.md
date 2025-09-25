# RtlIpv4AddressToStringExA function

## Description

The **RtlIpv4AddressToStringEx** function converts an IPv4 address and port number to a string in Internet standard format.

## Parameters

### `Address` [in]

The IPv4 address in network byte order.

### `Port` [in]

The port number in network byte order format. This parameter is optional.

### `AddressString` [out]

A pointer to the buffer to receive the **NULL**-terminated string representation of the IPv4 address and port. This buffer should be large enough to hold at least INET_ADDRSTRLEN characters. The INET_ADDRSTRLEN value is defined in the *Ws2ipdef.h* header file.

### `AddressStringLength` [in, out]

On input, the number of characters that fit in the buffer pointed to by the *AddressString* parameter, including the NULL terminator.

On output, this parameter contains the number of characters actually written to the buffer pointed to by the *AddressString* parameter.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *AddressString* or *AddressStringLength* parameter. This error is also returned if the length of the buffer pointed to by the *AddressString* parameter is not large enough to receive the string representation of the IPv4 address and port. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv4AddressToStringEx** function is used to convert an IPv4 address and port number to the string representation of the IPv4 address in Internet dotted-decimal format followed by a colon character and a string representation of the port.

**RtlIpv4AddressToStringEx** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform IP address to string conversion.

If the length of the buffer pointed to by the *AddressString* parameter is not large enough to receive the string representation of the IPv4 address and port, **RtlIpv4AddressToStringEx** returns **ERROR_INVALID_PARAMETER** and sets the *AddressStringLength* parameter to the buffer length required.

When either UNICODE or _UNICODE is defined, **RtlIpv4AddressToStringEx** is defined to **RtlIpv4AddressToStringExW**, the Unicode version of this function. The *AddressString* parameter is defined to the PWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv4AddressToStringEx** is defined to **RtlIpv4AddressToStringExA**, the ANSI version of this function. The *AddressString* parameter is defined to the PSTR data type.

The **IN_ADDR** structure is defined in the *Inaddr.h* header file.

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)
[InetNtop](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_ntop)
[InetPton](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-inet_pton)
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)
[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)
[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)
[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexa)
[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)
[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexa)
[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)
[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexa)
[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)
[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)