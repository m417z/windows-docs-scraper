# CoGetCancelObject function

## Description

Obtains a pointer to a call control interface, normally [ICancelMethodCalls](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icancelmethodcalls), on the cancel object corresponding to an outbound COM method call pending on the same or another client thread.

## Parameters

### `dwThreadId` [in]

The identifier of the thread on which the pending COM call is to be canceled. If this parameter is 0, the call is on the current thread.

### `iid` [in]

The globally unique identifier of an interface on the cancel object for the call to be canceled. This argument is usually IID_ICancelMethodCalls.

### `ppUnk` [out]

Receives the address of a pointer to the interface specified by *riid*.

## Return value

This function can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call control object was retrieved successfully. |
| **E_NOINTERFACE** | The object on which the call is executing does not support the interface specified by *riid*. |

## Remarks

If two or more calls are pending on the same thread through nested calls, the thread ID may not be sufficient to identify the call to be canceled. In this case, **CoGetCancelObject** returns a cancel interface corresponding to the innermost call that is pending on the thread and has registered a cancel object.

This function does not locate cancel objects for asynchronous calls.