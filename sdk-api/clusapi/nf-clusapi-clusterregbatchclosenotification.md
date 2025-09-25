# ClusterRegBatchCloseNotification function

## Description

Frees the memory associated with the batch notification.

## Parameters

### `hBatchNotification` [in]

A handle to the batch notification.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. This error returns if the command is properly filled. |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle is not valid. This error is returned if the *hBatchNotification* parameter is **NULL**. |

## Remarks

The **PCLUSTER_REG_BATCH_CLOSE_NOTIFICATION** type defines a pointer to this
function.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)