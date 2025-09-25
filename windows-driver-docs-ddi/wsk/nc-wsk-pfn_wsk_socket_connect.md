# PFN_WSK_SOCKET_CONNECT callback function

## Description

The
**WskSocketConnect** function creates a new connection-oriented socket, binds it to a local transport
address, connects it to a given remote transport address, and returns a pointer to the associated socket
object.

## Parameters

### `Client` [in]

A pointer to a
[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client) structure that was returned through
the
*WskProviderNpi* parameter of the
[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi) function.

### `SocketType` [in]

The type of the socket that is being created. The following socket types are supported:

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

### `LocalAddress` [in]

A pointer to a structure that specifies the local transport address to which to bind the socket.
The WSK application must specify a pointer to the specific SOCKADDR structure type that corresponds to
the address family for the socket that is being created.

### `RemoteAddress` [in]

A pointer to a structure that specifies the remote transport address to which to connect the
socket. The WSK application must specify a pointer to the specific SOCKADDR structure type that
corresponds to the address family for the socket that is being created.

### `Flags`

This parameter is reserved for system use. WSK applications must set this parameter to
zero.

### `SocketContext` [in, optional]

A pointer to a caller-supplied context for the socket that is being created. The WSK subsystem
passes this pointer to the socket's event callback functions. The context information is opaque to the
WSK subsystem and must be stored in non-paged memory. If the WSK application will not be enabling any
event callback functions on the new socket, it should set this pointer to **NULL**.

### `Dispatch` [in, optional]

A pointer to a constant
[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch) structure. This structure is a dispatch table that contains
pointers to the event callback functions for the new socket. If the WSK application will not be enabling
all of the event callback functions for the new socket, it should set the pointers in the dispatch table
to **NULL** for those event callback functions that it does not enable. If the WSK application will not be
enabling any event callback functions on the new socket, it should set this pointer to **NULL**.

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

**WskSocketConnect** returns one of the following NTSTATUS codes:

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
*SocketType* and
*Protocol* parameters.

The WSK subsystem determines the address family for the new socket from the address family that is
specified in the
[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr) structure that is pointed to by the
*LocalAddress* parameter.

If the WSK application needs to set a socket option or issue an I/O control operation on the socket
before binding or connecting the socket, the WSK application must call the
[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket),
[WskBind](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_bind), and
[WskConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_connect) functions instead of calling the
**WskSocketConnect** function.

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

[SOCKADDR](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-sockaddr)

[WSK_CLIENT](https://learn.microsoft.com/windows-hardware/drivers/network/wsk-client)

[WSK_CLIENT_CONNECTION_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_client_connection_dispatch)

[WSK_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_dispatch)

[WSK_PROVIDER_NPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_provider_npi)

[WSK_SOCKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/ns-wsk-_wsk_socket)

[WskCaptureProviderNPI](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nf-wsk-wskcaptureprovidernpi)

[WskCloseSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_close_socket)

[WskControlClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_client)

[WskSocket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_socket)