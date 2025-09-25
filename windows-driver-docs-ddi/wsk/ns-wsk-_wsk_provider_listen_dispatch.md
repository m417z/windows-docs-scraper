# _WSK_PROVIDER_LISTEN_DISPATCH structure

## Description

The WSK_PROVIDER_LISTEN_DISPATCH structure specifies the WSK subsystem's table of functions for a
listening socket.

## Members

### `Basic`

The members of the
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure are included as members of the WSK_PROVIDER_LISTEN_DISPATCH
structure.

### `WskBind`

A pointer to the WSK subsystem's
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function for the socket.

### `WskAccept`

A pointer to the WSK subsystem's
[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function for the socket.

### `WskInspectComplete`

A pointer to the WSK subsystem's
[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete) function for the
socket.

### `WskGetLocalAddress`

A pointer to the WSK subsystem's
[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address) function for the
socket.

## Remarks

The member list of the WSK_PROVIDER_LISTEN_DISPATCH structure includes an unnamed
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure. The compiler that is included with the WDK supports a
Microsoft-specific extension to the C language that allows unnamed structures within structure
declarations. The result is that the structure members of the WSK_PROVIDER_BASIC_DISPATCH structure are
included in the WSK_PROVIDER_LISTEN_DISPATCH structure as if they were native members of the
WSK_PROVIDER_LISTEN_DISPATCH structure.

A WSK application receives a pointer to a WSK_PROVIDER_LISTEN_DISPATCH structure when the WSK
application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a listening socket.
The pointer is contained in the
**Dispatch** member of the
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that is received from the
WSK subsystem.

## See also

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)