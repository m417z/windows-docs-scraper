# RemoveResourceFromClusterSharedVolumes function

## Description

Removes storage from Cluster Shared Volumes. The
**PCLUSAPI_REMOVE_RESOURCE_FROM_CLUSTER_SHARED_VOLUMES** type defines a pointer to this
function.

## Parameters

### `hResource` [in]

Handle to the physical disk resource to remove from Cluster Shared Volumes.

## Return value

If the operation succeeds, it returns **ERROR_SUCCESS**.

If the operation fails,
**RemoveResourceFromClusterSharedVolumes**
returns one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[AddResourceToClusterSharedVolumes](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-addresourcetoclustersharedvolumes)