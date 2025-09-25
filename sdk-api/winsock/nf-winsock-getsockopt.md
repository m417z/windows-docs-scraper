## Description

The **getsockopt** function retrieves a socket option.

## Parameters

### `s` [in]

A descriptor identifying a socket.

### `level` [in]

The level at which the option is defined. Example: [SOL_SOCKET](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options).

### `optname` [in]

The socket option for which the value is to be retrieved. Example: [SO_ACCEPTCONN](https://learn.microsoft.com/windows/desktop/WinSock/socket-options-and-ioctls-2). The *optname* value must be a socket option defined within the specified *level*, or behavior is undefined.

### `optval` [out]

A pointer to the buffer in which the value for the requested option is to be returned.

### `optlen` [in, out]

A pointer to the size, in bytes, of the *optval* buffer.

## Return value

If no error occurs,
**getsockopt** returns zero. Otherwise, a value of SOCKET_ERROR is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | **Note** The network subsystem has failed. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | One of the *optval* or the *optlen* parameters is not a valid part of the user address space, or the *optlen* parameter is too small. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *level* parameter is unknown or invalid. |
| **[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The option is unknown or unsupported by the indicated protocol family. |
| **[WSAENOTSOCK](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The descriptor is not a socket. |

## Remarks

The
**getsockopt** function retrieves the current value for a socket option associated with a socket of any type, in any state, and stores the result in *optval*. Options can exist at multiple protocol levels, but they are always present at the uppermost socket level. Options affect socket operations, such as the packet routing and OOB data transfer.

The value associated with the selected option is returned in the buffer *optval*. The integer pointed to by *optlen* should originally contain the size of this buffer; on return, it will be set to the size of the value returned. For SO_LINGER, this will be the size of a
[LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure. For most other options, it will be the size of an integer.

The application is responsible for allocating any memory space pointed to directly or indirectly by any of the parameters it specified.

If the option was never set with
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt), then
**getsockopt** returns the default value for the option.

The following options are supported for
**getsockopt**. The Type column identifies the type of data addressed by *optval*.

For more information on socket options, see [Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options).

The following table of value for the *optname* parameter are valid when the *level* parameter is set to **SOL_SOCKET**.

| Value | Type | Meaning |
| --- | --- | --- |
| SO_ACCEPTCONN | BOOL | The socket is listening. |
| SO_BROADCAST | BOOL | The socket is configured for the transmission and receipt of broadcast messages. |
| [SO_BSP_STATE](https://learn.microsoft.com/windows/desktop/WinSock/so-bsp-state) | [CSADDR_INFO](https://learn.microsoft.com/windows/desktop/api/nspapi/ns-nspapi-csaddr_info) | Returns the local address, local port, remote address, remote port, socket type, and protocol used by a socket. |
| SO_CONDITIONAL_ACCEPT | BOOL | Returns current socket state, either from a previous call to [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) or the system default. |
| SO_CONNECT_TIME | DWORD | Returns the number of seconds a socket has been connected. This socket option is valid for connection oriented protocols only. |
| SO_DEBUG | BOOL | Debugging is enabled. |
| SO_DONTLINGER | BOOL | If **TRUE**, the SO_LINGER option is disabled. |
| SO_DONTROUTE | BOOL | Routing is disabled. Setting this succeeds but is ignored on AF_INET sockets; fails on AF_INET6 sockets with [WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). This option is not supported on ATM sockets. |
| SO_ERROR | int | Retrieves error status and clear. |
| [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse) | BOOL | Prevents any other socket from binding to the same address and port. This option must be set before calling the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. |
| SO_GROUP_ID | GROUP | Reserved. |
| SO_GROUP_PRIORITY | int | Reserved. |
| [SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive) | BOOL | Keep-alives are being sent. Not supported on ATM sockets. |
| SO_LINGER | [LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure | Returns the current linger options. |
| SO_MAX_MSG_SIZE | unsigned int | The maximum size of a message for message-oriented socket types (for example, SOCK_DGRAM). Has no meaning for stream oriented sockets. |
| SO_OOBINLINE | BOOL | OOB data is being received in the normal data stream. (See section [Windows Sockets 1.1 Blocking Routines and EINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-1-1-blocking-routines-and-einprogress-2) for a discussion of this topic.) |
| [SO_PORT_SCALABILITY](https://learn.microsoft.com/windows/desktop/WinSock/so-port-scalability) | BOOL | Enables local port scalability for a socket by allowing port allocation to be maximized by allocating wildcard ports multiple times for different local address port pairs on a local machine. |
| SO_PROTOCOL_INFO | [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) | A description of the protocol information for the protocol that is bound to this socket. |
| SO_RCVBUF | int | The total per-socket buffer space reserved for receives. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of the TCP receive window. |
| SO_REUSEADDR | BOOL | The socket can be bound to an address which is already in use. Not applicable for ATM sockets. |
| SO_SNDBUF | int | The total per-socket buffer space reserved for sends. This is unrelated to SO_MAX_MSG_SIZE and does not necessarily correspond to the size of a TCP send window. |
| SO_TYPE | int | The type of the socket (for example, SOCK_STREAM). |
| PVD_CONFIG | Service Provider Dependent | An opaque data structure object from the service provider associated with socket *s*. This object stores the current configuration information of the service provider. The exact format of this data structure is service provider specific. |

*level* = **IPPROTO_TCP**

See **TCP_NODELAY** in [IPPROTO_TCP socket options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-tcp-socket-options). Also see that topic for more complete and detailed information about socket options for *level* = **IPPROTO_TCP**.

The following table of value for the *optname* parameter are valid when the *level* parameter is set to **NSPROTO_IPX**.

**Note** Windows NT supports all IPX options. Windows Me, Windows 98, and Windows 95 support only the following options:

IPX_PTYPE

IPX_FILTERPTYPE

IPX_DSTYPE

IPX_RECVHDR

IPX_MAXSIZE

IPX_ADDRESS

| Value | Type | Meaning |
| --- | --- | --- |
| IPX_PTYPE | int | Retrieves the IPX packet type. |
| IPX_FILTERPTYPE | int | Retrieves the receive filter packet type |
| IPX_DSTYPE | int | Obtains the value of the data stream field in the SPX header on every packet sent. |
| IPX_EXTENDED_ADDRESS | BOOL | Finds out whether extended addressing is enabled. |
| IPX_RECVHDR | BOOL | Finds out whether the protocol header is sent up on all receive headers. |
| IPX_MAXSIZE | int | Obtains the maximum data size that can be sent. |
| IPX_ADDRESS | [IPX_ADDRESS_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_address_data) structure | Obtains information about a specific adapter to which IPX is bound. Adapter numbering is base zero. The **adapternum** member is filled in upon return. |
| IPX_GETNETINFO | [IPX_NETNUM_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_netnum_data) structure | Obtains information about a specific IPX network number. If not available in the cache, uses RIP to obtain information. |
| IPX_GETNETINFO_NORIP | [IPX_NETNUM_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_netnum_data) structure | Obtains information about a specific IPX network number. If not available in the cache, will not use RIP to obtain information, and returns error. |
| IPX_SPXGETCONNECTIONSTATUS | [IPX_SPXCONNSTATUS_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_spxconnstatus_data) structure | Retrieves information about a connected SPX socket. |
| IPX_ADDRESS_NOTIFY | [IPX_ADDRESS_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_address_data) structure | Retrieves status notification when changes occur on an adapter to which IPX is bound. |
| IPX_MAX_ADAPTER_NUM | int | Retrieves maximum number of adapters present, numbered as base zero. |
| IPX_RERIPNETNUMBER | [IPX_NETNUM_DATA](https://learn.microsoft.com/windows/desktop/api/wsnwlink/ns-wsnwlink-ipx_netnum_data) structure | Similar to IPX_GETNETINFO, but forces IPX to use RIP for resolution, even if the network information is in the local cache. |
| IPX_IMMEDIATESPXACK | BOOL | Directs SPX connections not to delay before sending an ACK. Applications without back-and-forth traffic should set this to **TRUE** to increase performance. |
| TCP_MAXSEG | int | Receives TCP maximum-segment size. Supported in Windows 10 and newer versions. |

The following table lists value for the *optname* that represent BSD socket options that are not supported by the **getsockopt** function.

| Value | Type | Meaning |
| --- | --- | --- |
| SO_RCVLOWAT | int | Receives low watermark. |
| SO_RCVTIMEO | int | Receives time-out. |
| SO_SNDLOWAT | int | Sends low watermark. |
| SO_SNDTIMEO | int | Sends time-out. |
| TCP_MAXSEG | int | Receives TCP maximum-segment size. Not supported in versions before Windows 10. |

**Note** When using the
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) function, if no data arrives during the period specified in SO_RCVTIMEO, the
**recv** function completes. In Windows versions prior to Windows 2000, any data received subsequently fails with [WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). In Windows 2000 and later, if no data arrives within the period specified in SO_RCVTIMEO, the
**recv** function returns WSAETIMEDOUT, and if data is received,
**recv** returns SUCCESS.

Calling
**getsockopt** with an unsupported option will result in an error code of
[WSAENOPROTOOPT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) being returned from
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

More detailed information on some of the socket options for the *optname* parameter supported by the **getsockopt** function are listed below.

SO_CONNECT_TIME

This option returns the number of seconds a socket has been connected. This option is valid for connection oriented protocols only.

The SO_CONNECT_TIME option can be used with the **getsockopt** function to check
whether a connection has been established. This option can also be used while a [ConnectEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nc-mswsock-lpfn_connectex) function call is in progress.
If a connection is established, the SO_CONNECT_TIME option can determine how long the connection has
been established. If the socket is not connected, the **getsockopt** returns
SOCKET_ERROR. Checking a connection like this is necessary to see if
connections that have been established for a while, without sending any
data. It is recommended that applications terminate these connections.

SO_DEBUG

**Note** Windows Sockets service providers are encouraged (but not required) to supply output debug information if the SO_DEBUG option is set by an application. The mechanism for generating the debug information and the form it takes are beyond the scope of this document.

SO_ERROR

The SO_ERROR option returns and resets the per socket–based error code, which is different from the per thread based–error code that is handled using the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) and
[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror) function calls. A successful call using the socket does not reset the socket based error code returned by the SO_ERROR option.

SO_EXCLUSIVEADDRUSE

Prevents any other socket from binding to the same address and port. This option must be set before calling the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function. See the [SO_EXCLUSIVEADDRUSE](https://learn.microsoft.com/windows/desktop/WinSock/so-exclusiveaddruse) reference for more information.

SO_GROUP_ID

**Note** This option is reserved. This option is also exclusive to
**getsockopt**; the value should be **NULL**.

SO_GROUP_PRIORITY

This option is reserved. Group priority indicates the priority of the specified socket relative to other sockets within the socket group. Values are nonnegative integers, with zero corresponding to the highest priority. Priority values represent a hint to the underlying service provider about how potentially scarce resources should be allocated. For example, whenever two or more sockets are both ready to transmit data, the highest priority socket (lowest value for SO_GROUP_PRIORITY) should be serviced first, with the remainder serviced in turn according to their relative priorities.

The WSAENOPROTOOPT error code is indicated for nongroup sockets or for service providers that do not support group sockets.

[SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive)

An application can request that a TCP/IP service provider enable the use of keep-alive packets on TCP connections by turning on the SO_KEEPALIVE socket option. This option queries the current value of the keep-alive option on a socket. A Windows Sockets provider need not support the use of keep-alive: if it does, the precise semantics are implementation-specific but should conform to section 4.2.3.6 on the *Requirements for Internet Hosts—Communication Layers* specified in RFC 1122 available at the [IETF website](https://www.ietf.org/rfc/rfc1122.txt). If a connection is dropped as the result of keep-alives the error code
[WSAENETRESET](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) is returned to any calls in progress on the socket, and any subsequent calls will fail with
[WSAENOTCONN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). [SO_KEEPALIVE](https://learn.microsoft.com/windows/desktop/WinSock/so-keepalive) is not supported on ATM sockets, and requests to enable the use of keep-alive packets on an ATM socket results in an error being returned by the socket.

SO_LINGER

SO_LINGER controls the action taken when unsent data is queued on a socket and a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) is performed. See
**closesocket** for a description of the way in which the SO_LINGER settings affect the semantics of
**closesocket**. The application gets the current behavior by retrieving a
[LINGER](https://learn.microsoft.com/windows/desktop/api/winsock/ns-winsock-linger) structure (pointed to by the *optval* parameter).

SO_MAX_MSG_SIZE

This is a get-only socket option that indicates the maximum outbound (send) size of a message for message-oriented socket types (for example, SOCK_DGRAM) as implemented by a particular service provider. It has no meaning for byte stream oriented sockets. There is no provision to find out the maximum inbound–message size.

SO_PROTOCOL_INFO

This is a get-only option that supplies the
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure associated with this socket. See
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) for more information about this structure.

SO_SNDBUF

When a Windows Sockets implementation supports the SO_RCVBUF and SO_SNDBUF options, an application can request different buffer sizes (larger or smaller). The call to
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) can succeed even if the implementation did not provide the whole amount requested. An application must call this function with the same option to check the buffer size actually provided.

SO_REUSEADDR

By default, a socket cannot be bound (see
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)) to a local address that is already in use. On occasion, however, it can be necessary to reuse an address in this way. Because every connection is uniquely identified by the combination of local and remote addresses, there is no problem with having two sockets bound to the same local address as long as the remote addresses are different. To inform the Windows Sockets provider that a
**bind** on a socket should not be disallowed because the desired address is already in use by another socket, the application should set the SO_REUSEADDR socket option for the socket before issuing the
**bind**. Note that the option is interpreted only at the time of the
**bind**: it is therefore unnecessary (but harmless) to set the option on a socket that is not to be bound to an existing address, and setting or resetting the option after the
**bind** has no effect on this or any other socket. SO_REUSEADDR is not applicable for ATM sockets, and although requests to reuse and address do not result in an error, they have no effect on when an ATM socket is in use.

PVD_CONFIG

This option retrieves an opaque data structure object from the service provider associated with socket *s*. This object stores the current configuration information of the service provider. The exact format of this data structure is service provider specific.

TCP_NODELAY

The TCP_NODELAY option is specific to TCP/IP service providers. The Nagle algorithm is disabled if the TCP_NODELAY option is enabled (and vice versa). The Nagle algorithm (described in RFC 896) is very effective in reducing the number of small packets sent by a host. The process involves buffering send data when there is unacknowledged data already in flight or buffering send data until a full-size packet can be sent. It is highly recommended that Windows Sockets implementations enable the Nagle Algorithm by default because, for the vast majority of application protocols, the Nagle Algorithm can deliver significant performance enhancements. However, for some applications this algorithm can impede performance, and
[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) with the same option can be used to turn it off. These are applications where many small messages are sent, and the time delays between the messages are maintained.

**Note** When issuing a blocking Winsock call such as **getsockopt**, Winsock may need to wait for a network event before the call can complete. Winsock performs an alertable wait in this situation, which can be interrupted by an asynchronous procedure call (APC) scheduled on the same thread. Issuing another blocking Winsock call inside an APC that interrupted an ongoing blocking Winsock call on the same thread will lead to undefined behavior, and must never be attempted by Winsock clients.

### Example Code

The following code sample demonstrates the use of the **getsockopt** function.

```cpp
#include <stdio.h>
#include "winsock2.h"
#include <windows.h>

void main() {

  //---------------------------------------
  // Declare variables
  WSADATA wsaData;
  SOCKET ListenSocket;
  sockaddr_in service;

  //---------------------------------------
  // Initialize Winsock
  int iResult = WSAStartup( MAKEWORD(2,2), &wsaData );
  if( iResult != NO_ERROR )
    printf("Error at WSAStartup\n");

  //---------------------------------------
  // Create a listening socket
  ListenSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
  if (ListenSocket == INVALID_SOCKET) {
    printf("Error at socket()\n");
    WSACleanup();
    return;
  }

  //---------------------------------------
  // Bind the socket to the local IP address
  // and port 27015
  hostent* thisHost;
  char* ip;
  u_short port;
  port = 27015;
  thisHost = gethostbyname("");
  ip = inet_ntoa (*(struct in_addr *)*thisHost->h_addr_list);

  service.sin_family = AF_INET;
  service.sin_addr.s_addr = inet_addr(ip);
  service.sin_port = htons(port);

  if ( bind( ListenSocket,(SOCKADDR*) &service, sizeof(service) )  == SOCKET_ERROR ) {
    printf("bind failed\n");
    closesocket(ListenSocket);
    return;
  }

  //---------------------------------------
  // Initialize variables and call getsockopt.
  // The SO_ACCEPTCONN parameter is a socket option
  // that tells the function to check whether the
  // socket has been put in listening mode or not.
  // The various socket options return different
  // information about the socket. This call should
  // return 0 to the optVal parameter, since the socket
  // is not in listening mode.
  int optVal;
  int optLen = sizeof(int);

  if (getsockopt(ListenSocket,
    SOL_SOCKET,
    SO_ACCEPTCONN,
    (char*)&optVal,
    &optLen) != SOCKET_ERROR)
    printf("SockOpt Value: %ld\n", optVal);

  //---------------------------------------
  // Put the listening socket in listening mode.
  if (listen( ListenSocket, 100 ) == SOCKET_ERROR) {
    printf("error listening\n");
  }

  //---------------------------------------
  // Call getsockopt again to verify that
  // the socket is in listening mode.
  if (getsockopt(ListenSocket,
    SOL_SOCKET,
    SO_ACCEPTCONN,
    (char*)&optVal,
    &optLen) != SOCKET_ERROR)
    printf("SockOpt Value: %ld\n", optVal);

  WSACleanup();
  return;
}

```

### Notes for IrDA Sockets

* The Af_irda.h header file must be explicitly included.
* Windows returns
  [WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) to indicate the underlying transceiver driver failed to initialize with the IrDA protocol stack.
* IrDA supports several special socket options:

  | Value | Type | Meaning |
  | --- | --- | --- |
  | IRLMP_ENUMDEVICES | *DEVICELIST | Describes devices in range. |
  | IRLMP_IAS_QUERY | *IAS_QUERY | Retrieve IAS attributes. |

Before an IrDA socket connection can be initiated, a device address must be obtained by performing a
**getsockopt**(,,IRLMP_ENUMDEVICES,,) function call, which returns a list of all available IrDA devices. A device address returned from the function call is copied into a
[SOCKADDR_IRDA](https://learn.microsoft.com/windows/desktop/api/af_irda/ns-af_irda-sockaddr_irda) structure, which in turn is used by a subsequent call to the
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function call.

Discovery can be performed in two ways:

1. First, performing a getsockopt function call with the IRLMP_ENUMDEVICES option causes a single discovery to be run on each idle adapter. The list of discovered devices and cached devices (on active adapters) is returned immediately.

   The following code demonstrates this approach.

   ```cpp
   #include <winsock2.h>
   #include <ws2tcpip.h>
   #include <af_irda.h>
   #include <stdio.h>
   #include <windows.h>

   // link with Ws2_32.lib

   int __cdecl main()
   {

       //-----------------------------------------
       // Declare and initialize variables
       WSADATA wsaData;

       int iResult;
       int i;
       DWORD dwError;

       SOCKET Sock = INVALID_SOCKET;

   #define DEVICE_LIST_LEN    10

       SOCKADDR_IRDA DestSockAddr = { AF_IRDA, 0, 0, 0, 0, "SampleIrDAService" };

       unsigned char DevListBuff[sizeof (DEVICELIST) -
                                 sizeof (IRDA_DEVICE_INFO) +
                                 (sizeof (IRDA_DEVICE_INFO) * DEVICE_LIST_LEN)];

       int DevListLen = sizeof (DevListBuff);
       PDEVICELIST pDevList;

       pDevList = (PDEVICELIST) & DevListBuff;

       // Initialize Winsock
       iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
       if (iResult != 0) {
           printf("WSAStartup failed: %d\n", iResult);
           return 1;
       }

       Sock = socket(AF_IRDA, SOCK_STREAM, 0);
       if (Sock == INVALID_SOCKET) {
           dwError = WSAGetLastError();
           printf
               ("socket failed trying to create an AF_IRDA socket with error %d\n",
                dwError);

           if (dwError == WSAEAFNOSUPPORT) {
               printf("Check that the local computer has an infrared device\n");
               printf
                   ("and a device driver is installed for the infrared device\n");
           }
           WSACleanup();
           return 1;
       }
       // Sock is not in connected state
       iResult = getsockopt(Sock, SOL_IRLMP, IRLMP_ENUMDEVICES,
                            (char *) pDevList, &DevListLen);
       if (iResult == SOCKET_ERROR) {
           printf("getsockopt failed with error %d\n", WSAGetLastError());
           WSACleanup();
           return 1;
       }

       if (pDevList->numDevice == 0) {
           // no devices discovered or cached
           // not a bad idea to run a couple of times
           printf("No IRDA devices were discovered or cached\n");
       } else {
           // one per discovered device
           for (i = 0; i < (int) pDevList->numDevice; i++) {
               // typedef struct _IRDA_DEVICE_INFO
               // {
               //     u_char    irdaDeviceID[4];
               //     char      irdaDeviceName[22];
               //     u_char    irdaDeviceHints1;
               //     u_char    irdaDeviceHints2;
               //     u_char    irdaCharSet;
               // } _IRDA_DEVICE_INFO;

               // pDevList->Device[i]. see _IRDA_DEVICE_INFO for fields
               // display the device names and let the user select one
           }
       }

       // assume the user selected the first device [0]
       memcpy(&DestSockAddr.irdaDeviceID[0], &pDevList->Device[0].irdaDeviceID[0],
              4);

       iResult = connect(Sock, (const struct sockaddr *) &DestSockAddr,
                         sizeof (SOCKADDR_IRDA));
       if (iResult == SOCKET_ERROR) {
           printf("connect failed with error %d\n", WSAGetLastError());
       } else
           printf("connect to first IRDA device was successful\n");

       WSACleanup();
       return 0;
   }

   ```
2. The second approach to performing discovery of IrDA device addresses is to perform a lazy discovery; in this approach, the application is not notified until the discovered devices list changes from the last discovery run by the stack.

The **DEVICELIST** structure shown in the Type column in the previous table is an extendible array of device descriptions. IrDA fills in as many device descriptions as can fit in the specified buffer. The device description consists of a device identifier necessary to form a sockaddr_irda structure, and a displayable string describing the device.

The **IAS_QUERY** structure shown in the Type column in the previous table is used to retrieve a single attribute of a single class from a peer device's IAS database. The application specifies the device and class to query and the attribute and attribute type. Note that the device would have been obtained previously by a call to
**getsockopt**(IRLMP_ENUMDEVICES). It is expected that the application allocates a buffer, of the necessary size, for the returned parameters.

Many level socket options are not meaningful to IrDA; only SO_LINGER and SO_DONTLINGER are specifically supported.

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

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror)

[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)