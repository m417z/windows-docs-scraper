# _WSK_SOCKET structure

## Description

The WSK_SOCKET structure defines a socket object for a socket.

## Members

### `Dispatch`

A pointer to a constant provider dispatch structure. This structure is a dispatch table that
contains pointers to a socket's functions. Depending on the WSK
[socket category](https://learn.microsoft.com/windows-hardware/drivers/network/winsock-kernel-socket-categories) of the
socket, this pointer is a pointer to one of the following structures:

| Socket category | Dispatch table structure |
| --- | --- |
| Basic socket | [WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) |
| Listening socket | [WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch) |
| Datagram socket | [WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch) |
| Connection-oriented socket | [WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch) |
| Stream socket | [WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch) |

## Remarks

The WSK subsystem allocates and fills in a WSK_SOCKET structure whenever a new socket is created. A
WSK application receives a pointer to the WSK_SOCKET structure for a socket from the WSK subsystem in one
of the following ways:

* The WSK application calls the
  [WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a socket.
* The WSK application calls the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function to create,
  bind, and connect a connection-oriented socket.
* The WSK application calls the
  [WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function to accept an incoming
  connection-oriented socket on a listening socket.
* The WSK subsystem calls the WSK application's
  [WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function to
  notify the WSK application that an incoming connection-oriented socket has been accepted on a listening
  socket.

A WSK application passes the pointer to a socket's WSK_SOCKET structure when calling any of the
socket's functions.

The WSK subsystem frees the memory for the WSK_SOCKET structure when the WSK application calls the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the
socket.

## See also

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)