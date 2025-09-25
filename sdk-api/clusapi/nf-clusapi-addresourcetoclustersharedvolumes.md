# AddResourceToClusterSharedVolumes function

## Description

Adds storage to Cluster Shared Volumes. The
**PCLUSAPI_ADD_RESOURCE_TO_CLUSTER_SHARED_VOLUMES** type defines a pointer to this
function.

## Parameters

### `hResource` [in]

Handle to the physical disk resource to add to Cluster Shared Volumes.

## Return value

If the operation succeeds, it returns **ERROR_SUCCESS**.

If the operation fails,
**AddResourceToClusterSharedVolumes**
returns one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The system crash dump path cannot reside on any cluster shared volumes that use BitLocker encryption.

## See also

[RemoveResourceFromClusterSharedVolumes](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-removeresourcefromclustersharedvolumes)