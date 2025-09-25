# CoDisableCallCancellation function

## Description

Undoes the action of a call to [CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation). Disables cancellation of synchronous calls on the calling thread when all calls to **CoEnableCallCancellation** are balanced by calls to **CoDisableCallCancellation**.

## Parameters

### `pReserved` [in, optional]

This parameter is reserved and must be **NULL**.

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Call cancellation was successfully disabled on the thread. |
| **CO_E_CANCEL_DISABLED** | There have been more successful calls to [CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation) on the thread than there have been calls to [CoDisableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisablecallcancellation). Cancellation is still enabled on the thread. |

## Remarks

When call cancellation is enabled on a thread, marshaled synchronous calls from that thread to objects on the same computer can suffer serious performance degradation. By default, then, synchronous calls cannot be canceled, even if a cancel object is available. To enable call cancellation, you must call [CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation) first.

When call cancellation is disabled, attempts to gain a pointer to a call object will fail. If the calling thread already has a pointer to a call object, calls on that object will fail.

Unless you want to enable call cancellation on a thread at all times, you should pair calls to [CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation) with calls to **CoDisableCallCancellation**. Call cancellation is disabled only if each successful call to **CoEnableCallCancellation** is balanced by a successful call to **CoDisableCallCancellation**.

A call will be cancelable or not depending on the state of the thread at the time the call was made. Subsequently enabling or disabling call cancellation has no effect on any calls that are pending on the thread.

If a thread is uninitialized and then reinitialized by calls to [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) and [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize), call cancellation is disabled on the thread, even if it was enabled when the thread was uninitialized.

## See also

[CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation)

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)