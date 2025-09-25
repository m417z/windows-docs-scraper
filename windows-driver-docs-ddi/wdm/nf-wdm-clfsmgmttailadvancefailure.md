# ClfsMgmtTailAdvanceFailure function

## Description

The **ClfsMgmtTailAdvanceFailure** routine notifies CLFS management that the client could not advance the log's tail.

## Parameters

### `Client` [in]

A pointer to the client. This is the value that was obtained through a call to the [ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient) routine.

### `Reason` [in]

A value that indicates why the log's tail could not be advanced.

## Return value

The **ClfsMgmtTailAdvanceFailure** routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | CLFS management has processed the notification that the log's tail could not be advanced. |
| **STATUS_INVALID_PARAMETER** | A **NULL** value was supplied for the *Client* parameter. |
| **STATUS_INVALID_PARAMETER_1** | The value that was supplied for the *Client* parameter does not represent a valid client. |

## Remarks

If a client cannot advance its log's tail to or beyond the requested LSN, then the client must call the **ClfsMgmtTailAdvanceFailure** routine to indicate that it is not able to advance its tail. Until the client either moves its tail as requested or calls the **ClfsMgmtTailAdvanceFailure** routine, the client will not receive any further requests to move its tail.

The value of the *Reason* parameter is passed back to the client as the value of the *OperationStatus* parameter when the [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function is invoked.

## See also

[ClfsMgmtRegisterManagedClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsmgmtregistermanagedclient)