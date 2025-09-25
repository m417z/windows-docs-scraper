# OpenClusterResource function

## Description

Opens a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) and returns a handle to
it. The **PCLUSAPI_OPEN_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszResourceName` [in]

Pointer to a null-terminated Unicode string containing the name of the resource to be opened.

Resource names are not case sensitive. A resource name must be unique within the cluster. The name is set
when the resource is created and can be changed using the
[SetClusterResourceName](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusterresourcename) function.

## Return value

If the operation was successful,
**OpenClusterResource** returns a handle to the
opened resource.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[OpenClusterResourceEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresourceex)