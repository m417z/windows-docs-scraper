# PMRX_GET_CONNECTION_ID callback function

## Description

The**MRxGetConnectionId** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector return a connection ID, which can be used for handling multiple sessions.

## Parameters

### `RxContext`

[in, out] A pointer to the RX_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

### `UniqueId`

[in, out] A pointer to the connection ID when the routine returns.

## Return value

**MRxGetConnectionId** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| ------------- | ------------- |
| STATUS_NOT_IMPLEMENTED | This routine is not implemented.

## Remarks

**MRxGetConnectionId** is called by RDBSS when trying to find or construct a V_NET_ROOT structure.

If connection IDs are supported by the network mini-redirector, then the returned connection ID is appended to the NET_ROOT structure name stored in the NetName table used by RDBSS for storing network names. RDBSS considers the connection ID as an opaque blob, and does a byte-by-byte comparison of the connection ID blob while looking up the NetName table for a given name with a connection ID.

## See also

[**MRxCompleteBufferingStateChangeRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_change_buffering_state_calldown)

[**MRxComputeNewBufferingState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_compute_new_buffering_state)