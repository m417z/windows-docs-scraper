# ICancelMethodCalls::TestCancel

## Description

Determines whether a call has been canceled.

## Return value

If the call was canceled, the return value is RPC_E_CALL_CANCELED. Otherwise, it is RPC_S_CALLPENDING.

## Remarks

The server object calls **TestCancel** to determine if the call has been canceled. If the call has been canceled, the server should clean up the necessary resources and return control to the client.

This method can be called from both the client and the server.

## See also

[CoTestCancel](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotestcancel)

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)