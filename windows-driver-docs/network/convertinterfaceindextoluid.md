# ConvertInterfaceIndexToLuid function

The **ConvertInterfaceIndexToLuid** function converts a local index for a network interface to the locally unique identifier (LUID) for the interface.

> [!NOTE]
> The ConvertInterface*Xxx* API family enumerates identifiers over all interfaces bound to TCP/IP, which may include virtual miniports, lightweight filters, tunnel adapters, and physical interfaces.

## Parameters

- *InterfaceIndex* \[in\]
The local index value for the network interface.

- *InterfaceLuid* \[out\]
A pointer to the [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union for the network interface.

## Return value

**ConvertInterfaceIndexToLuid** returns STATUS\_SUCCESS if the function succeeds. If the function fails, the *InterfaceLuid* parameter is set to **NULL**, and **ConvertInterfaceIndexToLuid** returns the following error code:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters was invalid. **ConvertInterfaceIndexToLuid** returns this error if the *InterfaceLuid* parameter is **NULL**, or if the *InterfaceIndex* parameter is invalid. |

## Remarks

The **ConvertInterfaceIndexToLuid** function is protocol-independent and works with network interfaces for both the IPv6 and IPv4 protocols.

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

[**ConvertInterfaceLuidToAlias**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoalias)

[**ConvertInterfaceLuidToGuid**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoguid)

[**ConvertInterfaceLuidToIndex**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtoindex)

[**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea)

[**ConvertInterfaceLuidToNameW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamew)

[**ConvertInterfaceNameToLuidA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluida)

[**ConvertInterfaceNameToLuidW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluidw)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)