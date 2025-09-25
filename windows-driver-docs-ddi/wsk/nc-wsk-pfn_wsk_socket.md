# PFN_WSK_SOCKET callback function

## Description

The
**WskSocket** function creates a new socket and returns a pointer to the associated socket object.

## Parameters

### `Client` [in]

A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `AddressFamily` [in]

The address family for the socket that is being created. For more information about supported
address families, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `SocketType` [in]

The type of socket that is being created. The following socket types are supported:

#### SOCK_STREAM

Supports reliable connection-oriented byte stream communication.

#### SOCK_DGRAM

Supports unreliable connectionless datagram communication.

#### SOCK_RAW

Supports raw access to the transport protocol.

For more information about the socket types that are supported for each supported address family, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `Protocol` [in]

The transport protocol for the socket that is being created. For more information about the
protocols that are supported for each supported address family, see
[WSK Address Families](https://learn.microsoft.com/windows-hardware/drivers/network/ws2def-h).

### `Flags` [in]

A flag that specifies the WSK
[socket category](https://learn.microsoft.com/windows-hardware/drivers/network/winsock-kernel-socket-categories) for the
socket that is being created. This parameter can be one of the following flags:

#### WSK_FLAG_BASIC_SOCKET

A basic socket will be created that can be used only to get and set transport stack socket
options or to perform socket I/O control operations.

#### WSK_FLAG_LISTEN_SOCKET

A listening socket will be created that can be used to listen for incoming connections from
remote transport addresses.

#### WSK_FLAG_DATAGRAM_SOCKET

A datagram socket will be created that can be used to send and receive datagrams.

#### WSK_FLAG_CONNECTION_SOCKET

A connection-oriented socket will be created that can be used to send and receive network data
over a connection.

#### WSK_FLAG_STREAM_SOCKET

A stream socket will be created that can either be used to listen for incoming connections from remote transport addresses, or send and receive network data over a connection.

If a WSK application does not specify any of the preceding flags,
**WskSocket** creates a basic socket.

### `SocketContext` [in, optional]

A pointer to a caller-supplied context for the socket that is being created. The WSK subsystem
passes this pointer to the socket's event callback functions. The context information is opaque to the
WSK subsystem and must be stored in non-paged memory. If the WSK application will not be enabling any
event callback functions on the new socket, it should set this pointer to **NULL**. For a basic socket, this
pointer should always be **NULL**.

### `Dispatch` [in, optional]

A pointer to a constant client dispatch structure. This structure is a dispatch table that
contains pointers to the event callback functions for the new socket. Depending on the WSK
[socket category](https://learn.microsoft.com/windows-hardware/drivers/network/winsock-kernel-socket-categories) of the socket
(as specified by the
*Flags* parameter), this parameter is a pointer to one of the following structures.

| Flag | Dispatch table structure |
| --- | --- |
| WSK_FLAG_LISTEN_SOCKET | [WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch) |
| WSK_FLAG_DATAGRAM_SOCKET | [WSK_CLIENT_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_datagram_dispatch) |
| WSK_FLAG_CONNECTION_SOCKET | [WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch) |
| WSK_FLAG_STREAM_SOCKET | [WSK_CLIENT_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_stream_dispatch) |

If the WSK application will not be enabling all of the event callback functions for the new socket,
it should set the pointers in the dispatch table to **NULL** for those event callback functions that it does
not enable. If the WSK application will not be enabling any event callback functions on the new socket,
it should set the
*Dispatch* pointer to **NULL**. For a basic socket, this pointer should always be **NULL**.

### `OwningProcess` [in, optional]

A pointer to the process from which the WSK subsystem will retrieve the security context to use
when it binds the socket. The WSK subsystem uses the security context to determine whether the local
transport address can be shared if that address is already in use. To specify the current process, a WSK
application sets this pointer to **NULL**.

### `OwningThread` [in, optional]

A pointer to a specific thread from which the WSK subsystem will retrieve the security context to
use when it binds the socket. The WSK subsystem uses the security context to determine whether the local
transport address can be shared if that address is already in use. If a WSK application does not need to
specify a specific thread, it sets this pointer to **NULL**.

### `SecurityDescriptor` [in, optional]

A pointer to a SECURITY_DESCRIPTOR structure that specifies the security descriptor to apply to
the socket that is being created. The security descriptor controls the sharing of the local transport
address to which the socket is bound. If a WSK application specifies a non-**NULL** pointer, it must specify
a pointer to a cached copy of a security descriptor that was obtained by calling the
[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client) function with the
[WSK_CACHE_SD](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-cache-sd) control code. To specify a
default security descriptor that does not allow sharing of the local transport address, a WSK
application sets
*SecurityDescriptor* to **NULL**.

For more information about the SECURITY_DESCRIPTOR structure, see the reference page for
SECURITY_DESCRIPTOR in the Microsoft Windows SDK documentation.

### `Irp` [in, out]

A pointer to a caller-allocated IRP that the WSK subsystem uses to complete the creation of the
new socket asynchronously. For more information about using IRPs with WSK functions, see
[Using IRPs with Winsock
Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

## Return value

**WskSocket** returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The new socket was successfully created. The IRP will be completed with success status. |
| **STATUS_PENDING** | The WSK subsystem could not create the socket immediately. The WSK subsystem will complete the IRP after it has created the new socket. The status of the socket creation will be returned in the **IoStatus.Status** field of the IRP. |
| **Other status codes** | An error occurred. The IRP will be completed with failure status. |

## Remarks

If the IRP is completed with success status, the
**IoStatus.Information** field of the IRP contains a pointer to a socket object structure (
[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)) for the new socket.

A WSK application can obtain a list of available transport protocols by calling the
[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client) function with the
[WSK_TRANSPORT_LIST_QUERY](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-transport-list-query) control
code.
**WskControlClient** returns a list of
[WSK_TRANSPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_transport) structures that contains all of
the valid combinations of the
*AddressFamily*,
*SocketType*, and
*Protocol* parameters.

When a WSK application successfully creates a new socket, all of the event callback functions on the
new socket are disabled by default. For more information about enabling any of the new socket's event
callback functions, see
[Enabling and
Disabling Event Callback Functions](https://learn.microsoft.com/windows/win32/api/evntprov/nc-evntprov-penablecallback).

If a WSK application specifies a non-**NULL** pointer for the
*SecurityDescriptor* parameter, it must not release the cached security descriptor until after the
IRP is completed.

The WSK subsystem allocates the memory for the socket object structure (WSK_SOCKET) for the new socket
on behalf of the WSK application. The WSK subsystem deallocates this memory when the socket is
closed.

## See also

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_CLIENT_DATAGRAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_datagram_dispatch)

[WSK_CLIENT_LISTEN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_listen_dispatch)

[WSK_CLIENT_STREAM_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_stream_dispatch)

[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch)

[WSK_PROVIDER_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_npi)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)

[WskSocketConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket_connect)