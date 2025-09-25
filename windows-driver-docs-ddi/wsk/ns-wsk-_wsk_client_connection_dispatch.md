# _WSK_CLIENT_CONNECTION_DISPATCH structure

## Description

The WSK_CLIENT_CONNECTION_DISPATCH structure specifies a WSK application's dispatch table of event
callback functions for a connection-oriented socket.

## Members

### `WskReceiveEvent`

A pointer to the WSK application's
[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event) event callback function
for the socket. If the WSK application does not enable the
*WskReceiveEvent* event callback function for the socket, this pointer can be **NULL**.

### `WskDisconnectEvent`

A pointer to the WSK application's
[WskDisconnectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect_event) event callback
function for the socket. If the WSK application does not enable the
*WskDisconnectEvent* event callback function for the socket, this pointer can be **NULL**.

### `WskSendBacklogEvent`

A pointer to the WSK application's
[WskSendBacklogEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_backlog_event) event callback
function for the socket. If the WSK application does not enable the
*WskSendBacklogEvent* event callback function for the socket, this pointer can be **NULL**.

## Remarks

A WSK application passes a pointer to a WSK_CLIENT_CONNECTION_DISPATCH structure to the WSK subsystem
in one of the following ways:

* When calling the
  [WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a
  connection-oriented socket.
* When calling the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function to create,
  bind, and connect a connection-oriented socket.
* When calling the
  [WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function to accept an incoming
  connection-oriented socket on a listening socket.
* As a returned parameter when the WSK subsystem calls the WSK application's
  [WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function.
  The WSK subsystem calls a WSK application's
  *WskAcceptEvent* event callback function to notify the WSK application that an incoming
  connection-oriented socket has been accepted on a listening socket.

## See also

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskDisconnectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect_event)

[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event)

[WskSendBacklogEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_backlog_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)