# ClusterRegReadBatchAddCommand function

## Description

Adds a read command to a batch that executes on a cluster registry key.

## Parameters

### `hRegReadBatch` [in]

The handle of the read batch to which a command will be added. Create a batch by calling the [ClusterRegCreateReadBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatereadbatch) function.

### `wzSubkeyName` [in, optional]

The name of the key relative to the cluster registry key. If this name is **NULL**, the read is performed on the cluster registry key represented in the *hRegReadBatch* parameter.

### `wzValueName` [in, optional]

The name of the registry value to be read. If this name is **NULL**, the content of the default value is returned.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_OUTOFMEMORY**<br><br>14 | Not enough storage is available to complete this operation. |
| **ERROR_INVALID_HANDLE**<br><br>6 | *hRegReadBatch* is **NULL** or not valid. |

## Remarks

Additional calls to the **ClusterRegReadBatchAddCommand** function add additional read commands to the batch.

## See also

[ClusterRegCreateReadBatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregcreatereadbatch)