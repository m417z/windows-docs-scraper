# CloseClusterNetInterface function

## Description

Closes a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) handle. The **PCLUSAPI_CLOSE_CLUSTER_NET_INTERFACE** type defines a pointer to this function.

## Parameters

### `hNetInterface` [in]

Handle of the network interface to close.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful; call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for more information. |

## See also

[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)