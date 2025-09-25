## Description

The **WSAAccept** function conditionally accepts a connection based on the return value of a condition function, provides quality of service flow specifications, and allows the transfer of connection data.

## Parameters

### `s` [in]

A descriptor that identifies a socket that is listening for connections after a call to the
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) function.

### `addr` [out]

An optional pointer to an [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure that receives the address of the connecting entity, as known to the communications layer. The exact format of the *addr* parameter is determined by the address family established when the socket was created.

### `addrlen` [in, out]

An optional pointer to an integer that contains the length of the [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure pointed to by the *addr* parameter, in bytes.

### `lpfnCondition` [in]

The address of an optional, application-specified condition function that will make an accept/reject decision based on the caller information passed in as parameters, and optionally create or join a socket group by assigning an appropriate value to the result parameter *g* of this function. If this parameter is **NULL**, then no condition function is called.

### `dwCallbackData` [in]

Callback data passed back to the application-specified condition function as the value of the *dwCallbackData* parameter passed to the condition function. This parameter is only applicable if the *lpfnCondition* parameter is not **NULL**. This parameter is not interpreted by Windows Sockets.

## Return value

If no error occurs,
**WSAAccept** returns a value of type SOCKET that is a descriptor for the accepted socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

The integer referred to by *addrlen* initially contains the amount of space pointed to by *addr*. On return it will contain the actual length in bytes of the address returned.

| Error code | Meaning |
| --- | --- |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An attempt was made to access a socket in a way forbidden by its access permissions. This error is returned if the connection request that was offered has timed out or been withdrawn. |
| **[WSAECONNREFUSED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No connection could be made because the target machine actively refused it. This error is returned if the connection request was forcefully rejected as indicated in the return value of the condition function (CF_REJECT). |
| **[WSAECONNRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An existing connection was forcibly closed by the remote host. This error is returned of an incoming connection was indicated, but was subsequently terminated by the remote peer prior to accepting the call. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid pointer address in attempting to use a pointer argument in a call. This error is returned of the *addrlen* parameter is too small or the *addr* or *lpfnCondition* is not part of the user address space. |
| **[WSAEINTR](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking operation was interrupted by a call to [WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall). This error is returned if a blocking Windows Sockets 1.1 call was canceled through **WSACancelBlockingCall**. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking operation is currently executing. This error is returned if a blocking Windows Sockets 1.1 call is in progress. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) was not invoked prior to [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept), the return value of the condition function is not a valid one, or any case where the specified socket is in an invalid state. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Too many open sockets. This error is returned if the queue is nonempty upon entry to [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) and there are no socket descriptors available. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A socket operation encountered a dead network. This error is returned if the network subsystem has failed. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full. This error is returned if no buffer space is available. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation was attempted on something that is not a socket. This error is returned if the socket descriptor passed in the *s* parameter is not a socket. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The protocol family has not been configured into the system or no implementation for it exists. This error is returned if the referenced socket is not a type that supports connection-oriented service. |
| **[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A non-blocking socket operation could not be completed immediately. This error is returned if the socket is marked as nonblocking and no connections are present to be accepted. |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Either the application has not called [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup), or **WSAStartup** failed. This error is returned of a successful call to the **WSAStartup** function dit not occur before using this function. |
| **[WSATRY_AGAIN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This is usually a temporary error during hostname resolution and means that the local server did not receive a response from an authoritative server. This error is returned if the acceptance of the connection request was deferred as indicated in the return value of the condition function (CF_DEFER). |

## Remarks

The **WSAAccept** function extracts the first connection on the queue of pending connections on socket *s*, and checks it against the condition function, provided the condition function is specified (that is, not **NULL**). If the condition function returns CF_ACCEPT,
**WSAAccept** creates a new socket. The newly created socket has the same properties as socket *s* including asynchronous events registered with
[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect) or with
[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect). If the condition function returns CF_REJECT,
**WSAAccept** rejects the connection request. The condition function runs in the same thread as this function does, and should return as soon as possible. If the decision cannot be made immediately, the condition function should return CF_DEFER to indicate that no decision has been made, and no action about this connection request should be taken by the service provider. When the application is ready to take action on the connection request, it will invoke
**WSAAccept** again and return either CF_ACCEPT or CF_REJECT as a return value from the condition function.

A socket in default mode (blocking) will block until a connection is present when an application calls
**WSAAccept** and no connections are pending on the queue.

A socket in nonblocking mode (blocking) fails with the error
[WSAEWOULDBLOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) when an application calls
**WSAAccept** and no connections are pending on the queue. After
**WSAAccept** succeeds and returns a new socket handle, the accepted socket cannot be used to accept any more connections. The original socket remains open and listens for new connection requests.

The *addr* parameter is a result parameter that is filled in with the address of the connecting entity, as known to the communications layer. The exact format of the *addr* parameter is determined by the address family in which the communication is occurring. The *addrlen* is a value-result parameter; it should initially contain the amount of space pointed to by *addr*. On return, it will contain the actual length (in bytes) of the address returned. This call is used with connection-oriented socket types such as SOCK_STREAM. If *addr* and/or *addrlen* are equal to **NULL**, then no information about the remote address of the accepted socket is returned. Otherwise, these two parameters will be filled in if the connection is successfully accepted.

A prototype of the condition function is defined in the `Winsock2.h` header file as the **LPCONDITIONPROC**, as follows.

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

The **ConditionFunc** is a placeholder for the application-specified callback function. The actual condition function must reside in a DLL or application module. It is exported in the module definition file.

The *lpCallerId* parameter points to a WSABUF structure that contains the address of the connecting entity, where its *len* parameter is the length of the buffer in bytes, and its *buf* parameter is a pointer to the buffer. The *lpCallerData* is a value parameter that contains any user data. The information in these parameters is sent along with the connection request. If no caller identification or caller data is available, the corresponding parameters will be **NULL**. Many network protocols do not support connect-time caller data. Most conventional network protocols can be expected to support caller identifier information at connection-request time. The buf portion of the
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) pointed to by *lpCallerId* points to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2). The **sockaddr** structure is interpreted according to its address family (typically by casting the **sockaddr** to some type specific to the address family).

The *lpSQOS* parameter references the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structures for socket *s* specified by the caller, one for each direction, followed by any additional provider-specific parameters. The sending or receiving flow specification values will be ignored as appropriate for any unidirectional sockets. A **NULL** value indicates that there is no caller-supplied quality of service and that no negotiation is possible. A non-**NULL** *lpSQOS* pointer indicates that a quality of service negotiation is to occur or that the provider is prepared to accept the quality of service request without negotiation.

The *lpGQOS* parameter is reserved, and should be **NULL**. (reserved for future use with socket groups) references the
[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure for the socket group the caller is to create, one for each direction, followed by any additional provider-specific parameters. A **NULL** value for *lpGQOS* indicates no caller-specified group quality of service. Quality of service information can be returned if negotiation is to occur.

The *lpCalleeId* is a parameter that contains the local address of the connected entity. The *buf* portion of the WSABUF pointed to by *lpCalleeId* points to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The **sockaddr** structure is interpreted according to its address family (typically by casting the **sockaddr** to some type specific to the address family such as struct **sockaddr_in**).

The *lpCalleeData* is a result parameter used by the condition function to supply user data back to the connecting entity. The *lpCalleeData->len* initially contains the length of the buffer allocated by the service provider and pointed to by *lpCalleeData->buf*. A value of zero means passing user data back to the caller is not supported. The condition function should copy up to *lpCalleeData->len* bytes of data into *lpCalleeData->buf*, and then update *lpCalleeData->len* to indicate the actual number of bytes transferred. If no user data is to be passed back to the caller, the condition function should set *lpCalleeData->len* to zero. The format of all address and user data is specific to the address family to which the socket belongs.

The *g* parameter is assigned within the condition function to indicate any of the following actions:

* If *g* is an existing socket group identifier, add *s* to this group, provided all the requirements set by this group are met.
* If *g* = SG_UNCONSTRAINED_GROUP, create an unconstrained socket group and have *s* as the first member.
* If *g* = SG_CONSTRAINED_GROUP, create a constrained socket group and have *s* as the first member.
* If *g* = zero, no group operation is performed.

For unconstrained groups, any set of sockets can be grouped together as long as they are supported by a single service provider. A constrained socket group can consist only of connection-oriented sockets, and requires that connections on all grouped sockets be to the same address on the same host. For newly created socket groups, the new group identifier can be retrieved by using
[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function with *level* parameter set to [SOL_SOCKET](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options) and the *optname* parameter set to **SO_GROUP_ID**. A socket group and its associated socket group ID remain valid until the last socket belonging to this socket group is closed. Socket group IDs are unique across all processes for a given service provider. A socket group and its associated identifier remain valid until the last socket belonging to this socket group is closed. Socket group identifiers are unique across all processes for a given service provider. For more information on socket groups, see the Remarks for the [WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa) functions.

The *dwCallbackData* parameter value passed to the condition function is the value passed as the *dwCallbackData* parameter in the original
**WSAAccept** call. This value is interpreted only by the Windows Socket version 2 client. This allows a client to pass some context information from the
**WSAAccept** call site through to the condition function. This also provides the condition function with any additional information required to determine whether to accept the connection or not. A typical usage is to pass a (suitably cast) pointer to a data structure containing references to application-defined objects with which this socket is associated.

**Note** To protect use of the **WSAAccept** function from SYN attacks, applications must perform full TCP handshakes (SYN-SYNACK-ACK) before reporting the connection request. Protecting against SYN attacks in this manner results in the SO_CONDITIONAL_ACCEPT socket option becoming inoperative; the conditional function is still called, and the **WSAAccept** function operates properly, but server applications that rely on clients being unable to perform the handshake will not operate properly.

**Note** When issuing a blocking Winsock call such as **WSAAccept**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the use of the **WSAAccept** function.

```cpp
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>

/* Define an example conditional function that depends on the pQos field */
int CALLBACK ConditionAcceptFunc(
    LPWSABUF lpCallerId,
    LPWSABUF lpCallerData,
    LPQOS pQos,
    LPQOS lpGQOS,
    LPWSABUF lpCalleeId,
    LPWSABUF lpCalleeData,
    GROUP FAR * g,
    DWORD_PTR dwCallbackData
    )
{

    if (pQos != NULL) {
        RtlZeroMemory(pQos, sizeof(QOS));
        return CF_ACCEPT;
    } else
        return CF_REJECT;
}

int main() {

    /* Declare and initialize variables */
    WSADATA wsaData;
    SOCKET ListenSocket, AcceptSocket;
    struct sockaddr_in saClient;
    int iClientSize = sizeof(saClient);
    u_short port = 27015;
    char* ip;
    sockaddr_in service;
    int error;

    /* Initialize Winsock */
    error = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (error) {
        printf("WSAStartup() failed with error: %d\n", error);
        return 1;
    }

    /* Create a TCP listening socket */
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket() failed with error: %d\n", WSAGetLastError() );
        WSACleanup();
        return 1;
    }

    /*-----------------------------------------
     *  Set up the sock addr structure that the listening socket
     *  will be bound to. In this case, the structure holds the
     * local IP address and the port specified. */
    service.sin_family = AF_INET;
    service.sin_port = htons(port);
    hostent* thisHost;
    thisHost = gethostbyname("");
    ip = inet_ntoa (*(struct in_addr *)*thisHost->h_addr_list);
    service.sin_addr.s_addr = inet_addr(ip);

    /*-----------------------------------------
     *  Bind the listening socket to the IP address.
     * and port number specified by the sockaddr structure. */
    error = bind(ListenSocket, (SOCKADDR *) &service, sizeof(SOCKADDR));
    if (error == SOCKET_ERROR) {
        printf("bind() failed with error: %d\n", WSAGetLastError() );
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    /* Make the socket listen for incoming connection requests */
    error = listen(ListenSocket, 1);
    if (error == SOCKET_ERROR) {
        printf("listen() failed with error: %d\n", WSAGetLastError() );
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    printf("Listening...\n");

    /*-----------------------------------------
     *  Accept an incoming connection request on the
     *  listening socket and transfer control to the
     * accepting socket. */
    AcceptSocket = WSAAccept(ListenSocket, (SOCKADDR*) &saClient, &iClientSize,
        &ConditionAcceptFunc, NULL);

    /*  Now do some work with the AcceptSocket
     *  At this point, the application could
     *  handle data transfer on the socket, or other socket
     * functionality.*/

    /* Then clean up and quit */

    closesocket(AcceptSocket);
    closesocket(ListenSocket);
    WSACleanup();

    return 0;
}
```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)