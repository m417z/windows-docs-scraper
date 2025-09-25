# OpenClusterNetwork function

## Description

Opens a connection to a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) and returns a handle
to it. The **PCLUSAPI_OPEN_CLUSTER_NETWORK** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszNetworkName` [in]

Pointer to the name of an existing network.

## Return value

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

If the operation was successful,
**OpenClusterNetwork** returns a network handle.

## See also

[CloseClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetwork)

[Failover Cluster Network Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-management-functions)

[OpenClusterNetworkEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetworkex)