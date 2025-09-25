# PFN_WSK_RELEASE_DATAGRAM_INDICATION_LIST callback function

## Description

The
**WskRelease** function releases a linked list of
[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structures
that was previously retained by a WSK application.

**WskRelease** can be declared in two different ways, depending on the type of socket. This topic describes **WskRelease** for datagram sockets. For connection-oriented or listening sockets, see [WskRelease (connection-oriented or listening sockets)](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)).

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket from which the data was received.

### `DatagramIndication` [in]

A pointer to the linked list of structures to be released. For this parameter, the WSK application
should specify the
*DatagramIndication* parameter that was passed to its
[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event) or
[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event) event callback
function.

## Return value

**WskRelease** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The list of structures was successfully released. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |

## Remarks

A WSK application calls the
**WskRelease** function to release a linked list of [WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structures
that it previously retained by returning STATUS_PENDING from either its
[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event) or its
[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event) event callback
function.

Closing a socket by calling the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function does not release
any outstanding retained linked lists of structures. A WSK application must release all retained linked
lists of structures before the application calls the
**WskCloseSocket** function to close the socket.

## See also

[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication)

[WSK_DATA_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_data_indication)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event)

[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event)