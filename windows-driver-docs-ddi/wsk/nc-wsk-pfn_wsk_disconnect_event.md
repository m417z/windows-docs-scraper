# PFN_WSK_DISCONNECT_EVENT callback function

## Description

The
*WskDisconnectEvent* event callback function notifies a WSK application that a connection on a
connection-oriented socket has been disconnected by the remote application.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the connection-oriented socket that has been disconnected. The
WSK application provided this pointer to the WSK subsystem in one of the following ways:

* It called the
  [WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the socket.
* It called the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function to create
  the socket.
* It called the
  [WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function to accept the socket as an
  incoming connection.
* Its
  [WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function
  was called to accept the socket as an incoming connection.

### `Flags` [in]

A ULONG value that contains a bitwise OR of a combination of the following flags:

#### WSK_FLAG_ABORTIVE

The remote application performed an abortive disconnect of the socket. If this flag is not set,
the remote application performed a graceful disconnect of the socket.

#### WSK_FLAG_AT_DISPATCH_LEVEL

The WSK subsystem called the
*WskDisconnectEvent* event callback function at IRQL = DISPATCH_LEVEL. If this flag is not set,
the WSK subsystem might have called the
*WskDisconnectEvent* event callback function at any IRQL <= DISPATCH_LEVEL.

## Return value

A WSK application's
*WskDisconnectEvent* event callback function must always return STATUS_SUCCESS.

## Remarks

The WSK subsystem calls a WSK application's
*WskDisconnectEvent* event callback function when a connection-oriented socket is disconnected by the
remote application only if the event callback function was previously enabled with the
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket option.
For more information about enabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/network/enabling-and-disabling-event-callback-functions).

If the remote application performed a graceful disconnect of the socket, no further data will be
received from the socket. However, the WSK application can still send data to the socket until the socket
is either completely closed by the remote application or the WSK application calls the
[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect) function or the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function on the socket.

If the remote application performed an abortive disconnect of the socket, no further data will be
received from the socket and no further data can be sent to the socket.

The WSK subsystem calls a WSK application's
*WskDisconnectEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskDisconnectEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)