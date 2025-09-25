# CloseClusterNode function

## Description

Closes a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) handle. The **PCLUSAPI_CLOSE_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to an existing node.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)