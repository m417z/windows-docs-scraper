# PFN_WSK_DISCONNECT callback function

## Description

The
**WskDisconnect** function disconnects a connection-oriented or stream socket from a remote transport
address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being disconnected.

### `Buffer` [in, optional]

A pointer to a
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure. This structure describes a data
buffer that contains data to be transmitted by the WSK subsystem to the remote transport address before
the socket is disconnected. If there is no such data to be transmitted, the WSK application sets this
pointer to **NULL**. If WSK_FLAG_ABORTIVE is specified in the
*Flags* parameter, the
*Buffer* parameter must be **NULL**.

### `Flags` [in]

A ULONG value that contains the following flag, or zero:

#### WSK_FLAG_ABORTIVE

Directs the WSK subsystem to perform an abortive disconnect of the socket. If a WSK application
does not specify this flag, the WSK subsystem will perform a graceful disconnect of the socket.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the disconnect
operation asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskDisconnect** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The socket was successfully disconnected from the remote transport address. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not disconnect the socket immediately. The WSK subsystem will complete the IRP after it has disconnected the socket from the remote transport address. The status of the disconnect operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskDisconnect** function only on a connection-oriented or stream socket that it previously connected to a
remote transport address or on a socket that it accepted on a listening socket.

**WskDisconnect** causes the WSK subsystem to notify the remote transport address, through whatever
means is appropriate for the underlying transport, that the connection is being disconnected. If the
*Buffer* parameter is non-**NULL**, the WSK subsystem transmits the data in the buffer to the remote
transport address before disconnecting the socket.

If a graceful disconnect is performed, the WSK subsystem waits until all outstanding transmit data has
been sent before disconnecting the socket. After the socket has been disconnected, the WSK application
cannot send any additional data to the remote transport address. However, the WSK application can still
receive additional data from the remote transport address until the remote application disconnects its
end of the socket.

Note that not all transports support half-open connections. If a transport does not support half-open
connections, the WSK application will not receive any additional data from the remote transport address
after a graceful disconnect has been performed.

With a graceful disconnect, the IRP is completed only when the disconnect operation is fully completed
by the transport protocol. For some transport protocols, the IRP might not complete if there is a problem
transmitting data to the remote transport address. In this situation, the WSK application can recover by
either calling the
**WskDisconnect** function again and specifying the WSK_FLAG_ABORTIVE flag or by calling the
[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function. In either
situation, the WSK subsystem will abortively disconnect the socket and force completion of the pending
IRP.

If an abortive disconnect is performed, the WSK subsystem cancels all in-progress and pending transmit
operations and does not wait to disconnect the socket. After an abortive disconnect, the WSK application
cannot send any additional data to the remote transport address or receive any additional data from the
remote transport address.

A WSK application can completely close the connection by calling the
**WskCloseSocket** function.

## See also

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)

[WskDisconnectEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_disconnect_event)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)