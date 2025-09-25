# ClusterRegCloseReadBatchEx function

## Description

Executes a read batch and returns results from the read batch executions.

## Parameters

### `hRegReadBatch` [in]

The handle of the read batch. After the [ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch) function completes, this handle is no longer valid, and memory associated with it is freed.

### `flags`

The flags for the operation.

#### None (0)

#### IsolatedRead (2)

### `phRegReadBatchReply` [out]

A pointer to the handle of the created read batch result. You must close this handle later by calling the [ClusterRegCloseReadBatchReply](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatchreply) function.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_OUTOFMEMORY**<br><br>14 | Not enough storage is available to complete this operation. |
| **ERROR_INVALID_HANDLE**<br><br>6 | *hRegReadBatch* is **NULL** or not valid. |

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch)

[ClusterRegCreateReadBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatereadbatch)

[ClusterRegReadBatchAddCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregreadbatchaddcommand)