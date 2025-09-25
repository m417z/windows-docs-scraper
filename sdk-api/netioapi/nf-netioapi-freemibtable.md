# FreeMibTable function

## Description

The
**FreeMibTable** function frees the buffer allocated by the functions that return tables of network interfaces, addresses, and routes ([GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) and [GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable), for example).

## Parameters

### `Memory` [in]

A pointer to the buffer to free.

## Return value

This function does not return a value.

## Remarks

The **FreeMibTable** function is defined on Windows Vista and later.

The **FreeMibTable** function is used to free the internal buffers used by various functions to retrieve tables of interfaces, addresses, and routes. When these tables are no longer needed, then **FreeMibTable** should be called to release the memory used by these tables.

## See also

[GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable)

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable)

[GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)