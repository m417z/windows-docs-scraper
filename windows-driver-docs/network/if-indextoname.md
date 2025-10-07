# if\_indextoname function

The **if\_indextoname** function converts the local index for a network interface to the ANSI interface name.

## Parameters

- *InterfaceIndex* \[in\]
The local index for a network interface.

- *InterfaceName* \[out\]
A pointer to a buffer to hold the NULL-terminated ANSI string. If **if\_indextoname** succeeds, *InterfaceName* contains the ANSI interface name. The length, in bytes, of the buffer that this parameter points to must be equal to or greater than IF\_NAMESIZE. For more information about IF\_NAMESIZE, see the following Remarks section.

## Return value

If this function succeeds, **if\_indextoname** returns a pointer to a NULL-terminated ANSI string that contains the interface name. If this function fails, **if\_indextoname** returns a **NULL** pointer

## Remarks

The **if\_indextoname** function maps an interface index into its corresponding name. This function is designed as part of basic socket extensions for IPv6, as described by the IETF in [RFC 2553](https://www.ietf.org/rfc/rfc2553.txt).

The **if\_indextoname** function is implemented for portability of drivers with Unix environments, but the **ConvertInterface*Xxx*** functions are the preferred method to convert network interface identifiers. You can replace the **if\_indextoname** function by a call to the [**ConvertInterfaceIndexToLuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceindextoluid) function to convert an interface index to a [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union, followed by a call to the [**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea) function to convert NET\_LUID to the ANSI interface name.

The length, in bytes, of the buffer that the *InterfaceName* parameter points to must be equal or greater than IF\_NAMESIZE. The IF\_NAMESIZE value is defined in the Netioapi.h header file as equal to NDIS\_IF\_MAX\_STRING\_SIZE. The maximum length of an interface name, NDIS\_IF\_MAX\_STRING\_SIZE, without the terminating NULL character is declared in the Ntddndis.h header file. The NDIS\_IF\_MAX\_STRING\_SIZE is defined to be the IF\_MAX\_STRING\_SIZE constant that is defined in the Ifdef.h header file.

> [!NOTE]
> The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file. You should never use the *Ntddndis.h* and *Ifdef.h* header files directly.

If the **if\_indextoname** function fails and returns a **NULL** pointer, you cannot determine an error code.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | PASSIVE_LEVEL |

## See also

[**ConvertInterfaceIndexToLuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceindextoluid)

[**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)