# RtlIpv4AddressToStringW function

## Description

The
**RtlIpv4AddressToString** function converts an IPv4 address to a string in Internet standard dotted-decimal format.

## Parameters

### `Addr` [in]

The IPv4 address in network byte order.

### `S` [out]

A pointer to a buffer in which to store the **NULL**-terminated string representation of the IPv4 address. This buffer should be large enough to hold at least 16 characters.

## Return value

A pointer to the NULL character inserted at the end of the string representation of the IPv4 address.
This can be used by the caller to easily append more information to the string.

## Remarks

The **RtlIpv4AddressToString** function is used to convert an IPv4 address to the string representation of the IPv4 address in Internet dotted-decimal format.

**RtlIpv4AddressToString** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform IP address to string conversion.

When either UNICODE or _UNICODE is defined, **RtlIpv4AddressToString** is defined to **RtlIpv4AddressToStringW**, the Unicode version of this function. The string parameter *S* and the function return value are defined to the PWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv4AddressToString** is defined to **RtlIpv4AddressToStringA**, the ANSI version of this function. The string parameter *S* and the function return value are defined to the PSTR data type.

The **IN_ADDR** structure is defined in the *Inaddr.h* header file.

> [!NOTE]
> The ip2string.h header defines RtlIpv4AddressToString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressa)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)