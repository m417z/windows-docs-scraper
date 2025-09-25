# RtlIpv4StringToAddressA function

## Description

The
**RtlIpv4StringToAddress** function converts a string representation of an IPv4 address to a binary IPv4 address.

## Parameters

### `S` [in]

A pointer to a buffer containing the **NULL**-terminated string representation of the IPv4 address.

### `Strict` [in]

A value that indicates whether the string must be an IPv4 address represented in strict four-part dotted-decimal notation. If this parameter is **TRUE**, the string must be dotted-decimal with four parts.
If this parameter is **FALSE**, any of four possible forms are allowed, with decimal,
octal, or hexadecimal notation. See the Remarks section for details.

### `Terminator` [out]

A parameter that receives a pointer to the character that terminated
the converted string. This can be used by the caller to extract more information from the string.

### `Addr` [out]

A pointer where the binary representation of the IPv4 address is to be stored.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the *Strict* parameter was set to **TRUE**, but the string pointed to by the *S* parameter did not contain a four-part dotted decimal string representation of an IPv4 address. This error is also returned if the string pointed to by the *S* parameter did not contain a proper string representation of an IPv4 address.<br><br>This error code is defined in the Ntstatus.h header file. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlIpv4StringToAddress** function is used to convert a string representation of the IPv4 address to an IPv4 address returned in network order (bytes ordered from
left to right).

**RtlIpv4StringToAddress** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to IP address conversion.

If the *Strict* parameter is set to **TRUE**, then the string pointed to by the *S* parameter must be in strict dotted-decimal notation. This strict format requires that four parts are specified. Each part is interpreted as a decimal byte of data
and assigned, from left to right, to the four bytes of an IPv4
address.

When the *Strict* parameter is set to **FALSE**, the string pointed to by *S* parameter may be in any of the several possible formats. When the buffer pointed to by *S* parameter contains a three-part address string, the last part is interpreted
as a 16-bit quantity and placed in the right most two bytes of the
network address. This makes the three-part address format
convenient for specifying Class B network addresses as
"128.net.host". When the buffer pointed to by *S* parameter contains a two-part address string, the last part is interpreted
as a 24-bit quantity and placed in the right most three bytes of the
network address. This makes the two part address format convenient
for specifying Class A network addresses as "net.host". When the buffer pointed to by *S* parameter contains only a one-part address string, the value is stored directly in the
network address without any byte rearrangement.

On success, the *Terminator* parameter points to the character that terminated the string that was converted. This allows an application to pass a string that contains an IP address plus additional information to the **RtlIpv4StringToAddress** function and then parse the remaining information.

When either UNICODE or _UNICODE is defined, **RtlIpv4StringToAddress** is defined to **RtlIpv4StringToAddressW**, the Unicode version of this function. The *S* parameter is defined to the PCWSTR data type and the *Terminator* parameter is defined to the LPCWSTR data type.

When both UNICODE and _UNICODE are not defined, **RtlIpv4StringToAddress** is defined to **RtlIpv4StringToAddressA**, the ANSI version of this function. The *S* and *Terminator* parameters are defined to the PCSTR data type.

The [IN_ADDR](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure is defined in the *Inaddr.h* header file.

> [!NOTE]
> The ip2string.h header defines RtlIpv4StringToAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[InetNtop](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetntopw)

[InetPton](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-inetptonw)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RtlIpv4AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringa)

[RtlIpv4AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4addresstostringexw)

[RtlIpv4StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv4stringtoaddressexw)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[RtlIpv6StringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressa)

[RtlIpv6StringToAddressEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6stringtoaddressexw)

[inet_addr](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)