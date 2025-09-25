# OpenClusterNode function

## Description

Opens a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) and returns a handle to it. The **PCLUSAPI_OPEN_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) returned from the
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster) or
[OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex) functions.

### `lpszNodeName` [in]

Pointer to the NetBIOS name of an existing node. If the DNS name of the node is used, the
**OpenClusterNode** function will fail and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return
**ERROR_CLUSTER_NODE_NOT_FOUND**.

## Return value

If the operation was successful, **OpenClusterNode**
returns a node handle.

| Return code | Description |
| --- | --- |
| **NULL** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CloseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternode)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterex)

[OpenClusterNodeEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternodeex)