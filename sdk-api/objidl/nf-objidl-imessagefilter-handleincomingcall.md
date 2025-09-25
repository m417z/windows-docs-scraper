# IMessageFilter::HandleInComingCall

## Description

Provides a single entry point for incoming calls.

This method is called prior to each method invocation originating outside the current process and provides the ability to filter or reject incoming calls (or callbacks) to an object or a process.

## Parameters

### `dwCallType` [in]

The type of incoming call that has been received. Possible values are from the enumeration [CALLTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-calltype).

### `htaskCaller` [in]

The thread id of the caller.

### `dwTickCount` [in]

The elapsed tick count since the outgoing call was made, if *dwCallType* is not CALLTYPE_TOPLEVEL. If *dwCallType* is CALLTYPE_TOPLEVEL, *dwTickCount* should be ignored.

### `lpInterfaceInfo` [in]

A pointer to an [INTERFACEINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-interfaceinfo) structure that identifies the object, interface, and method being called. In the case of DDE calls, *lpInterfaceInfo* can be **NULL** because the DDE layer does not return interface information.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **SERVERCALL_ISHANDLED** | The application might be able to process the call. |
| **SERVERCALL_REJECTED** | The application cannot handle the call due to an unforeseen problem, such as network unavailability, or if it is in the process of terminating. |
| **SERVERCALL_RETRYLATER** | The application cannot handle the call at this time. An application might return this value when it is in a user-controlled modal state. |

## Remarks

If implemented, **HandleInComingCall** is called by COM when an incoming COM message is received.

Depending on an application's current state, a call is either accepted and processed or rejected (permanently or temporarily). If SERVERCALL_ISHANDLED is returned, the application may be able to process the call, although success depends on the interface for which the call is destined. If the call cannot be processed, COM returns RPC_E_CALL_REJECTED.

Input-synchronized and asynchronous calls are dispatched even if the application returns SERVERCALL_REJECTED or SERVERCALL_RETRYLATER.

**HandleInComingCall** should not be used to hold off updates to objects during operations such as band printing. For that purpose, use [IViewObject::Freeze](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-freeze).

You can also use **HandleInComingCall** to set up the application's state so that the call can be processed in the future.

**Note** Although the *htaskCaller* parameter is typed as an HTASK, it contains the thread id of the calling thread. When you implement the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface, you can call the [OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to get the thread handle from the *htaskCaller* parameter, and you can call the [GetProcessIdOfThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessidofthread) function to get the process id.

## See also

[IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter)