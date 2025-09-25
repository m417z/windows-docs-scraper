# RxCeCancelConnectRequest function

## Description

**RxCeCancelConnectRequest** cancels a previously issued connection request. Note that this routine is not currently implemented.

## Parameters

### `pLocalAddress` [in]

A pointer to the local RDBSS connection engine address on which the previously issued connection request was made.

### `pServerName` [in]

A pointer to the name of the server on which the previous connection request was made.

### `pConnectionInformation` [in]

A pointer to the connection information that specifies the remote address. on which the previously issued connection request was made.

## Return value

**RxCeCancelConnectRequest** returns STATUS_NOT_IMPLEMENTED since this routine is not currently implemented.

## Remarks

**RXCE_CONNECTION_INFORMATION** is a typedef for a **TDI_CONNECTION_INFORMATION** structure.

## See also

[RxCeTearDownConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownconnection)

[TDI_CONNECTION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565085(v=vs.85))