# PCLFS_CLIENT_LOG_UNPINNED_CALLBACK callback function

## Description

The *ClfsLogUnpinnedCallback* function implements any actions that the client will take when a log that had previously been pinned becomes unpinned.

## Parameters

### `LogFile` [in]

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the CLFS log stream whose tail has become unpinned.

### `ClientData` [in]

A pointer to client-supplied information. You specify this data in the **LogUnpinnedCallbackData** member of the [CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration) structure.

## Remarks

If a client called the [ClfsMgmtHandleLogFileFull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmthandlelogfilefull) routine and CLFS management subsequently called the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function with a value of **TRUE** for the *LogIsPinned* parameter, then the *ClfsLogUnpinnedCallback* function will be invoked when the log becomes unpinned.

When a client uses the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine to register with CLFS management, the client provides both a pointer to the *ClfsLogUnpinnedCallback* function and the custom data that will be passed as a parameter to the *ClfsLogUnpinnedCallback* function when this function is called.

The *ClfsLogUnpinnedCallback* function should only perform a minimal amount of processing before returning. For example, it might create and queue a work item to inform the client that it can resume processing.

The *ClfsLogGrowthCompleteCallback* function is called before the *ClfsLogUnpinnedCallback* function.

## See also

[CLFS_MGMT_CLIENT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_clfs_mgmt_client_registration)

[ClfsMgmtHandleLogFileFull](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmthandlelogfilefull)