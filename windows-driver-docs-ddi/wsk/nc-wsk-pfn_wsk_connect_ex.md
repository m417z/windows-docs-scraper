# PFN_WSK_CONNECT_EX callback function

## Description

The
**WskConnectEx** function connects a connection-oriented or stream socket to a remote transport address.

**WskConnectEx** is similar to [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)
except that it can also optionally send a buffer of data during or after connection synchronization.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being connected to a remote transport address.

### `RemoteAddress` [in]

A pointer to a structure that specifies the remote transport address to which to connect the
socket. This pointer must be a pointer to the specific [SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr) structure type that corresponds to the
address family that the WSK application specified when it created the socket.

### `Buffer` [in, optional]

A pointer to a [WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure, which contains the data to send during or after connection synchronization. The maximum allowed size in bytes is 65,535.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the connect operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskConnectEx** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The socket was successfully connected to the remote transport address. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not connect the socket immediately. The WSK subsystem will complete the IRP after it has connected the socket to the remote transport address. The status of the connect operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **STATUS_INVALID_PARAMETER** | The WSK application attempted to pass a flag in to the *Flags* parameter (as no valid flags are currently defined for **WskConnectEx**, this is not allowed). |
| **STATUS_BUFFER_OVERFLOW** | The WSK application attempted to pass in a buffer larger than 65,535 bytes to the *Buffer* parameter. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can create, bind, and connect a connection-oriented socket in a single function call
by calling the
[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function rather than
calling the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket) function, the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function, and then the
**WskConnectEx** function. We recommend calling the
**WskSocketConnect** function unless the WSK application needs to set a socket option or issue an I/O
control operation before binding or connecting the socket.

A WSK application can call the
**WskConnectEx** function only on a connection-oriented or stream socket that the application previously bound to a
local transport address by calling the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function.

For stream sockets, once **WskConnectEx** is successfully called on a stream socket, the socket is committed to a connection-oriented flow and may no longer call listening socket functions.

If the *Buffer* parameter is used, the caller can free the MDL in its [WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure as soon as the connect request is complete.

Before calling **WskConnectEx** with a provided send buffer, if the WSK application sets the **TCP_FASTOPEN** option on a WSK socket via the [WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function the system will optionally send some or all of the data in a SYN packet. For more information, see the **TCP Fastopen** option in [IPPROTO_TCP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-tcp-socket-options).

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect)

[WskDisconnectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect_event)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)