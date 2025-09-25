# _WSK_CLIENT_DATAGRAM_DISPATCH structure

## Description

The WSK_CLIENT_DATAGRAM_DISPATCH structure specifies a WSK application's dispatch table of event
callback functions for a datagram socket.

## Members

### `WskReceiveFromEvent`

A pointer to the WSK application's
[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event) event callback
function for the socket. If the WSK application does not enable the
*WskReceiveFromEvent* event callback function for the socket, this pointer can be **NULL**.

## Remarks

A WSK application passes a pointer to a WSK_CLIENT_DATAGRAM_DISPATCH structure to the WSK subsystem
when the WSK application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a datagram
socket.

## See also

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)