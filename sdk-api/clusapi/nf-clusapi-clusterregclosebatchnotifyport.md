# ClusterRegCloseBatchNotifyPort function

## Description

Closes a subscription to a batch notification port created by the
[ClusterRegCreateBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatchnotifyport)
function.

## Parameters

### `hBatchNotifyPort` [in]

A handle to the batch notification port created earlier via the
[ClusterRegCreateBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatchnotifyport)
function.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle is not valid. |

## Remarks

The **PCLUSTER_REG_CLOSE_BATCH_NOTIFY_PORT** type defines a pointer to this
function.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCreateBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatchnotifyport)