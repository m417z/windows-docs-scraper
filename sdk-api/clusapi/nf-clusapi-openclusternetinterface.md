# OpenClusterNetInterface function

## Description

Opens a handle to a
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces). The **PCLUSAPI_OPEN_CLUSTER_NET_INTERFACE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszInterfaceName` [in]

Pointer to a null-terminated Unicode string containing the name of the network interface to open.

## Return value

If the operation was successful,
**OpenClusterNetInterface** returns an open
handle to the specified network interface.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CloseClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetinterface)

[Network Interface Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interface-management-functions)

[OpenClusterNetInterfaceEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterfaceex)