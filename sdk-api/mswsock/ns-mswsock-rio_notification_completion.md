# RIO_NOTIFICATION_COMPLETION structure

## Description

The **RIO_NOTIFICATION_COMPLETION** structure specifies the method for I/O completion to be used with a [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function for sending or receiving network data with the Winsock registered I/O extensions.

## Members

### `Type`

The type of completion to use with the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function when sending or receiving data.

### `Event`

### `Event.EventHandle`

The handle for the event to set following a completed [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) request.

This value is valid when the **Type**  member is set to **RIO_EVENT_COMPLETION**.

### `Event.NotifyReset`

The boolean value that causes the associated event to be reset when the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function is called. A non-zero value cause the associated event to be reset.

This value is valid when the **Type**  member is set to **RIO_EVENT_COMPLETION**.

### `Iocp`

### `Iocp.IocpHandle`

The handle for the I/O completion port to use for queuing a [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) request completion.

This value is valid when the **Type**  member is set to **RIO_IOCP_COMPLETION**.

### `Iocp.CompletionKey`

The value to use for *lpCompletionKey* parameter returned by the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func) function when queuing a [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) request.

This value is valid when the **Type**  member is set to **RIO_IOCP_COMPLETION**.

### `Iocp.Overlapped`

A pointer to the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure to use when queuing a [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) request completion. This member must point to a valid **OVERLAPPED** structure.

This value is valid when the **Type**  member is set to **RIO_IOCP_COMPLETION**.

## Remarks

The **RIO_NOTIFICATION_COMPLETION** structure is used to specify the behavior of the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function used with the Winsock registered I/O extensions.

The **RIO_NOTIFICATION_COMPLETION** structure is passed to the [RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue) function when a [RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue) is created. If an application does not call the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) function for a completion queue, the completion queue can be created without a **RIO_NOTIFICATION_COMPLETION** object.

For completion queues using an event, the **Type** member of the **RIO_NOTIFICATION_COMPLETION** structure is set to **RIO_EVENT_COMPLETION**. The **Event.EventHandle** member of the **RIO_NOTIFICATION_COMPLETION** structure should contain the handle for an event created by the [WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent) or [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. To receive the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) completion, the application should wait on the specified event handle using [WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents) or a similar wait routine. If the application plans to reset and reuse the event, the application can reduce overhead by setting the **Event.NotifyReset** member of the **RIO_NOTIFICATION_COMPLETION** structure to a non-zero value. This causes the event to be reset by the **RIONotify** function when notification occurs. This mitigates the need to call the [WSAResetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaresetevent) function to reset the event between calls to the **RIONotify** function.

For completion queues using an I/O completion port, the **Type** member of the **RIO_NOTIFICATION_COMPLETION** structure is set to **RIO_IOCP_COMPLETION**. The **Iocp.IocpHandle** member of the **RIO_NOTIFICATION_COMPLETION** structure should contain the handle for an I/O completion port created by the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. To receive the [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) completion, the application should call the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) or [GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func) function. The application should provide a dedicated [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) object for the completion queue, and it may also use the **Iocp.CompletionKey** member to distinguish **RIONotify** requests on the completion queue from other I/O completions including **RIONotify** completions for other completion queues.

An application using thread pools can use thread pool wait objects to get [RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify) completions via its thread pool. In that case, the call to the [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) function should immediately follow the call to **RIONotify**. If the **SetThreadpoolWait** function is called before **RIONotify** and the application relies on **RIONotify** to clear the event object, this may result in spurious executions of the wait object callback.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport)

[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus)

[GetQueuedCompletionStatusEx](https://learn.microsoft.com/windows/desktop/FileIO/getqueuedcompletionstatusex-func)

[OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped)

[RIOCreateCompletionQueue](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_riocreatecompletionqueue)

[RIONotify](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_rionotify)

[RIO_CQ](https://learn.microsoft.com/windows/desktop/WinSock/riocqueue)

[RIO_NOTIFICATION_COMPLETION_TYPE](https://learn.microsoft.com/windows/desktop/api/mswsock/ne-mswsock-rio_notification_completion_type)

[SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait)

[WSACreateEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacreateevent)

[WSAResetEvent](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaresetevent)

[WSAWaitForMultipleEvents](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsawaitformultipleevents)