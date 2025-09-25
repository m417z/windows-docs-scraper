# WSASocketA function

## Description

The
**WSASocket** function creates a socket that is bound to a specific transport-service provider.

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

### `lpProtocolInfo` [in]

A pointer to a
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure that defines the characteristics of the socket to be created. If this parameter is not **NULL**, the socket will be bound to the provider associated with the indicated
**WSAPROTOCOL_INFO** structure.

### `g` [in]

An existing socket group ID or an appropriate action to take when creating a new socket and a new socket group.

If *g* is an existing socket group ID, join the new socket to this
socket group, provided all the requirements set by this group are met.

If *g* is not an existing socket group ID, then the following values are possible.

| g | Meaning |
| --- | --- |
| 0 | No group operation is performed. |
| **SG_UNCONSTRAINED_GROUP**<br><br>0x01 | Create an unconstrained socket group and have the new socket be the first member. For an unconstrained group, Winsock does not constrain all sockets in the socket group to have been created with the same value for the *type* and *protocol* parameters. |
| **SG_CONSTRAINED_GROUP**<br><br>0x02 | Create a constrained socket group and have the new socket be the first member. For a constrained socket group, Winsock constrains all sockets in the socket group to have been created with the same value for the *type* and *protocol* parameters. A constrained socket group may consist only of connection-oriented sockets, and requires that connections on all grouped sockets be to the same address on the same host. |

**Note** The SG_UNCONSTRAINED_GROUP and SG_CONSTRAINED_GROUP constants are not currently defined in a public header file.

### `dwFlags` [in]

A set of flags used to specify additional socket attributes.

A combination of these flags may be set, although some combinations are not allowed.

| Value | Meaning |
| --- | --- |
| **WSA_FLAG_OVERLAPPED**<br><br>0x01 | Create a socket that supports overlapped I/O operations.<br><br>Most sockets should be created with this flag set. Overlapped sockets can utilize [WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), and [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl) for overlapped I/O operations, which allow multiple operations to be initiated and in progress simultaneously. <br><br>All functions that allow overlapped operation ([WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend), [WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv), [WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto), [WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom), [WSAIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaioctl)) also support nonoverlapped usage on an overlapped socket if the values for parameters related to overlapped operations are **NULL**. |
| **WSA_FLAG_MULTIPOINT_C_ROOT**<br><br>0x02 | Create a socket that will be a c_root in a multipoint session.<br><br>This attribute is only allowed if the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider that creates the socket supports a multipoint or multicast mechanism and the control plane for a multipoint session is rooted. This would be indicated by the **dwServiceFlags1** member of the **WSAPROTOCOL_INFO** structure with the **XP1_SUPPORT_MULTIPOINT** and **XP1_MULTIPOINT_CONTROL_PLANE** flags set. <br><br>When the *lpProtocolInfo* parameter is not NULL, the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider is pointed to by the *lpProtocolInfo* parameter. When the *lpProtocolInfo* parameter is NULL, the **WSAPROTOCOL_INFO** structure is based on the transport provider selected by the values specified for the *af*, *type*, and *protocol* parameters. <br><br>Refer to [Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information on a multipoint session. |
| **WSA_FLAG_MULTIPOINT_C_LEAF**<br><br>0x04 | Create a socket that will be a c_leaf in a multipoint session.<br><br>This attribute is only allowed if the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider that creates the socket supports a multipoint or multicast mechanism and the control plane for a multipoint session is non-rooted. This would be indicated by the **dwServiceFlags1** member of the **WSAPROTOCOL_INFO** structure with the **XP1_SUPPORT_MULTIPOINT** flag set and the **XP1_MULTIPOINT_CONTROL_PLANE** flag not set. <br><br>When the *lpProtocolInfo* parameter is not NULL, the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider is pointed to by the *lpProtocolInfo* parameter. When the *lpProtocolInfo* parameter is NULL, the **WSAPROTOCOL_INFO** structure is based on the transport provider selected by the values specified for the *af*, *type*, and *protocol* parameters. <br><br>Refer to [Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information on a multipoint session. |
| **WSA_FLAG_MULTIPOINT_D_ROOT**<br><br>0x08 | Create a socket that will be a d_root in a multipoint session.<br><br>This attribute is only allowed if the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider that creates the socket supports a multipoint or multicast mechanism and the data plane for a multipoint session is rooted. This would be indicated by the **dwServiceFlags1** member of the **WSAPROTOCOL_INFO** structure with the **XP1_SUPPORT_MULTIPOINT** and **XP1_MULTIPOINT_DATA_PLANE** flags set. <br><br>When the *lpProtocolInfo* parameter is not NULL, the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider is pointed to by the *lpProtocolInfo* parameter. When the *lpProtocolInfo* parameter is NULL, the **WSAPROTOCOL_INFO** structure is based on the transport provider selected by the values specified for the *af*, *type*, and *protocol* parameters. <br><br>Refer to [Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information on a multipoint session. |
| **WSA_FLAG_MULTIPOINT_D_LEAF**<br><br>0x10 | Create a socket that will be a d_leaf in a multipoint session.<br><br>This attribute is only allowed if the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider that creates the socket supports a multipoint or multicast mechanism and the data plane for a multipoint session is non-rooted. This would be indicated by the **dwServiceFlags1** member of the **WSAPROTOCOL_INFO** structure with the **XP1_SUPPORT_MULTIPOINT** flag set and the **XP1_MULTIPOINT_DATA_PLANE** flag not set. <br><br>When the *lpProtocolInfo* parameter is not NULL, the [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure for the transport provider is pointed to by the *lpProtocolInfo* parameter. When the *lpProtocolInfo* parameter is NULL, the **WSAPROTOCOL_INFO** structure is based on the transport provider selected by the values specified for the *af*, *type*, and *protocol* parameters. <br><br>Refer to [Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information on a multipoint session. |
| **WSA_FLAG_ACCESS_SYSTEM_SECURITY**<br><br>0x40 | Create a socket that allows the ability to set a security descriptor on the socket that contains a security access control list (SACL) as opposed to just a discretionary access control list (DACL).<br><br>SACLs are used for generating audits and alarms when an access check occurs on the object. For a socket, an access check occurs to determine whether the socket should be allowed to bind to a specific address specified to the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function.<br><br>The **ACCESS_SYSTEM_SECURITY** access right controls the ability to get or set the SACL in an object's security descriptor. The system grants this access right only if the **SE_SECURITY_NAME** privilege is enabled in the access token of the requesting thread. |
| **WSA_FLAG_NO_HANDLE_INHERIT**<br><br>0x80 | Create a socket that is non-inheritable. <br><br>A socket handle created by the **WSASocket** or the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function is inheritable by default. When this flag is set, the socket handle is non-inheritable. <br><br>The [GetHandleInformation](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-gethandleinformation) function can be used to determine if a socket handle was created with the **WSA_FLAG_NO_HANDLE_INHERIT** flag set. The **GetHandleInformation** function will return that the **HANDLE_FLAG_INHERIT** value is set.<br><br>This flag is supported on Windows 7 with SP1, Windows Server 2008 R2 with SP1, and later |

**Important** For multipoint sockets, only one of **WSA_FLAG_MULTIPOINT_C_ROOT** or **WSA_FLAG_MULTIPOINT_C_LEAF** flags can be specified, and only one of **WSA_FLAG_MULTIPOINT_D_ROOT** or **WSA_FLAG_MULTIPOINT_D_LEAF** flags can be specified. Refer to
[Multipoint and Multicast Semantics](https://learn.microsoft.com/windows/desktop/WinSock/multipoint-and-multicast-semantics-2) for additional information.

## Return value

If no error occurs,
**WSASocket** returns a descriptor referencing the new socket. Otherwise, a value of INVALID_SOCKET is returned, and a specific error code can be retrieved by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

**Note** This error code description is Microsoft-specific.

| Error code | Meaning |
| --- | --- |
| **[WSANOTINITIALISED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A successful [WSAStartup](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsastartup) call must occur before using this function. |
| **[WSAENETDOWN](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The network subsystem has failed. |
| **[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified address family is not supported. |
| **[WSAEFAULT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The *lpProtocolInfo* parameter is not in a valid part of the process address space. |
| **[WSAEINPROGRESS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function. |
| **[WSAEINVAL](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | This value is true for any of the following conditions. <br><br>* The parameter *g* specified is not valid.<br>* The   [WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure that *lpProtocolInfo* points to is incomplete, the contents are invalid or the   **WSAPROTOCOL_INFO** structure has already been used in an earlier duplicate socket operation.<br>* The values specified for members of the socket triple <*af*, *type*, and *protocol*> are individually supported, but the given combination is not. |
| **[WSAEINVALIDPROVIDER](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider returned a version other than 2.2. |
| **[WSAEINVALIDPROCTABLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider returned an invalid or incomplete procedure table to the [WSPStartup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nf-ws2spi-wspstartup). |
| **[WSAEMFILE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No more socket descriptors are available. |
| **[WSAENOBUFS](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | No buffer space is available. The socket cannot be created. |
| **[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is not supported. |
| **[WSAEPROTOTYPE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified protocol is the wrong type for this socket. |
| **[WSAEPROVIDERFAILEDINIT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The service provider failed to initialize. This error is returned if a layered service provider (LSP) or namespace provider was improperly installed or the provider fails to operate correctly. |
| **[WSAESOCKTNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The specified socket type is not supported in this address family. |

## Remarks

The
**WSASocket** function causes a socket descriptor and any related resources to be allocated and associated with a transport-service provider. Most sockets should be created with the **WSA_FLAG_OVERLAPPED** attribute set in the *dwFlags* parameter. A socket created with this attribute supports the use of overlapped I/O operations which provide higher performance. By default, a socket created with the **WSASocket** function will not have this overlapped attribute set. In contrast, the [socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket) function creates a socket that supports overlapped I/O operations as the default behavior.

If the *lpProtocolInfo* parameter is **NULL**, Winsock will utilize the first available transport-service provider that supports the requested combination of address family, socket type and protocol specified in the *af*, *type*, and *protocol* parameters.

If the *lpProtocolInfo* parameter is not **NULL**, the socket will be bound to the provider associated with the indicated
[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa) structure. In this instance, the application can supply the manifest constant **FROM_PROTOCOL_INFO** as the value for any of *af*, *type*, or *protocol* parameters. This indicates that the corresponding values from the indicated
**WSAPROTOCOL_INFO** structure (**iAddressFamily**, **iSocketType**, **iProtocol**) are to be assumed. In any case, the values specified for *af*, *type*, and *protocol* are passed unmodified to the transport-service provider.

When selecting a protocol and its supporting service provider based on *af*, *type*, and *protocol*, this procedure will only choose a base protocol or a protocol chain, not a protocol layer by itself. Unchained protocol layers are not considered to have partial matches on *type* or *af*, either. That is, they do not lead to an error code of
[WSAEAFNOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2) or
[WSAEPROTONOSUPPORT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2), if no suitable protocol is found.

**Note** The manifest constant **AF_UNSPEC** continues to be defined in the header file but its use is strongly discouraged, as this can cause ambiguity in interpreting the value of the *protocol* parameter.

Applications are encouraged to use **AF_INET6** for the *af* parameter and create a dual-mode socket that can be used with both IPv4 and IPv6.

If a socket is created using the **WSASocket** function, then the *dwFlags* parameter must have the **WSA_FLAG_OVERLAPPED** attribute set for the **SO_RCVTIMEO** or **SO_SNDTIMEO** socket options to function properly. Otherwise the timeout never takes effect on the socket.

Connection-oriented sockets such as **SOCK_STREAM** provide full-duplex connections, and must be in a connected state before any data can be sent or received on them. A connection to a specified socket is established with a
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) or [WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect) function call. Once connected, data can be transferred using
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)/[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) and
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)/[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv) calls. When a session has been completed, the [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function should be called to release the resources associated with the socket. For connection-oriented sockets, the [shutdown](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-shutdown) function should be called to stop data transfer on the socket before calling the **closesocket** function.

The communications protocols used to implement a reliable, connection-oriented socket ensure that data is not lost or duplicated. If data for which the peer protocol has buffer space cannot be successfully transmitted within a reasonable length of time, the connection is considered broken and subsequent calls will fail with the error code set to
[WSAETIMEDOUT](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2).

Connectionless, message-oriented sockets allow sending and receiving of datagrams to and from arbitrary peers using
[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)/[WSASendTo](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendto) and
[recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom)/[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom). If such a socket is connected to a specific peer, datagrams can be sent to that peer using
[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)/[WSASend](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasend) and can be received from (only) this peer using
[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)/[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv).

Support for sockets with type **SOCK_RAW** is not required, but service providers are encouraged to support raw sockets whenever possible.

The **WSASocket** function can be used to create a socket to be used by a service so that if another socket tries to bind to the same port used by the service, an audit record is generated. To enable this option, an application would need to do the following:

* Call the [AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to enable the **SE_SECURITY_NAME** privilege in the access token for the process. This privilege is required to set the **ACCESS_SYSTEM_SECURITY** access rights on the security descriptor for an object.
* Call the **WSASocket** function to create a socket with *dwFlag* with the **WSA_FLAG_ACCESS_SYSTEM_SECURITY** option set. The **WSASocket** function will fail if the [AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function is not called first to enable the **SE_SECURITY_NAME** privilege needed for this operation.
* Call the [SetSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-setsecurityinfo) function to set a security descriptor with a System Access Control List (SACL) on the socket. The socket handle returned by the **WSASocket** function is passed in the *handle* parameter. If the function succeeds, this will set the **ACCESS_SYSTEM_SECURITY** access right on the security descriptor for the socket.
* Call the [bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) function to bind the socket to a specific port. If the **bind** function succeeds, then an audit entry is generated if another socket tries to bind to the same port.
* Call the [AdjustTokenPrivileges](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-adjusttokenprivileges) function to remove the **SE_SECURITY_NAME** privilege in the access token for the process, since this is no longer needed.

For more information on **ACCESS_SYSTEM_SECURITY**, see [SACL Access Right](https://learn.microsoft.com/windows/desktop/SecAuthZ/sacl-access-right) and [Audit Generation](https://learn.microsoft.com/windows/desktop/SecAuthZ/audit-generation) in the Authorization documentation.

### Socket Groups

WinSock 2 introduced the notion of a socket group as a means for an application, or cooperating set of applications, to indicate to an underlying service provider that a particular set of sockets are related and that the group thus formed has certain attributes. Group attributes include relative priorities of the individual sockets within the group and a group quality of service specification.

Applications that need to exchange multimedia streams over the network are an example where being able to establish a specific relationship among a set of sockets could be beneficial. It is up to the transport on how to treat socket groups.

The **WSASocket** and [WSAAccept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaaccept) functions can be used to explicitly create and join a socket group when creating a new socket. The socket group ID for a socket can be retrieved by using the [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function with *level* parameter set to [SOL_SOCKET](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options) and the *optname* parameter set to **SO_GROUP_ID**. A socket group
and its associated socket group ID remain valid until the last socket belonging to this
socket group is closed. Socket group IDs are unique across all processes
for a given service provider. A socket group of zero indicates that the socket is not member of a socket group.

The relative group priority of a socket group can be accessed by using the [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function with the *level* parameter set to [SOL_SOCKET](https://learn.microsoft.com/windows/desktop/WinSock/sol-socket-socket-options) and the *optname* parameter set to **SO_GROUP_PRIORITY**. The relative group priority of a socket group can be set by using [setsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-setsockopt) with the *level* parameter set to SOL_SOCKET and the *optname* parameter set to **SO_GROUP_PRIORITY**.

The Winsock provider included with Windows allows the creation of socket groups and it enforces the SG_CONSTRAINED_GROUP. All sockets in a constrained socket group must be created with the same value for the *type* and *protocol* parameters. A constrained socket group may consist only of connection-oriented sockets, and requires that connections on all grouped sockets be to the same address on the same host. This is the only restriction applied to a socket group by the Winsock provider included with Windows. The socket group priority is not currently used by the Winsock provider or the TCP/IP stack included with Windows.

### Example Code

The following example demonstrates the use of the **WSASocket** function.

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
    DWORD dwFlags = 0;

    // Validate the parameters
    if (argc != 5) {
        wprintf(L"usage: %s <addressfamily> <type> <protocol> <flags>\n", argv[0]);
        wprintf(L"       opens a socket for the specified family, type, protocol, and flags\n");
        wprintf(L"       flags value must be in decimal, not hex\n");
        wprintf(L"%ws example usage\n", argv[0]);
        wprintf(L"   %ws 0 2 17 1\n", argv[0]);
        wprintf(L"   where AF_UNSPEC=0 SOCK_DGRAM=2 IPPROTO_UDP=17 OVERLAPPED\n", argv[0]);
        return 1;
    }

    iFamily = _wtoi(argv[1]);
    iType = _wtoi(argv[2]);
    iProtocol = _wtoi(argv[3]);
    dwFlags = _wtoi(argv[4]);

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

    wprintf(L"  Flags = ");
    if (dwFlags & WSA_FLAG_OVERLAPPED)
        wprintf(L"  WSA_FLAG_OVERLAPPED");
    if (dwFlags & WSA_FLAG_MULTIPOINT_C_ROOT)
        wprintf(L"  WSA_FLAG_MULTIPOINT_C_ROOT");
    if (dwFlags & WSA_FLAG_MULTIPOINT_C_LEAF)
        wprintf(L"  WSA_FLAG_MULTIPOINT_C_LEAF");
    if (dwFlags & WSA_FLAG_MULTIPOINT_D_ROOT)
        wprintf(L"  WSA_FLAG_MULTIPOINT_D_ROOT");
    if (dwFlags & WSA_FLAG_MULTIPOINT_D_LEAF)
        wprintf(L"  WSA_FLAG_MULTIPOINT_D_LEAF");
    if (dwFlags & WSA_FLAG_ACCESS_SYSTEM_SECURITY)
        wprintf(L"  WSA_FLAG_ACCESS_SYSTEM_SECURITY");
#ifdef WSA_FLAG_NO_HANDLE_INHERIT
    if (dwFlags & WSA_FLAG_NO_HANDLE_INHERIT)
        wprintf(L"  WSA_FLAG_NO_HANDLE_INHERIT");
#endif
    wprintf(L" (0x%x)\n" , dwFlags);

    sock = WSASocket(iFamily, iType, iProtocol, NULL, 0, dwFlags);
    if (sock == INVALID_SOCKET)
        wprintf(L"WSASocket function failed with error = %d\n", WSAGetLastError() );
    else {
        wprintf(L"WSASocket function succeeded\n");

        // Close the socket to release the resources associated
        // Normally an application calls shutdown() before closesocket
        //   to  disables sends or receives on a socket first
        // This isn't needed in this simple sample
        iResult = closesocket(sock);
        if (iResult == SOCKET_ERROR) {
            wprintf(L"closesocket function zfailed with error = %d\n", WSAGetLastError() );
            WSACleanup();
            return 1;
        }
    }
    WSACleanup();

    return 0;
}

```

**Windows Phone 8:** The **WSASocketW** function is supported for Windows Phone Store apps on Windows Phone 8 and later.

**Windows 8.1** and **Windows Server 2012 R2**: The **WSASocketW** function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and later.

> [!NOTE]
> The winsock2.h header defines WSASocket as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WSAPROTOCOL_INFO](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaprotocol_infoa)

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

[socket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-socket)