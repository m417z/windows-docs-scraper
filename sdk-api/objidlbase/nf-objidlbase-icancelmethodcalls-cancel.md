# ICancelMethodCalls::Cancel

## Description

Requests that a method call be canceled.

## Parameters

### `ulSeconds` [in]

The number of seconds to wait for the server to complete the outbound call after the client requests cancellation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The cancellation request was made. |
| **RPC_S_CALL_CANCELED** | The call was already canceled. |
| **CO_E_CANCEL_DISABLED** | Call cancellation is not enabled on the thread that is processing the call. |
| **RPC_E_CALL_COMPLETE** | The call was completed during the timeout interval. |

## Remarks

The **Cancel** method only issues a cancel request. A return value of S_OK does not mean that the call was canceled, only that an attempt was made to cancel the call. The behavior of the cancel object on receiving a cancel request is entirely at the discretion of the implementer.

If a method that returns an **HRESULT** is canceled, the return value will be RPC_S_CALL_CANCELED.

## See also

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)