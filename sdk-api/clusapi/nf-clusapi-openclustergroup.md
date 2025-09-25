# OpenClusterGroup function

## Description

Opens a failover cluster [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) and returns a handle to
it.

## Parameters

### `hCluster` [in]

Handle to a cluster that includes the group to open.

### `lpszGroupName` [in]

Name of the group to open.

## Return value

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

If the operation was successful,
**OpenClusterGroup** returns a group handle.

## See also

[CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)

[OpenClusterGroupEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroupex)