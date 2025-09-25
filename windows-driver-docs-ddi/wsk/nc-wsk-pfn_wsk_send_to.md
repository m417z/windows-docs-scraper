# PFN_WSK_SEND_TO callback function

## Description

The
**WskSendTo** function sends datagram data to a remote transport address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the datagram socket over which to send the datagram.

### `Buffer` [in]

A pointer to an initialized
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that describes the data buffer
that contains the datagram that is being sent over the socket.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `RemoteAddress` [in, optional]

A pointer to a structure that specifies the remote transport address to which to send the
datagram. This pointer must be a pointer to the specific SOCKADDR structure type that corresponds to the
address family that the WSK application specified when it created the socket.

If the WSK application has set either a fixed remote transport address or a fixed destination
transport address for the datagram socket, this pointer is optional and may be **NULL**. If **NULL**, the
datagram is sent to the fixed remote transport address or the fixed destination transport address. If
non-**NULL**, the datagram is sent to the specified remote transport address.

For more information about setting a fixed remote transport address for a datagram socket, see
[SIO_WSK_SET_REMOTE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-set-remote-address).

For more information about setting a fixed destination transport address for a datagram socket, see
[SIO_WSK_SET_SENDTO_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-set-sendto-address).

### `ControlInfoLength` [in]

The number of bytes of data in the buffer that is pointed to by the
*ControlInfo* parameter. If there is no control information associated with the datagram, the
*ControlInfoLength* parameter must be zero.

### `ControlInfo` [in, optional]

A pointer to a buffer that contains control information that is associated with the datagram that
is being sent. The control information data consists of one or more control data objects, each of which
begins with a
[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr) structure. If there is no control
information that is associated with the datagram, this parameter should be **NULL**.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the send operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskSendTo** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The datagram was successfully sent over the socket. The IRP will be completed with success status. The **IoStatus.Information** field of the IRP contains the number of bytes that were sent. |
| **STATUS_PENDING** | The WSK subsystem could not send the datagram over the socket immediately. The WSK subsystem will complete the IRP after it has sent the datagram over the socket. The status of the send operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the **IoStatus.Information** field of the IRP will contain the number of bytes that were sent. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

If the
**WskSendTo** function returns STATUS_PENDING, the MDL chain that is described in the
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that is pointed to by the
*Buffer* parameter must remain locked in memory until the IRP is completed. In addition, the buffer
that is pointed to by the
*ControlInfo* parameter must also remain valid until the IRP is completed. If the WSK application
allocated the MDL chain or the control information buffer with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the MDL chain or
the control information buffer on the stack, it cannot return from the function that calls the
**WskSendTo** function until after the IRP is completed.

The WSK subsystem does not perform any buffering of data when it sends datagrams over a socket.
Therefore, a call to the
**WskSendTo** function will not be completed by the WSK subsystem until all of the data has actually
been sent.

## See also

[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskReceiveFrom](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from)

[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event)