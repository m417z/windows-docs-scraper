# SOCKADDR structure

## Description

The SOCKADDR structure is a generic structure that specifies a transport address.

## Members

### `sa_family`

The address family for the transport address. For more information about supported address
families, see
[WSK Address Families](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt808757(v=vs.85)).

### `sa_data`

An array of 14 bytes that contains the transport address data.

## Remarks

The SOCKADDR structure is large enough to contain a transport address for most address families. For a
structure that is guaranteed to be large enough to contain a transport address for all possible address
families, see
[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh).

A WSK application typically does not access the
**sa_data** member directly. Instead, a pointer to a SOCKADDR structure is normally cast to a pointer
to the specific SOCKADDR structure type that corresponds to a particular address family.

## See also

[SOCKADDR_STORAGE](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr_storage_lh)

[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/ns-wsk-_wsk_datagram_indication)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_accept_event)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_bind)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_connect)

[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_get_local_address)

[WskGetRemoteAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_get_remote_address)

[WskInspectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_inspect_event)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_receive_from)

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_send_to)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wsk/nc-wsk-pfn_wsk_socket_connect)