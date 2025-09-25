# COWAIT_FLAGS enumeration

## Description

Specifies the behavior of the [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) function.

## Constants

### `COWAIT_DEFAULT:0`

Dispatch calls needed for marshaling without dispatching arbitrary calls.

### `COWAIT_WAITALL:1`

If set, the call to [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) will return S_OK only when all handles associated with the synchronization object have been signaled and an input event has been received, all at the same time. In this case, the behavior of **CoWaitForMultipleHandles** corresponds to the behavior of the [MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex) function with the *dwFlags* parameter set to **MWMO_WAITALL**. If **COWAIT_WAITALL** is not set, the call to **CoWaitForMultipleHandles** will return S_OK as soon as any handle associated with the synchronization object has been signaled, regardless of whether an input event is received.

### `COWAIT_ALERTABLE:2`

If set, the call to [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) will return S_OK if an asynchronous procedure call (APC) has been queued to the calling thread with a call to the [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc) function, even if no handle has been signaled.

### `COWAIT_INPUTAVAILABLE:4`

If set, the call to [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) will return S_OK if input exists for the queue, even if the input has been seen (but not removed) using a call to another function, such as [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea).

### `COWAIT_DISPATCH_CALLS:8`

Dispatch calls from [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) in an ASTA. Default is no call dispatch. This value has no meaning in other apartment types and is ignored.

### `COWAIT_DISPATCH_WINDOW_MESSAGES:0x10`

Enables dispatch of window messages from [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles) in an ASTA or STA. Default in ASTA is no window messages dispatched, default in STA is only a small set of special-cased messages dispatched. The value has no meaning in MTA and is ignored.

## See also

[CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles)

[ISynchronize::Wait](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isynchronize-wait)

[ISynchronizeContainer::WaitMultiple](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isynchronizecontainer-waitmultiple)