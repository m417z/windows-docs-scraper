# _WSK_CLIENT_LISTEN_DISPATCH structure

## Description

The WSK_CLIENT_LISTEN_DISPATCH structure specifies a WSK application's dispatch table of event
callback functions for a listening socket.

## Members

### `WskAcceptEvent`

A pointer to the WSK application's
[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function for
the socket. If the WSK application does not enable the
*WskAcceptEvent* event callback function for the socket, this pointer can be **NULL**.

### `WskInspectEvent`

A pointer to the WSK application's
[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event) event callback function
for the socket. If the WSK application does not enable conditional accept mode for the socket, this
pointer can be **NULL**.

### `WskAbortEvent`

A pointer to the WSK application's
[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event) event callback function for
the socket. If the WSK application does not enable conditional accept mode for the socket, this pointer
can be **NULL**.

## Remarks

A WSK application passes a pointer to a WSK_CLIENT_LISTEN_DISPATCH structure to the WSK subsystem when
the WSK application calls the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create a listening
socket.

## See also

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)