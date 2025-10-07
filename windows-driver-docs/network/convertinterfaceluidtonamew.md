# ConvertInterfaceLuidToNameW function

The **ConvertInterfaceLuidToNameW** function converts a locally unique identifier (LUID) for a network interface to the Unicode interface name.

> [!NOTE]
> The ConvertInterface*Xxx* API family enumerates identifiers over all interfaces bound to TCP/IP, which may include virtual miniports, lightweight filters, tunnel adapters, and physical interfaces.

## Parameters

- *InterfaceLuid* \[in\]
A pointer to a [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union for the network interface.

- *InterfaceName* \[out\]
A pointer to a buffer to hold the NULL-terminated Unicode string. If **ConvertInterfaceLuidToNameW** returns successfully, *InterfaceName* contains the Unicode interface name.

- *Length* \[in\]
The length of the buffer, by character count, that the *InterfaceName* parameter points to. This value must be large enough to hold the interface name and the terminating NULL character. The maximum allowed length is NDIS\_IF\_MAX\_STRING\_SIZE + 1. For more information about NDIS\_IF\_MAX\_STRING\_SIZE, see the following Remarks section.

## Return value

**ConvertInterfaceLuidToNameW** returns STATUS\_SUCCESS if the function succeeds. If the function fails, **ConvertInterfaceLuidToNameW** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters is invalid. **ConvertInterfaceLuidToNameW** returns this error if either *InterfaceLuid* or *InterfaceName* is **NULL**, or if *InterfaceLuid* is invalid. |
| **STATUS_NOT_ENOUGH_MEMORY** | **ConvertInterfaceLuidToNameW** returns this error if the *InterfaceName* buffer was not as large as specified in the *Length* parameter and, therefore, the buffer could not hold the interface name. |

## Remarks

The **ConvertInterfaceLuidToNameW** function is protocol-independent and works with network interfaces for both the IPv6 and IPv4 protocols.

The maximum length of the network interface name, NDIS\_IF\_MAX\_STRING\_SIZE, without the terminating NULL character, is defined in the Ntddndis.h header file. The NDIS\_IF\_MAX\_STRING\_SIZE is defined to be the IF\_MAX\_STRING\_SIZE constant, which is defined in the Ifdef.h header file.

> [!NOTE]
> The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file. You should never use the *Ntddndis.h* and *Ifdef.h* header files directly.

Use [**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea) to convert a network interface LUID to an ANSI interface name.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | PASSIVE_LEVEL |

## See also

[**ConvertInterfaceAliasToLuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacealiastoluid)

[**ConvertInterfaceGuidToLuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceguidtoluid)

[**ConvertInterfaceIndexToLuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceindextoluid)

[**ConvertInterfaceLuidToAlias**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoalias)

[**ConvertInterfaceLuidToGuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoguid)

[**ConvertInterfaceLuidToIndex**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoindex)

[**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea)

[**ConvertInterfaceNameToLuidA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluida)

[**ConvertInterfaceNameToLuidW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluidw)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)