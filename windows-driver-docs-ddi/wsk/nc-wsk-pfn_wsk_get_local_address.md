# PFN_WSK_GET_LOCAL_ADDRESS callback function

## Description

The
**WskGetLocalAddress** function retrieves the local transport address of a socket.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being queried.

### `LocalAddress` [out]

A pointer to a caller-allocated buffer that receives the local transport address for the socket.
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

**WskGetLocalAddress** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The local transport address for the socket was successfully retrieved. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not retrieve the local transport address for the socket immediately. The WSK subsystem will complete the IRP after it has retrieved the local transport address for the socket. The status of the retrieve operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_INVALID_DEVICE_STATE** | The socket is not bound to a local transport address. The IRP will be completed with failure status. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

A WSK application can call the
**WskGetLocalAddress** function only on a socket that has been bound to a local transport address.

A listening, datagram, or stream socket is bound to a local transport address when the WSK application
calls the
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind) function.

A connection-oriented socket is bound to a local transport address in one of the following ways:

* The WSK application calls the
  **WskBind** function.
* The WSK application creates, binds, and connects the socket by calling the
  [WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect) function.
* The WSK subsystem binds the socket when the WSK application accepts an incoming connection request
  on a listening socket.

The
**WskGetLocalAddress** function is particularly useful for determining the specific local transport
address that was assigned to a socket by the transport protocol when the socket was bound to the local
wildcard address. For a connection-oriented socket that was bound to the local wildcard address, the
local transport address might not be assigned to the socket by the transport protocol until the socket is
connected to a remote transport address. The step where the local transport address is assigned to the
socket is transport protocol-dependent. For TCP, the port number is assigned when a connection-oriented
socket is bound, but the IP address is not assigned until the socket is connected.

If the
**WskGetLocalAddress** function returns STATUS_PENDING, the buffer that is pointed to by the
*LocalAddress* parameter must remain valid until the IRP is completed. If the WSK application
allocated the buffer with one of the
**ExAllocate*Xxx*** functions, it cannot free the memory with the corresponding
**ExFree*Xxx*** function until after the IRP is completed. If the WSK application allocated the buffer on the
stack, it cannot return from the function that calls the
**WskGetLocalAddress** function until after the IRP is completed.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskAccept](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept)

[WskAcceptEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_accept_event)

[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)

[WskGetRemoteAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_get_remote_address)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)