## Description

The
**WSAMSG** structure is used with the
[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) and [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg) functions to store address and optional control information about connected and unconnected sockets as well as an array of buffers used to store message data.

## Members

### `name`

Type: **LPSOCKADDR**

A pointer to a
[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure that stores information about the remote address. Used only with unconnected sockets.

### `namelen`

Type: **INT**

The length, in bytes, of the
[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address) structure pointed to in the **pAddr** member. Used only with unconnected sockets.

### `lpBuffers`

Type: **LPWSABUF**

An array of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) structures used to receive the message data. The capability of the **lpBuffers** member to contain multiple buffers enables the use of scatter/gather I/O.

### `dwBufferCount`

Type: **DWORD**

The number of buffers pointed to in the **lpBuffers** member.

### `Control`

Type: **WSABUF**

A structure of
[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf) type used to specify optional control data. See Remarks.

### `dwFlags`

Type: **DWORD**

One or more control flags, specified as the logical **OR** of values. The possible values for **dwFlags** member on input are defined in the Winsock2.h header file. The possible values for **dwFlags** member on output are defined in the Ws2def.h header file which is automatically included by the Winsock2.h header file.

| Flags on input | Meaning |
| --- | --- |
| **MSG_PEEK** | Peek at the incoming data. The data is copied into the buffer, but is not removed from the input queue. This flag is valid only for non-overlapped sockets. |

| Flag returned | Meaning |
| --- | --- |
| **MSG_BCAST** | The datagram was received as a link-layer broadcast or with a destination IP address that is a broadcast address. |
| **MSG_MCAST** | The datagram was received with a destination IP address that is a multicast address. |
| **MSG_TRUNC** | The datagram was truncated. More data was present than the process allocated room for. |
| **MSG_CTRUNC** | The control (ancillary) data was truncated. More control data was present than the process allocated room for. |

## Remarks

In the Microsoft Windows Software Development Kit (SDK), the version of this structure for use on Windows Vista is defined with the data type for the **dwBufferCount** and **dwFlags** members as a **ULONG**. When compiling an application if the target platform is Windows Vista and later (**NTDDI_VERSION >= NTDDI_LONGHORN, _WIN32_WINNT >= 0x0600**, or **WINVER >= 0x0600**), the data type for the **dwBufferCount** and **dwFlags** members is a **ULONG**.

**Windows Server 2003 and Windows XP:**  When compiling an application, the data type for the **dwBufferCount** and **dwFlags** members is a **DWORD**.

On the Windows SDK released for Windows Vista and later, the **WSAMSG** structure is defined in the Ws2def.h header file. Note that the Ws2def.h header file is automatically included in Winsock2.h, and should never be used directly

If the datagram or control data is truncated during the transmission, the function being used in association with the
**WSAMSG** structure returns SOCKET_ERROR and a call to the
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror) function returns WSAEMSGSIZE. It is up to the application to determine what was truncated by checking for MSG_TRUNC and/or MSG_CTRUNC flags.

### Use of the control member

The following table summarizes the various uses of control data available for use in the *Control* member for IPv4 and IPv6.

|Protocol|cmsg_level|cmsg_type|Description|
|-|-|-|-|
|IPv4|IPPROTO_IP|IP_ORIGINAL_ARRIVAL_IF|Receives the original IPv4 arrival interface where the packet was received for datagram sockets. This control data is used by firewalls when a Teredo, 6to4, or ISATAP tunnel is used for IPv4 NAT traversal. The cmsg_data[] member in the **WSAMSG** structure is a **ULONG** that contains the IF_INDEX defined in the Ifdef.h header file.<br><br>For more information, see the [IPPROTO_IP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) for the IP_ORIGINAL_ARRIVAL_IF socket option.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** The IP_ORIGINAL_ARRIVAL_IF **cmsg_type** is not supported.|
|IPv4|IPPROTO_IP|[IP_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ip-pktinfo)|Specifies/receives packet information for an IPv4 socket. For more information, see the [IP_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ip-pktinfo) socket option.|
|IPv4|IPPROTO_IP|IP_ECN|Specifies/receives ECN codepoint in the Type of Service (TOS) IPv4 header field. For more info, see [WSASetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetrecvipecn).|
|IPv6|IPPROTO_IPV6|IPV6_DSTOPTS|Specifies/receives destination options.|
|IPv6|IPPROTO_IPV6|IPV6_HOPLIMIT|Specifies/receives hop limit. For more information, see the [IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options) for the IPV6_HOPLIMIT socket option.|
|IPv6|IPPROTO_IPV6|IPV6_HOPOPTS|Specifies/receives hop-by-hop options.|
|IPv6|IPPROTO_IPV6|IPV6_NEXTHOP|Specifies next-hop address.|
|IPv6|IPPROTO_IPV6|[IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo)|Specifies/receives packet information for an IPv6 socket. For more information, see the [IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo) socket option.|
|IPv6|IPPROTO_IPV6|IPV6_RTHDR|Specifies/receives routing header.|
|IPv6|IPPROTO_IPV6|IPV6_ECN|Specifies/receives ECN codepoint in the Traffic Class IPv6 header field. For more information, see [WSASetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetrecvipecn).|

Control data is made up of one or more control data objects, each beginning with a **WSACMSGHDR** structure, defined as the following.

```cpp
struct wsacmsghdr {
  UINT        cmsg_len;
  INT         cmsg_level;
  INT         cmsg_type;
  /* followed by UCHAR cmsg_data[] */
} WSACMSGHDR;
```

**Note** The transport, not the application, fills out the header information in the **WSACMSGHDR** structure. The application simply sets the needed socket options and provides the adequate buffer size.

The members of the **WSACMSGHDR** structure are as follows:

| Term | Description |
| --- | --- |
| cmsg_len | The number of bytes of data starting from the beginning of the **WSACMSGHDR** to the end of data (excluding padding bytes that may follow data). |
| cmsg_level | The protocol that originated the control information. |
| cmsg_type | The protocol-specific type of control information. |

The following macros are used to navigate the data objects:

```cpp

#define LPCMSGHDR *WSA_CMSG_FIRSTHDR(LPWSAMSG msg);

```

Returns a pointer to the first control data object. Returns a **NULL** pointer if there is no control data in the
**WSAMSG** structure, such as when the **Control** member is a **NULL** pointer.

```cpp

#define LPCMSGHDR *WSA_CMSG_NXTHDR(LPWSAMSG msg, LPWSACMSGHDR cmsg);

```

Returns a pointer to the next control data object, or **NULL** if there are no more data objects. If the *pcmsg* parameter is **NULL**, a pointer to the first control data object is returned.

```cpp

#define UCHAR *WSA_CMSG_DATA(LPWSACMSGHDR pcmsg);

```

Returns a pointer to the first byte of data (referred to as the **cmsg_data** member, though it is not defined in the structure).

```cpp

#define UINT WSA_CMSG_SPACE(UINT length);

```

Returns the total size of a control data object, given the amount of data. Used to allocate the correct amount of buffer space. Includes alignment padding.

```cpp

#define UINT WSA_CMSG_LEN(UINT length);

```

Returns the value in **cmsg_len** given the amount of data. Includes alignment padding.

## See also

[IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo)

[IP_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ip-pktinfo)

[SOCKET_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-socket_address)

[WSABUF](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsabuf)

[WSARecv](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecv)

[WSARecvFrom](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsarecvfrom)

[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg)

[WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg)