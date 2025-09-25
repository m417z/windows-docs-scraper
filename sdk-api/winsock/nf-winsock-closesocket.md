# closesocket function

## Description

The
**closesocket** function closes an existing socket.

## Parameters

### `s` [in]

A descriptor identifying the socket to close.

## Return value

If no error occurs,
**closesocket** returns zero. Otherwise, a value of **SOCKET_ERROR** is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The (blocking) Windows Socket 1.1 call was canceled through [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is marked as nonblocking, but the **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is set to nonzero and the **l_linger** member of the **linger** structure is set to a nonzero timeout value. |

## Remarks

The **closesocket** function closes a socket. Use it to release the socket descriptor passed in the *s* parameter. Note that the socket descriptor passed in the *s* parameter may immediately be reused by the system as soon as **closesocket** function is issued. As a result, it is not reliable to expect further references to the socket descriptor passed in the *s* parameter to fail with the error [WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). A Winsock client must never issue **closesocket** on *s* concurrently with another Winsock function call.

Any pending overlapped send and receive operations (
[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend)/
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto)/
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)/
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom) with an overlapped socket) issued by any thread in this process are also canceled. Any event, completion routine, or completion port action specified for these overlapped operations is performed. The pending overlapped operations fail with the error status
[WSA_OPERATION_ABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

An application should not assume that any outstanding I/O operations on a socket will all be guaranteed to completed when **closesocket** returns. The **closesocket** function will initiate cancellation on the outstanding I/O operations, but that does not mean that an application will receive I/O completion for these I/O operations by the time the **closesocket** function returns. Thus, an application should not cleanup any resources ([WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structures, for example) referenced by the outstanding I/O requests until the I/O requests are indeed completed.

An application should always have a matching call to
**closesocket** for each successful call to
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) to return any socket resources to the system.

The
[linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure maintains information about a specific socket that specifies how that socket should behave when data is queued to be sent and the
**closesocket** function is called on the socket.

The **l_onoff** member of the **linger** structure determines whether a socket should remain open for a specified amount of time after a
**closesocket** function call to enable queued data to be sent. This member can be modified in two ways:

* Call the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_DONTLINGER**. The *optval* parameter determines how the **l_onoff** member is modified.
* Call the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_LINGER**. The *optval* parameter specifies how both the **l_onoff** and **l_linger** members are modified.

The **l_linger** member of the **linger** structure determines the amount of time, in seconds, a socket should remain open. This member is only applicable if the **l_onoff** member of the **linger** structure is nonzero.

The default parameters for a socket are the **l_onoff** member of the **linger** structure is zero, indicating that the socket should not remain open. The default value for the **l_linger** member of the **linger** structure is zero, but this value is ignored when the **l_onoff** member is set to zero.

To enable a socket to remain open, an application should set the **l_onoff** member to a nonzero value and set the **l_linger** member to the desired timeout in seconds. To disable a socket from remaining open, an application only needs to set the **l_onoff** member of the **linger** structure to zero.

 If an application calls the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function with the *optname* parameter set to **SO_DONTLINGER** to set the **l_onoff** member to a nonzero value, the value for the **l_linger** member is not specified. In this case, the timeout used is implementation dependent. If a previous timeout has been established for a socket (by previously calling the **setsockopt** function with the *optname* parameter set to **SO_LINGER**), this timeout value should be reinstated by the service provider.

The semantics of
the **closesocket** function are affected by the socket options that set members of **linger** structure.

| **l_onoff** | **l_linger** | Type of close | Wait for close? |
| --- | --- | --- | --- |
| zero | Do not care | Graceful close | No |
| nonzero | zero | Hard | No |
| nonzero | nonzero | Graceful if all data is sent within timeout value specified in the **l_linger** member. <br><br>Hard if all data could not be sent within timeout value specified in the **l_linger** member. | Yes |

If the **l_onoff** member of the
[LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is zero on a stream socket, the
**closesocket** call will return immediately and does not receive
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) whether the socket is blocking or nonblocking. However, any data queued for transmission will be sent, if possible, before the underlying socket is closed. This is also called a graceful disconnect or close. In this case, the Windows Sockets provider cannot release the socket and other resources for an arbitrary period, thus affecting applications that expect to use all available sockets. This is the default behavior for a socket.

If the
**l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is nonzero and **l_linger** member is zero,
**closesocket** is not blocked even if queued data has not yet been sent or acknowledged. This is called a hard or abortive close, because the socket's virtual circuit is reset immediately, and any unsent data is lost. On Windows, any
**recv** call on the remote side of the circuit will fail with
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

If the
**l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is set to nonzero and **l_linger** member is set to a nonzero timeout on a blocking socket, the
**closesocket** call blocks until the remaining data has been sent or until the timeout expires. This is called a graceful disconnect or close if all of the data is sent within timeout value specified in the **l_linger** member. If the timeout expires before all data has been sent, the Windows Sockets implementation terminates the connection before
**closesocket** returns and this is called a hard or abortive close.

Setting the **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure to nonzero and the **l_linger** member with a nonzero timeout interval on a nonblocking socket is not recommended. In this case, the call to
**closesocket** will fail with an error of
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) if the close operation cannot be completed immediately. If
**closesocket** fails with [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) the socket handle is still valid, and a disconnect is not initiated. The application must call
**closesocket** again to close the socket.

If the **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is nonzero and the **l_linger** member is a nonzero timeout interval on a blocking socket, the result of the **closesocket** function can't be used to determine whether all data has been sent to the peer. If the data is sent before the timeout specified in the **l_linger** member expires or if the connection was aborted, the **closesocket** function won't return an error code (the return value from the **closesocket** function is zero).

The **closesocket** call will only block until all data has been delivered to the peer or the timeout expires. If the connection is reset because the timeout expires, then the socket will not go into TIME_WAIT state. If all data is sent within the timeout period, then the socket can go into TIME_WAIT state.

If the **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is nonzero and the **l_linger** member is a zero timeout interval on a blocking socket, then a call to **closesocket** will reset the connection. The socket will not go to the TIME_WAIT state.

The [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function can be called with the *optname* parameter set to **SO_LINGER** to retrieve the current value of the **linger** structure associated with a socket.

**Note** To assure that all data is sent and received on a connection, an application should call
[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) before calling
**closesocket** (see
[Graceful shutdown, linger options, and socket closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2) for more information). Also note, an FD_CLOSE network event is not posted after
**closesocket** is called.

Here is a summary of
**closesocket** behavior:

* If the **l_onoff** member of the
  [LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is zero (the default for a socket), **closesocket** returns immediately and the connection is gracefully closed in the background.
* If the
  **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is set to nonzero and the **l_linger** member is set to zero (no timeout) **closesocket** returns immediately and the connection is reset or terminated.
* If the
  **l_onoff** member of the [linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure is set to nonzero and the **l_linger** member is set to a nonzero timeout:– For a blocking socket, **closesocket** blocks until all data is sent or the timeout expires.

  – For a nonblocking socket, **closesocket** returns immediately indicating failure.

For additional information please see
[Graceful Shutdown, Linger Options, and Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2) for more information.

**Note** When issuing a blocking Winsock call such as **closesocket**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Notes for IrDA Sockets

Keep the following in mind:

* The Af_irda.h header file must be explicitly included.
* The standard linger options are supported.
* Although IrDA does not provide a graceful close, IrDA will defer closing until receive queues are purged. Thus, an application can send data and immediately call the
  [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function, and be confident that the receiver will copy the data before receiving an FD_CLOSE message.

### Notes for ATM

The following are important issues associated with connection teardown when using Asynchronous Transfer Mode (ATM) and Windows Sockets 2:

* Using the
  **closesocket** or
  [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) functions with SD_SEND or SD_BOTH results in a RELEASE signal being sent out on the control channel. Due to ATM's use of separate signal and data channels, it is possible that a RELEASE signal could reach the remote end before the last of the data reaches its destination, resulting in a loss of that data. One possible solutions is programming a sufficient delay between the last data sent and the **closesocket** or [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) function calls for an ATM socket.
* Half close is not supported by ATM.
* Both abortive and graceful disconnects result in a RELEASE signal being sent out with the same cause field. In either case, received data at the remote end of the socket is still delivered to the application. See
  [Graceful Shutdown, Linger Options, and Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2) for more information.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[Graceful Shutdown, Linger Options, and Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSADuplicateSocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaduplicatesocketa)

[WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket)

[linger](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)