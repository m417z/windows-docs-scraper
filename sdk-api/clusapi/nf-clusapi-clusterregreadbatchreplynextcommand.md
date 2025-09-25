# ClusterRegReadBatchReplyNextCommand function

## Description

Reads the next command from a read batch result.

## Parameters

### `hRegReadBatchReply` [in]

A handle to a read batch result that was created by calling the [ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch) function. You must close this handle later by calling the [ClusterRegCloseReadBatchReply](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatchreply) function.

### `pBatchCommand` [out]

A pointer to a [CLUSTER_READ_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_read_batch_command) structure that contains information about the read command.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_HANDLE**<br><br>6 | *hRegReadBatchReply* is **NULL** or not valid. |
| **ERROR_NO_MORE_ITEMS**<br><br>259 | There is no more information in *hRegReadBatchReply*. |

## Remarks

The number of records in the read batch results is equal to the number of commands in the read batch. Also, the results are in the same order as the commands that were added to the read batch.

## See also

[CLUSTER_READ_BATCH_COMMAND](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-cluster_read_batch_command)

[ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch)

[ClusterRegCloseReadBatchReply](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatchreply)