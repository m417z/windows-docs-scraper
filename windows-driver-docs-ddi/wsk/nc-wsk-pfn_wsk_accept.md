# PFN_WSK_ACCEPT callback function

## Description

The
**WskAccept** function accepts an incoming connection on a listening socket.

## Parameters

### `ListenSocket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the listening or stream socket that is being checked for an incoming connection.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `AcceptSocketContext` [in, optional]

A pointer to a caller-supplied context for the socket that is being accepted. The WSK subsystem
passes this pointer to the accepted socket's event callback functions. The context information is opaque
to the WSK subsystem. The context information must be stored in non-paged memory. If the WSK application
will not be enabling any event callback functions on the accepted socket, it should set this pointer to
**NULL**.

### `AcceptSocketDispatch` [in, optional]

A pointer to a constant
[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch) structure. This structure is a dispatch table that contains
pointers to the event callback functions for the accepted socket. If the WSK application will not be
enabling all of the event callback functions for the accepted socket, it should set the pointers in the
dispatch table to **NULL** for those event callback functions that it does not enable. If the WSK
application will not be enabling any event callback functions on the accepted socket, it should set this
pointer to **NULL**.

### `LocalAddress` [out, optional]

A pointer to a caller-allocated buffer that receives the local transport address on which the
incoming connection arrived. The buffer must be located in non-paged memory. The buffer must also be
large enough to contain the specific SOCKADDR structure type that corresponds to the address family that
the WSK application specified when it created the listening socket. This pointer is optional and can be
**NULL**.

### `RemoteAddress` [out, optional]

A pointer to a caller-allocated buffer that receives the remote transport address from which the
incoming connection originated. The buffer must be located in non-paged memory. The buffer must also be
large enough to contain the specific SOCKADDR structure type that corresponds to the address family that
the WSK application specified when it created the listening socket. This pointer is optional and can be
**NULL**.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the accept operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskAccept** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | An incoming connection was successfully accepted. The IRP will be completed with success status. |
| **STATUS_PENDING** | The IRP has been queued by the WSK subsystem, which is waiting for an incoming connection on the listening socket. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskAccept** function on either a listening socket or stream socket that it previously bound to a local transport address
by calling the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function.

The behavior of the
**WskAccept** function depends on whether an incoming connection is waiting to be accepted on the
listening socket:

* If an incoming connection has already arrived on the listening socket and is waiting to be accepted,
  the
  **WskAccept** function returns STATUS_SUCCESS. In this situation, the IRP is completed with success
  status and the
  **IoStatus.Information** field of the IRP contains a pointer to the socket object for the accepted
  socket.
* If an incoming connection is not waiting to be accepted on the listening socket,
  **WskAccept** returns STATUS_PENDING and the WSK subsystem queues the IRP until an incoming
  connection is received. When an incoming connection is received, the WSK subsystem asynchronously
  completes the IRP with success status. In this situation, the
  **IoStatus.Information** field of the IRP contains a pointer to the socket object for the accepted
  socket.

If a WSK application's
[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event) event callback function is
enabled on a listening socket and the application has a pending call to the
**WskAccept** function on the same listening socket, then, when an incoming connection arrives, the
pending call to
**WskAccept** takes precedence over the
*WskAcceptEvent* event callback function. The WSK subsystem calls the application's
*WskAcceptEvent* event callback function only if there are no IRPs queued from pending calls to
**WskAccept**. However, a WSK application should not assume that the WSK subsystem will not call the
application's
*WskAcceptEvent* event callback function for a listening socket that has a pending call to the
**WskAccept** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskAcceptEvent* event callback function for the socket. The only way for a WSK application to ensure
that the WSK subsystem will not call the application's
*WskAcceptEvent* event callback function for a listening socket is to disable the application's
*WskAcceptEvent* event callback function on the socket.

When the
**WskAccept** function successfully accepts an incoming connection, all of the event callback functions
on the accepted socket are disabled by default. For more information about enabling any of the accepted
socket's event callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows-hardware/drivers/network/enabling-and-disabling-event-callback-functions).

If a WSK application specifies a non-**NULL** pointer in the
*LocalAddress* parameter, in the
*RemoteAddress* parameter, or in both parameters, and if
**WskAccept** returns STATUS_PENDING, the buffers that are pointed to by those parameters must remain
valid until the IRP is completed. If the WSK application allocated the buffers with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the buffers on the
stack, it cannot return from the function that calls the
**WskAccept** function until after the IRP is completed.

The WSK subsystem allocates the memory for the socket object structure (
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)) for the accepted connection on
behalf of the WSK application. The WSK subsystem deallocates this memory when the socket is closed.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)