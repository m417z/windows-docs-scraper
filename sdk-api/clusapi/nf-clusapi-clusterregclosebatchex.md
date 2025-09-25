# ClusterRegCloseBatchEx function

## Description

Executes or ignores the batch created by the
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch) function.

## Parameters

### `hRegBatch` [in]

The handle of the cluster registry key opened by
[ClusterRegCreateBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatebatch). After the completion
of [ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch), this handle is no
longer valid and memory associated with it is freed.

### `flags` [in]

### `failedCommandNumber` [out, optional]

If execution of the batch is not successful, the number of the command that failed is returned in the form of
a *failedCommandNumber* argument. The first command in the batch has number 0, the
second has number 1, and so on.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle is not valid. This value is returned if the *hRegBatch* parameter is **NULL**. |

## Remarks

If a failure has occurred before any command was executed, the *failedCommandNumber*
parameter is set to –1.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch)