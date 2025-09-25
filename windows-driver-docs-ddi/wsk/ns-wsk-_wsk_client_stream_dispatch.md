# _WSK_CLIENT_STREAM_DISPATCH structure

## Description

The WSK_CLIENT_STREAM_DISPATCH structure specifies a WSK application's dispatch table of event callback functions for a stream socket. Because a stream socket can act either as a listening socket or a connection-oriented socket, this structure allows a stream socket to access the dispatch tables for both the WSK_CLIENT_LISTEN_DISPATCH structure and the WSK_CLIENT_CONNECTION_DISPATCH structure.

## Members

### `Listen`

A pointer to a [WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch) structure, which specifies a WSK application's dispatch table of event
callback functions for a stream socket which is acting as a listening socket.

### `Connect`

A pointer to a [WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch) structure, which specifies a WSK application's dispatch table of event
callback functions for a stream socket which is acting as a connection-oriented socket.

## Remarks

A WSK application passes a pointer to a **WSK_CLIENT_STREAM_DISPATCH** structure to the WSK subsystem when
the WSK application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a stream
socket.

## See also

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)