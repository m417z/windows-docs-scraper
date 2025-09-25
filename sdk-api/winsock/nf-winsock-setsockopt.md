## Description

The **setsockopt** function sets a socket option.

## Parameters

### `s` [in]

A descriptor that identifies a socket.

### `level` [in]

The level at which the option is defined (for example, SOL_SOCKET).

### `optname` [in]

The socket option for which the value is to be set (for example, SO_BROADCAST). The *optname* parameter must be a socket option defined within the specified *level*, or behavior is undefined.

### `optval` [in]

A pointer to the buffer in which the value for the requested option is specified.

### `optlen` [in]

The size, in bytes, of the buffer pointed to by the *optval* parameter.

## Return value

If no error occurs,
**setsockopt** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The buffer pointed to by the *optval* parameter is not in a valid part of the process address space or the *optlen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *level* parameter is not valid, or the information in the buffer pointed to by the *optval* parameter is not valid. |
| **[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has timed out when [SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive) is set. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The option is unknown or unsupported for the specified provider or socket (see SO_GROUP_PRIORITY limitations). |
| **[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The connection has been reset when [SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive) is set. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**setsockopt** function sets the current value for a socket option associated with a socket of any type, in any state. Although options can exist at multiple protocol levels, they are always present at the uppermost socket level. Options affect socket operations, such as whether expedited data (OOB data for example) is received in the normal data stream, and whether broadcast messages can be sent on the socket.

**Note** If the
**setsockopt** function is called before the
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function, TCP/IP options will not be checked by using TCP/IP until the
**bind** occurs. In this case, the
**setsockopt** function call will always succeed, but the
**bind** function call can fail because of an early
**setsockopt** call failing.

**Note** If a socket is opened, a
**setsockopt** call is made, and then a
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) call is made, Windows Sockets performs an implicit
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function call.

There are two types of socket options: Boolean options that enable or disable a feature or behavior, and options that require an integer value or structure. To enable a Boolean option, the *optval* parameter points to a nonzero integer. To disable the option *optval* points to an integer equal to zero. The *optlen* parameter should be equal to `sizeof(int)` for Boolean options. For other options, *optval* points to an integer or structure that contains the desired value for the option, and *optlen* is the length of the integer or structure.

The following tables list some of the common options supported by the **setsockopt** function. The Type column identifies the type of data addressed by *optval* parameter. The Description column provides some basic information about the socket option. For more complete lists of socket options and more detailed information (default values, for example), see the detailed topics under [Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options).

*level* = **SOL_SOCKET**

| Value | Type | Description |
| --- | --- | --- |
| SO_BROADCAST | BOOL | Configures a socket for sending broadcast data. |
| SO_CONDITIONAL_ACCEPT | BOOL | Enables incoming connections are to be accepted or rejected by the application, not by the protocol stack. |
| SO_DEBUG | BOOL | Enables debug output. Microsoft providers currently do not output any debug information. |
| SO_DONTLINGER | BOOL | Does not block close waiting for unsent data to be sent. Setting this option is equivalent to setting SO_LINGER with **l_onoff** set to zero. |
| SO_DONTROUTE | BOOL | Sets whether outgoing data should be sent on interface the socket is bound to and not a routed on some other interface. This option is not supported on ATM sockets (results in an error). |
| SO_GROUP_PRIORITY | int | Reserved. |
| [SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive) | BOOL | Enables sending keep-alive packets for a socket connection. Not supported on ATM sockets (results in an error). |
| SO_LINGER | [LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) | Lingers on close if unsent data is present. |
| SO_OOBINLINE | BOOL | Indicates that out-of-bound data should be returned in-line with regular data. This option is only valid for connection-oriented protocols that support out-of-band data. For a discussion of this topic, see [Protocol Independent Out-Of-band Data](https://learn.microsoft.com/windows/desktop/WinSock/protocol-independent-out-of-band-data-2). |
| SO_RCVBUF | int | Specifies the total per-socket buffer space reserved for receives. |
| SO_REUSEADDR | BOOL | Allows the socket to be bound to an address that is already in use. For more information, see [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind). Not applicable on ATM sockets. |
| [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse) | BOOL | Enables a socket to be bound for exclusive access. Does not require administrative privilege. |
| SO_RCVTIMEO | DWORD | Sets the timeout, in milliseconds, for blocking receive calls. |
| SO_SNDBUF | int | Specifies the total per-socket buffer space reserved for sends. |
| SO_SNDTIMEO | DWORD | The timeout, in milliseconds, for blocking send calls. |
| SO_UPDATE_ACCEPT_CONTEXT | UINT_PTR | Updates the accepting socket with the context of the listening socket. |
| PVD_CONFIG | Service Provider Dependent | This object stores the configuration information for the service provider associated with socket *s*. The exact format of this data structure is service provider specific. |

For more complete and detailed information about socket options for *level* = **SOL_SOCKET**, see [SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options).

*level* = **IPPROTO_TCP**

See **TCP_NODELAY** in [IPPROTO_TCP socket options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-tcp-socket-options). Also see that topic for more complete and detailed information about socket options for *level* = **IPPROTO_TCP**.

*level* = **NSPROTO_IPX**

| Value | Type | Description |
| --- | --- | --- |
| IPX_PTYPE | int | Sets the IPX packet type. |
| IPX_FILTERPTYPE | int | Sets the receive filter packet type |
| IPX_STOPFILTERPTYPE | int | Stops filtering the filter type set with IPX_FILTERTYPE |
| IPX_DSTYPE | int | Sets the value of the data stream field in the SPX header on every packet sent. |
| IPX_EXTENDED_ADDRESS | BOOL | Sets whether extended addressing is enabled. |
| IPX_RECVHDR | BOOL | Sets whether the protocol header is sent up on all receive headers. |
| IPX_RECEIVE_BROADCAST | BOOL | Indicates broadcast packets are likely on the socket. Set to **TRUE** by default. Applications that do not use broadcasts should set this to **FALSE** for better system performance. |
| IPX_IMMEDIATESPXACK | BOOL | Directs SPX connections not to delay before sending an ACK. Applications without back-and-forth traffic should set this to **TRUE** to increase performance. |

For more complete and detailed information about socket options for *level* = **NSPROTO_IPX**, see [NSPROTO_IPX Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/nsproto-ipx-socket-options).

BSD options not supported for
**setsockopt** are shown in the following table.

| Value | Type | Description |
| --- | --- | --- |
| SO_ACCEPTCONN | BOOL | Returns whether a socket is in listening mode. This option is only Valid for connection-oriented protocols. This socket option is not supported for the setting. |
| SO_RCVLOWAT | int | A socket option from BSD UNIX included for backward compatibility. This option sets the minimum number of bytes to process for socket input operations. |
| SO_SNDLOWAT | int | A socket option from BSD UNIX included for backward compatibility. This option sets the minimum number of bytes to process for socket output operations. |
| SO_TYPE | int | Returns the socket type for the given socket (SOCK_STREAM or SOCK_DGRAM, for example This socket option is not supported for the setting the socket type. |

**Note** When issuing a blocking Winsock call such as **setsockopt**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following example demonstrates the **setsockopt** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int main()
{

    //---------------------------------------
    // Declare variables
    WSADATA wsaData;

    SOCKET ListenSocket;
    sockaddr_in service;

    int iResult = 0;

    BOOL bOptVal = FALSE;
    int bOptLen = sizeof (BOOL);

    int iOptVal = 0;
    int iOptLen = sizeof (int);

    //---------------------------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"Error at WSAStartup()\n");
        return 1;
    }
    //---------------------------------------
    // Create a listening socket
    ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ListenSocket == INVALID_SOCKET) {
        wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    //---------------------------------------
    // Bind the socket to the local IP address
    // and port 27015
    hostent *thisHost;
    char *ip;
    u_short port;
    port = 27015;
    thisHost = gethostbyname("");
    ip = inet_ntoa(*(struct in_addr *) *thisHost->h_addr_list);

    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(ip);
    service.sin_port = htons(port);

    iResult = bind(ListenSocket, (SOCKADDR *) & service, sizeof (service));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"bind failed with error %u\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    //---------------------------------------
    // Initialize variables and call setsockopt.
    // The SO_KEEPALIVE parameter is a socket option
    // that makes the socket send keepalive messages
    // on the session. The SO_KEEPALIVE socket option
    // requires a boolean value to be passed to the
    // setsockopt function. If TRUE, the socket is
    // configured to send keepalive messages, if FALSE
    // the socket configured to NOT send keepalive messages.
    // This section of code tests the setsockopt function
    // by checking the status of SO_KEEPALIVE on the socket
    // using the getsockopt function.

    bOptVal = TRUE;

    iResult = getsockopt(ListenSocket, SOL_SOCKET, SO_KEEPALIVE, (char *) &iOptVal, &iOptLen);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"getsockopt for SO_KEEPALIVE failed with error: %u\n", WSAGetLastError());
    } else
        wprintf(L"SO_KEEPALIVE Value: %ld\n", iOptVal);

    iResult = setsockopt(ListenSocket, SOL_SOCKET, SO_KEEPALIVE, (char *) &bOptVal, bOptLen);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"setsockopt for SO_KEEPALIVE failed with error: %u\n", WSAGetLastError());
    } else
        wprintf(L"Set SO_KEEPALIVE: ON\n");

    iResult = getsockopt(ListenSocket, SOL_SOCKET, SO_KEEPALIVE, (char *) &iOptVal, &iOptLen);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"getsockopt for SO_KEEPALIVE failed with error: %u\n", WSAGetLastError());
    } else
        wprintf(L"SO_KEEPALIVE Value: %ld\n", iOptVal);

    closesocket(ListenSocket);
    WSACleanup();
    return 0;
}

```

### Notes for IrDA Sockets

When developing applications using Windows sockets for IrDA, note the following:

* The Af_irda.h header file must be explicitly included.
* IrDA provides the following socket option:

  | Value | Type | Meaning |
  | --- | --- | --- |
  | IRLMP_IAS_SET | *IAS_SET | Sets IAS attributes |

The IRLMP_IAS_SET socket option enables the application to set a single attribute of a single class in the local IAS. The application specifies the class to set, the attribute, and attribute type. The application is expected to allocate a buffer of the necessary size for the passed parameters.

IrDA provides an IAS database that stores IrDA-based information. Limited access to the IAS database is available through the Windows Sockets 2 interface, but such access is not normally used by applications, and exists primarily to support connections to non-Windows devices that are not compliant with the Windows Sockets 2 IrDA conventions.

The following structure, **IAS_SET**, is used with the IRLMP_IAS_SET setsockopt option to manage the local IAS database:

```cpp

// #include <Af_irda.h> for this struct

typedef struct _IAS_SET {
    u_char      irdaClassName[IAS_MAX_CLASSNAME];
    char      irdaAttribName[IAS_MAX_ATTRIBNAME];
    u_long    irdaAttribType;
    union
    {
              LONG irdaAttribInt;
              struct
              {
                   u_long   Len;
                   u_char    OctetSeq[IAS_MAX_OCTET_STRING];
              } irdaAttribOctetSeq;
              struct
              {
                   u_long    Len;
                   u_long    CharSet;
                   u_char    UsrStr[IAS_MAX_USER_STRING];
              } irdaAttribUsrStr;
    } irdaAttribute;
} IAS_SET, *PIAS_SET, FAR *LPIASSET;

```

The following structure, **IAS_QUERY**, is used with the IRLMP_IAS_QUERY setsockopt option to query a peer's IAS database:

```cpp

// #include <Af_irda.h> for this struct

typedef struct _WINDOWS_IAS_QUERY {
        u_char   irdaDeviceID[4];
        char     irdaClassName[IAS_MAX_CLASSNAME];
        char     irdaAttribName[IAS_MAX_ATTRIBNAME];
        u_long   irdaAttribType;
        union
        {
                  LONG    irdaAttribInt;
                  struct
                  {
                          u_long  Len;
                          u_char  OctetSeq[IAS_MAX_OCTET_STRING];
                  } irdaAttribOctetSeq;
                  struct
                  {
                          u_long  Len;
                          u_long  CharSet;
                          u_char  UsrStr[IAS_MAX_USER_STRING];
                  } irdaAttribUsrStr;
        } irdaAttribute;
} IAS_QUERY, *PIAS_QUERY, FAR *LPIASQUERY;

```

Many SO_ level socket options are not meaningful to IrDA. Only SO_LINGER is specifically supported.

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[IPPROTO_IP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options)

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[IPPROTO_RM Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-rm-socket-options)

[IPPROTO_TCP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-tcp-socket-options)

[IPPROTO_UDP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-udp-socket-options)

[NSPROTO_IPX Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/nsproto-ipx-socket-options)

[SOL_APPLETALK Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-appletalk-socket-options)

[SOL_IRLMP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-irlmp-socket-options)

[SOL_SOCKET Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[WSAAsyncSelect](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsaasyncselect)

[WSAEventSelect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaeventselect)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)