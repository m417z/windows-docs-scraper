# PFN_WSK_RECEIVE callback function

## Description

The
**WskReceive** function receives data over a connection-oriented or stream socket from a remote transport
address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket from which to receive the data.

### `Buffer` [in]

A pointer to an initialized
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that describes the data buffer
that receives the data from the socket.

### `Flags` [in]

A ULONG value that contains a bitwise OR of a combination of the following flags:

#### WSK_FLAG_WAITALL

Wait until the data buffer is completely filled. If this flag is specified, the IRP specified in
the
*Irp* parameter will not be completed until one of the following events occurs:

* The data buffer that is described by the WSK_BUF structure that is pointed to by the
  *Buffer* parameter is completely filled.
* The connection is gracefully disconnected by the remote sender.
* The connection is abortively disconnected by either the WSK application or by the remote
  sender.
* The specified IRP is canceled.

This flag is supported by the Microsoft TCP/IP transport protocol. This flag might not be supported
by other transport protocols.

#### WSK_FLAG_DRAIN

Wait until the socket is disconnected, discarding any data that is received on the socket. If
this flag is specified, the specified IRP will not be completed until one of the following events
occurs:

* The connection is gracefully disconnected by the remote sender.
* The connection is abortively disconnected by either the WSK application or by the remote
  sender.
* The specified IRP is canceled.

Any received data is discarded by the WSK subsystem. No received data will be copied into the data
buffer. The
*Buffer* parameter is still required when this flag is specified, but the length of the buffer
that is described by the WSK_BUF structure must be zero.

This flag is supported by the Microsoft TCP/IP transport protocol. This flag might not be supported
by other transport protocols.

The WSK_FLAG_WAITALL and WSK_FLAG_DRAIN flags are mutually exclusive. A WSK application should not
specify both of these flags at the same time.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the receive operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskReceive** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Data was successfully received from the socket. The IRP will be completed with success status. The **IoStatus.Information** field of the IRP contains the number of bytes that were received. |
| **STATUS_PENDING** | The WSK subsystem could not receive the data from the socket immediately. The WSK subsystem will complete the IRP after it has received the data from the socket. The status of the receive operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the **IoStatus.Information** field of the IRP will contain the number of bytes that were received. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **STATUS_NOT_SUPPORTED** | A specified flag is not supported by the underlying network transport. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskReceive** function only on a connection-oriented or stream socket that has been previously connected to a
remote transport address. A connection-oriented socket is connected to a remote transport address by one
of the following methods:

* The WSK application connects the socket by calling the
  [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function.
* The WSK application creates, binds, and connects the socket by calling the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function.
* The WSK subsystem connects the socket when the WSK application accepts an incoming connection
  request on a listening socket.

If a WSK application's
[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event) event callback function is
enabled on a connection-oriented socket and the application also has a pending call to the
**WskReceive** function on the same connection-oriented socket, then, when data arrives, the pending
call to the
**WskReceive** function will take precedence over the
*WskReceiveEvent* event callback function. The WSK subsystem calls the application's
*WskReceiveEvent* event callback function only if there are no IRPs queued from pending calls to the
**WskReceive** function. However, a WSK application should not assume that the WSK subsystem will not
call the application's
*WskReceiveEvent* event callback function for a connection-oriented socket that has a pending call to
the
**WskReceive** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskReceiveEvent* event callback function for the socket. The only way for a WSK application to
ensure that the WSK subsystem will not call the application's
*WskReceiveEvent* event callback function for a connection-oriented socket is to disable the
application's
*WskReceiveEvent* event callback function on the socket.

A WSK application can call the
**WskReceive** function with a zero length specified in the
**Length** member of the
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that is pointed to by the
*Buffer* parameter. Specifying a zero length in this member is useful in the following
situations:

* When re-enabling the
  *WskReceiveEvent* event callback function for a socket after the
  *WskReceiveEvent* event callback function previously returned STATUS_DATA_NOT_ACCEPTED
* When specifying the WSK_FLAG_DRAIN flag to discard any additional data that is received on the
  socket

If the
**WskReceive** function returns STATUS_PENDING, the MDL chain that is described in the WSK_BUF
structure that is pointed to by the
*Buffer* parameter must remain locked in memory until the IRP is completed.

## See also

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event)

[WskSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send)