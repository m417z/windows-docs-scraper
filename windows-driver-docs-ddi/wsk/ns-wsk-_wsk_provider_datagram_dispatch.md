# _WSK_PROVIDER_DATAGRAM_DISPATCH structure

## Description

The WSK_PROVIDER_DATAGRAM_DISPATCH structure specifies the WSK subsystem's table of functions for a
datagram socket.

## Members

### `Basic`

The members of the
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure are included as members of the
WSK_PROVIDER_DATAGRAM_DISPATCH structure.

### `WskBind`

A pointer to the WSK subsystem's
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function for the socket.

### `WskSendTo`

A pointer to the WSK subsystem's
[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_to) function for the socket.

### `WskReceiveFrom`

A pointer to the WSK subsystem's
[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from) function for the
socket.

### `WskRelease`

A pointer to the WSK subsystem's
[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)) function for the socket.

### `WskGetLocalAddress`

A pointer to the WSK subsystem's
[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address) function for the
socket.

### `WskSendMessages`

A pointer to the WSK subsystem's
[WskSendMessages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_messages) function for the
socket.

## Remarks

The member list of the WSK_PROVIDER_DATAGRAM_DISPATCH structure includes an unnamed
[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch) structure. The compiler that is included with the WDK supports a
Microsoft-specific extension to the C language that allows unnamed structures within structure
declarations. The result is that the structure members of the WSK_PROVIDER_BASIC_DISPATCH structure are
included in the WSK_PROVIDER_DATAGRAM_DISPATCH structure as if they were native members of the
WSK_PROVIDER_DATAGRAM_DISPATCH structure.

A WSK application receives a pointer to a WSK_PROVIDER_DATAGRAM_DISPATCH structure when the WSK
application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a datagram socket.
The pointer is contained in the
**Dispatch** member of the
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that is received from the
WSK subsystem .

## See also

[WSK_CLIENT_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_datagram_dispatch)

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from)

[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85))

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_to)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)