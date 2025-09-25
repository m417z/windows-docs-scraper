# CoTestCancel function

## Description

Determines whether the call being executed on the server has been canceled by the client.

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **RPC_S_CALLPENDING** | The call is still pending and has not yet been canceled by the client. |
| **RPC_E_CALL_CANCELED** | The call has been canceled by the client. |

## Remarks

Server objects should call **CoTestCancel** at least once before returning to detect client cancellation requests. Doing so can save the server unnecessary work if the client has issued a cancellation request, and it can reduce the client's wait time if it has set the cancel timeout as RPC_C_CANCEL_INFINITE_TIMEOUT. Furthermore, if the server object detects a cancellation request before returning from a pending call, it can clean up any memory, marshaled interfaces, or handles it has created or obtained.

**CoTestCancel** calls [CoGetCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcallcontext) to obtain the [ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls) interface on the current cancel object and then calls [ICancelMethodCalls::TestCancel](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icancelmethodcalls-testcancel). Objects that implement custom marshaling should first call [CoSwitchCallContext](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coswitchcallcontext) to install the appropriate call context object.

This function does not test cancellation for asynchronous calls.

## See also

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)