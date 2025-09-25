# PFN_WSK_CLOSE_SOCKET callback function

## Description

The
**WskCloseSocket** function closes a socket and frees any associated resources.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being closed.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the close operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskCloseSocket** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The socket was successfully closed. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not close the socket immediately. The WSK subsystem will complete the IRP after it has closed the socket. The status of the close operation will be returned in the **IoStatus.Status** field of the IRP. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

Before calling the
**WskCloseSocket** function, a WSK application must ensure that there are no other function calls in
progress to any of the socket's functions, including any extension functions, in any of the application's
other threads. For example, a WSK application must not call
**WskCloseSocket** on a socket in one thread while the application is calling
**WskSend** on the same socket in another thread. Any in-progress calls to the socket's functions must
return control back to the WSK application before it calls
**WskCloseSocket** to close the socket. However, a WSK application can call
**WskCloseSocket** if there are pending IRPs from prior calls to the socket's functions that have not
yet completed.

Calling the
**WskCloseSocket** function causes the WSK subsystem to cancel and complete all pending IRPs from prior
calls to the socket's functions. The WSK subsystem also ensures that any in-progress event callback
functions have returned control back to the WSK subsystem before it closes the socket.

After a WSK application has called
**WskCloseSocket**, it should not make any further calls to any of the socket's functions.

If a WSK application applies a security descriptor to a socket, the cached copy of the security
descriptor that is specified in the call to
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket),
[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect), or
[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) is not released when the
socket is closed. A WSK application must release the cached copy of the security descriptor by using the
[WSK_RELEASE_SD](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-release-sd) client control operation when
the security descriptor is no longer needed.

The WSK subsystem deallocates the memory for the socket's socket object,
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket), which was allocated by the WSK
subsystem when the socket was created.

For connection-oriented sockets, the
**WskCloseSocket** function always performs an abortive disconnect of the socket unless the socket is
already fully disconnected in both directions. To gracefully disconnect a connection-oriented socket from
a remote transport address, a WSK application should call the
[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect) function.

## See also

[WSK_PROVIDER_BASIC_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_basic_dispatch)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)