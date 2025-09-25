# bind function

## Description

The
**bind** function associates a local address with a socket.

## Parameters

### `s` [in]

A descriptor identifying an unbound socket.

### `name` [in]

A pointer to a [sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure of the local address to assign to the bound socket .

### `namelen` [in]

The length, in bytes, of the value pointed to by the *name* parameter.

## Return value

If no error occurs,
**bind** returns zero. Otherwise, it returns SOCKET_ERROR, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Note** A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEACCES](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An attempt was made to access a socket in a way forbidden by its access permissions.<br><br>This error is returned if an attempt to bind a datagram socket to the broadcast address failed because the [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) option SO_BROADCAST is not enabled. |
| **[WSAEADDRINUSE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | Only one usage of each socket address (protocol/network address/port) is normally permitted.<br><br>This error is returned if a process on the computer is already bound to the same fully qualified address and the socket has not been marked to allow address reuse with SO_REUSEADDR. For example, the IP address and port specified in the *name* parameter are already bound to another socket being used by another application. For more information, see the SO_REUSEADDR socket option in the [SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options) reference, [Using SO_REUSEADDR and SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/using-so-reuseaddr-and-so-exclusiveaddruse), and [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse). |
| **[WSAEADDRNOTAVAIL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The requested address is not valid in its context.<br><br>This error is returned if the specified address pointed to by the *name* parameter is not a valid local IP address on this computer. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The system detected an invalid pointer address in attempting to use a pointer argument in a call.<br><br>This error is returned if the *name* parameter is NULL, the *name* or *namelen* parameter is not a valid part of the user address space, the *namelen* parameter is too small, the *name* parameter contains an incorrect address format for the associated address family, or the first two bytes of the memory block specified by *name* do not match the address family associated with the socket descriptor *s*. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied.<br><br>This error is returned of the socket *s* is already bound to an address. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full.<br><br>This error is returned of not enough buffers are available or there are too many connections. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An operation was attempted on something that is not a socket.<br><br>This error is returned if the descriptor in the *s* parameter is not a socket. |

## Remarks

The
**bind** function is required on an unconnected socket before subsequent calls to the
[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) function. It is normally used to bind to either connection-oriented (stream) or connectionless (datagram) sockets. The
**bind** function may also be used to bind to a raw socket (the socket was created by calling the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function with the *type* parameter set to SOCK_RAW). The
**bind** function may also be used on an unconnected socket before subsequent calls to the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect), [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex), [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect), [WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist), or [WSAConnectByName](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbynamea) functions before send operations.

When a socket is created with a call to the
[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function, it exists in a namespace (address family), but it has no name assigned to it. Use the
**bind** function to establish the local association of the socket by assigning a local name to an unnamed socket.

A name consists of three parts when using the Internet address family:

* The address family.
* A host address.
* A port number that identifies the application.

In Windows Sockets 2, the *name* parameter is not strictly interpreted as a pointer to a
[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. It is cast this way for Windows Sockets 1.1 compatibility. Service providers are free to regard it as a pointer to a block of memory of size *namelen*. The first 2 bytes in this block (corresponding to the **sa_family** member of the **sockaddr** structure, the **sin_family** member of the **sockaddr_in** structure, or the **sin6_family** member of the **sockaddr_in6** structure) must contain the address family that was used to create the socket. Otherwise, an error WSAEFAULT occurs.

If an application does not care what local address is assigned, specify the constant value **INADDR_ANY** for an IPv4 local address or the constant value **in6addr_any** for an IPv6 local address in the **sa_data** member of the *name* parameter. This allows the underlying service provider to use any appropriate network address, potentially simplifying application programming in the presence of *multihomed* hosts (that is, hosts that have more than one network interface and address).

For TCP/IP, if the port is specified as zero, the service provider assigns a unique port to the application from the dynamic client port range. On Windows Vista and later, the dynamic client port range is a value between 49152 and 65535. This is a change from Windows Server 2003 and earlier where the dynamic client port range was a value between 1025 and 5000. The maximum value for the client dynamic port range can be changed by setting a value under the following registry key:

**HKLM\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters**

The **MaxUserPort** registry value sets the value to use for the maximum value of the dynamic client port range. You must restart the computer for this setting to take effect.

On Windows Vista and later, the dynamic client port range can be viewed and changed using **netsh** commands. The dynamic client port range can be set differently for UDP and TCP and also for IPv4 and IPv6. For more information, see [KB 929851](https://support.microsoft.com/kb/929851).

The application can use
[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) after calling
**bind** to learn the address and the port that has been assigned to the socket. If the Internet address is equal to **INADDR_ANY** or **in6addr_any**,
**getsockname** cannot necessarily supply the address until the socket is connected, since several addresses can be valid if the host is multihomed. Binding to a specific port number other than port 0 is discouraged for client applications, since there is a danger of conflicting with another socket already using that port number on the local computer.

**Note** When using **bind** with the SO_EXCLUSIVEADDRUSE or SO_REUSEADDR socket option, the socket option must be set prior to executing **bind** to have any affect. For more information, see [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse) and [Using SO_REUSEADDR and SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/using-so-reuseaddr-and-so-exclusiveaddruse).

For multicast operations, the preferred method is to call the **bind** function to associate a socket with a local IP address and then join the multicast group. Although this order of operations is not mandatory, it is strongly recommended. So a multicast application would first select an IPv4 or IPv6 address on the local computer, the wildcard IPv4 address (**INADDR_ANY**), or the wildcard IPv6 address (**in6addr_any**). The multicast application would then call the **bind** function with this address in the in the **sa_data** member of the *name* parameter to associate the local IP address with the socket. If a wildcard address was specified, then Windows will select the local IP address to use. After the **bind** function completes, an application would then join the multicast group of interest. For more information on how to join a multicast group, see the section on [Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming). This socket can then be used to receive multicast packets from the multicast group using the [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv), [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), [WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex), [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), or [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) functions.

The **bind** function is not normally required for send operations to a multicast group. The [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto),[WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg), and [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) functions implicitly bind the socket to the wildcard address if the socket is not already bound. The **bind** function is required before the use of the [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) or [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) functions which do not perform an implicit bind and are allowed only on connected sockets, which means the socket must have already been bound for it to be connected. The **bind** function might be used before send operations using the **sendto**,**WSASendMsg**, or **WSASendTo** functions if an application wanted to select a specific local IP address on a local computer with multiple network interfaces and local IP addresses. Otherwise an implicit bind to the wildcard address using the **sendto**,**WSASendMsg** , or **WSASendTo** functions might result in a different local IP address being used for send operations.

**Note** When issuing a blocking Winsock call such as **bind**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Notes for IrDA Sockets

* The Af_irda.h header file must be explicitly included.
* Local names are not exposed in IrDA. IrDA client sockets therefore, must never call the
  **bind** function before the
  [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function. If the IrDA socket was previously bound to a service name using
  **bind**, the
  **connect** function will fail with SOCKET_ERROR.
* If the service name is of the form "LSAP-SELxxx," where xxx is a decimal integer in the range 1-127, the address indicates a specific LSAP-SEL xxx rather than a service name. Service names such as these allow server applications to accept incoming connections directed to a specific LSAP-SEL, without first performing an ISA service name query to get the associated LSAP-SEL. One example of this service name type is a non-Windows device that does not support IAS.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

The following example demonstrates the use of the **bind** function. For another example that uses the **bind** function, see [Getting Started With Winsock](https://learn.microsoft.com/windows/desktop/WinSock/getting-started-with-winsock).

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{

    // Declare some variables
    WSADATA wsaData;

    int iResult = 0;            // used to return function results

    // the listening socket to be created
    SOCKET ListenSocket = INVALID_SOCKET;

    // The socket address to be passed to bind
    sockaddr_in service;

    //----------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"Error at WSAStartup()\n");
        return 1;
    }
    //----------------------
    // Create a SOCKET for listening for
    // incoming connection requests
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //----------------------
    // The sockaddr_in structure specifies the address family,
    // IP address, and port for the socket that is being bound.
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr("127.0.0.1");
    service.sin_port = htons(27015);

    //----------------------
    // Bind the socket.
    iResult = bind(ListenSocket, (SOCKADDR *) &service, sizeof (service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"bind failed with error %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        wprintf(L"bind returned success\n");

    WSACleanup();
    return 0;
}

```

## See also

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options)

[SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse)

[TCP/IP Raw Sockets](https://learn.microsoft.com/windows/desktop/WinSock/tcp-ip-raw-sockets-2)

[Using SO_REUSEADDR and SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/using-so-reuseaddr-and-so-exclusiveaddruse)

[WSACancelBlockingCall](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsacancelblockingcall)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)