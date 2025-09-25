# CSADDR_INFO structure

## Description

The
**CSADDR_INFO** structure contains Windows Sockets address information for a socket, network service, or namespace provider.

## Members

### `LocalAddr`

Type: **SOCKET_ADDRESS**

The Windows Sockets local address.

In a client application, pass this address to the
**bind** function to obtain access to a network service.

In a network service, pass this address to the
**bind** function so that the service is bound to the appropriate local address.

### `RemoteAddr`

Type: **SOCKET_ADDRESS**

Windows Sockets remote address.

There are several uses for this remote address:

* You can use this remote address to connect to the service through the
  [connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect) function. This is useful if an application performs
  [send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)/[receive](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv) operations that involve connection-oriented protocols.
* You can use this remote address with the
  [sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto) function when you are communicating over a connectionless (datagram) protocol. If you are using a connectionless protocol, such as UDP,
  **sendto** is typically the way you pass data to the remote system.

### `iSocketType`

Type: **INT**

The type of Windows socket. Possible values for the socket type are defined in the *Winsock2.h* header file.

The following table lists the possible values supported for Windows Sockets 2:

| Value | Meaning |
| --- | --- |
| **SOCK_STREAM** | A stream socket. This is a protocol that sends data as a stream of bytes, with no message boundaries. This socket type provides sequenced, reliable, two-way, connection-based byte streams with an OOB data transmission mechanism. This socket type uses the Transmission Control Protocol (TCP) for the Internet address family (AF_INET or AF_INET6). |
| **SOCK_DGRAM** | A datagram socket. This socket type supports datagrams, which are connectionless, unreliable buffers of a fixed (typically small) maximum length. This socket type uses the User Datagram Protocol (UDP) for the Internet address family (AF_INET or AF_INET6).<br><br>Services use [recvfrom](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recvfrom) function to obtain datagrams. The [listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) and [accept](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-accept) functions do not work with datagrams. |
| **SOCK_RDM** | A reliable message datagram socket. This socket type preserves message boundaries in data. An example of this type is the Pragmatic General Multicast (PGM) multicast protocol implementation in Windows, often referred to as [reliable multicast programming](https://learn.microsoft.com/windows/desktop/WinSock/reliable-multicast-programming--pgm-). |
| **SOCK_SEQPACKET** | A sequenced packet stream socket. This socket type provides a pseudo-stream packet based on datagrams. |

### `iProtocol`

Type: **INT**

The protocol used. The possible options for the *protocol* parameter are specific to the address family and socket type specified. Possible values are defined in the *Winsock2.h* and *Wsrm.h* header files.

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and this parameter can be one of the values from the **IPPROTO** enumeration type defined in the *Ws2def.h* header file. Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The table below lists common values for the *protocol* although many other values are possible.

| protocol | Meaning |
| --- | --- |
| **IPPROTO_TCP**<br><br>6 | The Transmission Control Protocol (TCP). This is a possible value when the address family is **AF_INET** or **AF_INET6** and the **iSocketType** member is **SOCK_STREAM**. |
| **IPPROTO_UDP**<br><br>17 | The User Datagram Protocol (UDP). This is a possible value when the address family is **AF_INET** or **AF_INET6** and the **iSocketType** member is **SOCK_DGRAM**. |
| **IPPROTO_RM**<br><br>113 | The PGM protocol for reliable multicast. This is a possible value when the address family is **AF_INET** and the **iSocketType** member is **SOCK_RDM**. On the Windows SDK released for Windows Vista and later, this value is also called **IPPROTO_PGM**. |

## Remarks

The
[GetAddressByName](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getaddressbynamea) function obtains Windows Sockets address information using
**CSADDR_INFO** structures.

The [getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt) function called with the [SO_BSP_STATE](https://learn.microsoft.com/windows/desktop/WinSock/so-bsp-state) socket option retrieves a **CSADDR_INFO** structure for the specified socket.

## See also

[GetAddressByName](https://learn.microsoft.com/windows/desktop/api/nspapi/nf-nspapi-getaddressbynamea)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)

[SO_BSP_STATE](https://learn.microsoft.com/windows/desktop/WinSock/so-bsp-state)

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[getsockopt](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-getsockopt)

[recv](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-recv)

[send](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-send)

[sendto](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-sendto)