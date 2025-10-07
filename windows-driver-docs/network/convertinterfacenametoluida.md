# ConvertInterfaceNameToLuidA function

The **ConvertInterfaceNameToLuidA** function converts an ANSI network interface name to the locally unique identifier (LUID) for the interface.

> [!NOTE]
> The ConvertInterface*Xxx* API family enumerates identifiers over all interfaces bound to TCP/IP, which may include virtual miniports, lightweight filters, tunnel adapters, and physical interfaces.

## Parameters

- *InterfaceName* \[in\]
A pointer to a NULL-terminated ANSI string that contains the network interface name.

- *InterfaceLuid* \[out\]
A pointer to the [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union for this interface.

## Return value

**ConvertInterfaceNameToLuidA** returns STATUS\_SUCCESS if the function succeeds. If the function fails, **ConvertInterfaceNameToLuidA** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **ERROR_BUFFER_OVERFLOW** | The length of the ANSI interface name is invalid. **ConvertInterfaceNameToLuidA** returns this error if the *InterfaceName* parameter exceeds the maximum allowed string length for this parameter. |
| **STATUS_INVALID_NAME** | The interface name is invalid. **ConvertInterfaceNameToLuidA** returns this error if the *InterfaceName* parameter contains an invalid interface name. |
| **STATUS_INVALID_PARAMETER** | One of the parameters is invalid. **ConvertInterfaceNameToLuidA** returns this error if the *InterfaceLuid* parameter is **NULL**. |

## Remarks

The **ConvertInterfaceNameToLuidA** function is protocol-independent and works with network interfaces for both the IPv6 and IPv4 protocols.

The maximum length of the network interface name, NDIS\_IF\_MAX\_STRING\_SIZE, without the terminating **NULL**, is defined in the Ntddndis.h header file. NDIS\_IF\_MAX\_STRING\_SIZE is defined to be the IF\_MAX\_STRING\_SIZE constant, which is defined in the Ifdef.h header file.

> [!NOTE]
> The *Ntddndis.h* and *Ifdef.h* header files are automatically included in the *Netioapi.h* header file. You should never use the *Ntddndis.h* and *Ifdef.h* header files directly.

Use the [**ConvertInterfaceNameToLuidW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluidw) function to convert a Unicode interface name to a LUID.

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

[**ConvertInterfaceLuidToNameW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamew)

[**ConvertInterfaceNameToLuidW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluidw)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)