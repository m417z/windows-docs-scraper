# IMessageFilter::MessagePending

## Description

Indicates that a message has arrived while COM is waiting to respond to a remote call.

Handling input while waiting for an outgoing call to finish can introduce complications. The application should determine whether to process the message without interrupting the call, to continue waiting, or to cancel the operation.

## Parameters

### `htaskCallee` [in]

The thread id of the called application.

### `dwTickCount` [in]

The number of ticks since the call was made. It is calculated from the [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) function.

### `dwPendingType` [in]

The type of call made during which a message or event was received. Possible values are from the enumeration [PENDINGTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-pendingtype), where PENDINGTYPE_TOPLEVEL means the outgoing call was not nested within a call from another application and PENDINTGYPE_NESTED means the outgoing call was nested within a call from another application.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **PENDINGMSG_CANCELCALL** | Cancel the outgoing call. This should be returned only under extreme conditions. Canceling a call that has not replied or been rejected can create orphan transactions and lose resources. COM fails the original call and returns RPC_E_CALL_CANCELLED. |
| **PENDINGMSG_WAITNOPROCESS** | Unused. |
| **PENDINGMSG_WAITDEFPROCESS** | Keyboard and mouse messages are no longer dispatched. However there are some cases where mouse and keyboard messages could cause the system to deadlock, and in these cases, mouse and keyboard messages are discarded. WM_PAINT messages are dispatched. Task-switching and activation messages are handled as before. |

## Remarks

COM calls **MessagePending** after an application has made a COM method call and a Windows message occurs before the call has returned. A Windows message is sent, for example, when the user selects a menu command or double-clicks an object. Before COM makes the **MessagePending** call, it calculates the elapsed time since the original COM method call was made. COM delivers the elapsed time in the *dwTickCount* parameter. In the meantime, COM does not remove the message from the queue.

Windows messages that appear in the caller's queue should remain in the queue until sufficient time has passed to ensure that the messages are probably not the result of typing ahead, but are instead an attempt to get attention. Set the delay with the *dwTickCount* parameter —a two-second or three-second delay is recommended. If that amount of time passes and the call has not been completed, the caller should flush the messages from the queue and the OLE UI busy dialog box should be displayed offering the user the choice of retrying the call (continue waiting) or switching to the specified task. This ensures the following behaviors:

* If calls are completed in a reasonable amount of time, type ahead will be treated correctly.
* If the callee does not respond, type ahead is not misinterpreted and the user is able to act to solve the problem. For example, OLE 1 servers can queue up requests without responding when they are in modal dialog boxes.

Handling input while waiting for an outgoing call to finish can introduce complications. The application should determine whether to process the message without interrupting the call, to continue waiting, or to cancel the operation.

When there is no response to the original COM call, the application can cancel the call and restore the COM object to a consistent state by calling [IStorage::Revert](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-revert) on its storage. The object can be released when the container can shut down. However, canceling a call can create orphaned operations and resource leaks. Canceling should be used only as a last resort. It is strongly recommended that applications not allow such calls to be canceled.

**Note** Although the *htaskCallee* parameter is typed as an HTASK, it contains the thread id of the called thread. When you implement the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface, you can call the [OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to get the thread handle from the *htaskCallee* parameter, and you can call the [GetProcessIdOfThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessidofthread) function to get the process id.

## See also

[IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter)

[OleUIBusy](https://learn.microsoft.com/windows/desktop/api/oledlg/nf-oledlg-oleuibusya)