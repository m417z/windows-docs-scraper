## Description

This inline helper function is provided as a convenience to retrieve the events mask from an [OVERLAPPED_ENTRY](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped_entry).

For more info, and code examples, see [Winsock socket state notifications](https://learn.microsoft.com/windows/win32/winsock/winsock-socket-state-notifications).

## Parameters

### `notification`

Type: \_In\_ **[OVERLAPPED_ENTRY](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped_entry)\***

A pointer to an [OVERLAPPED_ENTRY](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped_entry) received for a socket state notification.

## Return value

A [UINT32](https://learn.microsoft.com/windows/win32/winprog/windows-data-types) containing a bitmask of the notification events for the socket.

This table lists the socket notification events. These are the events possible when a notification is received.

|Event|Description|
|-|-|
|SOCK_NOTIFY_EVENT_IN|Input is available from the socket without blocking.|
|SOCK_NOTIFY_EVENT_OUT|Output can be provided to the socket without blocking.|
|SOCK_NOTIFY_EVENT_HANGUP|The socket connection has terminated.|
|SOCK_NOTIFY_EVENT_ERR|The socket is in an error state.|
|SOCK_NOTIFY_EVENT_REMOVE|The notification has been deregistered.|

## Remarks

The **SOCK_NOTIFY_EVENT_ERR** and **SOCK_NOTIFY_EVENT_REMOVE** events might be indicated regardless of registered event filter.

If a **SOCK_NOTIFY_EVENT_REMOVE** event is indicated, then no more notifications will be provided.

## See also

* [OVERLAPPED_ENTRY](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped_entry)
* [ProcessSocketNotifications](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-processsocketnotifications)
* [Winsock socket state notifications](https://learn.microsoft.com/windows/win32/winsock/winsock-socket-state-notifications)