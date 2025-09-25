## Description

The **LPWSPAccept** function conditionally accepts a connection based on the return value of a condition function.

## Parameters

### `s` [in]

Descriptor identifying a socket that is listening for connections after a [LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten).

### `addr` [out]

Optional pointer to a buffer that receives the address of the connecting entity, as known to the service provider. The exact format of the *addr* parameter is determined by the address family established when the socket in the [sockaddr](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2) structure was created.

### `addrlen` [in, out]

Optional pointer to an integer that contains the length of the *addr* parameter, in bytes.

### `lpfnCondition` [in]

Procedure instance address of an optional-condition function furnished by Windows Sockets. This function is used in the accept or reject decision based on the caller information passed in as parameters.

### `dwCallbackData` [in]

Callback data to be passed back to the Windows Socket 2 client as the value of the *dwCallbackData* parameter of the condition function. This parameter is not interpreted by the service provider.

### `lpErrno` [out]

Pointer to the error code.

## Return value

If no error occurs, **LPWSPAccept** returns a value of type SOCKET that is a descriptor for the accepted socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED)** | The connection request was forcefully rejected as indicated in the return value of the condition function (CF_REJECT). |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET)** | An incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT)** | The *addrlen* parameter is too small or the *lpfnCondition* parameter is not part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINTR)** | A (blocking) call was canceled through [LPWSPCancelBlockingCall](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | A blocking Windows Sockets call is in progress. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | [LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten) was not invoked prior to LPWSPAccept, parameter *g* specified in the condition function is not a valid value, the return value of the condition function is not a valid one, or any case where the specified socket is in an invalid state. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMFILE)** | Queue is nonempty upon entry to LPWSPAccept and there are no socket descriptors available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS)** | No buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | Referenced socket is not a type that supports connection-oriented service. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSATRY_AGAIN)** | Acceptance of the connection request was deferred as indicated in the return value of the condition function (CF_DEFER). |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK)** | Socket is marked as nonblocking and no connections are present to be accepted. |
| **[WSAEACCES](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEACCES)** | The connection request that was offered has timed out or been withdrawn. |

## Remarks

The **LPWSPAccept** function extracts the first connection on the queue of pending connections on socket *s*, and checks it against the condition function, provided the condition function is specified (that is, not null). The condition function must be executed in the same thread as this routine. If the condition function returns CF_ACCEPT, **LPWSPAccept** creates a new socket.

Newly created sockets have the same properties as the socket *s*, including network events registered with [**LPWSPAsyncSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect) or with [**LPWSPEventSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect). As described in [**DescriptorAllocation**](https://learn.microsoft.com/windows/win32/winsock/descriptor-allocation-2), when new socket descriptors are allocated, IFS providers must call [**WPUModifyIFSHandle**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpumodifyifshandle) and non-IFS providers must call [**WPUCreateSocketHandle**](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpucreatesockethandle).

If the condition function returns CF_REJECT, **LPWSPAccept** rejects the connection request. If the application's accept/reject decision cannot be made immediately, the condition function will return CF_DEFER to indicate that no decision has been made. No action about this connection request is to be taken by the service provider. When the application is ready to take action on the connection request, it will invoke **LPWSPAccept** again and return either CF_ACCEPT or CF_REJECT as a return value from the condition function.

For sockets that are in the (default) blocking mode, if no pending connections are present on the queue, **LPWSPAccept** blocks the caller until a connection is present. For sockets in nonblocking mode, if this function is called when no pending connections are present on the queue, **LPWSPAccept** returns the error code [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEWOULDBLOCK). The accepted socket cannot be used to accept more connections. The original socket remains open.

The parameter *addr* is a result parameter that is filled with the address of the connecting entity, as known to the service provider. The exact format of the *addr* parameter is determined by the address family in which the communication is occurring. The *addrlen* is a value-result parameter; it will initially contain the amount of space pointed to by *addr*. On return, it must contain the actual length (in bytes) of the address returned by the service provider. This call is used with connection-oriented socket types such as SOCK_STREAM. If *addr* and/or *addrlen* are equal to null, then no information about the remote address of the accepted socket is returned. Otherwise, these two parameters shall be filled in regardless of whether the condition function is specified or what it returns.

The prototype of the condition function is as follows.

```cpp
int CALLBACK
ConditionFunc(
  IN     LPWSABUF    lpCallerId,
  IN     LPWSABUF    lpCallerData,
  IN OUT LPQOS       lpSQOS,
  IN OUT LPQOS       lpGQOS,
  IN     LPWSABUF    lpCalleeId,
  IN     LPWSABUF    lpCalleeData,
  OUT    GROUP FAR * g, 	
  IN     DWORD_PTR   dwCallbackData
);
```

The *lpCallerId* and *lpCallerData* are value parameters that must contain the address of the connecting entity and any user data that was sent along with the connection request. If no caller identifier or caller data is available, the corresponding parameter will be null. Many network protocols do not support connect-time caller data. Most conventional network protocols can be expected to support caller identifier information at connection-request time. The **buf** part of the [**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) pointed to by *lpCallerId* points to a [**sockaddr**](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2). The **sockaddr** is interpreted according to its address family (typically by casting the **sockaddr** to some type specific to the address family).

The *lpSQOS* parameter references the flow specifications for socket *s* specified by the caller, one for each direction, followed by any additional provider-specific parameters. The sending or receiving flow specification values will be ignored as appropriate for any unidirectional sockets. A null value for *lpSQOS* indicates that there is no caller-supplied QoS and that no negotiation is possible. A non-**NULL** *lpSQOS* pointer indicates that a QoS negotiation is to occur or that the provider is prepared to accept the QoS request without negotiation.

The *lpCalleeId* is a value parameter that contains the local address of the connected entity. The **buf** part of the [**WSABUF**](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-wsabuf) pointed to by *lpCalleeId* points to a [**sockaddr**](https://learn.microsoft.com/windows/win32/winsock/sockaddr-2). The **sockaddr** is interpreted according to its address family (typically by casting the **sockaddr** to some type specific to the address family).

The *lpCalleeData* is a result parameter used by the condition function to supply user data back to the connecting entity. The storage for this data must be provided by the service provider. The *lpCalleeData*->**len** initially contains the length of the buffer allocated by the service provider and pointed to by *lpCalleeData*->**buf**. A value of zero means passing user data back to the caller is not supported. The condition function will copy up to *lpCalleeData*->**len** bytes of data into *lpCalleeData*->**buf**, and then update *lpCalleeData*->**len** to indicate the actual number of bytes transferred. If no user data is to be passed back to the caller, the condition function will set *lpCalleeData*->**len** to zero. The format of all address and user data is specific to the address family to which the socket belongs.

The *dwCallbackData* parameter value passed to the condition function is the value passed as the *dwCallbackData* parameter in the original **LPWSPAccept** call. This value is interpreted only by the Windows Sockets 2 client. This allows a client to pass some context information from the **LPWSPAccept** call site through to the condition function, which provides the condition function with any additional information required to determine whether to accept the connection. A typical usage is to pass a (suitably cast) pointer to a data structure containing references to application-defined objects with which this socket is associated.

## See also

[LPWSPAsyncSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspasyncselect)

[LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind)

[LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect)

[LPWSPEventSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect)

[LPWSPGetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspgetsockopt)

[LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten)

[LPWSPSelect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)

[LPWSPSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsocket)