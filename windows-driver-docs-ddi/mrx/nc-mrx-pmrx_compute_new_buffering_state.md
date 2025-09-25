# PMRX_COMPUTE_NEW_BUFFERING_STATE callback function

## Description

The**MRxComputeNewBufferingState** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that the network mini-redirector compute a new buffering state change.

## Parameters

### `SrvOpen` [in, out]

A pointer to the SRV_OPEN structure and the associated FCB structure.

### `MRxContext` [in]

A pointer to a context parameter for use by the network mini-redirector callback.

### `NewBufferingState` [out]

A pointer to where the new buffering state is stored when the routine returns.

## Return value

**MRxComputeNewBufferingState** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_NOT_SUPPORTED | A feature that is requested is not supported. |

## Remarks

Before calling **MRxComputeNewBufferingState**, RDBSS sets the **FcbState** member of **SrvOpen****->Fcb** to FCB_STATE_BUFFERSTATE_CHANGING.

The Server Message Block (SMB) redirector uses **MRxComputeNewBufferingState** to map the SMB-specific oplock levels into the appropriate RDBSS buffering state flags. The oplock level is passed in the **MrxContext** parameter.

## See also

[**MRxCompleteBufferingStateChangeRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_change_buffering_state_calldown)

[**MRxGetConnectionId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_get_connection_id)