## Description

The **LPWSPAsyncSelect** function requests Windows message-based event notification of network events for a socket.

## Parameters

### `s` [in]

Descriptor identifying the socket for which event notification is required.

### `hWnd` [in]

Handle identifying the window that should receive a message when a network event occurs.

### `wMsg` [in]

Message to be sent when a network event occurs.

### `lEvent` [in]

Bitmask that specifies a combination of network events in which the Windows Sockets service provider interface (SPI) client is interested. Constructed by using the bitwise OR operator with any of these values.

| Value | Meaning |
| --- | --- |
| FD_READ | Issues notification of readiness for reading. |
| FD_WRITE | Issues notification of readiness for writing. |
| FD_OOB | Issues notification of the arrival of OOB data. |
| FD_ACCEPT | Issues notification of incoming connections. |
| FD_CONNECT | Issues notification of completed connections. |
| FD_CLOSE | Issues notification of socket closure. |
| FD_QOS | Issues notification of socket quality of service (QoS) changes. |
| FD_GROUP_QOS | Reserved. |
| FD_ROUTING_INTERFACE_CHANGE | Issues notification of routing interface change for the specified destination. |
| FD_ADDRESS_ LIST_CHANGE | Issues notification of local address list change for the socket's protocol family. |

### `lpErrno` [out]

Pointer to the error code. See the **Return value** section for more info.

## Return value

The return value is zero if the Windows Sockets SPI client's declaration of interest in the network event set was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error code is available in *lpErrno*.

| Error Code | Meaning |
| --- | --- |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN)** | The network subsystem has failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL)** | Indicates that one of the specified parameters was invalid such as the window handle not referring to an existing window, or the specified socket is in an invalid state. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINPROGRESS)** | A blocking Windows Sockets call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTSOCK)** | The descriptor is not a socket. |

See **Remarks** for info about additional error codes that can be set (in the high word of *lParam* within the message) when an application window receives a message.

## Remarks

This function is used to request that the service provider send a Windows message to the client's window *hWnd* whenever the service provider detects any of the network events specified by the *lEvent* argument. The service provider should use the [WPUPostMessage](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpupostmessage) function to post the message. The message to be sent is specified by the *wMsg* parameter. The socket for which notification is required is identified by *s*.

This function automatically sets socket *s* to nonblocking mode, regardless of the value of *lEvent*. See **[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl)** about how to set the socket back to blocking mode.

Invoking **LPWSPAsyncSelect** for a socket cancels any previous **LPWSPAsyncSelect** or [**LPWSPEventSelect**](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspeventselect) for the same socket. For example, to receive notification for both reading and writing, the Windows Sockets SPI client must call **LPWSPAsyncSelect** with both FD_READ and FD_WRITE, like this.

```cpp
rc = WSPAsyncSelect(s, hWnd, wMsg, FD_READ | FD_WRITE, &error);
```

It's not possible to specify different messages for different events. The following code won't work; the second call cancels the effects of the first, and the only association will be the FD_WRITE event associated with wMsg2.

```cpp
// Incorrect example.
rc = WSPAsyncSelect(s, hWnd, wMsg1, FD_READ, &error);
rc = WSPAsyncSelect(s, hWnd, wMsg2, FD_WRITE, &error);
```

To cancel all notification (that is, to indicate that the service provider should send no further messages related to network events on the socket), set *lEvent* to zero.

```cpp
rc = WSPAsyncSelect(s, hWnd, 0, 0, &error);
```

Since an **[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept)**'ed socket has the same properties as the listening socket used to accept it, any **LPWSPAsyncSelect** events set for the listening socket apply to the accepted socket. For example, if a listening socket has **LPWSPAsyncSelect** events FD_ACCEPT, FD_READ, and FD_WRITE, then any socket accepted on that listening socket will also have FD_ACCEPT, FD_READ, and FD_WRITE events with the same *wMsg* value used for messages. If a different *wMsg* or events are desired, then the Windows Sockets SPI client should call **LPWSPAsyncSelect**, passing the accepted socket, and the desired new information.

When one of the nominated network events occurs on the specified socket *s*, the service provider uses [WPUPostMessage](https://learn.microsoft.com/windows/win32/api/ws2spi/nf-ws2spi-wpupostmessage) to send message *wMsg* to the Windows Sockets SPI client's window *hWnd*. In the posted message, the *wParam* argument identifies the socket on which a network event has occurred. The low word of *lParam* specifies the network event that has occurred. The possible network event codes that may be indicated are as follows.

|Value|Meaning|
|-|-|
|FD_READ|Socket *s* is ready for reading|
|FD_WRITE|Socket *s* is ready for writing|
|FD_OOB|Out-of-band data is ready for reading on socket *s*|
|FD_ACCEPT|Socket *s* is ready to accept a new incoming connection|
|FD_CONNECT|The connection that was initiated on socket *s* has completed|
|FD_CLOSE|The connection identified by socket *s* has been closed|
|FD_QOS|The quality of service associated with socket *s* has changed|
|FD_GROUP_QOS|Reserved for future use with socket groups: Quality of service associated with the socket group to which socket *s* belongs has changed|
|FD_ROUTING_INTERFACE_CHANGE|The local interface that should be used to send to the specified destination has changed|
|FD_ADDRESS_LIST_CHANGE|The list of addresses of the socket's protocol family to which the Windows Sockets SPI client can bind has changed|

The high word of *lParam* contains any error code (it can be extracted by using the **WSAGETSELECTERROR** macro). The error code be any error as defined in `ws2spi.h`. Possible error codes for each network event are listed in the following table.

**Event: FD_CONNECT**

| Error Code | Meaning |
| --- | --- |
| [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEAFNOSUPPORT) | Addresses in the specified family cannot be used with this socket. |
| [WSAECONNREFUSED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNREFUSED) | The attempt to connect was rejected. |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH) | The network cannot be reached from this host at this time. |
| [WSAEFAULT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEFAULT) | The *namelen* parameter is invalid. |
| [WSAEINVAL](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEINVAL) | The socket is already bound to an address. |
| [WSAEISCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEISCONN) | The socket is already connected. |
| [WSAEMFILE](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAEMFILE) | No more file descriptors are available. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOBUFS) | No buffer space is available. The socket cannot be connected. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENOTCONN) | The socket is not connected. |
| [WSAETIMEDOUT](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAETIMEDOUT) | Attempt to connect timed out without establishing a connection. |

**Event: FD_CLOSE**

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem failed. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNRESET) | The connection was reset by the remote side. |
| [WSAECONNABORTED](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAECONNABORTED) | The connection was terminated due to a time-out or other failure. |

**Event...: FD_ACCEPT, FD_ADDRESS_LIST_CHANGE, FD_GROUP_QOS, FD_OOB, FD_QOS, FD_READ, FD_WRITE**

| Error Code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem failed. |

**Event: FD_ROUTING_INTERFACE_CHANGE**

| Error Code | Meaning |
| --- | --- |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETUNREACH) | The specified destination is no longer reachable. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2#WSAENETDOWN) | The network subsystem failed. |

Although **LPWSPAsyncSelect** can be called with interest in multiple events, the service provider issues the same Windows message for each event.

A Windows Sockets 2 provider shouldn't continually flood a Windows Sockets SPI client with messages for a particular network event. Having successfully posted notification of a particular event to a Windows Sockets SPI client window, no further message(s) for that network event will be posted to the Windows Sockets SPI client window until the Windows Sockets SPI client makes the function call that implicitly re-enables notification of that network event.

|Network event|Re-enabling function|
|-|-|
|FD_READ|[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) or [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)|
|FD_WRITE|[LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto)|
|FD_OOB|[LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) or [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom)|
|FD_ACCEPT|[LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept), unless the error code returned is WSATRY_AGAIN indicating that the condition function returned CF_DEFER|
|FD_CONNECT|NONE|
|FD_CLOSE|NONE|
|FD_QOS|[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_GET_QOS|
|FD_GROUP_QOS|Reserved for future use with socket groups: [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_GET_GROUP_QOS|
|FD_ROUTING_INTERFACE_CHANGE|[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with command SIO_ROUTING_INTERFACE_CHANGE|
|FD_ADDRESS_LIST_CHANGE|[LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with command SIO_ADDRESS_LIST_CHANGE|

Any call to the re-enabling routine, even one that fails, results in re-enabling of message-posting for the relevant event.

For FD_READ, FD_OOB, and FD_ACCEPT events, message-posting is *level-triggered*. This means that if the re-enabling routine is called and the relevant condition is still met after the call, an **LPWSPAsyncSelect** message is posted to the Windows Sockets SPI client.

The FD_QOS and FD_GROUP_QOS events are considered *edge-triggered*. A message will be posted exactly once when a QOS change occurs. Further messages won't be forthcoming until either the provider detects a further change in QOS, or the Windows Sockets SPI client renegotiates the QOS for the socket.

The FD_ROUTING_INTERFACE_CHANGE and FD_ADDRESS_LIST_CHANGE events are considered *edge-triggered* as well. A message will be posted exactly once when a change occurs after the Windows Sockets SPI client has request the notification by issuing [WSAIoctl](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaioctl) with SIO_ROUTING_INTERFACE_CHANGE or SIO_ADDRESS_LIST_CHANGE correspondingly. Further messages will not be forthcoming until the Windows Sockets SPI client reissues the IOCTL *and* another change is detected since the IOCTL has been issued.

If any event has already happened when the Windows Sockets SPI client calls **LPWSPAsyncSelect**, or when the re-enabling function is called, then a message is posted as appropriate. For example, consider the following sequence.

1. A Windows Sockets SPI client calls [LPWSPListen](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsplisten).
2. A connect request is received, but not yet accepted.
3. The Windows Sockets SPI client calls **LPWSPAsyncSelect** specifying that it wants to receive FD_ACCEPT messages for the socket. Due to the persistence of events, the WinSock service provider posts an FD_ACCEPT message immediately.

The FD_WRITE event is handled slightly differently. An FD_WRITE message is posted when a socket is first connected with [LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) (after FD_CONNECT, if also registered) or accepted with [LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept), and then after an [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto) fails with WSAEWOULDBLOCK and buffer space becomes available. Therefore, a Windows Sockets SPI client can assume that sends are possible starting from the first FD_WRITE message and lasting until a send returns WSAEWOULDBLOCK. After such a failure, the Windows Sockets SPI client will be notified that sends are again possible with an FD_WRITE message.

The FD_OOB event is used only when a socket is configured to receive out-of-band data separately. If the socket is configured to receive out-of-band data in-line, then the out-of-band (expedited) data is treated as normal data, and the Windows Sockets SPI client must register an interest in FD_READ events, not FD_OOB events.

The error code in an FD_CLOSE message indicates whether the socket close was graceful or abortive. If the error code is 0, then the close was graceful; if the error code is WSAECONNRESET, then the socket's virtual circuit was reset. This only applies to connection-oriented sockets such as SOCK_STREAM.

The FD_CLOSE message is posted when a close indication is received for the virtual circuit corresponding to the socket. In TCP terms, this means that the FD_CLOSE is posted when the connection goes into the TIME WAIT or CLOSE WAIT states. This results from the remote end performing an [LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown) on the send side or an [LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket). It's correct for FD_CLOSE to be posted only after all data is read from a socket.

In the case of a graceful close, the service provider should send an FD_CLOSE message to indicate virtual circuit closure only after all the received data has been read. It shouldn't send an FD_READ message to indicate this condition.

The FD_QOS or FD_GROUP_QOS message is posted when there has been a change to any field in the flow spec associated with socket *s*, or the socket group that *s* belongs to, respectively. The service provider must update the QOS information available to the client via [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_GET_QOS and/or SIO_GET_GROUP_QOS.

The FD_ROUTING_INTERFACE_CHANGE message is posted when the local interface that should be used to reach the destination specified in [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_ROUTING_INTERFACE_CHANGE changes *after* such IOCTL has been issued.

The FD_ADDRESS_LIST_CHANGE message is posted when the list of addresses to which the Windows Sockets SPI client can bind changes *after* [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_ADDRESS_LIST_CHANGE has been issued.

Here is a summary of events and conditions for each asynchronous notification message.

**FD_READ**

1. When **LPWSPAsyncSelect** is called, if there is data currently available to receive.
2. When data arrives, if FD_READ not already posted.
3. After [LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) or [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom) is called (with or without MSG_PEEK), if data is still available to receive.

When [LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt) SO_OOBINLINE is enabled, *data* includes both normal data and out-of-band (OOB) data in the instances noted above.

**FD_WRITE**

1. When **LPWSPAsyncSelect** is called, if an [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto) is possible.
2. After [LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) or [LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) is called, when connection established.
3. After [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto) fail with WSAEWOULDBLOCK, when [LPWSPSend](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsend) or [LPWSPSendTo](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsendto) are likely to succeed.
4. After [LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind) on a connectionless socket. FD_WRITE may or may not occur at this time (implementation-dependent). In any case, a connectionless socket is always writable immediately after [LPWSPBind](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspbind).

**FD_OOB** (valid only when [LPWSPSetSockOpt](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspsetsockopt) SO_OOBINLINE is disabled (default))

1. When **LPWSPAsyncSelect** is called, if there is OOB data currently available to receive with the MSG_OOB flag.
2. When OOB data arrives, if FD_OOB not already posted.
3. After [LPWSPRecv](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecv) or [LPWSPRecvFrom](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwsprecvfrom) is called with or without MSG_OOB flag, if OOB data is still available to receive.

**FD_ACCEPT**

1. When **LPWSPAsyncSelect** is called, if there is currently a connection request available to accept.
2. When a connection request arrives, if FD_ACCEPT not already posted.
3. After [LPWSPAccept](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspaccept) is called, if there is another connection request available to accept.

**FD_CONNECT**

1. When **LPWSPAsyncSelect** is called, if there is currently a connection established.
2. After [LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) is called, when connection is established (even when [LPWSPConnect](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspconnect) succeeds immediately, as is typical with a datagram socket), and even when it fails immediately).
3. After [WSPJoinLeaf](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspjoinleaf) is called, when the join operation completes.
4. After [connect](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-connect), [WSAConnect](https://learn.microsoft.com/windows/win32/api/winsock2/nf-winsock2-wsaconnect), or [WSPJoinLeaf](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspjoinleaf) was called with a non-blocking, connection-oriented socket. The initial operation returned with a specific error of WSAEWOULDBLOCK, but the network operation went ahead. Whether the operation eventually succeeds or not, when the outcome has been determined, FD_CONNECT happens. The client should check the error code to determine whether the outcome was a success or failure.

**FD_CLOSE** (valid only on connection-oriented sockets (for example, SOCK_STREAM))

1. When **LPWSPAsyncSelect** is called, if the socket connection has been closed.
2. After the remote system initiated a graceful close, when no data is currently available to receive (if data has been received and is waiting to be read when the remote system initiates a graceful close, then the FD_CLOSE is not delivered until all pending data has been read).
3. After the local system initiates a graceful close with [LPWSPShutdown](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspshutdown) and the remote system has responded with an *end-of-data* notification (such as TCP FIN), when no data is currently available to receive.
4. When the remote system aborts the connection (for example, sent TCP RST), and *lParam* will contain the WSAECONNRESET error value.

FD_CLOSE is not posted after [LPWSPCloseSocket](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspclosesocket) is called.

**FD_QOS**

1. When **LPWSPAsyncSelect** is called, if the QOS associated with the socket has been changed.
2. After [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_GET_QOS is called, when the QOS is changed.

**FD_GROUP_QOS**

Reserved for future use with socket groups:
1. When **LPWSPAsyncSelect** is called, if the group QOS associated with the socket has been changed.
2. After [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_GET_GROUP_QOS is called, when the group QOS is changed.

**FD_ROUTING_INTERFACE_CHANGE**

1) after [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_ROUTING_INTERFACE_CHANGE is called, when the local interface that should be used to reach the destination specified in the IOCTL changes.

**FD_ADDRESS_LIST_CHANGE**

1) after [LPWSPIoctl](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspioctl) with SIO_ADDRESS_LIST_CHANGE is called, when the list of local addresses to which the Windows Sockets SPI client can bind changes.

## See also

[LPWSPAsyncSelect callback function](https://learn.microsoft.com/windows/win32/api/ws2spi/nc-ws2spi-lpwspselect)