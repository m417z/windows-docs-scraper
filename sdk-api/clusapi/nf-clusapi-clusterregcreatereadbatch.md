# ClusterRegCreateReadBatch function

## Description

Creates a handle to the read batch that executes read commands on the cluster registry key.

## Parameters

### `hKey` [in]

The handle to the opened cluster registry key. All of the operations on the batch are relative to this cluster registry key.

### `phRegReadBatch` [out]

A pointer to the handle of the created read batch.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_OUTOFMEMORY**<br><br>14 | Not enough storage is available to complete this operation. |

## Remarks

Add commands to the batch by calling the [ClusterRegReadBatchAddCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregreadbatchaddcommand) function. Execute the batch by calling the [ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch) function.

Do not close the key until the read batch has been submitted for execution.

## See also

[ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch)

[ClusterRegReadBatchAddCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregreadbatchaddcommand)