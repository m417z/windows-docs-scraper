# RPC_NOTIFICATION_TYPES enumeration

## Description

The
**RPC_NOTIFICATION_TYPES** enumerated type contains values that specify the method of asynchronous notification that a client program will use.

## Constants

### `RpcNotificationTypeNone`

The client does not require notification of the completion of an asynchronous remote procedure call.

### `RpcNotificationTypeEvent`

Notify the client program by signaling an event object. See
[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects).

### `RpcNotificationTypeApc`

Use an asynchronous procedure call to notify the client that the remote procedure call is complete.

### `RpcNotificationTypeIoc`

Send the asynchronous RPC notification to the client through an I/O completion port.

### `RpcNotificationTypeHwnd`

Post a notification message to the specified window handle.

### `RpcNotificationTypeCallback`

Invoke a callback function provided by the client program.

## See also

[Making the Asynchronous Call](https://learn.microsoft.com/windows/desktop/Rpc/making-the-asynchronous-call)