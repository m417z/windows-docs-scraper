## Description

The **LPWSPDuplicateSocket** function returns a **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure that can be used to create a new socket descriptor for a shared socket.

## Parameters

### `s` [in]

Local socket descriptor.

### `dwProcessId` [in]

Identifier of the target process for which the shared socket will be used.

### `lpProtocolInfo` [out]

Pointer to a buffer allocated by the client that is large enough to contain a **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure. The service provider copies the protocol information structure contents to this buffer.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPDuplicateSocket** returns zero. Otherwise, the value of SOCKET_ERROR is returned, and a specific error number is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Indicates that one of the specified parameters was invalid. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Blocking Windows Sockets call is in progress or the service provider is still processing a callback function. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMFILE)** | No more socket descriptors are available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS)** | No buffer space is available. The socket cannot be created. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

## Remarks

A source process calls **LPWSPDuplicateSocket** to obtain a special **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure. It uses some interprocess communications (IPC) mechanism to pass the contents of this structure to a target process, which in turn uses it in a call to **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)** to obtain a descriptor for the duplicated socket. Note that the special **WSAPROTOCOL_INFO** structure can only be used once by the target process.

It is the service provider's responsibility to perform whatever operations are needed in the source process context and to create a **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure that will be recognized when it subsequently appears as a parameter to **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)** in the target processes' context. The provider must then return a socket descriptor that references a common underlying socket. The **dwProviderReserved** member of the **WSAPROTOCOL_INFO** structure is available for the service provider's use and can be used to store any useful context information, including a duplicated handle.

When a new socket descriptor is allocated, an installable file system (IFS) provider must call [WPUModifyIFSHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpumodifyifshandle), and a non-IFS provider must call [WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle). An IFS provider can use the [DuplicateHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-duplicatehandle) function. To ensure proper execution of socket duplication, a non-IFS service provider must use the **LPWSPDuplicateSocket** function.

One possible scenario for establishing and using a shared socket in handoff mode is illustrated in the following.

| Source process | IPC | Meaning |
| --- | --- | --- |
| 1) **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)**, **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** |  |  |
| 2) Requests target process identifier. | ==> |  |
|  |  | 3) Receives process identifier request and respond. |
| 4) Receives process identifier. | <== |  |
| 5) Calls **LPWSPDuplicateSocket** to get a special **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure. |  |  |
| 6) Sends **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure to target. |  |  |
|  | ==> | 7) Receives **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure. |
|  |  | 8) Calls **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)** to create shared socket descriptor. |
|  |  | 9) Uses shared socket for data exchange. |
| 10) **[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket)** | <== |  |

The descriptors that reference a shared socket can be used independently as far as I/O is concerned. However, the Windows Sockets interface does not implement any type of access control, so it is up to the processes involved to coordinate their operations on a shared socket. A typical use for shared sockets is to have one process that is responsible for creating sockets and establishing connections, hand off sockets to other processes that are responsible for information exchange.

Since what is duplicated are the socket descriptors and not the underlying socket, all the states associated with a socket are held in common across all the descriptors. For example a **[WSPSetSockOpt](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566318(v=vs.85))** operation performed using one descriptor is subsequently visible using a **[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)** from any or all descriptors. A process can call [LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) on a duplicated socket and the descriptor will become deallocated. The underlying socket, however, will remain open until **LPWSPClosesocket** is called by the last remaining descriptor.

Notification on shared sockets is subject to the usual constraints of **[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)** and **[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**. Issuing either of these calls using any of the shared descriptors cancels any previous event registration for the socket, regardless of which descriptor was used to make that registration. Thus, for example, a shared socket cannot deliver FD_READ events to process A and FD_WRITE events to process B. For situations when such tight coordination is required, it is suggested that developers use threads instead of separate processes.

A layered service provider supplies an implementation of this function, but it is also a client of this function if and when it calls **LPWSPDuplicateSocket** of the next layer in the protocol chain. Some special considerations apply to this function's *lpProtocolInfo* parameter as it is propagated down through the layers of the protocol chain.

If the next layer in the protocol chain is another layer then when the next layer's **LPWSPDuplicateSocket** is called, this layer must pass to the next layer a *lpProtocolInfo* that references the same unmodified **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure with the same unmodified chain information. However, if the next layer is the base protocol (that is, the last element in the chain), this layer performs a substitution when calling the base provider's **LPWSPDuplicateSocket**. In this case, the base provider's **WSAPROTOCOL_INFO** structure should be referenced by the *lpProtocolInfo* parameter.

One vital benefit of this policy is that base service providers do not have to be aware of protocol chains. This same policy applies when propagating a **[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/win32/api/winsock2/ns-winsock2-wsaprotocol_infoa)** structure through a layered sequence of other functions such as **[LPWSPAddressToString](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaddresstostring)**, **[WSPStartup](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wspstartup)**, **[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)**, or **[LPWSPStringToAddress](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspstringtoaddress)**.

## See also

[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)

[WPUModifyIFSHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpumodifyifshandle)