# LPWSPJOINLEAF callback function

## Description

The **WSPJoinLeaf** function joins a leaf node into a multipoint session, exchanges connect data, and specifies needed quality of service based on the supplied flow specifications.

## Parameters

### `s` [in]

Descriptor identifying a multipoint socket.

### `name` [in]

Name of the peer to which the socket in the
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure is to be joined.

### `namelen` [in]

Length of the *name*, in bytes.

### `lpCallerData` [in]

Pointer to the user data that is to be transferred to the peer during multipoint session establishment.

### `lpCalleeData` [out]

Pointer to the user data that is to be transferred back from the peer during multipoint session establishment.

### `lpSQOS` [in]

Pointer to the flow specifications for socket *s*, one for each direction.

### `lpGQOS` [in]

Reserved.

### `dwFlags` [in]

Flags to indicate that the socket is acting as a sender, receiver, or both.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs,
**WSPJoinLeaf** returns a value of type **SOCKET** that is a descriptor for the newly created multipoint socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code is available in *lpErrno*.

On a blocking socket, the return value indicates success or failure of the join operation.

With a nonblocking socket, successful initiation of a join operation is indicated by a return value of a valid socket descriptor. Subsequently, an FD_CONNECT indication is given when the join operation completes, either successfully or otherwise. The error code associated with the FD_CONNECT indicates the success or failure of the
**WSPJoinLeaf**.

Also, until the multipoint session join attempt completes all subsequent calls to
**WSPJoinLeaf** on the same socket will fail with the error code
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). After the
**WSPJoinLeaf** completes successfully a subsequent attempt will usually fail with the error code
[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). An exception to the WSAEISCONN rule occurs for a c_root socket that allows root-initiated joins. In such a case another join may be initiated after a prior
**WSPJoinLeaf** completes.

If the return error code indicates the multipoint session join attempt failed (that is, [WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)) the Windows Sockets SPI client can call
**WSPJoinLeaf** again for the same socket.

| Error code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs at the time of [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), but could be delayed until this function if the **bind** was to a partially wild-card address (involving ADDR_ANY) and if a specific address needs to be "committed" at the time of this function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | (Blocking) call was canceled through [WSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspcancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Nonblocking [WSPJoinLeaf](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspjoinleaf) call is in progress on the specified socket. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Remote address is not a valid address (for example, ADDR_ANY). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to join was forcefully rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or the *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the buffer length for *lpCalleeData*, *lpSQOS*, and *lpGQOS* are too small, or the buffer length for *lpCallerData* is too large. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Socket is already member of the multipoint session. |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be joined. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | Flow specifications specified in *lpSQOS* cannot be satisfied. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpCallerData* augment is not supported by the service provider. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An attempt to join timed out without establishing a multipoint session. |

## Remarks

This function is used to join a leaf node to a multipoint session, and to perform a number of other ancillary operations that occur at session join time as well. If the socket, *s*, is unbound, unique values are assigned to the local association by the system, and the socket is marked as bound.

**WSPJoinLeaf** has the same parameters and semantics as
[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) except that it returns a socket descriptor (as in
[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)), and it has an additional *dwFlags* parameter. Only multipoint sockets created using
[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket) with appropriate multipoint flags set can be used for input parameter *s* in this function. If the socket is in the nonblocking mode, the returned socket descriptor will not be usable until after a corresponding FD_CONNECT indication on the original socket *s* has been received, except that
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) can be invoked on this new socket descriptor to cancel a pending join operation. A root node in a multipoint session can call
**WSPJoinLeaf** one or more times in order to add a number of leaf nodes, however at most one multipoint connection request can be outstanding at a time. Refer to
[Protocol-Independent Multicast and Multipoint in the SPI](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-multicast-and-multipoint-in-the-spi-2) for additional information.

For nonblocking sockets it is often not possible to complete the connection immediately. In such a case, this function returns an as-yet unusable socket descriptor and the operation proceeds. There is no error code such as [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) in this case, since the function has effectively returned a "successful start" indication. When the final outcome success or failure becomes known, it may be reported through
[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect) or
[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect) depending on how the client registers for notification on the original socket *s*. In either case, the notification is announced with FD_CONNECT and the error code associated with the FD_CONNECT indicates either success or a specific reason for failure. Note that
[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect) cannot be used to detect completion notification for
**WSPJoinLeaf**.

The socket descriptor returned by
**WSPJoinLeaf** is different depending on whether the input socket descriptor, *s*, is a c_root or a c_leaf. When used with a c_root socket, the *name* parameter designates a particular leaf node to be added and the returned socket descriptor is a c_leaf socket corresponding to the newly added leaf node. (As is described in section
[Descriptor Allocation](https://learn.microsoft.com/windows/desktop/WinSock/descriptor-allocation-2), when new socket descriptors are allocated IFS providers must call
[WPUModifyIFSHandle](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wpumodifyifshandle) and non-IFS providers must call
[WPUCreateSocketHandle](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle)). The newly created socket has the same properties as *s* including asynchronous events registered with
[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect) or with
[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect). It is not intended to be used for exchange of multipoint data, but rather is used to receive network event indications (for example, FD_CLOSE) for the connection that exists to the particular c_leaf. Some multipoint implementations can also allow this socket to be used for "side chats" between the root and an individual leaf node. An FD_CLOSE indication will be received for this socket if the corresponding leaf node calls
[LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) to drop out of the multipoint session. Symmetrically, invoking
**WSPCloseSocket** on the c_leaf socket returned from
**WSPJoinLeaf** will cause the socket in the corresponding leaf node to get FD_CLOSE notification.

When
**WSPJoinLeaf** is invoked with a c_leaf socket, the *name* parameter contains the address of the root node (for a rooted control scheme) or an existing multipoint session (nonrooted control scheme), and the returned socket descriptor is the same as the input socket descriptor. In other words, a new socket descriptor is not allocated. In a rooted control scheme, the root application would put its c_root socket in the listening mode by calling
[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten). The standard FD_ACCEPT notification will be delivered when the leaf node requests to join itself to the multipoint session. The root application uses the usual
[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) functions to admit the new leaf node. The value returned from
**WSPAccept** is also a c_leaf socket descriptor just like those returned from
**WSPJoinLeaf**. To accommodate multipoint schemes that allow both root-initiated and leaf-initiated joins, it is acceptable for a c_root socket that is already in listening mode to be used as an input to
**WSPJoinLeaf**.

The Windows Sockets SPI client is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specifies.

The *lpCallerData* is a value parameter that contains any user data that is to be sent along with the multipoint session join request. If *lpCallerData* is **NULL**, no user data will be passed to the peer. The *lpCalleeData* is a result parameter that will contain any user data passed back from the peer as part of the multipoint session establishment. *lpCalleeData*->**len** initially contains the length of the buffer allocated by the Windows Sockets SPI client and pointed to by *lpCalleeData*->**buf**. *lpCalleeData*->**len** will be set to zero if no user data has been passed back. The *lpCalleeData* information will be valid when the multipoint join operation is complete. For blocking sockets, this will be when the
**WSPJoinLeaf** function returns. For nonblocking sockets, this will be after the FD_CONNECT notification has occurred on the original socket *s*. If *lpCalleeData* is **NULL**, no user data will be passed back. The exact format of the user data is specific to the address family to which the socket belongs and/or the applications involved.

At multipoint session establishment time, a Windows Sockets SPI client can use the *lpSQOS* parameters to override any previous QoS specification made for the socket through
[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with the SIO_SET_QOS opcode.

*lpSQOS* specifies the flow specifications for socket *s*, one for each direction, followed by any additional provider-specific parameters. If either the associated transport provider in general or the specific type of socket in particular cannot honor the QoS request, an error will be returned as indicated below. The sending or receiving flow specification values will be ignored, respectively, for any unidirectional sockets. If no provider-specific parameters are supplied, the **buf** and **len** members of *lpSQOS*->**ProviderSpecific** should be set to **NULL** and zero, respectively. A **NULL** value for *lpSQOS* indicates no application supplied quality of service.

The *dwFlags* parameter is used to indicate whether the socket will be acting only as a sender (JL_SENDER_ONLY), only as a receiver (JL_RECEIVER_ONLY), or both (JL_BOTH).

**Note** When connected sockets break (that is, become closed for whatever reason), they should be discarded and recreated. It is safest to assume that when things go awry for any reason on a connected socket, the Windows Sockets SPI client must discard and recreate the needed sockets in order to return to a stable point.

## See also

[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)

[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)

[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)

[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)

[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)