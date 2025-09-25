# shutdown function

## Description

The
**shutdown** function disables sends or receives on a socket.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `how` [in]

A flag that describes what types of operation will no longer be allowed. Possible values for this flag are listed in the *Winsock2.h* header file.

| Value | Meaning |
| --- | --- |
| **SD_RECEIVE**<br><br>0 | Shutdown receive operations. |
| **SD_SEND**<br><br>1 | Shutdown send operations. |
| **SD_BOTH**<br><br>2 | Shutdown both send and receive operations. |

## Return value

If no error occurs,
**shutdown** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable.<br><br> This error applies only to a connection-oriented socket. |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. <br><br>This error applies only to a connection-oriented socket. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *how* parameter is not valid, or is not consistent with the socket type. For example, SD_SEND is used with a UNI_RECV socket type. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The socket is not connected. This error applies only to a connection-oriented socket. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Note** The descriptor is not a socket. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |

## Remarks

The
**shutdown** function is used on all types of sockets to disable reception, transmission, or both.

If the *how* parameter is SD_RECEIVE, subsequent calls to the
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function on the socket will be disallowed. This has no effect on the lower protocol layers. For TCP sockets, if there is still data queued on the socket waiting to be received, or data arrives subsequently, the connection is reset, since the data cannot be delivered to the user. For UDP sockets, incoming datagrams are accepted and queued. In no case will an ICMP error packet be generated.

If the *how* parameter is SD_SEND, subsequent calls to the
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) function are disallowed. For TCP sockets, a FIN will be sent after all data is sent and acknowledged by the receiver.

Setting *how* to SD_BOTH disables both sends and receives as described above.

The
**shutdown** function does not close the socket. Any resources attached to the socket will not be freed until
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) is invoked.

To assure that all data is sent and received on a connected socket before it is closed, an application should use
**shutdown** to close connection before calling
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket). One method to wait for notification that the remote end has sent all its data and initiated a graceful disconnect uses the [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) function as follows :

1. Call
   [WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) to register for FD_CLOSE notification.
2. Call
   **shutdown** with *how*=SD_SEND.
3. When FD_CLOSE received, call
   the [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) until the function completes with success and indicates that zero bytes were received. If SOCKET_ERROR is returned, then the graceful disconnect is not possible.
4. Call
   [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket).

Another method to wait for notification that the remote end has sent all its data and initiated a graceful disconnect uses overlapped receive calls follows :

1. Call
   **shutdown** with *how*=SD_SEND.
2. Call
   [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) until the function completes with success and indicates zero bytes were received. If SOCKET_ERROR is returned, then the graceful disconnect is not possible.
3. Call
   [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket).

**Note** The
**shutdown** function does not block regardless of the SO_LINGER setting on the socket.

For more information, see the section on [Graceful Shutdown, Linger Options, and Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2).

Once the **shutdown** function is called to disable send, receive, or both, there is no method to re-enable send or receive for the existing socket connection.

An application should not rely on being able to reuse a socket after it has been shut down. In particular, a Windows Sockets provider is not required to support the use of
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) on a socket that has been shut down.

If an application wants to reuse a socket, then the [DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85)) function should be called with the *dwFlags* parameter set to **TF_REUSE_SOCKET** to close a connection on a socket and prepare the socket handle to be reused. When the
**DisconnectEx** request completes, the socket handle can be passed to the
[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) or
[ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function.

If an application wants to reuse a socket, the [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile) or [TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets) functions can be called with the *dwFlags* parameter set with **TF_DISCONNECT** and **TF_REUSE_SOCKET** to disconnect after all the data has been queued for transmission and prepare the socket handle to be reused. When the **TransmitFile** request completes, the socket handle can be passed to the
function call previously used to establish the connection, such as [AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex) or [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex). When the
**TransmitPackets** function completes, the socket handle can be passed to the
**AcceptEx** function.

**Note** The socket level disconnect is subject to the behavior of the underlying transport. For example, a TCP socket may be subject to the TCP TIME_WAIT state, causing the [DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85)), [TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile), or [TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets) call to be delayed.

**Note** When issuing a blocking Winsock call such as **shutdown**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Notes for ATM

There are important issues associated with connection teardown when using Asynchronous Transfer Mode (ATM) and Windows Sockets 2. For more information about these important considerations, see the section titled Notes for ATM in the Remarks section of the
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function reference.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[AcceptEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-acceptex)

[ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex)

[DisconnectEx](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms737757(v=vs.85))

[TransmitFile](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-transmitfile)

[TransmitPackets](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_transmitpackets)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)