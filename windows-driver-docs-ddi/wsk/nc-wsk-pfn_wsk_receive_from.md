# PFN_WSK_RECEIVE_FROM callback function

## Description

The
**WskReceiveFrom** function receives a datagram and any associated control information from a remote
transport address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the datagram socket from which to receive the datagram.

### `Buffer` [in]

A pointer to an initialized
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that describes the data buffer
that receives the datagram from the socket.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `RemoteAddress` [out, optional]

A pointer to a caller-allocated buffer that receives the remote transport address from which the
received datagram originated. The buffer must be located in non-paged memory. The buffer must also be
large enough to contain the specific SOCKADDR structure type that corresponds to the address family that
the WSK application specified when it created the datagram socket. This pointer is optional and can be
**NULL**.

### `ControlLength` [in, out]

A pointer to a ULONG that specifies the size of the buffer that is pointed to by the *ControlInfo* parameter. When the receive operation is complete, the variable receives the size of the control information that is associated with the received datagram. If the value that is returned is zero, there is no control information present for the datagram. This pointer is optional and can be **NULL**. If this parameter is **NULL**, the *ControlInfo* parameter is ignored.

### `ControlInfo` [out, optional]

A pointer to a caller-allocated buffer that receives the control information that is associated
with the received datagram. The control information data that is associated with a datagram is made up
of one or more control data objects, each of which begins with a
[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr) structure. If there is no control
information present for the received datagram, the contents of the buffer are undefined. This pointer is
optional and can be **NULL**. If the
*ControlInfoLength* parameter is **NULL**, the
*ControlInfo* parameter should be **NULL**.

### `ControlFlags` [out, optional]

A pointer to a ULONG-typed variable that receives the bitwise OR of a combination of the following
flags:

#### MSG_BCAST

The datagram was received as a link-layer broadcast or with a destination transport address that
is a broadcast address.

#### MSG_MCAST

The datagram was received with a destination transport address that is a multicast
address.

#### MSG_TRUNC

The datagram was truncated because the size of the datagram was larger than the size of the
buffer that is specified by the
*Buffer* parameter.

#### MSG_CTRUNC

The control information data was truncated because the number of bytes of control information
was greater than the size of the buffer that is specified by the
*ControlInfo* parameter.

This parameter is optional and can be **NULL**.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the receive operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskReceiveFrom** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Data was successfully received from the socket. The IRP will be completed with success status. The **IoStatus.Information** field of the IRP contains the number of bytes that were received. |
| **STATUS_PENDING** | The WSK subsystem could not receive the datagram from the socket immediately. The WSK subsystem will complete the IRP after it has received the datagram from the socket. The status of the receive operation will be returned in the **IoStatus.Status** field of the IRP. If the operation succeeds, the **IoStatus.Information** field of the IRP will contain the number of bytes that were received. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

If the WSK application has set a fixed remote transport address for the datagram socket, datagrams
that are received from any other remote transport address will be discarded by the WSK subsystem. For
more information about setting the remote transport address for a datagram socket, see
[SIO_WSK_SET_REMOTE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-set-remote-address).

If a WSK application's
[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event) event callback
function is enabled on a datagram socket and the application also has a pending call to the
**WskReceiveFrom** function on the same datagram socket, then, when datagrams arrive, the pending call
to the
**WskReceiveFrom** function will take precedence over the
*WskReceiveFromEvent* event callback function. The WSK subsystem calls the application's
*WskReceiveFromEvent* event callback function only if there are no IRPs queued from pending calls to
the
**WskReceiveFrom** function. However, a WSK application should not assume that the WSK subsystem will
not call the application's
*WskReceiveFromEvent* event callback function for a datagram socket that has a pending call to the
**WskReceiveFrom** function. Race conditions exist where the WSK subsystem could still call the WSK
application's
*WskReceiveFromEvent* event callback function for the socket. The only way for a WSK application to
ensure that the WSK subsystem will not call the application's
*WskReceiveFromEvent* event callback function on a datagram socket is to disable the application's
*WskReceiveFromEvent* event callback function on the socket.

If the
**WskReceiveFrom** function returns STATUS_PENDING, the MDL chain that is described in the
[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf) structure that is pointed to by the
*Buffer* parameter must remain locked in memory until the IRP is completed. In addition, the variable
that is pointed to by the
*ControlInfoLength* parameter, the buffer that is pointed to by the
*ControlInfo* parameter, and the variable that is pointed to by the
*ControlFlags* parameter must also remain valid until the IRP is completed. If the WSK application
allocated these buffers or variables with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated these buffers or
variables on the stack, it cannot return from the function that calls the
**WskReceiveFrom** function until after the IRP is completed.

## See also

[CMSGHDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsacmsghdr)

[SIO_WSK_SET_REMOTE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/network/sio-wsk-set-remote-address)

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_BUF](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_buf)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket)

[WskReceiveFromEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_receive_from_event)

[WskSendTo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_send_to)