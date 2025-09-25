## Description

The **ClfsMgmtHandleLogFileFull** routine attempts to make more space available in a log. It might make more space available by adding containers to the log, or it might ask clients to move their log tails.

## Parameters

### `Client` [in]

The client that is requesting CLFS management to make space available in the log. The value of this parameter should be the **CLFS_MGMT_CLIENT** structure that is obtained through a call to the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine.

## Return value

The **ClfsMgmtHandleLogFileFull** routine returns one of the following NTSTATUS values:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The client is not managing a log. |
| **STATUS_INVALID_PARAMETER_1** | The value that was supplied for the *Client* parameter either was **NULL** or does not represent a valid client. |
| **STATUS_LOG_FULL_HANDLER_IN_PROGRESS** | CLFS management is already attempting to resolve a log file full condition for this client. |
| **STATUS_UNSUCCESSFUL** | CLFS management was not able to process the request. |
| **STATUS_PENDING** | CLFS management is processing the request to create space in the log. |
| **STATUS_SUCCESS** | The requested amount of space is available in the log. |

## Remarks

To make more space available in the log, the **ClfsMgmtHandleLogFileFull** routine first tries to add more containers to the log in accordance with the growth rate, new container size, and maximum size policies. If more containers cannot be added, then the **ClfsMgmtHandleLogFileFull** routine tries to free existing space by invoking one or more clients' [ClfsAdvanceTailCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_advance_tail_callback) functions.

If the **ClfsMgmtHandleLogFileFull** routine returns STATUS_PENDING, the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function will be called when the request to make space in the log has been completed.

If the **ClfsMgmtHandleLogFileFull** routine returns STATUS_LOG_FULL_HANDLER_IN_PROGRESS, the client has already requested CLFS management to handle a log file full condition. The client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function will not be called a second time.

If the **ClfsMgmtHandleLogFileFull** routine returns STATUS_SUCCESS, the call completed synchronously, and the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function will not be invoked.

If the **ClfsMgmtHandleLogFileFull** routine returns STATUS_PENDING, then CLFS management is in the process of trying to free space in the log, and will call the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function when the log file full condition has been handled. If the log is pinned, CLFS management will call the client's *ClfsLogGrowthCompleteCallback* function with the *LogIsPinned* parameter set to **TRUE** before the **ClfsMgmtHandleLogFileFull** routine returns STATUS_PENDING.

It is possible that the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function could be called before the call to **ClfsMgmtHandleLogFileFull** returns.

If the **ClfsMgmtHandleLogFileFull** routine returns STATUS_PENDING, you should not call the **ClfsMgmtHandleLogFileFull** routine again for this client until the client's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function has been called.

## See also

[ClfsAdvanceTailCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_advance_tail_callback)

[ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback)

[ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient)