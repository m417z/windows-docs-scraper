## Description

The **LPWSPSocket** function creates a socket. For info about the part played by **LPWSPSocket** in creating a shared socket, see [Shared sockets](https://learn.microsoft.com/windows/win32/winsock/shared-sockets-2) and [Shared sockets in the SPI](https://learn.microsoft.com/windows/win32/winsock/shared-sockets-in-the-spi-2).

## Parameters

### `af` [in]

Address family specification.

### `type` [in]

Type specification for the new socket.

### `protocol` [in]

Protocol to be used with the socket that is specific to the indicated address family.

### `lpProtocolInfo` [in]

Pointer to a
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure that defines the characteristics of the socket to be created.

### `g` [in]

Reserved.

### `dwFlags`

Socket attribute specification.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**LPWSPSocket** returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code is available in *lpErrno*.

| Error code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No more socket descriptors are available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be created. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is not supported. |
| **[WSAEPROTOTYPE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is the wrong type for this socket. |
| **[WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified socket type is not supported in this address family. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Parameter *g* specified is not valid. |

## Remarks

The **LPWSPSocket** function causes a socket descriptor and any related resources to be allocated. By default, the created socket will not have the overlapped attribute. Windows Sockets providers are encouraged to be realized as Windows installable file systems, and supply system file handles as socket descriptors. These providers must call
[WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle) prior to returning from this function. For nonfile-system Windows Sockets providers,
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle) must be used to acquire a unique socket descriptor from the Ws2_32.dll prior to returning from this function. See
[Descriptor Allocation](https://learn.microsoft.com/windows/desktop/WinSock/descriptor-allocation-2) for more information.

The values for *af*, *type*, and *protocol* are those supplied by the application in the corresponding API functions
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) or
[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa). A service provider is free to ignore or pay attention to any or all of these values as is appropriate for the particular protocol. However, the provider must be willing to accept the value of zero for *af* and *type*, since the Ws2_32.dll considers these to be wildcard values. Also the value of manifest constant **FROM_PROTOCOL_INFO** must be accepted for any of *af*, *type*, and *protocol*. This value indicates that the Windows Sockets 2 application needs to use the corresponding values from the
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure (**iAddressFamily**, **iSocketType**, **iProtocol**).

The *dwFlags* parameter can be used to specify the attributes of the socket by using the bitwise OR operator with any of the following flags.

|Flag|Meaning|
|-|-|
|WSA_FLAG_OVERLAPPED|This flag causes an overlapped socket to be created. Overlapped sockets can utilize [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend), [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto), [LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv), [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom), and [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) for overlapped I/O operations, which allow multiple operations to be initiated and in process simultaneously. All functions that allow overlapped operations also support nonoverlapped usage on an overlapped socket if the values for parameters related to overlapped operation are null.|
|WSA_FLAG_MULTIPOINT_C_ROOT|Indicates that the socket created will be a c_root in a multipoint session. Only allowed if a rooted control plane is indicated in the protocol's [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.|
|WSA_FLAG_MULTIPOINT_C_LEAF|Indicates that the socket created will be a c_leaf in a multicast session. Only allowed if XP1_SUPPORT_MULTIPOINT is indicated in the protocol's [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.|
|WSA_FLAG_MULTIPOINT_D_ROOT|Indicates that the socket created will be a d_root in a multipoint session. Only allowed if a rooted data plane is indicated in the protocol's [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.|
|WSA_FLAG_MULTIPOINT_D_LEAF|Indicates that the socket created will be a d_leaf in a multipoint session. Only allowed if XP1_SUPPORT_MULTIPOINT is indicated in the protocol's [WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure.|

> [!NOTE]
> For multipoint sockets, exactly one WSA_FLAG_MULTIPOINT_C_ROOT or WSA_FLAG_MULTIPOINT_C_LEAF must be specified, and exactly one of WSA_FLAG_MULTIPOINT_D_ROOT or WSA_FLAG_MULTIPOINT_D_LEAF must be specified. Refer to [Protocol-Independent Multicast and Multipoint in the SPI](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-multicast-and-multipoint-in-the-spi-2) for additional information.

Connection-oriented sockets such as SOCK_STREAM provide full-duplex connections, and must be in a connected state before any data can be sent or received on them. A connection to another socket is created with a
[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) call. Once connected, data can be transferred using
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) and
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) calls. When a session has been completed, a
[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) must be performed.

The communications protocols used to implement a reliable, connection-oriented socket ensure that data is not lost or duplicated. If data for which the peer protocol has buffer space cannot be successfully transmitted within a reasonable length of time, the connection is considered broken and subsequent calls will fail with the error code set to [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Connectionless, message-oriented sockets allow sending and receiving of datagrams to and from arbitrary peers using
[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto) and
[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom). If such a socket is connected by using
[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) to a specific peer, datagrams can be sent to that peer using
[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) and can be received from (only) this peer using
[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv).

Support for sockets with type **SOCK RAW** is not required but service providers are encouraged to support raw sockets whenever it makes sense to do so.

A layered service provider supplies an implementation of this function, but it is also a client of this function if and when it calls
**LPWSPSocket** of the next layer in the protocol chain. Some special considerations apply to this function's *lpProtocolInfo* parameter as it is propagated down through the layers of the protocol chain.

If the next layer in the protocol chain is another layer then when the next layer's
**LPWSPSocket** is called, this layer must pass to the next layer a *lpProtocolInfo* that references the same unmodified
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure with the same unmodified chain information. However, if the next layer is the base protocol (that is, the last element in the chain), this layer performs a substitution when calling the base provider's
**LPWSPSocket**. In this case, the base provider's
**WSAPROTOCOL_INFO** structure should be referenced by the *lpProtocolInfo* parameter.

One vital benefit of this policy is that base service providers do not have to be aware of protocol chains.

This same propagation policy applies when propagating a
[WSAProtocol_Info](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure through a layered sequence of other functions such as
[LPWSPAddressToString](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaddresstostring),
[LPWSPDuplicateSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspduplicatesocket),
[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup), or
[LPWSPStringToAddress](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspstringtoaddress).

## See also

* [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)
* [LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)
* [LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)
* [LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)
* [LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)
* [LPWSPGetSockName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname)
* [LPWSPGetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)
* [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)
* [LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)
* [LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)
* [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)
* [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)
* [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)
* [LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt)
* [LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown)