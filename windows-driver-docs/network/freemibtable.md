# FreeMibTable function

The **FreeMibTable** function frees the buffer that is allocated by the functions that return tables of network interfaces, addresses, and routes (for example, [**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2) and [**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable)).

## Parameters

- *Memory* \[in\]
A pointer to the buffer to free.

## Return value

None

## Remarks

The **FreeMibTable** function is used to free the internal buffers that various functions use to retrieve tables of interfaces, addresses, and routes. When these tables are no longer needed, your driver should call **FreeMibTable** to release the memory that these tables use.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable)

[**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable)

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**GetIpInterfaceTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfacetable)

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**GetMulticastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddresstable)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)