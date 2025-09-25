# CloseClusterResource function

## Description

Closes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) handle. The **PCLUSAPI_CLOSE_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource to be closed.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful. For information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CreateClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusterresource)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)