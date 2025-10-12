# PFN_WSK_INSPECT_EVENT callback function

## Description

The
*WskInspectEvent* event callback function notifies a WSK application that an incoming connection
request on a listening socket that has conditional accept mode enabled has been received.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the listening socket on which the incoming connection request
was received. The WSK application provided this pointer to the WSK subsystem when it called the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the listening
socket.

### `LocalAddress` [in]

A pointer to a buffer that contains the local transport address on which the incoming connection
request arrived. The buffer contains the specific SOCKADDR structure type that corresponds to the
address family that the WSK application specified when it created the listening socket.

### `RemoteAddress` [in]

A pointer to a buffer that contains the remote transport address from which the incoming
connection request originated. The buffer contains the specific SOCKADDR structure type that corresponds
to the address family that the WSK application specified when it created the listening socket.

### `InspectID` [in, optional]

A pointer to a
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure. The contents of
the structure identify the incoming connection request that is being inspected. If this pointer is **NULL**,
the listening socket is no longer functional and the WSK application must call the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the
listening socket as soon as possible.

## Return value

A WSK application's
*WskInspectEvent* event callback function can return one of the following WSK_INSPECT_ACTION
values:

| Return code | Description |
| --- | --- |
| **WskInspectAccept** | The incoming connection request is accepted. |
| **WskInspectReject** | The incoming connection request is rejected. |
| **WskInspectPend** | The WSK application could not determine if the incoming connection request should be accepted or rejected immediately. |

## Remarks

The WSK subsystem calls a WSK application's
*WskInspectEvent* event callback function on a listening socket that has conditional accept mode
enabled. A WSK application can enable conditional accept mode on a listening socket by enabling the
[SO_CONDITIONAL_ACCEPT](https://learn.microsoft.com/windows-hardware/drivers/network/so-conditional-accept) socket option.
For more information about conditionally accepting incoming connections, see
[Listening for and
Accepting Incoming Connections](https://learn.microsoft.com/windows-hardware/drivers/network/listening-for-and-accepting-incoming-connections).

If a WSK application returns
**WskInspectAccept** from its
*WskInspectEvent* event callback function, the WSK subsystem continues to establish the socket
connection. The WSK subsystem returns the socket to the WSK application by either completing a call to
the
[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function, or by calling the WSK
application's
[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function if
the event callback function is enabled. If the incoming connection request is dropped before the socket
connection is fully established, the WSK subsystem calls the WSK application's
[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event) event callback function.

If a WSK application returns
**WskInspectReject** from its
*WskInspectEvent* event callback function, the incoming connection request is dropped and the socket
connection is not established.

If a WSK application returns
**WskInspectPend** from its
*WskInspectEvent* event callback function, the application must call the
[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete) function after it
has determined whether the incoming connection request should be accepted or rejected (unless the
incoming connection request is aborted in the meantime). The WSK application must copy the contents of
the
[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id) structure that is pointed to
by the
*InspectID* parameter to its own WSK_INSPECT_ID structure before returning from the
*WskInspectEvent* event callback function. The WSK application passes a pointer to its own
WSK_INSPECT_ID structure to the
**WskInspectComplete** function when it completes the inspection. The WSK application also uses this
structure to identify the incoming connection request if the request is aborted before the inspection is
complete.

The
[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr) structures that are pointed to by the
*LocalAddress* and
*RemoteAddress* parameters are valid only for the duration of the call to the
*WskInspectEvent* event callback function. If a WSK application returns
**WskInspectPend** from its
*WskInspectEvent* event callback function and it needs these transport addresses during the remainder
of the inspection, it must copy the contents of these structures to its own SOCKADDR structures before
returning from the
*WskInspectEvent* event callback function.

The WSK subsystem calls a WSK application's
*WskInspectEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskInspectEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_INSPECT_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_inspect_id)

[WskAbortEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_abort_event)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskInspectComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_inspect_complete)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)