# PMRX_CHANGE_BUFFERING_STATE_CALLDOWN callback function

## Description

The**MRxCompleteBufferingStateChangeRequest** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to notify the network mini-redirector that a buffering state change request has been completed.

## Parameters

### `RxContext` [in, out]

A pointer to the RX_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

### `SrvOpen` [in, out]

A pointer to a context parameter for use by the network mini-redirector callback routine.

### `MRxContext` [in]

A pointer to the SRV_OPEN structure and the associated FCB structure to be changed.

## Return value

**MRxCompleteBufferingStateChangeRequest** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_NOT_SUPPORTED | An option in the buffering request change is not supported. |

## Remarks

Before calling **MRxCompleteBufferingStateChangeRequest**, RDBSS:

* Acquires an exclusive lock on the FCB structure.

* Sets the **FcbState** member of **SrvOpen->Fcb** to FCB_STATE_BUFFERSTATE_CHANGING.

* Modifies the following members in the RX_CONTEXT structure pointed to by the **RxContext** parameter:

  * **pRelevantSrvOpen** is set to the SRV_OPEN structure.
  * **pFcb** is set to the FCB structure.
  * **pFobx** is set to the FOBX structure.

If lock buffering is enabled, **MRxCompleteBufferingStateChangeRequest** will need to flush out the byte-range locks to the server. The list of locked regions is passed to the network mini-redirector in the **LowIoContext.ParamsFor.Locks.LockList** member of the RX_CONTEXT structure.

The Server Message Block (SMB) redirector uses **MRxCompleteBufferingStateChangeRequest** to send an oplock break response or to close the handle on an oplock break if the file is no longer in use. Byte range locks that need to be flushed out to the server are passed to the network mini-redirector in the **LowIoContext.ParamsFor.Locks.LockList** member of the RX_CONTEXT structure. The new oplock level is passed in the **MrxContext** parameter.

RDBSS ignores the return value from **MRxCompleteBufferingStateChangeRequest**.

## See also

[**MRxComputeNewBufferingState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_compute_new_buffering_state)

[**MRxGetConnectionId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_get_connection_id)