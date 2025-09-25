# RxCeBuildConnection function

## Description

**RxCeBuildConnection** establishes a connection between a local RDBSS connection address and a given remote address.

## Parameters

### `pLocalAddress`

A pointer to the local RDBSS connection engine address.

### `pConnectionInformation` [in]

A pointer to the connection information that specifies the remote address.

### `pHandler` [in]

A pointer to the event handler for processing receive indications.

### `pEventContext` [in]

A pointer to the context parameter to be passed back to the event handler and used for indications.

### `pConnection` [in, out]

On input, this parameter contains a pointer to an uninitialized RDBSS connection. On output when this call is successful, the connection is properly initialized.

### `pVc` [in, out]

On input, this parameter contains a pointer to an uninitialized RDBSS virtual circuit. On output when this call is successful, the virtual circuit is associated with the connection and the virtual circuit is properly initialized.

## Return value

**RxCeBuildConnection** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |

## Remarks

**RxCeBuildConnection** should be called in the context of a system worker thread.

When **RxCeBuildConnection** is successful, the data members in the RXCE_CONNECTION structure pointed to by the *pConnection* parameter and the data members in the RXCE_VC structure pointed to by the *pVc* parameter will be properly initialized and the virtual circuit will be associated with the connection.

**RXCE_CONNECTION_INFORMATION** is a typedef for a **TDI_CONNECTION_INFORMATION** structure.

## See also

[RxCeTearDownConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownconnection)

[TDI_CONNECTION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565085(v=vs.85))