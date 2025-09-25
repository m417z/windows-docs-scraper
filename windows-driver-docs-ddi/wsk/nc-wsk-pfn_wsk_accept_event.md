# PFN_WSK_ACCEPT_EVENT callback function

## Description

The
*WskAcceptEvent* event callback function notifies a WSK application that an incoming connection on a
listening socket has been accepted.

## Parameters

### `SocketContext` [in, optional]

A pointer to the socket context for the listening socket on which the incoming connection was
accepted. The WSK application provided this pointer to the WSK subsystem when it called the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function to create the listening
socket.

### `Flags` [in]

A ULONG value that contains the following flag, or zero:

#### WSK_FLAG_AT_DISPATCH_LEVEL

The WSK subsystem called the
*WskAcceptEvent* event callback function at IRQL = DISPATCH_LEVEL. If this flag is not set, the
WSK subsystem might have called the
*WskAcceptEvent* event callback function at any IRQL <= DISPATCH_LEVEL.

### `LocalAddress` [in]

A pointer to a buffer that contains the local transport address on which the incoming connection
arrived. The buffer contains the specific SOCKADDR structure type that corresponds to the address family
that the WSK application specified when it created the listening socket.

### `RemoteAddress` [in]

A pointer to a buffer that contains the remote transport address from which the incoming
connection originated. The buffer contains the specific SOCKADDR structure type that corresponds to the
address family that the WSK application specified when it created the listening socket.

### `AcceptSocket` [in, optional]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that is the socket object
for the accepted socket. If this pointer is **NULL**, the listening socket is no longer functional and the
WSK application must call the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the
listening socket as soon as possible.

### `AcceptSocketContext` [out]

A pointer to a variable that receives a pointer to a WSK application-supplied context for the
socket that is being accepted. The WSK subsystem passes this pointer to the accepted socket's event
callback functions. The context information is opaque to the WSK subsystem and must be stored in
non-paged memory. If the WSK application will not be enabling any event callback functions on the
accepted socket, the application should set the variable that is pointed to by the
*AcceptSocketContext* parameter to **NULL**.

### `AcceptSocketDispatch` [out]

A pointer to a variable that receives a pointer to a constant
[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch) structure. This structure is a dispatch table that contains
pointers to the event callback functions for the accepted socket. If the WSK application will not be
enabling all of the event callback functions for the accepted socket, the application should set the
pointers in the dispatch table to **NULL** for those event callback functions that it does not enable. If
the WSK application will not be enabling any event callback functions on the accepted socket, it should
set the variable that is pointed to by the
*AcceptSocketDispatch* parameter to **NULL**.

## Return value

A WSK application's
*WskAcceptEvent* event callback function can return one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The WSK application accepted the incoming connection. |
| **STATUS_REQUEST_NOT_ACCEPTED** | The WSK application rejected the incoming connection. If this value is returned, the WSK subsystem will close the accepted socket on behalf of the WSK application. |

## Remarks

The WSK subsystem calls a WSK application's
*WskAcceptEvent* event callback function when an incoming connection is accepted on the listening
socket only if the event callback function was previously enabled with the
[SO_WSK_EVENT_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/network/so-wsk-event-callback) socket option.
For more information about enabling a socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/network/enabling-and-disabling-event-callback-functions).

If a WSK application's
*WskAcceptEvent* event callback function is enabled on a listening socket and the application has a
pending call to the
[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept) function on the same listening socket,
then, when an incoming connection arrives, the pending call to
**WskAccept** takes precedence over the
*WskAcceptEvent* event callback function. The WSK subsystem calls the application's
*WskAcceptEvent* event callback function only if there are no IRPs queued from pending calls to the
**WskAccept** function. However, a WSK application should not assume that the WSK subsystem will not
call the application's
*WskAcceptEvent* event callback function for a listening socket that has a pending call to the
**WskAccept** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskAcceptEvent* event callback function for the socket. The only way for a WSK application to ensure
that the WSK subsystem will not call the application's
*WskAcceptEvent* event callback function for a listening socket is to disable the application's
*WskAcceptEvent* event callback function on the socket.

When the WSK subsystem calls a WSK application's
*WskAcceptEvent* event callback function, all of the event callback functions on the accepted socket
are disabled by default. If a WSK application enables any of the connection-oriented socket event
callback functions on a listening socket, those event callback functions will be enabled by default on
all connection-oriented sockets that are accepted on that listening socket. For more information about
enabling any of the accepted socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback).

The
[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr) structures that are pointed to by the
*LocalAddress* and
*RemoteAddress* parameters are valid only for the duration of the call to the
*WskAcceptEvent* event callback function. If a WSK application needs these transport addresses at a
later time, it can copy the contents of these structures to its own SOCKADDR structures before returning
from the
*WskAcceptEvent* event callback function, or it can later call the
[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address) and
[WskGetRemoteAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_remote_address) functions on the
accepted socket.

The WSK subsystem allocates the memory for the socket object structure (
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)) for the accepted connection on
behalf of the WSK application. The WSK subsystem deallocates this memory when the socket is closed.

The WSK subsystem calls a WSK application's
*WskAcceptEvent* event callback function at IRQL <= DISPATCH_LEVEL.

A WSK application's *WskAcceptEvent* event callback function must not wait for completion of other WSK requests in the context of WSK completion or event callback functions. The callback can initiate other WSK requests (assuming that it doesn't spend too much time at DISPATCH_LEVEL), but it must not wait for their completion even when the callback is called at IRQL = PASSIVE_LEVEL.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address)

[WskGetRemoteAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_remote_address)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)