# IMessageFilter::RetryRejectedCall

## Description

Provides applications with an opportunity to display a dialog box offering retry, cancel, or task-switching options.

## Parameters

### `htaskCallee` [in]

The thread id of the called application.

### `dwTickCount` [in]

The number of elapsed ticks since the call was made.

### `dwRejectType` [in]

Specifies either SERVERCALL_REJECTED or SERVERCALL_RETRYLATER, as returned by the object application.

## Return value

This method can return the following values.

| Return value | Description |
| --- | --- |
| -1 | The call should be canceled. COM then returns RPC_E_CALL_REJECTED from the original method call. |
| 0 ≤ *value* < 100 | The call is to be retried immediately. |
| 100 ≤ *value* | COM will wait for this many milliseconds and then retry the call. |

## Remarks

COM calls **RetryRejectedCall** on the caller's [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface immediately after receiving SERVERCALL_RETRYLATER or SERVERCALL_REJECTED from the [IMessageFilter::HandleInComingCall](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imessagefilter-handleincomingcall) method on the callee's **IMessageFilter** interface.

If a called task rejects a call, the application is probably in a state where it cannot handle such calls, possibly only temporarily. When this occurs, COM returns to the caller and issues **RetryRejectedCall** to determine whether it should retry the rejected call.

Applications should silently retry calls that have returned with SERVERCALL_RETRYLATER. If, after a reasonable amount of time has passed, say about 30 seconds, the application should display the busy dialog box; a standard implementation of this dialog box is available in the OLEDLG library. The callee may momentarily be in a state where calls can be handled. The option to wait and retry is provided for special kinds of calling applications, such as background tasks executing macros or scripts, so that they can retry the calls in a nonintrusive way.

If, after a dialog box is displayed, the user chooses to cancel, **RetryRejectedCall** returns -1 and the call will appear to fail with RPC_E_CALL_REJECTED.

If a client implements [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) and calls a server method on a remote machine, **RetryRejectedCall** will not be called.

**Note** Although the *htaskCallee* parameter is typed as an HTASK, it contains the thread id of the called thread. When you implement the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) interface, you can call the [OpenThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthread) function to get the thread handle from the *htaskCallee* parameter, and you can call the [GetProcessIdOfThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getprocessidofthread) function to get the process id.

## See also

[IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter)