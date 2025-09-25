# WSAJoinLeaf function

## Description

The
**WSAJoinLeaf** function joins a leaf node into a multipoint session, exchanges connect data, and specifies needed quality of service based on the specified
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures.

## Parameters

### `s` [in]

Descriptor identifying a multipoint socket.

### `name` [in]

Name of the peer to which the socket is to be joined.

### `namelen` [in]

Length of *name*, in bytes.

### `lpCallerData` [in]

Pointer to the user data that is to be transferred to the peer during multipoint session establishment.

### `lpCalleeData` [out]

Pointer to the user data that is to be transferred back from the peer during multipoint session establishment.

### `lpSQOS` [in]

Pointer to the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for socket *s*, one for each direction.

### `lpGQOS` [in]

Reserved for future use with socket groups. A pointer to the [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for the socket group (if applicable).

### `dwFlags` [in]

Flags to indicate that the socket is acting as a sender (JL_SENDER_ONLY), receiver (JL_RECEIVER_ONLY), or both (JL_BOTH).

## Return value

If no error occurs,
**WSAJoinLeaf** returns a value of type SOCKET that is a descriptor for the newly created multipoint socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

On a blocking socket, the return value indicates success or failure of the join operation.

With a nonblocking socket, successful initiation of a join operation is indicated by a return of a valid socket descriptor. Subsequently, an FD_CONNECT indication will be given on the original socket *s* when the join operation completes, either successfully or otherwise. The application must use either
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) with interest registered for the FD_CONNECT event in order to determine when the join operation has completed and checks the associated error code to determine the success or failure of the operation. The
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function cannot be used to determine when the join operation completes.

Also, until the multipoint session join attempt completes all subsequent calls to
**WSAJoinLeaf** on the same socket will fail with the error code
[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). After the
**WSAJoinLeaf** operation completes successfully, a subsequent attempt will usually fail with the error code
[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). An exception to the WSAEISCONN rule occurs for a c_root socket that allows root-initiated joins. In such a case, another join may be initiated after a prior
**WSAJoinLeaf** operation completes.

If the return error code indicates the multipoint session join attempt failed (that is,
[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2),
[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)) the application can call
**WSAJoinLeaf** again for the same socket.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs at the time of [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind), but could be delayed until this function if the **bind** was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be committed at the time of this function. |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The remote address is not a valid address (such as ADDR_ANY). |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Addresses in the specified family cannot be used with this socket. |
| **[WSAEALREADY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A nonblocking [WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf) call is in progress on the specified socket. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to join was forcefully rejected. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *name* or the *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the buffer length for *lpCalleeData*, *lpSQOS*, and *lpGQOS* are too small, or the buffer length for *lpCallerData* is too large. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A [WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf) function call was performed on a UDP socket that was opened without setting its WSA_FLAG_MULTIPOINT_C_LEAF or WSA_FLAG_MULTIPOINT_D_LEAF multipoint flag. |
| **[WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is already a member of the multipoint session. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network cannot be reached from this host at this time. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be joined. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures specified in *lpSQOS* and *lpGQOS* cannot be satisfied. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpCallerData* augment is not supported by the service provider. |
| **[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The attempt to join timed out without establishing a multipoint session. |

## Remarks

The
**WSAJoinLeaf** function is used to join a leaf node to a multipoint session, and to perform a number of other ancillary operations that occur at session join time as well. If the socket *s* is unbound, unique values are assigned to the local association by the system, and the socket is marked as bound.

The
**WSAJoinLeaf** function has the same parameters and semantics as
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) except that it returns a socket descriptor (as in
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)), and it has an additional *dwFlags* parameter. Only multipoint sockets created using
[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) with appropriate multipoint flags set can be used for input parameter *s* in this function. The returned socket descriptor will not be usable until after the join operation completes. For example, if the socket is in nonblocking mode after a corresponding FD_CONNECT indication has been received from
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) on the original socket *s*, except that
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) may be invoked on this new socket descriptor to cancel a pending join operation. A root application in a multipoint session may call
**WSAJoinLeaf** one or more times in order to add a number of leaf nodes, however at most one multipoint connection request may be outstanding at a time. Refer to
[Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information.

For nonblocking sockets it is often not possible to complete the connection immediately. In such a case, this function returns an as-yet unusable socket descriptor and the operation proceeds. There is no error code such as
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) in this case, since the function has effectively returned a successful start indication. When the final outcome success or failure becomes known, it may be reported through
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) depending on how the client registers for notification on the original socket *s*. In either case, the notification is announced with FD_CONNECT and the error code associated with the FD_CONNECT indicates either success or a specific reason for failure. The
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function cannot be used to detect completion notification for
**WSAJoinLeaf**.

The socket descriptor returned by
**WSAJoinLeaf** is different depending on whether the input socket descriptor, *s*, is a c_root or a c_leaf. When used with a c_root socket, the *name* parameter designates a particular leaf node to be added and the returned socket descriptor is a c_leaf socket corresponding to the newly added leaf node. The newly created socket has the same properties as *s*, including asynchronous events registered with
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or with
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect). It is not intended to be used for exchange of multipoint data, but rather is used to receive network event indications (for example, FD_CLOSE) for the connection that exists to the particular c_leaf. Some multipoint implementations can also allow this socket to be used for side chats between the root and an individual leaf node. An FD_CLOSE indication will be received for this socket if the corresponding leaf node calls
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) to drop out of the multipoint session. Symmetrically, invoking
**closesocket** on the c_leaf socket returned from
**WSAJoinLeaf** will cause the socket in the corresponding leaf node to get an FD_CLOSE notification.

When
**WSAJoinLeaf** is invoked with a c_leaf socket, the *name* parameter contains the address of the root application (for a rooted control scheme) or an existing multipoint session (nonrooted control scheme), and the returned socket descriptor is the same as the input socket descriptor. In other words, a new socket descriptor is not allocated. In a rooted control scheme, the root application would put its c_root socket in listening mode by calling
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen). The standard FD_ACCEPT notification will be delivered when the leaf node requests to join itself to the multipoint session. The root application uses the usual
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) or
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) functions to admit the new leaf node. The value returned from either
**accept** or
**WSAAccept** is also a c_leaf socket descriptor just like those returned from
**WSAJoinLeaf**. To accommodate multipoint schemes that allow both root-initiated and leaf-initiated joins, it is acceptable for a c_root socket that is already in listening mode to be used as an input to
**WSAJoinLeaf**.

The application is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specifies.

The *lpCallerData* is a value parameter that contains any user data that is to be sent along with the multipoint session join request. If *lpCallerData* is **NULL**, no user data will be passed to the peer. The *lpCalleeData* is a result parameter that will contain any user data passed back from the peer as part of the multipoint session establishment. The **len** member of the [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure pointed to by the *lpCalleeData* parameter initially contains the length of the buffer allocated by the application and pointed to by the **buf** member of the **WSABUF** structure. The **len** member of the **WSABUF** structure pointed to by the *lpCalleeData* parameter will be set to zero if no user data has been passed back. The *lpCalleeData* information will be valid when the multipoint join operation is complete.

For blocking sockets, this will be when the
**WSAJoinLeaf** function returns. For nonblocking sockets, this will be after the join operation has completed. For example, this could occur after FD_CONNECT notification on the original socket *s*). If *lpCalleeData* is **NULL**, no user data will be passed back. The exact format of the user data is specific to the address family to which the socket belongs.

At multipoint session establishment time, an application can use the *lpSQOS* and/or *lpGQOS* parameters to override any previous quality of service specification made for the socket through
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with the SIO_SET_QOS or SIO_SET_GROUP_QOS opcodes.

The *lpSQOS* parameter specifies the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for socket *s*, one for each direction, followed by any additional provider-specific parameters. If either the associated transport provider in general or the specific type of socket in particular cannot honor the quality of service request, an error will be returned as indicated in the following. The respective sending or receiving flow specification values will be ignored for any unidirectional sockets. If no provider-specific parameters are specified, the **buf** and **len** members of the [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure pointed to by the *lpCalleeData* parameter should be set to **NULL** and zero, respectively. A **NULL** value for *lpSQOS* indicates no application-supplied quality of service.

Reserved for future socket groups. The *lpGQOS* parameter specifies the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for the socket group (if applicable), one for each direction, followed by any additional provider-specific parameters. If no provider-specific parameters are specified, the **buf** and **len** members of the [WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structure pointed to by the *lpCalleeData* parameter should be set to should be set to **NULL** and zero, respectively. A **NULL** value for *lpGQOS* indicates no application-supplied group quality of service. This parameter will be ignored if *s* is not the creator of the socket group.

When connected sockets break (that is, become closed for whatever reason), they should be discarded and recreated. It is safest to assume that when things go awry for any reason on a connected socket, the application must discard and recreate the needed sockets in order to return to a stable point.

**Note** When issuing a blocking Winsock call such as **WSAJoinLeaf**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)