# RtlEthernetAddressToStringW function

## Description

The
**RtlEthernetAddressToString** function converts a binary Ethernet address to a string representation of the Ethernet MAC address.

## Parameters

### `Addr` [in]

The Ethernet address in binary format. The Ethernet address is in network order (bytes ordered from
left to right).

### `S` [out]

A pointer to a buffer in which to store the **NULL**-terminated string representation of the Ethernet address. This buffer should be large enough to hold at least 18 characters.

## Return value

A pointer to the NULL character inserted at the end of the string representation of the Ethernet MAC address.
This can be used by the caller to easily append more information to the string.

## Remarks

The **RtlEthernetAddressToString** function is used to convert a binary Ethernet address to the string representation of the Ethernet address in Ethernet EUI-48 data-link layer address format (also commonly known as a MAC address). The string represents a numeric Ethernet address
expressed in the non-DIX standard "-'' notation.

The string returned in the *S* parameter is represented in the form for an Ethernet MAC address string in the non-DIX standard "-" notation. The basic string representation of an Ethernet MAC address consists of 6 pairs of hexadecimal numbers
separated by dashes (F4-CE-46-2D-90-8C, for example).

**RtlEthernetAddressToString** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to Ethernet address conversion.

When either UNICODE or _UNICODE is defined, **RtlEthernetAddressToString** is defined to **RtlEthernetAddressToStringW**, the Unicode version of this function. The string parameter *S* and the function return value are defined to the **PWSTR** data type.

When both UNICODE and _UNICODE are not defined, **RtlEthernetAddressToString** is defined to **RtlEthernetAddressToStringA**, the ANSI version of this function. The string parameter *S* and the function return value are defined to the **PSTR** data type.

The **DL_EUI48** data type is defined in the *Mstcpip.h* header file.

> [!NOTE]
> The ip2string.h header defines RtlEthernetAddressToString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RtlEthernetStringToAddress](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlethernetstringtoaddressa)