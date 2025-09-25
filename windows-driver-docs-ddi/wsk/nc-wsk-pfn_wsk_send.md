# PFN_WSK_SEND callback function

## Description

The
**WskSend** function sends data over a connection-oriented or stream socket to a remote transport address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket over which to send the data.

### `Buffer` [in]

A pointer to an initialized
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that describes the data buffer
that contains the data that is being sent over the socket.

### `Flags` [in]

A ULONG value that contains a bitwise OR of a combination of the following flags:

#### WSK_FLAG_NODELAY

Directs the underlying transport to immediately send the data, and any previously queued data,
to the remote application without delay.

This flag is supported by the Microsoft TCP/IP transport protocol. This flag might not be supported
by other transport protocols.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the send operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskSend** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Data was successfully sent over the socket. The IRP will be completed with success status. The **IoStatus.Information** field of the IRP contains the number of bytes that were sent. |
| **STATUS_PENDING** | The WSK subsystem could not send the data over the socket immediately. The WSK subsystem will complete the IRP after it has sent the data over the socket. The status of the send operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the **IoStatus.Information** field of the IRP will contain the number of bytes that were sent. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **STATUS_NOT_SUPPORTED** | A specified flag is not supported by the underlying network transport. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskSend** function only on a connection-oriented or stream socket that has been previously connected to a
remote transport address. A connection-oriented socket is connected to a remote transport address by one
of the following methods:

* The WSK application connects the socket by calling the
  [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function.
* The WSK application creates, binds, and connects the socket by calling the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function.
* The WSK subsystem connects the socket when the WSK application accepts an incoming connection
  request on a listening socket.

If the
**WskSend** function returns STATUS_PENDING, the MDL chain that is described in the
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that is pointed to by the
*Buffer* parameter must remain locked in memory until the IRP is completed.

The WSK subsystem does not perform any buffering of data when it sends data over a socket. Therefore,
a call to the
**WskSend** function will not be completed by the WSK subsystem until all of the data has actually been
sent.

## See also

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive)

[WskReceiveEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_event)