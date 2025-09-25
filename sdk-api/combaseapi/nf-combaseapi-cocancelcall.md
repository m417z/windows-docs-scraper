# CoCancelCall function

## Description

Requests cancellation of an outbound DCOM method call pending on a specified thread.

## Parameters

### `dwThreadId` [in]

The identifier of the thread on which the pending DCOM call is to be canceled. If this parameter is 0, the call is on the current thread.

### `ulTimeout` [in]

The number of seconds **CoCancelCall** waits for the server to complete the outbound call after the client requests cancellation.

## Return value

This function can return the standard return values E_FAIL, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The cancellation request was made. |
| **E_NOINTERFACE** | There is no cancel object corresponding to the specified thread. |
| **CO_E_CANCEL_DISABLED** | Call cancellation is not enabled on the specified thread. |
| **RPC_E_CALL_COMPLETE** | The call was completed during the timeout interval. |
| **RPC_E_CALL_CANCELED** | The call was already canceled. |

## Remarks

**CoCancelCall** calls [CoGetCancelObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcancelobject) and then [ICancelMethodCalls::Cancel](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icancelmethodcalls-cancel) on the cancel object for the call being executed.

This function does not locate cancel objects for asynchronous calls.

The object server can determine if the call has been canceled by periodically calling [CoTestCancel](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotestcancel). If the call has been canceled, the object server should clean up and return control to the client.

## See also

[CoTestCancel](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotestcancel)