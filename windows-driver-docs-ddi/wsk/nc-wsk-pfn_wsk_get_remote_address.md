# PFN_WSK_GET_REMOTE_ADDRESS callback function

## Description

The
**WskGetRemoteAddress** function retrieves the remote transport address of a connection-oriented
or stream socket.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being queried.

### `RemoteAddress` [out]

A pointer to a caller-allocated buffer that receives the remote transport address for the socket.
The buffer must be located in non-paged memory. The buffer must also be large enough to contain the
specific SOCKADDR structure type that corresponds to the address family that the WSK application
specified when it created the socket.

For a connection-oriented socket that the WSK application accepted on a listening socket, the address
family is the same as the address family that the WSK application specified when it created the
listening socket.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the retrieve operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskGetRemoteAddress** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The remote transport address for the socket was successfully retrieved. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not retrieve the remote transport address for the socket immediately. The WSK subsystem will complete the IRP after it has retrieved the remote transport address for the socket. The status of the retrieve operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_INVALID_DEVICE_STATE** | The socket is not connected to a remote transport address. The IRP will be completed with failure status. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskGetRemoteAddress** function only on a connection-oriented or stream socket that has been connected to a
remote transport address. A stream socket is connected to a remote transport address by calling the [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function. A connection-oriented socket is connected to a remote transport address in one
of the following ways:

* The WSK application calls the
  [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function.
* The WSK application creates, binds, and connects the socket by calling the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function.
* The WSK subsystem connects the socket when the WSK application accepts an incoming connection
  request on a listening socket.

If the
**WskGetRemoteAddress** function returns STATUS_PENDING, the buffer that is pointed to by the
*RemoteAddress* parameter must remain valid until the IRP is completed. If the WSK application
allocated the buffer with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the buffer on the
stack, it cannot return from the function that calls the
**WskGetRemoteAddress** function until after the IRP is completed.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)

[WskGetLocalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_local_address)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)