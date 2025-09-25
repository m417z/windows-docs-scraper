# _WSK_PROVIDER_STREAM_DISPATCH structure

## Description

The WSK_PROVIDER_STREAM_DISPATCH structure specifies the WSK subsystem's table of functions for a
stream socket.

## Members

### `Basic`

The members of the
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure are included as members of the WSK_PROVIDER_STREAM_DISPATCH
structure.

### `WskBind`

A pointer to the WSK subsystem's
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function for the socket.

### `WskAccept`

A pointer to the WSK subsystem's
[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function for the socket.

### `WskConnect`

A pointer to the WSK subsystem's
[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function for the socket.

### `WskListen`

A pointer to the WSK subsystem's
[WskListen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_listen) function for the socket.

### `WskSend`

A pointer to the WSK subsystem's
[WskSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send) function for the socket.

### `WskReceive`

A pointer to the WSK subsystem's
[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive) function for the socket.

### `WskDisconnect`

A pointer to the WSK subsystem's
[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect) function for the
socket.

### `WskRelease`

A pointer to the WSK subsystem's
[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)) function for the socket.

### `WskGetLocalAddress`

A pointer to the WSK subsystem's
[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address) function for the
socket.

### `WskGetRemoteAddress`

A pointer to the WSK subsystem's
[WskGetRemoteAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_remote_address) function for the
socket.

### `WskConnectEx`

A pointer to the WSK subsystem's
[WskConnectEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect_ex) function for the
socket.

### `WskSendEx`

This member is reserved for system use.

### `WskReceiveEx`

This member is reserved for system use.

## Remarks

The member list of the WSK_PROVIDER_STREAM_DISPATCH structure includes an unnamed
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure. The compiler that is included with the WDK supports a
Microsoft-specific extension to the C language that allows unnamed structures within structure
declarations. The result is that the structure members of the WSK_PROVIDER_BASIC_DISPATCH structure are
included in the WSK_PROVIDER_STREAM_DISPATCH structure as if they were native members of the
WSK_PROVIDER_STREAM_DISPATCH structure.

A WSK application receives a pointer to a WSK_PROVIDER_STREAM_DISPATCH structure when the WSK
application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a stream socket.
The pointer is contained in the
**Dispatch** member of the
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that is received from the
WSK subsystem.

## See also

[WSK_CLIENT_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_stream_dispatch)

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)