# PFN_WSK_RECEIVE_FROM_EVENT callback function

## Description

The
*WskReceiveFromEvent* event callback function notifies a WSK application that one or more datagrams
have been received on a datagram socket.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the datagram socket that has received the datagrams. The WSK
application provided this pointer to the WSK subsystem when it called the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the datagram
socket.

### `Flags` [in]

A ULONG value that contains a bitwise OR of a combination of the following flags:

#### MSG_BCAST

The datagrams were received as a link-layer broadcast or with a destination transport address
that is a broadcast address.

#### MSG_MCAST

The datagrams were received with a destination transport address that is a multicast
address.

#### WSK_FLAG_AT_DISPATCH_LEVEL

The WSK subsystem called the
*WskReceiveFromEvent* event callback function at IRQL = DISPATCH_LEVEL. If this flag is not set,
the WSK subsystem might have called the
*WskReceiveFromEvent* event callback function at any IRQL <= DISPATCH_LEVEL.

### `DataIndication` [in, optional]

A pointer to a linked list of
[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structures
that describe the received datagrams. If this parameter is **NULL**, the socket is no longer functional and
the WSK application must call the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the
socket as soon as possible.

## Return value

A WSK application's
*WskReceiveFromEvent* event callback function can return one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The WSK application accepted the datagrams and retrieved all of the datagrams from the linked list of [WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structures. The WSK subsystem can call the *WskReceiveFromEvent* event callback function again when new datagrams are received on the socket. |
| **STATUS_PENDING** | The WSK application accepted the datagrams but did not retrieve all of the datagrams from the linked list of [WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication) structures. The WSK application retains the linked list of WSK_DATAGRAM_INDICATION structures until all of the datagrams have been retrieved. After the WSK application has retrieved all of the datagrams, it calls the [WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85)) function to release the linked list of WSK_DATAGRAM_INDICATION structures back to the WSK subsystem. The WSK subsystem can call the *WskReceiveFromEvent* event callback function again when new datagrams are received on the socket. |
| **STATUS_DATA_NOT_ACCEPTED** | The WSK application did not accept the datagrams. If a WSK application returns this status code, the WSK subsystem will respond differently depending on how the WSK application enabled the *WskReceiveFromEvent* event callback function.<br><br>* If the WSK application enabled the   *WskReceiveFromEvent* event callback function by using the   [SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket   option, the WSK subsystem will have the underlying transport buffer the datagrams if possible or if   otherwise required by the protocol. The WSK subsystem will disable the   *WskReceiveFromEvent* event callback function and will not call the   *WskReceiveFromEvent* event callback function again until after the WSK application re-enables   this event callback function with the SO_WSK_EVENT_CALLBACK socket option. After the WSK application   has re-enabled the   *WskReceiveFromEvent* event callback function, the WSK subsystem will resume calling the   *WskReceiveFromEvent* event callback function with any remaining buffered datagrams and when new   datagrams are received on the socket.<br>* If the WSK application enabled the   *WskReceiveFromEvent* event callback function by using the   [WSK_SET_STATIC_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-set-static-event-callbacks) client control operation, the WSK subsystem will not disable   the   *WskReceiveFromEvent* event callback function. The WSK subsystem will continue calling the   *WskReceiveFromEvent* event callback function when new datagrams are received on the socket. |

## Remarks

The WSK subsystem calls a WSK application's
*WskReceiveFromEvent* event callback function when new datagrams are received on a datagram socket
only if the event callback function was previously enabled with the
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket option.
For more information about enabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback).

If a WSK application's
*WskReceiveFromEvent* event callback function is enabled on a datagram socket and the application
also has a pending call to the
[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from) function on the same
datagram socket, then, when datagrams arrive, the pending call to the
**WskReceiveFrom** function will take precedence over the
*WskReceiveFromEvent* event callback function. The WSK subsystem calls the application's
*WskReceiveFromEvent* event callback function only if there are no IRPs queued from pending calls to
the
**WskReceiveFrom** function. However, a WSK application should not assume that the WSK subsystem will
not call the application's
*WskReceiveFromEvent* event callback function for a datagram socket that has a pending call to the
**WskReceiveFrom** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskReceiveFromEvent* event callback function for the socket. The only way for a WSK application to
ensure that the WSK subsystem will not call the application's
*WskReceiveFromEvent* event callback function on a datagram socket is to disable the application's
*WskReceiveFromEvent* event callback function on the socket.

The WSK subsystem calls a WSK application's
*WskReceiveFromEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskReceiveFromEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[WSK_CLIENT_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_datagram_dispatch)

[WSK_DATAGRAM_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_datagram_indication)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from)

[WskRelease](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff571144(v=vs.85))

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_to)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)