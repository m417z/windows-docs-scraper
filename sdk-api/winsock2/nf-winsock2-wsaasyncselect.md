# WSAAsyncSelect function

## Description

[The **WSAAsyncSelect** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Rather than use Select-style I/O, use [Overlapped I/O and Event Objects](https://learn.microsoft.com/windows/desktop/WinSock/overlapped-i-o-and-event-objects-2) with WinSock2.]

The
**WSAAsyncSelect** function requests Windows message-based notification of network events for a socket.

## Parameters

### `s` [in]

A descriptor that identifies the socket for which event notification is required.

### `hWnd` [in]

A handle that identifies the window that will receive a message when a network event occurs.

### `wMsg` [in]

A message to be received when a network event occurs.

### `lEvent` [in]

A bitmask that specifies a combination of network events in which the application is interested.

## Return value

If the
**WSAAsyncSelect** function succeeds, the return value is zero, provided that the application's declaration of interest in the network event set was successful. Otherwise, the value SOCKET_ERROR is returned, and a specific error number can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem failed. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One of the specified parameters was invalid, such as the window handle not referring to an existing window, or the specified socket is in an invalid state. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

Additional error codes can be set when an application window receives a message. This error code is extracted from the *lParam* in the reply message using the **WSAGETSELECTERROR** macro. Possible error codes for each network event are listed in the following table.

Event: FD_CONNECT

| Error code | Meaning |
| --- | --- |
| [WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | Addresses in the specified family cannot be used with this socket. |
| [WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The attempt to connect was rejected. |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network cannot be reached from this host at this time. |
| [WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The *namelen* parameter is invalid. |
| [WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The socket is already bound to an address. |
| [WSAEISCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The socket is already connected. |
| [WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | No more file descriptors are available. |
| [WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | No buffer space is available. The socket cannot be connected. |
| [WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The socket is not connected. |
| [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | Attempt to connect timed out without establishing a connection. |

Event: FD_CLOSE

| Error code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem failed. |
| [WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The connection was reset by the remote side. |
| [WSAECONNABORTED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The connection was terminated due to a time-out or other failure. |

| Error code | Meaning |
| --- | --- |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem failed. |

Event: FD_ROUTING_INTERFACE_CHANGE

| Error code | Meaning |
| --- | --- |
| [WSAENETUNREACH](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The specified destination is no longer reachable. |
| [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) | The network subsystem failed. |

## Remarks

The
**WSAAsyncSelect** function is used to request that WS2_32.DLL should send a message to the window *hWnd* when it detects any network event specified by the *lEvent* parameter. The message that should be sent is specified by the *wMsg* parameter. The socket for which notification is required is identified by the *s* parameter.

The **WSAAsyncSelect** function automatically sets socket *s* to nonblocking mode, regardless of the value of *lEvent*. To set socket *s* back to blocking mode, it is first necessary to clear the event record associated with socket *s* via a call to **WSAAsyncSelect** with *lEvent* set to zero. You can then call [ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket) or [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) to set the socket back to blocking mode. For more information about how to set the nonblocking socket back to blocking mode, see the **ioctlsocket** and **WSAIoctl** functions.

The *lEvent* parameter is constructed by using the bitwise OR operator with any value listed in the following table.

| Value | Meaning |
| --- | --- |
| **FD_READ** | Set to receive notification of readiness for reading. |
| **FD_WRITE** | Wants to receive notification of readiness for writing. |
| **FD_OOB** | Wants to receive notification of the arrival of OOB data. |
| **FD_ACCEPT** | Wants to receive notification of incoming connections. |
| **FD_CONNECT** | Wants to receive notification of completed connection or multipoint join operation. |
| **FD_CLOSE** | Wants to receive notification of socket closure. |
| **FD_QOS** | Wants to receive notification of socket Quality of Service (QoS) changes. |
| **FD_GROUP_QOS** | Wants to receive notification of socket group Quality of Service (QoS) changes (reserved for future use with socket groups). Reserved. |
| **FD_ROUTING_INTERFACE_CHANGE** | Wants to receive notification of routing interface changes for the specified destination(s). |
| **FD_ADDRESS_LIST_CHANGE** | Wants to receive notification of local address list changes for the socket protocol family. |

Issuing a
**WSAAsyncSelect** for a socket cancels any previous
**WSAAsyncSelect** or
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect) for the same socket. For example, to receive notification for both reading and writing, the application must call
**WSAAsyncSelect** with both **FD_READ** and **FD_WRITE**, as follows:

```cpp
rc = WSAAsyncSelect(s, hWnd, wMsg, FD_READ|FD_WRITE);

```

It is not possible to specify different messages for different events. The following code will not work; the second call will cancel the effects of the first, and only **FD_WRITE** events will be reported with message wMsg2:

```cpp
rc = WSAAsyncSelect(s, hWnd, wMsg1, FD_READ);
rc = WSAAsyncSelect(s, hWnd, wMsg2, FD_WRITE);

```

To cancel all notification indicating that Windows Sockets should send no further messages related to network events on the socket, *lEvent* is set to zero.

```cpp
rc = WSAAsyncSelect(s, hWnd, 0, 0);

```

Although
**WSAAsyncSelect** immediately disables event message posting for the socket in this instance, it is possible that messages could be waiting in the application message queue. Therefore, the application must be prepared to receive network event messages even after cancellation. Closing a socket with
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) also cancels
**WSAAsyncSelect** message sending, but the same caveat about messages in the queue still applies.

The socket created by the
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) function has the same properties as the listening socket used to accept it. Consequently,
**WSAAsyncSelect** events set for the listening socket also apply to the accepted socket. For example, if a listening socket has
**WSAAsyncSelect** events **FD_ACCEPT**, **FD_READ**, and **FD_WRITE**, then any socket accepted on that listening socket will also have **FD_ACCEPT**, **FD_READ**, and **FD_WRITE** events with the same *wMsg* value used for messages. If a different *wMsg* or events are desired, the application should call
**WSAAsyncSelect**, passing the accepted socket and the desired new data.

When one of the nominated network events occurs on the specified socket *s*, the application window *hWnd* receives message *wMsg*. The *wParam* parameter identifies the socket on which a network event has occurred. The low word of *lParam* specifies the network event that has occurred. The high word of *lParam* contains any error code. The error code be any error as defined in Winsock2.h.

**Note** Upon receipt of an event notification message, the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function cannot be used to check the error value because the error value returned can differ from the value in the high word of *lParam*.

The error and event codes can be extracted from the *lParam* using the macros **WSAGETSELECTERROR** and **WSAGETSELECTEVENT**, defined in Winsock2.h as:

```cpp
#include <windows.h>

#define WSAGETSELECTEVENT(lParam)       LOWORD(lParam)
#define WSAGETSELECTERROR(lParam)       HIWORD(lParam)

```

The use of these macros will maximize the portability of the source code for the application.

The possible network event codes that can be returned are listed in the following table.

| Value | Meaning |
| --- | --- |
| **FD_READ** | Socket *s* ready for reading. |
| **FD_WRITE** | Socket *s* ready for writing. |
| **FD_OOB** | OOB data ready for reading on socket *s* |
| **FD_ACCEPT** | Socket *s* ready for accepting a new incoming connection. |
| **FD_CONNECT** | Connection or multipoint *join* operation initiated on socket *s* completed. |
| **FD_CLOSE** | Connection identified by socket *s* has been closed. |
| **FD_QOS** | Quality of Service associated with socket *s* has changed. |
| **FD_GROUP_QOS** | Reserved. Quality of Service associated with the socket group to which *s* belongs has changed (reserved for future use with socket groups). |
| **FD_ROUTING_INTERFACE_CHANGE** | Local interface that should be used to send to the specified destination has changed. |
| **FD_ADDRESS_LIST_CHANGE** | The list of addresses of the socket protocol family to which the application client can bind has changed. |

Although
**WSAAsyncSelect** can be called with interest in multiple events, the application window will receive a single message for each network event.

As in the case of the
[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select) function,
**WSAAsyncSelect** will frequently be used to determine when a data transfer operation ([send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) or
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)) can be issued with the expectation of immediate success. Nevertheless, a robust application must be prepared for the possibility that it can receive a message and issue a Windows Sockets 2 call that returns
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) immediately. For example, the following sequence of events is possible:

1. Data arrives on socket *s*; Windows Sockets 2 posts
   **WSAAsyncSelect** message
2. Application processes some other message
3. While processing, application issues an `ioctlsocket(s, FIONREAD...)` and notices that there is data ready to be read
4. Application issues a `recv(s,...)` to read the data
5. Application loops to process next message, eventually reaching the
   **WSAAsyncSelect** message indicating that data is ready to read
6. Application issues `recv(s,...)`, which fails with the error [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Other sequences are also possible.

The WS2_32.DLL will not continually flood an application with messages for a particular network event. Having successfully posted notification of a particular event to an application window, no further message(s) for that network event will be posted to the application window until the application makes the function call that implicitly reenables notification of that network event.

| Event | Reenabling function |
| --- | --- |
| **FD_READ** | [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv), [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), or [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom). |
| **FD_WRITE** | [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send), [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto), [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), or [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto). |
| **FD_OOB** | [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv), [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), or [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom). |
| **FD_ACCEPT** | [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) or [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) unless the error code is [WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) indicating that the condition function returned CF_DEFER. |
| **FD_CONNECT** | None. |
| **FD_CLOSE** | None. |
| **FD_QOS** | [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with command SIO_GET_QOS. |
| **FD_GROUP_QOS** | Reserved. [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with command SIO_GET_GROUP_QOS (reserved for future use with socket groups). |
| **FD_ROUTING_INTERFACE_CHANGE** | [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with command SIO_ROUTING_INTERFACE_CHANGE. |
| **FD_ADDRESS_LIST_CHANGE** | [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with command SIO_ADDRESS_LIST_CHANGE. |

Any call to the reenabling routine, even one that fails, results in reenabling of message posting for the relevant event.

For **FD_READ**, **FD_OOB**, and **FD_ACCEPT** events, message posting is level-triggered. This means that if the reenabling routine is called and the relevant condition is still met after the call, a
**WSAAsyncSelect** message is posted to the application. This allows an application to be event-driven and not be concerned with the amount of data that arrives at any one time. Consider the following sequence:

1. Network transport stack receives 100 bytes of data on socket *s* and causes Windows Sockets 2 to post an **FD_READ** message.
2. The application issues
   [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)( *s*, *buffptr*, 50, 0) to read 50 bytes.
3. Another **FD_READ** message is posted because there is still data to be read.

With these semantics, an application need not read all available data in response to an **FD_READ** message—a single
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) in response to each **FD_READ** message is appropriate. If an application issues multiple
**recv** calls in response to a single **FD_READ**, it can receive multiple **FD_READ** messages. Such an application can require disabling **FD_READ** messages before starting the
**recv** calls by calling
**WSAAsyncSelect** with the **FD_READ** event not set.

The **FD_QOS** and **FD_GROUP_QOS** events are considered edge triggered. A message will be posted exactly once when a quality of service change occurs. Further messages will not be forthcoming until either the provider detects a further change in quality of service or the application renegotiates the quality of service for the socket.

The **FD_ROUTING_INTERFACE_CHANGE** message is posted when the local interface that should be used to reach the destination specified in
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_ROUTING_INTERFACE_CHANGE changes after such IOCTL has been issued.

The **FD_ADDRESS_LIST_CHANGE** message is posted when the list of addresses to which the application can bind changes after
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_ADDRESS_LIST_CHANGE has been issued.

If any event has occurred when the application calls
**WSAAsyncSelect** or when the reenabling function is called, then a message is posted as appropriate. For example, consider the following sequence:

1. An application calls
   [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen).
2. A connect request is received, but not yet accepted.
3. The application calls
   **WSAAsyncSelect** specifying that it requires receiving **FD_ACCEPT** messages for the socket. Due to the persistence of events, Windows Sockets 2 posts an **FD_ACCEPT** message immediately.

The **FD_WRITE** event is handled slightly differently. An **FD_WRITE** message is posted when a socket is first connected with
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) (after FD_CONNECT, if also registered) or accepted with
[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) or
[WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept), and then after a send operation fails with [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) and buffer space becomes available. Therefore, an application can assume that sends are possible starting from the first **FD_WRITE** message and lasting until a send returns [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). After such a failure the application will be notified that sends are again possible with an **FD_WRITE** message.

The **FD_OOB** event is used only when a socket is configured to receive OOB data separately. If the socket is configured to receive OOB data inline, the OOB (expedited) data is treated as normal data and the application should register an interest in, and will receive, **FD_READ** events, not **FD_OOB** events. An application can set or inspect the way in which OOB data is to be handled by using
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) or
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) for the SO_OOBINLINE option.

The error code in an **FD_CLOSE** message indicates whether the socket close was graceful or abortive. If the error code is zero, then the close was graceful; if the error code is
[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), then the socket's virtual circuit was reset. This only applies to connection-oriented sockets such as SOCK_STREAM.

The **FD_CLOSE** message is posted when a close indication is received for the virtual circuit corresponding to the socket. In TCP terms, this means that the **FD_CLOSE** is posted when the connection goes into the TIME WAIT or CLOSE WAIT states. This results from the remote end performing a
[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) on the send side or a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket). **FD_CLOSE** should only be posted after all data is read from a socket, but an application should check for remaining data upon receipt of **FD_CLOSE** to avoid any possibility of losing data.

Be aware that the application will only receive an **FD_CLOSE** message to indicate closure of a virtual circuit, and only when all the received data has been read if this is a graceful close. It will not receive an **FD_READ** message to indicate this condition.

The **FD_QOS** or **FD_GROUP_QOS** message is posted when any parameter in the flow specification associated with socket *s* or the socket group that *s* belongs to has changed, respectively. Applications should use
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with command SIO_GET_QOS or SIO_GET_GROUP_QOS to get the current quality of service for socket *s* or for the socket group *s* belongs to, respectively.

The **FD_ROUTING_INTERFACE_CHANGE** and **FD_ADDRESS_LIST_CHANGE** events are considered edge triggered as well. A message will be posted exactly once when a change occurs after the application has requested the notification by issuing
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_ROUTING_INTERFACE_CHANGE or SIO_ADDRESS_LIST_CHANGE correspondingly. Further messages will not be forthcoming until the application reissues the IOCTL and another change is detected because the IOCTL has been issued.

Here is a summary of events and conditions for each asynchronous notification message.

* **FD_READ**:

  1. When
     **WSAAsyncSelect** is called, if there is data currently available to receive.
  2. When data arrives, if **FD_READ** is not already posted.
  3. After
     [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or
     [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) is called, with or without MSG_PEEK), if data is still available to receive.

     **Note** When
     [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) SO_OOBINLINE is enabled, data includes both normal data and OOB data in the instances noted above.
* **FD_WRITE**:

  1. When
     **WSAAsyncSelect** called, if a
     [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) or
     [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) is possible.
  2. After
     [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or
     [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) called, when connection established.
  3. After
     [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) or
     [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) fail with
     [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), when
     **send** or
     **sendto** are likely to succeed.
  4. After
     [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) on a connectionless socket. **FD_WRITE** may or may not occur at this time (implementation-dependent). In any case, a connectionless socket is always writable immediately after a
     **bind** operation.
* **FD_OOB**: Only valid when
  [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) SO_OOBINLINE is disabled (default).

  1. When
     **WSAAsyncSelect** called, if there is OOB data currently available to receive with the MSG_OOB flag.
  2. When OOB data arrives, if **FD_OOB** not already posted.
  3. After
     [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or
     [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) called with or without MSG_OOB flag, if OOB data is still available to receive.
* **FD_ACCEPT**:

  1. When
     **WSAAsyncSelect** called, if there is currently a connection request available to accept.
  2. When a connection request arrives, if **FD_ACCEPT** not already posted.
  3. After
     [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) called, if there is another connection request available to accept.
* **FD_CONNECT**:

  1. When
     **WSAAsyncSelect** called, if there is currently a connection established.
  2. After
     [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) called, when connection is established, even when
     **connect** succeeds immediately, as is typical with a datagram socket.
  3. After calling
     [WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf), when join operation completes.
  4. After
     [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
     [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect), or
     [WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf) was called with a nonblocking, connection-oriented socket. The initial operation returned with a specific error of
     [WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), but the network operation went ahead. Whether the operation eventually succeeds or not, when the outcome has been determined, **FD_CONNECT** happens. The client should check the error code to determine whether the outcome was successful or failed.
* **FD_CLOSE**: Only valid on connection-oriented sockets (for example, SOCK_STREAM)

  1. When
     **WSAAsyncSelect** called, if socket connection has been closed.
  2. After remote system initiated graceful close, when no data currently available to receive (Be aware that, if data has been received and is waiting to be read when the remote system initiates a graceful close, the **FD_CLOSE** is not delivered until all pending data has been read).
  3. After local system initiates graceful close with
     [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) and remote system has responded with "End of Data" notification (for example, TCP FIN), when no data currently available to receive.
  4. When remote system terminates connection (for example, sent TCP RST), and *lParam* will contain
     [WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) error value.

     **Note** **FD_CLOSE** is not posted after
     [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) is called.
* **FD_QOS**:

  1. When
     **WSAAsyncSelect** called, if the quality of service associated with the socket has been changed.
  2. After
     [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_GET_QOS called, when the quality of service is changed.
* **FD_GROUP_QOS**: Reserved.
* **FD_ROUTING_INTERFACE_CHANGE**:

  + After
    [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_ROUTING_INTERFACE_CHANGE called, when the local interface that should be used to reach the destination specified in the IOCTL changes.
* **FD_ADDRESS_LIST_CHANGE**:

  + After
    [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) with SIO_ADDRESS_LIST_CHANGE called, when the list of local addresses to which the application can bind changes.

## See also

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)