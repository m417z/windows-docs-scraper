# RtlEthernetStringToAddressA function

## Description

The
**RtlEthernetStringToAddress** function converts a string representation of an Ethernet MAC address to a binary format of the Ethernet address.

## Parameters

### `S` [in]

A pointer to a buffer containing the **NULL**-terminated string representation of the Ethernet MAC address.

### `Terminator` [out]

A parameter that receives a pointer to the character that terminated
the converted string. This can be used by the caller to extract more information from the string.

### `Addr` [out]

A pointer where the binary representation of the Ethernet MAC address is to be stored.

## Return value

If the function succeeds, the return value is **STATUS_SUCCESS**.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if the string pointed to by the *S* parameter did not contain a proper string representation of an Ethernet MAC address.<br><br>This error code is defined in the *Ntstatus.h* header file. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

The **RtlEthernetStringToAddress** function is used to convert a string representation of an Ethernet EUI-48 data-link layer address (also commonly known as a MAC address) to binary format of the Ethernet address. The string represents a numeric Ethernet address
expressed in the non-DIX standard "-'' notation. The value
returned is a number suitable for use as an Ethernet address. All
Ethernet addresses are returned in network order (bytes ordered from
left to right).

The string pointed to by the *S* parameter must be represented in the form for an Ethernet MAC address string in the non-DIX standard "-" notation. The basic string representation of an Ethernet MAC address consists of 6 pairs of hexadecimal numbers
separated by dashes (F4-CE-46-2D-90-8C, for example).

On success, the *Terminator* parameter points to the character that terminated the string that was converted. This allows an application to pass a string that contains an Ethernet address plus additional information to the **RtlEthernetStringToAddress** function and then parse the remaining information.

**RtlEthernetStringToAddress** is a convenience function that does not require that the Windows Sockets DLL be loaded to access a function provided in Windows Sockets to perform string to Ethernet address conversion.

When either UNICODE or _UNICODE is defined, **RtlEthernetStringToAddress** is defined to **RtlEthernetStringToAddressW**, the Unicode version of this function. The *S* and *Terminator* parameters are defined to the **PCWSTR** data type.

When both UNICODE and _UNICODE are not defined, **RtlEthernetStringToAddress** is defined to **RtlEthernetStringToAddressA**, the ANSI version of this function. The *S* and *Terminator* parameters are defined to the **PCSTR** data type.

The **DL_EUI48** data type is defined in the *Mstcpip.h* header file.

> [!NOTE]
> The ip2string.h header defines RtlEthernetStringToAddress as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RtlEthernetAddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlethernetaddresstostringa)