# ConvertInterfaceLuidToIndex function

The **ConvertInterfaceLuidToIndex** function converts a locally unique identifier (LUID) for a network interface to the local index for the interface.

> [!NOTE]
> The ConvertInterface*Xxx* API family enumerates identifiers over all interfaces bound to TCP/IP, which may include virtual miniports, lightweight filters, tunnel adapters, and physical interfaces.

## Parameters

- *InterfaceLuid* \[in\]
A pointer to a [**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value) union for the network interface.

- *InterfaceIndex* \[out\]
The local index value for the network interface.

## Return value

**ConvertInterfaceLuidToIndex** returns STATUS\_SUCCESS if the function succeeds. If the function fails, the *InterfaceIndex* parameter is set to NET\_IFINDEX\_UNSPECIFIED, and **ConvertInterfaceLuidToIndex** returns the following error code:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | One of the parameters is invalid. **ConvertInterfaceLuidToIndex** returns this error if either *InterfaceLuid* or *InterfaceIndex* is **NULL**, or if *InterfaceLuid* is invalid. |

## Remarks

The **ConvertInterfaceLuidToIndex** function is protocol-independent and works with network interfaces for both the IPv6 and IPv4 protocols.

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

[**ConvertInterfaceLuidToNameA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamea)

[**ConvertInterfaceLuidToNameW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfaceluidtonamew)

[**ConvertInterfaceNameToLuidA**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluida)

[**ConvertInterfaceNameToLuidW**](https://learn.microsoft.com/windows-hardware/drivers/network/convertinterfacenametoluidw)

[**NET\_LUID**](https://learn.microsoft.com/windows-hardware/drivers/network/net-luid-value)