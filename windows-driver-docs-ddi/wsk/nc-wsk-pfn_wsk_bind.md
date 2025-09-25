# PFN_WSK_BIND callback function

## Description

The
**WskBind** function binds a socket to a local transport address.

## Parameters

### `Socket` [in]

A pointer to a
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket) structure that specifies the socket
object for the socket that is being bound.

### `LocalAddress` [in]

A pointer to a structure that specifies the local transport address to which to bind the socket.
This pointer must be a pointer to the specific SOCKADDR structure type that corresponds to the address
family that the WSK application specified when it created the socket.

### `Flags`

This parameter is reserved for system use. A WSK application must set this parameter to
zero.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the bind operation
asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskBind** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The socket was successfully bound to the local transport address. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not bind the socket immediately. The WSK subsystem will complete the IRP after it has bound the socket to the local transport address. The status of the bind operation will be returned in the **IoStatus.Status** field of the IRP. |
| **STATUS_FILE_FORCED_CLOSED** | The socket is no longer functional. The IRP will be completed with failure status. The WSK application must call the [WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket) function to close the socket as soon as possible. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

For a listening socket, calling the
**WskBind** function prepares the socket to listen for incoming connection requests on the specified
local transport address. If a WSK application specifies a local wildcard address, the socket will listen
for incoming connection requests on all local transport addresses.

For a datagram socket, calling the
**WskBind** function prepares the socket to send and receive datagrams on the specified local transport
address. If a WSK application specifies a local wildcard address, the socket will receive datagrams on
all local transport addresses and will send datagrams from the appropriate local transport address that
is determined by the system's routing information.

For a connection-oriented socket, calling the
**WskBind** function binds the socket to the specified local transport address.
**WskBind** must be called prior to calling the
[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) function. If a WSK application
specifies a local wildcard address, the network stack binds the socket to the appropriate local transport
address when the application calls
**WskConnect** to connect the socket to a remote transport address. In such a situation, the local
transport address is determined by the system's routing information.

For a stream socket, calling the **WskBind** function binds the socket to the specified local transport address. If a WSK application specifies a local wildcard address, the network stack binds the socket to an available local transport address. **WskBind** must be called prior to calling the [WskListen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_listen) or the [WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) functions.

## See also

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_PROVIDER_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_connection_dispatch)

[WSK_PROVIDER_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_datagram_dispatch)

[WSK_PROVIDER_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_listen_dispatch)

[WSK_PROVIDER_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_stream_dispatch)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)