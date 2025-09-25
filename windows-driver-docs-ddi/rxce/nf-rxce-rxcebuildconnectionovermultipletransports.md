# RxCeBuildConnectionOverMultipleTransports function

## Description

**RxCeBuildConnectionOverMultipleTransports** establishes a connection between a local RDBSS connection address and a given remote address and supports multiple transports. A set of local addresses are specified and this routine attempts to connect to the target server via all the transports associated with the local addresses. One connection is chosen as the winner depending on the connect options.

## Parameters

### `pMiniRedirectorDeviceObject` [in, out]

A pointer to the mini-redirector device object.

### `CreateOption`

Create options that determine which transport will be selected for establishing a connection. These options can be one of the following enumerations for RXCE_CONNECTION_CREATE_OPTIONS:

RxCeSelectFirstSuccessfulTransport

Select the first successful transport that responds.

RxCeSelectBestSuccessfulTransport

Select the best successful transport that responds.

RxCeSelectAllSuccessfulTransports

Select all of the successful transports that respond.

### `NumberOfAddresses` [in]

The number of local addresses (transports).

### `pLocalAddressPointers` [in]

A pointer to an array of the local address handles.

### `pServerName` [in]

A pointer to the name of the server (for connection enumeration).

### `pConnectionInformation` [in]

A pointer to the connection information that specifies the remote address.

### `pHandler` [in]

A pointer to the event handler for processing receive indications.

### `pEventContext` [in]

A pointer to the context parameter to be passed back to the event handler and used for indications.

### `pCompletionRoutine` [in]

A pointer to a connection completion routine when this routine completed if STATUS_PENDING is initially returned.

### `pCompletionContext` [in, out]

On input, this parameter contains a pointer to an uninitialized RXCE_CONNECTION_COMPLETION_CONTEXT structure. On output when this call is successful, the virtual circuit is associated with the connection and the virtual circuit and connection are properly initialized.

## Return value

**RxCeBuildConnectionOverMultipleTransports** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_HANDLE** | It was not possible to initialize a connection and a virtual circuit with any of the multiple transports. This error can occur if all of the RDBSS transports or the RBDSS connection engine addresses pointed to in the *pLocalAddressPointers* array are invalid. |
| **STATUS_INVALID_PARAMETER** | One of the parameters passed to this routine was invalid. |
| **STATUS_PENDING** | One of the asynchronous calls to the different transports passed as input parameters to the routine is still outstanding and has not been completed. |

## Remarks

**RxCeBuildConnectionOverMultipleTransports** will initiate a series of asynchronous calls to all of the different transports passed in as parameters to try and build a connection. The network mini-redirector cannot be unloaded until all of these asynchronous requests are completed.

**RxCeBuildConnectionOverMultipleTransports** must be called in the context of a system worker thread.

When **RxCeBuildConnectionOverMultipleTransports** is successful, the virtual circuit will be properly initialized and connections will be established.

**RXCE_CONNECTION_INFORMATION** is a typedef for a **TDI_CONNECTION_INFORMATION** structure.

## See also

[RxCeBuildConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcebuildconnection)

[RxCeTearDownConnection](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxceteardownconnection)

[TDI_CONNECTION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565085(v=vs.85))