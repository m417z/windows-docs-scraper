# CloseClusterNetwork function

## Description

Closes a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) handle. The **PCLUSAPI_CLOSE_CLUSTER_NETWORK** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

Handle to the network to close.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful; call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for more information. |

## See also

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)