# CoEnableCallCancellation function

## Description

Enables cancellation of synchronous calls on the calling thread.

## Parameters

### `pReserved` [in, optional]

This parameter is reserved and must be **NULL**.

## Return value

This function can return the standard return values S_OK, E_FAIL, E_INVALIDARG, and E_OUTOFMEMORY.

## Remarks

When call cancellation is enabled on a thread, marshaled synchronous calls from that thread to objects on the same computer can suffer serious performance degradation. By default, synchronous calls cannot be canceled, even if a cancel object is available. To enable call cancellation, you must call **CoEnableCallCancellation** first.

Unless you want to enable call cancellation on a thread at all times, you should pair calls to **CoEnableCallCancellation** with calls to [CoDisableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisablecallcancellation). Call cancellation is disabled only if **CoDisableCallCancellation** has been called once for each time **CoEnableCallCancellation** was called successfully.

A call will be cancelable or not depending on the state of the thread at the time the call was made. Subsequently enabling or disabling call cancellation has no effect on any calls that are pending on the thread.

## See also

[CoEnableCallCancellation](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coenablecallcancellation)

[ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls)