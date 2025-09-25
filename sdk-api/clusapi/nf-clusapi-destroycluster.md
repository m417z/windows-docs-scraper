# DestroyCluster function

## Description

Removes a cluster. The **PCLUSAPI_DESTROY_CLUSTER** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to a cluster, returned by the [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster) or
[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster) function.

### `pfnProgressCallback` [in, optional]

Address of callback function that matches the
[PCLUSTER_SETUP_PROGRESS_CALLBACK](https://learn.microsoft.com/windows/desktop/api/clusapi/nc-clusapi-pcluster_setup_progress_callback)
function pointer that will be called periodically to provide progress on the cluster destruction.

### `pvCallbackArg` [in, optional]

Argument for the callback function.

### `fdeleteVirtualComputerObjects` [in]

If **TRUE**, then delete the virtual computer objects associated with the cluster
from the directory.

## Return value

Returns **ERROR_SUCCESS** if the cluster was completely removed or a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) for the last failed operation.

## Remarks

It is possible for multiple steps to fail when removing a cluster with
**DestroyCluster**, but only one error code can be
returned. The cluster error log should be reviewed if an error is returned.

## See also

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[CreateCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createcluster)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)