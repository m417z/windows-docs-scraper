# ClusterRegCreateBatch function

## Description

Creates a batch that will execute commands on a cluster registry key. These commands will
be added to the batch by the
[ClusterRegBatchAddCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchaddcommand) function and
either executed or ignored by the
[ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch) function.

## Parameters

### `hKey` [in, optional]

The handle of the opened cluster registry key. All the operations on the batch are relative to this cluster
registry key.

### `pHREGBATCH` [out]

The pointer to the handle of the created batch.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_OUTOFMEMORY**<br><br>14 (0xE) | Not enough storage is available to complete this operation. |
| **ERROR_GEN_FAILURE**<br><br>31 (0x1F) | A device attached to the system is not functioning. |
| **ERROR_INVALID_PARAMETER**<br><br>87 (0x57) | The parameter is incorrect. This value will be returned if the *hKey* parameter is **NULL**. |

## Remarks

The key should not be closed until the batch has been submitted for execution.

The **PCLUSTER_REG_CREATE_BATCH** type defines a pointer to this function.

## See also

[Cluster Registry Access Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-registry-access-functions)

[ClusterRegBatchAddCommand](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregbatchaddcommand)

[ClusterRegCloseBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosebatch)