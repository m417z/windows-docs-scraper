# ClusterRegCreateBatchNotifyPort function

## Description

Creates a subscription to a batch notification port. The batch notification port needs to
be closed after it is no longer needed. This is done via the
[ClusterRegCloseBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatchnotifyport)
function.

## Parameters

### `hKey` [in]

A cluster registry key. Any updates performed at this key or keys below it will be posted to a notification
port.

### `phBatchNotifyPort` [out]

A handle to a batch notification port that allows subsequent reading batch notifications via the
[ClusterRegGetBatchNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterreggetbatchnotification)
function.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **PCLUSTER_REG_CREATE_BATCH_NOTIFY_PORT** type defines a pointer to this
function.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCloseBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatchnotifyport)

[ClusterRegGetBatchNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterreggetbatchnotification)