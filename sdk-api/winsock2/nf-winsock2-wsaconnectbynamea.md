# WSAConnectByNameA function

## Description

The **WSAConnectByName** function establishes a connection to a specified host and port. This function is provided to allow a quick connection to a network endpoint given a host name and port.

This function supports both IPv4 and IPv6 addresses.

## Parameters

### `s` [in]

A descriptor that identifies an unconnected socket.

**Note** On Windows 7, Windows Server 2008 R2, and earlier, the **WSAConnectByName** function requires an unbound and unconnected socket. This differs from other Winsock calls to establish a connection (for example, [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)).

### `nodename` [in]

A **NULL**-terminated string that contains the name of the host or the IP address of the host on which to connect for IPv4 or IPv6.

### `servicename` [in]

A **NULL**-terminated string that contains the service name or destination port of the host on which to connect for IPv4 or IPv6.

A service name is a string alias for a port number. For example, “http” is an alias for port 80 defined by the Internet Engineering Task Force (IETF) as the default port used by web servers for the HTTP protocol. Possible values for the *servicename* parameter when a port number is not specified are listed in the following file:

`%WINDIR%\system32\drivers\etc\services`

### `LocalAddressLength` [in, out]

On input, a pointer to the size, in bytes, of the *LocalAddress* buffer provided by the caller. On output, a pointer to the size, in bytes, of the **SOCKADDR** for the local address stored in the *LocalAddress* buffer filled in by the system upon successful completion of the call.

### `LocalAddress` [out]

A pointer to the **SOCKADDR** structure that receives the local address of the connection. The size of the parameter is exactly the size returned in *LocalAddressLength*. This is the same information that would be returned by the [getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname) function. This parameter can be **NULL**, in which case, the *LocalAddressLength* parameter is ignored.

### `RemoteAddressLength` [in, out]

On input, a pointer to the size, in bytes, of the *RemoteAddress* buffer provided by the caller. On output, a pointer to the size, in bytes, of the **SOCKADDR** for the remote address stored in *RemoteAddress* buffer filled-in by the system upon successful completion of the call.

### `RemoteAddress` [out]

A pointer to the **SOCKADDR** structure that receives the remote address of the connection. This is the same information that would be returned by the **getpeername** function. This parameter can be **NULL**, in which case, the *RemoteAddressLength* is ignored.

### `timeout` [in]

The time, in milliseconds, to wait for a response from the remote application before aborting the call.

### `Reserved`

Reserved for future implementation. This parameter must be set to **NULL**.

## Return value

If a connection is established, **WSAConnectByName** returns **TRUE** and *LocalAddress* and *RemoteAddress* parameters are filled in if these buffers were supplied by the caller.

If the call fails, **FALSE** is returned. [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) can then be called to get extended error information.

| Return code | Description |
| --- | --- |
| **WSAEHOSTUNREACH** | The host passed as the *nodename* parameter was unreachable. |
| **WSAEINVAL** | An invalid parameter was passed to the function. The *nodename* or the *servicename* parameter must not be **NULL**. The *Reserved* parameter must be **NULL**. |
| **WSAENOBUFS** | Sufficient memory could not be allocated. |
| **WSAENOTSOCK** | An invalid socket was passed to the function. The *s* parameter must not be **INVALID_SOCKET** or **NULL**. |
| **WSAETIMEDOUT** | A response from the remote application was not received before the *timeout* parameter was exceeded. |

## Remarks

**WSAConnectByName** is provided to enable quick and transparent connections to remote hosts on specific ports. It is compatible with both IPv6 and IPv4 versions.

To enable both IPv6 and IPv4 communications, use the following method:

* The [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function must be called on a socket created for the AF_INET6 address family to disable the **IPV6_V6ONLY** socket option before calling **WSAConnectByName**. This is accomplished by calling the **setsockopt** function on the socket with the *level* parameter set to **IPPROTO_IPV6** (see [IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)), the *optname* parameter set to **IPV6_V6ONLY**, and the *optvalue* parameter value set to zero .

**WSAConnectByName** has limitations:
It works only for connection-oriented sockets, such as those of type SOCK_STREAM.
The function does not support overlapped I/O or non-blocking behavior. **WSAConnectByName** will block even if the socket is in non-blocking mode.

**WSAConnectByName** does not support user-provided data during the establishment of a connection. This call does not support FLOWSPEC structures, either. In cases where these features are required, [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) must be used instead.

In versions before Windows 10, if an application needs to bind to a specific local address or port, then **WSAConnectByName** cannot be used since the socket parameter to **WSAConnectByName** must be an unbound socket.

This restriction was removed Windows 10.

The *RemoteAddress* and the *LocalAddress* parameters point to a **SOCKADDR** structure, which is a generic data type. When **WSAConnectByName** is called, it is expected that a socket address type specific to the network protocol or address family being used will actually be passed in these parameters. So for IPv4 addresses, a pointer to a **sockaddr_in** structure would be cast to a pointer to **SOCKADDR** as the *RemoteAddress* and *LocalAddress* parameters. For IPv6 addresses, a pointer to a **sockaddr_in6** structure would be cast to a pointer to **SOCKADDR** as the *RemoteAddress* and *LocalAddress* parameters.

When the
**WSAConnectByName** function returns **TRUE**, the socket *s* is in the default state for a connected socket. The socket *s* does not enable previously set properties or options until SO_UPDATE_CONNECT_CONTEXT is set on the socket. Use the
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) function to set the SO_UPDATE_CONNECT_CONTEXT option.

For example:

```cpp
//Need to #include <mswsock.h> for SO_UPDATE_CONNECT_CONTEXT

int iResult = 0;

iResult = setsockopt( s, SOL_SOCKET, SO_UPDATE_CONNECT_CONTEXT, NULL, 0 );

```

**Note** When issuing a blocking Winsock call such as **WSAConnectByName** with the *timeout* parameter set to **NULL**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

**Windows Phone 8:** The **WSAConnectByNameW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSAConnectByNameW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

#### Examples

Establish a connection using **WSAConnectByName**.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <mswsock.h>   // Need for SO_UPDATE_CONNECT_CONTEXT
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

SOCKET
OpenAndConnect(LPWSTR NodeName, LPWSTR PortName)
{
    SOCKET ConnSocket = INVALID_SOCKET;
    int ipv6only = 0;
    int iResult;
    BOOL bSuccess;
    SOCKADDR_STORAGE LocalAddr = {0};
    SOCKADDR_STORAGE RemoteAddr = {0};
    DWORD dwLocalAddr = sizeof(LocalAddr);
    DWORD dwRemoteAddr = sizeof(RemoteAddr);

    ConnSocket = socket(AF_INET6, SOCK_STREAM, 0);
    if (ConnSocket == INVALID_SOCKET){
        wprintf(L"socket failed with error: %d\n", WSAGetLastError());
        return INVALID_SOCKET;
    }

    iResult = setsockopt(ConnSocket, IPPROTO_IPV6,
        IPV6_V6ONLY, (char*)&ipv6only, sizeof(ipv6only) );
    if (iResult == SOCKET_ERROR){
        wprintf(L"setsockopt for IPV6_V6ONLY failed with error: %d\n",
            WSAGetLastError());
        closesocket(ConnSocket);
        return INVALID_SOCKET;
    }

    bSuccess = WSAConnectByName(ConnSocket, NodeName,
            PortName, &dwLocalAddr,
            (SOCKADDR*)&LocalAddr,
            &dwRemoteAddr,
            (SOCKADDR*)&RemoteAddr,
            NULL,
            NULL);
    if (!bSuccess){
        wprintf(L"WsaConnectByName failed with error: %d\n", WSAGetLastError());
        closesocket(ConnSocket);
        return INVALID_SOCKET;

    }

    iResult = setsockopt(ConnSocket, SOL_SOCKET,
        SO_UPDATE_CONNECT_CONTEXT, NULL, 0);
    if (iResult == SOCKET_ERROR){
        wprintf(L"setsockopt for SO_UPDATE_CONNECT_CONTEXT failed with error: %d\n",
            WSAGetLastError());
        closesocket(ConnSocket);
        return INVALID_SOCKET;
    }

    return ConnSocket;
}

int __cdecl wmain(int argc, wchar_t **argv)
{
   //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData;
    int iResult;

    SOCKET s = INVALID_SOCKET;

    // Validate the parameters
    if (argc != 3) {
        wprintf(L"usage: %ws <Nodename> <Portname>\n", argv[0]);
        wprintf(L"wsaconnectbyname establishes a connection to a specified host and port.\n");
        wprintf(L"%ws www.contoso.com 8080\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }

    wprintf(L"WsaConnectByName with following parameters:\n");
    wprintf(L"\tNodename = %ws\n", argv[1]);
    wprintf(L"\tPortname (or port) = %ws\n\n", argv[2]);

    //--------------------------------
    // Call our function that uses the WsaConnectByName.

    s = OpenAndConnect(argv[1], argv[2]);
    if ( s == INVALID_SOCKET ) {
        wprintf(L"WsaConnectByName failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    else
    {
        wprintf(L"WsaConnectByName succeeded\n");

        closesocket(s);
        WSACleanup();
        return 0;
    }
}

```

> [!NOTE]
> The winsock2.h header defines WSAConnectByName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[SOCKADDR](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAConnectByList](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnectbylist)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[getaddrinfo](https://learn.microsoft.com/windows/desktop/api/ws2tcpip/nf-ws2tcpip-getaddrinfo)

[getpeername](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getpeername)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)