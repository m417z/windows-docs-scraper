# AddClusterNode function

## Description

Adds a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) to an existing cluster. The **PCLUSAPI_ADD_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a cluster, returned by the [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster) or
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) function.

### `lpszNodeName` [in]

Name of the computer to add to the cluster.

### `pfnProgressCallback` [in, optional]

Optional address to a
[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)
callback function.

### `pvCallbackArg` [in, optional]

Argument for the callback function.

## Return value

Handle to the new node or **NULL** to indicate that the node was not successfully added
to the cluster. For more information about the error, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

After the [CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) function successfully
completes, at least 30 seconds should be allowed before the
**AddClusterNode** function is called to add additional
nodes.

## See also

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)