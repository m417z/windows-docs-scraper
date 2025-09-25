# CloseClusterGroup function

## Description

Closes a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) handle. The **PCLUSAPI_CLOSE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to close.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)