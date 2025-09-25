# RtlIpv6StringToAddressW function

## Description

The
**RtlIpv6StringToAddress** function converts a string representation of an IPv6 address to a binary IPv6 address.

## Parameters

### `S` [in]

A pointer to a buffer containing the **NULL**-terminated string representation of the IPv6 address.

### `Terminator` [out]

A parameter that receives a pointer to the character that terminated
the converted string. This can be used by the caller to extract more information from the string.

### `Addr` [out]

A pointer where the binary representation of the IPv6 address is to be stored.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the string pointed to by the *S* parameter did not contain a proper string representation of an IPv6 address.<br><br>This error code is defined in the Ntstatus.h header file. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv6StringToAddress** function is used to convert a string representation of the IPv6 address to an IPv6 address returned in network order (bytes ordered from
left to right).

**RtlIpv6StringToAddress** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to IP address conversion.

The string pointed to by the *S* parameter must be represented in the form for an IPv6 address string. The basic string representation of an IPv6 address consists of 8 hexadecimal numbers
separated by colons. A string of consecutive zero numbers may be replaced
with a double-colon.
There can only be one double-colon in the string representation of the IPv6 address. The last 32 bits may be represented in IPv4-style dotted-octet notation
if the address is an IPv4-compatible address, an IPv4-mapped IPv6 address, or an ISATAP address. For more information, see section 5 of [RFC 5942](http://tools.ietf.org/html/rfc5952) published by the IETF.

On success, the *Terminator* parameter points to the character that terminated the string that was converted. This allows an application to pass a string that contains and IP address plus additional information to the **RtlIpv6StringToAddress** function and then parse the remaining information.

**Note** Some malformed IPv6 addresses (::::, for example) start with a valid IPv6 address. The **RtlIpv6StringToAddress** function will return success, having parsed the valid part of the IPv6 address as the double colon (::). The terminator then points to the third colon. To validate that the entire passed-in string is a valid IPv6 address, you need to ensure that the terminator points to the correct character. If the *S* parameter contains only an IPv6 address, then the terminator should point to the **NULL** character at the end of the string.

When either UNICODE or _UNICODE is defined, **RtlIpv6StringToAddress** is defined to **RtlIpv6StringToAddressW**, the Unicode version of this function. The *S* and *Terminator* parameters are defined to the PCWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv6StringToAddress** is defined to **RtlIpv6StringToAddressA**, the ANSI version of this function. The *S* and *Terminator* parameters are defined to the PCSTR data type.

The [IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85)) structure is defined in the In6addr.h header file.

> [!NOTE]
> The ip2string.h header defines RtlIpv6StringToAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[IN6_ADDR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms738560(v=vs.85))

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)