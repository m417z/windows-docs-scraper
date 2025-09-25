# ClusterRegGetBatchNotification function

## Description

Fetches the batch notification. After the batch notification has been fetched, it is
interpreted via the
[ClusterRegBatchReadCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchreadcommand) function. After
the batch notification is processed, it needs to be closed via the
[ClusterRegBatchCloseNotification](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchclosenotification)
function.

## Parameters

### `hBatchNotify` [in]

The handle to the batch notification port opened earlier via the
[ClusterRegCreateBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatchnotifyport)
function.

### `phBatchNotification` [out]

A handle to the batch notification that represents all of the changes at or below the cluster registry key of
interest that have happened since the last call to
**ClusterRegGetBatchNotification** or
since the batch notification port was opened.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_DATA**<br><br>13 (0xD) | The data is not valid. |
| **ERROR_OUTOFMEMORY**<br><br>14 (0xE) | Not enough storage is available to complete this operation. |
| **ERROR_GEN_FAILURE**<br><br>31 (0x1F) | A device attached to the system is not functioning. |

## Remarks

The **PCLUSTER_REG_GET_BATCH_NOTIFICATION** type defines a pointer to this
function.

Only the functions from the batch function group, such as [ClusterRegBatchAddCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchaddcommand), will generate a registry change notification. A registry change that does not use one of the batch function commands will not generate a batch notification.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegBatchCloseNotification](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchclosenotification)

[ClusterRegBatchReadCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchreadcommand)

[ClusterRegCreateBatchNotifyPort](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatchnotifyport)