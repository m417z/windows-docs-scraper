## Description

The **LPWSPConnect** function establishes a connection to a peer, exchanges connect data, and specifies needed quality of service based on the supplied flow specification.

## Parameters

### `s` [in]

Descriptor identifying an unconnected socket.

### `name` [in]

Name of the peer to which the socket in the **[sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2)** is to be connected.

### `namelen` [in]

Length of the *name*, in bytes.

### `lpCallerData` [in]

Pointer to the user data that is to be transferred to the peer during connection establishment.

### `lpCalleeData` [out]

Pointer to a buffer into which any user data received from the peer during connection establishment can be copied.

### `lpSQOS` [in]

Pointer to the flow specifications for socket *s*, one for each direction.

### `lpGQOS` [in]

Reserved.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPConnect** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code is available in *lpErrno*.

On a blocking socket, the return value indicates success or failure of the connection attempt. If the return error code indicates the connection attempt failed (that is, [WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED), [WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH), [WSAETIMEDOUT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAETIMEDOUT)) the Winsock SPI client can call **LPWSPConnect** again for the same socket.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRINUSE)** | Local address of the socket is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs at the time of bind, but could be delayed until this function if the bind was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR)** | (Blocking) call was canceled through **[LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall)**. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | Blocking Winsock call is in progress or the service provider is still processing a callback function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEALREADY)** | Nonblocking **[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)** call is in progress on the specified socket. \  In order to preserve backward compatibility, this error is reported as WSAEINVAL to Windows Sockets 1.1 applications that link to either Winsock.dll or Wsock32.dll. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRNOTAVAIL)** | Remote address is not a valid address (for example, ADDR_ANY). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEAFNOSUPPORT)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED)** | An attempt to connect was rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *name* or the *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the buffer length for *lpCalleeData*, *lpSQOS*, and *lpGQOS* is too small, or the buffer length for *lpCallerData* is too large. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Parameter *s* is a listening socket. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEISCONN)** | Socket is already connected (connection-oriented sockets only). |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH)** | The network cannot be reached from this host at this time. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS)** | No buffer space is available. The socket cannot be connected. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | Flow specifications specified in *lpSQOS* cannot be satisfied. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEPROTONOSUPPORT)** | The *lpCallerData* augment is not supported by the service provider. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAETIMEDOUT)** | An attempt to connect timed out without establishing a connection. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK)** | Socket is marked as nonblocking and the connection cannot be completed immediately. It is possible to select the socket using the **[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)** function while it is connecting by using the **WSPSelect** function to select it for writing. |
| **[WSAEACCES](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEACCES)** | An attempt to connect datagram socket to broadcast address failed because **[WSPSetSockOpt](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566318(v=vs.85))** SO_BROADCAST is not enabled. |

## Remarks

This function is used to create a connection to the specified destination and to perform a number of other ancillary operations that occur at connect time as well. If the socket, *s*, is unbound, unique values are assigned to the local association by the system and the socket is marked as bound.

For connection-oriented sockets (for example, type SOCK_STREAM), an active connection is initiated to the specified host using *name* (an address in the namespace of the socket. For a detailed description, see **[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)**. When this call completes successfully, the socket is ready to send and receive data. If the address member of the **name** structure is all zeroes, **LPWSPConnect** will return the error [WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEADDRNOTAVAIL). Any attempt to reconnect an active connection will fail with the error code [WSAEISCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEISCONN).

For connection-oriented, nonblocking sockets it is often not possible to complete the connection immediately. In such a case, this function returns with the error [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK) but the operation proceeds. When the success or failure outcome becomes known, it may be reported in one of several ways depending on how the client registers for notification. If the client uses **[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)**, success is reported in the *writefds* set and failure is reported in the *exceptfds* set. If the client uses **[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)** or **[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)**, the notification is announced with FD_CONNECT and the error code associated with the FD_CONNECT indicates either success or a specific reason for failure.

For a connectionless socket (for example, type SOCK_DGRAM), the operation performed by **LPWSPConnect** is to establish a default destination address so the socket can be used with subsequent connection-oriented send and receive operations (**[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend)**, **[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv)**). Any datagrams received from an address other than the destination address specified will be discarded. If the address member of the *name* structure is all zeroes, the socket will be disconnected— the default remote address will be indeterminate, so **LPWSPSend** and **LPWSPRecv** calls will return the error code [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN). However, **[LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)** and **[LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)** can still be used. The default destination can be changed by simply calling **LPWSPConnect** again, even if the socket is already connected. Any datagrams queued for receipt are discarded if *name* is different from the previous **LPWSPConnect**.

For connectionless sockets, *name* can indicate any valid address, including a broadcast address. However, to connect to a broadcast address, a socket must have **[WSPSetSockOpt](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566318(v=vs.85))** SO_BROADCAST enabled. Otherwise, **LPWSPConnect** will fail with the error code [WSAEACCES](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEACCES).

On connectionless sockets, exchange of user-to-user data is not possible and the corresponding parameters will be silently ignored.

The Winsock SPI client is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specifies.

The *lpCallerData* is a value parameter that contains any user data to be sent along with the connection request. If *lpCallerData* is null, no user data will be passed to the peer. The *lpCalleeData* is a result parameter that will reference any user data passed back from the peer as part of the connection establishment. The *lpCalleeData*->**len** initially contains the length of the buffer allocated by the Winsock SPI client and pointed to by *lpCalleeData*->**buf**. The *lpCalleeData*->**len** will be set to zero if no user data has been passed back. The *lpCalleeData* information will be valid when the connection operation is complete. For blocking sockets, this will be when the **LPWSPConnect** function returns. For nonblocking sockets, this will be after the FD_CONNECT notification has occurred. If *lpCalleeData* is null, no user data will be passed back. The exact format of the user data is specific to the address family the socket belongs to and/or the applications involved.

At connect time, a Winsock SPI client can use the *lpSQOS* parameter to override any previous QoS specification made for the socket through **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)** with the SIO_SET_QOS opcode.

The *lpSQOS* specifies the flow specifications for socket *s*, one for each direction, followed by any additional provider-specific parameters. If either the associated transport provider in general or the specific type of socket in particular cannot honor the QoS request, an error will be returned as indicated below. The sending or receiving flow specification values will be ignored, respectively, for any unidirectional sockets. If no provider-specific parameters are supplied, the **buf** and **len** members of *lpSQOS*->**ProviderSpecific** should be set to null and zero, respectively. A null value for *lpSQOS* indicates that no application supplied quality of service.

> [!Note]
> When connected sockets break (that is, become closed for whatever reason), they should be discarded and recreated. It is safest to assume that when things go awry for any reason on a connected socket, the Winsock SPI client must discard and recreate the needed sockets in order to return to a stable point.

## See also

[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)

[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)

[LPWSPEnumNetworkEvents](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspenumnetworkevents)

[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)

[LPWSPGetSockName](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockname)

[LPWSPGetSockopt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)

[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)