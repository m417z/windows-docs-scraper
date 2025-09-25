# PFN_WSK_CONNECT callback function

## Description

The
**WskConnect** function connects a connection-oriented or stream socket to a remote transport address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being connected to a remote transport address.

### `RemoteAddress` [in]

A pointer to a structure that specifies the remote transport address to which to connect the
socket. This pointer must be a pointer to the specific SOCKADDR structure type that corresponds to the
address family that the WSK application specified when it created the socket.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the connect operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskConnect** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The socket was successfully connected to the remote transport address. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not connect the socket immediately. The WSK subsystem will complete the IRP after it has connected the socket to the remote transport address. The status of the connect operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskConnect** function only on a connection-oriented or stream socket that the application previously bound to a
local transport address by calling the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function.

For stream sockets, once **WskConnect** is successfully called on a stream socket, the socket is committed to a connection-oriented flow and may no longer call listening socket functions.

A WSK application can create, bind, and connect a connection-oriented socket in a single function call
by calling the
[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function rather than
calling the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function, the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function, and then the
**WskConnect** function. We recommend calling the
**WskSocketConnect** function unless the WSK application needs to set a socket option or issue an I/O
control operation before binding or connecting the socket.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect)

[WskDisconnectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)