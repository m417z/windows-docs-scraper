# RPC_ASYNC_NOTIFICATION_INFO structure

## Description

The **RPC_ASYNC_NOTIFICATION_INFO** union contains notification information for asynchronous remote procedure calls. This notification information can be configured for I/O completion ports (IOC), Windows asynchronous procedure calls (APC), Windows messaging, and Windows event notification.

## Members

### `APC`

Structure used for Windows asynchronous procedure call (APC) notifications.

### `APC.NotificationRoutine`

Calls the user-defined APC notification routine.

### `APC.hThread`

Handle to the thread on which the notification APC should be posted. A value of zero indicates the current thread.

### `IOC`

Structure used for notification on an I/O completion port.

### `IOC.hIOPort`

Handle to the I/O completion port.

### `IOC.dwNumberOfBytesTransferred`

Set by the RPC client before the asynchronous call is started. When the notification is delivered to the completion port, this value is filled in the location pointed to by the *lpNumberOfBytesTransferred* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

### `IOC.dwCompletionKey`

Set by the RPC client before the asynchronous call is started. When the notification is delivered to the completion port, this value is filled in the location pointed to by the *lpCompletionKey* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

### `IOC.lpOverlapped`

Set by the RPC client before the asynchronous call is started. When the notification is delivered to the completion port, this value is filled in the location pointed to by the *lpOverlapped* parameter of the
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function.

### `HWND`

Fields used for notification by a Windows message. When the RPC run time posts the message, **wParam** is zero, and **lParam** points to the asynchronous handle for the call (the
[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)).

**Windows Server 2003 or later:** Notification via the HWND is deprecated. Do not use this member.

### `HWND.hWnd`

Identifies the window to which the message should be posted.

### `HWND.Msg`

Message to be posted.

### `hEvent`

Handle used for notification by an event.

### `Event`

### `NotificationRoutine`

Windows Vista or earlier versions of Windows: COM uses this internally for direct callbacks. Do not use this member.

Windows 7 or later versions of Windows: An optional function pointer to a user-defined notification scheme built on top of RPC call completion. As an example, an application could call [SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork) from the notification callback.

**Note** Making additional RPC calls, blocking, or performing long running work from notification callbacks is strongly discouraged.

## Remarks

Prior to Windows Vista and earlier versions of Windows, the **RPC_ASYNC_NOTIFICATION_INFO** union was part of the [RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state) structure. Please see the **RPC_ASYNC_STATE** topic for additional information.

## See also

[RPC_ASYNC_STATE](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_state)