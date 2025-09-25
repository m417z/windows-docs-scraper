# PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK callback function

## Description

The *ClfsLogGrowthCompleteCallback* function implements the actions that the client will take when space is freed in a log that had previously been full.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log stream whose log has finished growing.

### `OperationStatus` [in]

The status of the client's earlier request to handle a log file full condition. This will be either STATUS_SUCCESS or an error status that indicates the reason that the request could not be completed successfully.

### `LogIsPinned` [in]

If **TRUE**, specifies that the log tail is currently pinned; **FALSE** if the log tail is not pinned.

### `ClientData` [in]

A pointer to client-supplied information.

## Remarks

Because a call to [ClfsMgmtHandleLogFileFull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmthandlelogfilefull) completes asynchronously, any actions that the client will take when the log file full condition has been handled belong in the *ClfsLogGrowthCompleteCallback* function.

If a call to the **ClfsMgmtHandleLogFileFull** routine returned returns STATUS_PENDING, then the *ClfsLogGrowthCompleteCallback* function will be invoked when the operation completes. If a different status was returned, then the *ClfsLogGrowthCompleteCallback* function will not be invoked.

The *ClfsLogGrowthCompleteCallback* function should only perform a minimal amount of processing before returning. For example, the *ClfsLogGrowthCompleteCallback* function might follow the following procedure:

1. If the value of the *OperationStatus* parameter is an error status, return.
2. If the value of the *OperationStatus* parameter is STATUS_SUCCESS, create and queue a work item to inform the client that it can resume processing.

When a client uses the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine to register with CLFS management, the client provides both a pointer to the *ClfsLogGrowthCompleteCallback* function and the custom data that will be passed as a parameter to the *ClfsLogGrowthCompleteCallback* function when this function is called.

## See also

[ClfsMgmtHandleLogFileFull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmthandlelogfilefull)

[ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient)