# RIO_NOTIFICATION_COMPLETION_TYPE enumeration

## Description

The **RIO_NOTIFICATION_COMPLETION_TYPE** enumeration specifies the type of completion queue notifications to use with the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function when sending or receiving data using the Winsock registered I/O extensions.

## Constants

### `RIO_EVENT_COMPLETION:1`

An event handle is used to signal completion queue notifications.

An event handle is provided as the **EventNotify.EventHandle** member in the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function when the [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue) is created. The completion of the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function for this **RIO_CQ** will signal the event. The **Event.NotifyReset** member in the **RIO_NOTIFICATION_COMPLETION** structure passed to the **RIOCreateCompletionQueue** function when the **RIO_CQ** is created indicates whether or not the event should be reset as part of a call to the **RIONotify** function.

### `RIO_IOCP_COMPLETION:2`

An I/O completion port handle is used to signal completion queue notifications.

An I/O completion port handle is provided as the **Iocp.IocpHandle** member in the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function when the [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue) is created. The completion of the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function for this **RIO_CQ** will queue an entry to the I/O completion port which can be retrieved using the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func) function. The queued entry will have the returned *lpCompletionKey* parameter value set to the value specified in the **Iocp.CompletionKey** member of the **RIO_NOTIFICATION_COMPLETION** and the returned *lpOverlapped* parameter value set to the value specified in the **Iocp.Overlapped** member in **RIO_NOTIFICATION_COMPLETION** structure. The **Iocp.Overlapped** member in the **RIO_NOTIFICATION_COMPLETION** will be a non-NULL value.

## Remarks

The **RIO_NOTIFICATION_COMPLETION_TYPE** enumeration is used with the Winsock registered I/O extensions to specify the type of I/O completion to use with a [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue). An enumeration value is set in the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function when the **RIO_CQ** is created.

When creating a [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue), the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure determines how the application will receive completion queue notifications. If the **RIO_NOTIFICATION_COMPLETION** structure is provided when creating the completion queue, the application may call the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function to request a completion queue notification. Normally this notification occurs when the completion queue is not empty. This may happen immediately or when the next completion entry is inserted into the completion queue. Once a completion queue notification is issued, the application must call **RIONotify** in order to receive another completion queue notification.

Two options are available for completion queue notification.

* Event handles.
* I/O completion ports

If the **Type** member of the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure is set to **RIO_EVENT_COMPLETION**, an event handle is used to signal completion queue notifications. An event handle is provided as the **EventNotify.EventHandle** member in the **RIO_NOTIFICATION_COMPLETION** structure passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function.

If the **Type** member of the [RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion) structure is set to **RIO_IOCP_COMPLETION**, an I/O completion port is used to signal completion queue notifications. An I/O completion port handle is provided as the **Iocp.IocpHandle** member in the **RIO_NOTIFICATION_COMPLETION** structure passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function. The completion of the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function for this [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue) will queue an entry to the I/O completion port which can be retrieved using the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func) function.

## See also

[RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue)

[RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify)

[RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue)

[RIO_NOTIFICATION_COMPLETION](https://learn.microsoft.com/windows/desktop/api/mswsock/ns-mswsock-rio_notification_completion)