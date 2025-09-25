# ClusterRegCloseReadBatchReply function

## Description

Closes a read batch result handle and frees the memory associated with it.

## Parameters

### `hRegReadBatchReply` [in]

A handle to a read batch result that was created by calling the [ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch) function.

## Return value

The function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. |
| **ERROR_INVALID_HANDLE**<br><br>6 | *hRegReadBatchReply* is **NULL** or not valid. |

## Remarks

Call the **ClusterRegCloseReadBatchReply** function to close a read batch result that was created by the [ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch) function.

## See also

[ClusterRegCloseReadBatch](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterregclosereadbatch)

[ClusterRegReadBatchReplyNextCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregreadbatchreplynextcommand)