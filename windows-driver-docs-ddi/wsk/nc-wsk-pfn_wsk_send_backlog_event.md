# PFN_WSK_SEND_BACKLOG_EVENT callback function

## Description

The
*WskSendBacklogEvent* event callback function notifies a WSK application when the ideal send backlog
size changes for a connection-oriented socket.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the connection-oriented socket that is notifying the WSK
application about a change to its ideal send backlog size. The WSK application provided this pointer to
the WSK subsystem in one of the following ways:

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

### `IdealBacklogSize` [in]

A variable that contains the new ideal send backlog size.

## Return value

A WSK application's
*WskSendBacklogEvent* event callback function must always return STATUS_SUCCESS.

## Remarks

The WSK subsystem calls a WSK application's
*WskSendBacklogEvent* event callback function when the ideal send backlog size changes for a
connection-oriented socket only if the event callback function was previously enabled with the
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket option.
For more information about enabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/network/enabling-and-disabling-event-callback-functions).

The ideal send backlog size for a connection-oriented socket is the optimal amount of send data that
needs to be kept outstanding (that is, passed to the WSK subsystem but not yet completed) to keep the
socket's data stream full at all times. A WSK application can use this size to incrementally probe and
lock the buffers of data to be sent based on the underlying connection's flow control state.

A WSK application can obtain the current ideal backlog size for a connection-oriented socket at any
time by calling the
[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function.

The WSK subsystem calls a WSK application's
*WskSendBacklogEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskSendBacklogEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)