# socket function

## Description

The
**socket** function creates a socket that is bound to a specific transport service provider.

## Parameters

### `af` [in]

The address family specification. Possible values for the address family are defined in the *Winsock2.h* header file.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the possible values for the address family are defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are AF_INET or AF_INET6, which are the Internet
address family formats for IPv4 and IPv6. Other options for address family (AF_NETBIOS for use with NetBIOS, for example) are supported if a Windows Sockets service provider for the address family is installed. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

The table below lists common values for address family although many other values are possible.

| Af | Meaning |
| --- | --- |
| **AF_UNSPEC**<br><br>0 | The address family is unspecified. |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_IPX**<br><br>6 | The IPX/SPX address family. This address family is only supported if the NWLink IPX/SPX NetBIOS Compatible Transport protocol is installed. <br><br>This address family is not supported on Windows Vista and later. |
| **AF_APPLETALK**<br><br>16 | The AppleTalk address family. This address family is only supported if the AppleTalk protocol is installed. <br><br>This address family is not supported on Windows Vista and later. |
| **AF_NETBIOS**<br><br>17 | The NetBIOS address family. This address family is only supported if the Windows Sockets provider for NetBIOS is installed. <br><br>The Windows Sockets provider for NetBIOS is supported on 32-bit versions of Windows. This provider is installed by default on 32-bit versions of Windows. <br><br>The Windows Sockets provider for NetBIOS is not supported on 64-bit versions of windows including Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, or Windows XP. <br><br>The Windows Sockets provider for NetBIOS only supports sockets where the *type* parameter is set to **SOCK_DGRAM**.<br><br>The Windows Sockets provider for NetBIOS is not directly related to the [NetBIOS](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) programming interface. The NetBIOS programming interface is not supported on Windows Vista, Windows Server 2008, and later. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |
| **AF_IRDA**<br><br>26 | The Infrared Data Association (IrDA) address family. <br><br>This address family is only supported if the computer has an infrared port and driver installed. |
| **AF_BTH**<br><br>32 | The Bluetooth address family. <br><br>This address family is supported on Windows XP with SP2 or later if the computer has a Bluetooth adapter and driver installed. |

### `type` [in]

The type specification for the new socket.

Possible values for the socket type are defined in the *Winsock2.h* header file.

The following table lists the possible values for the *type* parameter supported for Windows Sockets 2:

| Type | Meaning |
| --- | --- |
| **SOCK_STREAM**<br><br>1 | A socket type that provides sequenced, reliable, two-way, connection-based byte streams with an OOB data transmission mechanism. This socket type uses the Transmission Control Protocol (TCP) for the Internet address family (AF_INET or AF_INET6). |
| **SOCK_DGRAM**<br><br>2 | A socket type that supports datagrams, which are connectionless, unreliable buffers of a fixed (typically small) maximum length. This socket type uses the User Datagram Protocol (UDP) for the Internet address family (AF_INET or AF_INET6). |
| **SOCK_RAW**<br><br>3 | A socket type that provides a raw socket that allows an application to manipulate the next upper-layer protocol header. To manipulate the IPv4 header, the [IP_HDRINCL](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option must be set on the socket. To manipulate the IPv6 header, the [IPV6_HDRINCL](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options) socket option must be set on the socket. |
| **SOCK_RDM**<br><br>4 | A socket type that provides a reliable message datagram. An example of this type is the Pragmatic General Multicast (PGM) multicast protocol implementation in Windows, often referred to as [reliable multicast programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-). <br><br>This *type* value is only supported if the Reliable Multicast Protocol is installed. |
| **SOCK_SEQPACKET**<br><br>5 | A socket type that provides a pseudo-stream packet based on datagrams. |

In Windows Sockets 2, new socket types were introduced. An application can dynamically discover the attributes of each available transport protocol through the
[WSAEnumProtocols](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaenumprotocolsa) function. So an application can determine the possible socket type and protocol options for an address family and use this information when specifying this parameter. Socket type definitions in the *Winsock2.h* and *Ws2def.h* header files will be periodically updated as new socket types, address families, and protocols are defined.

In Windows Sockets 1.1, the only possible socket types are **SOCK_DGRAM** and **SOCK_STREAM**.

### `protocol` [in]

The protocol to be used. The possible options for the *protocol* parameter are specific to the address family and socket type specified. Possible values for the *protocol* are defined in the *Winsock2.h* and *Wsrm.h* header files.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and this parameter can be one of the values from the **IPPROTO** enumeration type defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

If a value of 0 is specified, the caller does not
wish to specify a protocol and the service provider will choose the *protocol* to use.

When the *af* parameter is AF_INET or AF_INET6 and the *type* is **SOCK_RAW**, the value specified for the *protocol* is set in the protocol field of the IPv6 or IPv4 packet header.

The table below lists common values for the *protocol* although many other values are possible.

| protocol | Meaning |
| --- | --- |
| **IPPROTO_ICMP**<br><br>1 | The Internet Control Message Protocol (ICMP). This is a possible value when the *af* parameter is **AF_UNSPEC**, **AF_INET**, or **AF_INET6** and the *type* parameter is **SOCK_RAW** or unspecified.<br><br>This *protocol* value is supported on Windows XP and later. |
| **IPPROTO_IGMP**<br><br>2 | The Internet Group Management Protocol (IGMP). This is a possible value when the *af* parameter is **AF_UNSPEC**, **AF_INET**, or **AF_INET6** and the *type* parameter is **SOCK_RAW** or unspecified.<br><br>This *protocol* value is supported on Windows XP and later. |
| **BTHPROTO_RFCOMM**<br><br>3 | The Bluetooth Radio Frequency Communications (Bluetooth RFCOMM) protocol. This is a possible value when the *af* parameter is **AF_BTH** and the *type* parameter is **SOCK_STREAM**. <br><br>This *protocol* value is supported on Windows XP with SP2 or later. |
| **IPPROTO_TCP**<br><br>6 | The Transmission Control Protocol (TCP). This is a possible value when the *af* parameter is **AF_INET** or **AF_INET6** and the *type* parameter is **SOCK_STREAM**. |
| **IPPROTO_UDP**<br><br>17 | The User Datagram Protocol (UDP). This is a possible value when the *af* parameter is **AF_INET** or **AF_INET6** and the *type* parameter is **SOCK_DGRAM**. |
| **IPPROTO_ICMPV6**<br><br>58 | The Internet Control Message Protocol Version 6 (ICMPv6). This is a possible value when the *af* parameter is **AF_UNSPEC**, **AF_INET**, or **AF_INET6** and the *type* parameter is **SOCK_RAW** or unspecified.<br><br>This *protocol* value is supported on Windows XP and later. |
| **IPPROTO_RM**<br><br>113 | The PGM protocol for reliable multicast. This is a possible value when the *af* parameter is **AF_INET** and the *type* parameter is **SOCK_RDM**. On the Windows SDK released for Windows Vista and later, this protocol is also called **IPPROTO_PGM**. <br><br>This *protocol* value is only supported if the Reliable Multicast Protocol is installed. |

## Return value

If no error occurs,
**socket** returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem or the associated service provider has failed. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. For example, an application tried to create a socket for the **AF_IRDA** address family but an infrared adapter and device driver is not installed on the local computer. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No more socket descriptors are available. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | An invalid argument was supplied. This error is returned if the *af* parameter is set to **AF_UNSPEC** and the *type* and *protocol* parameter are unspecified. |
| **[WSAEINVALIDPROVIDER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider returned a version other than 2.2. |
| **[WSAEINVALIDPROCTABLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider returned an invalid or incomplete procedure table to the [WSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wspstartup). |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be created. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is not supported. |
| **[WSAEPROTOTYPE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is the wrong type for this socket. |
| **[WSAEPROVIDERFAILEDINIT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider failed to initialize. This error is returned if a layered service provider (LSP) or namespace provider was improperly installed or the provider fails to operate correctly. |
| **[WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified socket type is not supported in this address family. |

## Remarks

The
**socket** function causes a socket descriptor and any related resources to be allocated and bound to a specific transport-service provider. Winsock will utilize the first available service provider that supports the requested combination of address family, socket type and protocol parameters. The socket that is created will have the overlapped attribute as a default. For Windows, the Microsoft-specific socket option, SO_OPENTYPE, defined in Mswsock.h can affect this default. See Microsoft-specific documentation for a detailed description of SO_OPENTYPE.

Sockets without the overlapped attribute can be created by using
[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa). All functions that allow overlapped operation ([WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend),
[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv),
[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto),
[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), and
[WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)) also support nonoverlapped usage on an overlapped socket if the values for parameters related to overlapped operation are **NULL**.

When selecting a protocol and its supporting service provider this procedure will only choose a base protocol or a protocol chain, not a protocol layer by itself. Unchained protocol layers are not considered to have partial matches on *type* or *af* either. That is, they do not lead to an error code of
[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) or
[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) if no suitable protocol is found.

**Note** The manifest constant **AF_UNSPEC** continues to be defined in the header file but its use is strongly discouraged, as this can cause ambiguity in interpreting the value of the *protocol* parameter.

Applications are encouraged to use **AF_INET6** for the *af* parameter and create a dual-mode socket that can be used with both IPv4 and IPv6.

Connection-oriented sockets such as **SOCK_STREAM** provide full-duplex connections, and must be in a connected state before any data can be sent or received on it. A connection to another socket is created with a
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) call. Once connected, data can be transferred using
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) and
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) calls. When a session has been completed, a
[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) must be performed.

The communications protocols used to implement a reliable, connection-oriented socket ensure that data is not lost or duplicated. If data for which the peer protocol has buffer space cannot be successfully transmitted within a reasonable length of time, the connection is considered broken and subsequent calls will fail with the error code set to
[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Connectionless, message-oriented sockets allow sending and receiving of datagrams to and from arbitrary peers using
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) and
[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom). If such a socket is connected to a specific peer, datagrams can be sent to that peer using
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send) and can be received only from this peer using
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv).

IPv6 and IPv4 operate differently when receiving a socket with a *type* of **SOCK_RAW**. The IPv4 receive packet includes the packet payload, the next upper-level header (for example, the IP header for a TCP or UDP packet), and the IPv4 packet header. The IPv6 receive packet includes the packet payload and the next upper-level header. The IPv6 receive packet never includes the IPv6 packet header.

**Note** On Windows NT, raw socket support requires administrative privileges.

A socket with a *type* parameter of **SOCK_SEQPACKET** is based on datagrams, but functions as a pseudo-stream protocol. For both send and receive packets, separate datagrams are used. However, Windows Sockets can coalesce multiple receive packets into a single packet. So an application can issue a receive call (for example, [recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) or [WSARecvEx](https://learn.microsoft.com/windows/desktop/api/mswsock/nf-mswsock-wsarecvex)) and retrieve the data from several coalesced multiple packets in single call. The AF_NETBIOS address family supports a *type* parameter of **SOCK_SEQPACKET**.

When the *af* parameter is **AF_NETBIOS** for NetBIOS over TCP/IP, the *type* parameter can be **SOCK_DGRAM** or **SOCK_SEQPACKET**. For the **AF_NETBIOS** address family, the *protocol* parameter is the LAN adapter number represented as a negative number.

On Windows XP and later, the following command can be used to list the Windows Sockets catalog to determine the service providers installed and the address family, socket type, and protocols that are supported.

**netsh winsock show catalog**

Support for sockets with type **SOCK_RAW** is not required, but service providers are encouraged to support raw sockets as practicable.

### Notes for IrDA Sockets

Keep the following in mind:

* The Af_irda.h header file must be explicitly included.
* Only **SOCK_STREAM** is supported; the **SOCK_DGRAM** type is not supported by IrDA.
* The *protocol* parameter is always set to 0 for IrDA.

A socket for use with the AF_IRDA address family can only be created if the local computer has an infrared port and driver installed. Otherwise, a call to the **socket** function with *af* parameter set to AF_IRDA will fail and [WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) returns [WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

### Example Code

The following example demonstrates the use of the **socket** function to create a socket that is bound to a specific transport service provider..

```cpp
#ifndef UNICODE
#define UNICODE 1
#endif

// link with Ws2_32.lib
#pragma comment(lib,"Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>   // Needed for _wtoi

int __cdecl wmain(int argc, wchar_t **argv)
{

    //-----------------------------------------
    // Declare and initialize variables
    WSADATA wsaData = {0};
    int iResult = 0;

//    int i = 1;

    SOCKET sock = INVALID_SOCKET;
    int iFamily = AF_UNSPEC;
    int iType = 0;
    int iProtocol = 0;

    // Validate the parameters
    if (argc != 4) {
        wprintf(L"usage: %s <addressfamily> <type> <protocol>\n", argv[0]);
        wprintf(L"socket opens a socket for the specified family, type, & protocol\n");
        wprintf(L"%ws example usage\n", argv[0]);
        wprintf(L"   %ws 0 2 17\n", argv[0]);
        wprintf(L"   where AF_UNSPEC=0 SOCK_DGRAM=2 IPPROTO_UDP=17\n", argv[0]);
        return 1;
    }

    iFamily = _wtoi(argv[1]);
    iType = _wtoi(argv[2]);
    iProtocol = _wtoi(argv[3]);

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iResult);
        return 1;
    }

    wprintf(L"Calling socket with following parameters:\n");
    wprintf(L"  Address Family = ");
    switch (iFamily) {
    case AF_UNSPEC:
        wprintf(L"Unspecified");
        break;
    case AF_INET:
        wprintf(L"AF_INET (IPv4)");
        break;
    case AF_INET6:
        wprintf(L"AF_INET6 (IPv6)");
        break;
    case AF_NETBIOS:
        wprintf(L"AF_NETBIOS (NetBIOS)");
        break;
    case AF_BTH:
        wprintf(L"AF_BTH (Bluetooth)");
        break;
    default:
        wprintf(L"Other");
        break;
    }
    wprintf(L" (%d)\n", iFamily);

    wprintf(L"  Socket type = ");
    switch (iType) {
    case 0:
        wprintf(L"Unspecified");
        break;
    case SOCK_STREAM:
        wprintf(L"SOCK_STREAM (stream)");
        break;
    case SOCK_DGRAM:
        wprintf(L"SOCK_DGRAM (datagram)");
        break;
    case SOCK_RAW:
        wprintf(L"SOCK_RAW (raw)");
        break;
    case SOCK_RDM:
        wprintf(L"SOCK_RDM (reliable message datagram)");
        break;
    case SOCK_SEQPACKET:
        wprintf(L"SOCK_SEQPACKET (pseudo-stream packet)");
        break;
    default:
        wprintf(L"Other");
        break;
    }
    wprintf(L" (%d)\n", iType);

    wprintf(L"  Protocol = %d = ", iProtocol);
    switch (iProtocol) {
    case 0:
        wprintf(L"Unspecified");
        break;
    case IPPROTO_ICMP:
        wprintf(L"IPPROTO_ICMP (ICMP)");
        break;
    case IPPROTO_IGMP:
        wprintf(L"IPPROTO_IGMP (IGMP)");
        break;
    case IPPROTO_TCP:
        wprintf(L"IPPROTO_TCP (TCP)");
        break;
    case IPPROTO_UDP:
        wprintf(L"IPPROTO_UDP (UDP)");
        break;
    case IPPROTO_ICMPV6:
        wprintf(L"IPPROTO_ICMPV6 (ICMP Version 6)");
        break;
    default:
        wprintf(L"Other");
        break;
    }
    wprintf(L" (%d)\n", iProtocol);

    sock = socket(iFamily, iType, iProtocol);
    if (sock == INVALID_SOCKET)
        wprintf(L"socket function failed with error = %d\n", WSAGetLastError() );
    else {
        wprintf(L"socket function succeeded\n");

        // Close the socket to release the resources associated
        // Normally an application calls shutdown() before closesocket
        //   to  disables sends or receives on a socket first
        // This isn't needed in this simple sample
        iResult = closesocket(sock);
        if (iResult == SOCKET_ERROR) {
            wprintf(L"closesocket failed with error = %d\n", WSAGetLastError() );
            WSACleanup();
            return 1;
        }
    }

    WSACleanup();

    return 0;
}

```

**Windows Phone 8:** This function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

## See also

[IPPROTO_IP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options)

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[Reliable Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-)

[WSASocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasocketa)

[Winsock Functions](https://learn.microsoft.com/windows/desktop/WinSock/winsock-functions)

[Winsock Reference](https://learn.microsoft.com/windows/desktop/WinSock/winsock-reference)

[accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockname](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockname)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[ioctlsocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ioctlsocket)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)

[select](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-select)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)

[setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt)

[shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown)