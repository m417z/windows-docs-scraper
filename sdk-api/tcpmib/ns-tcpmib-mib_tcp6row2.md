# MIB_TCP6ROW2 structure

## Description

The
**MIB_TCP6ROW2** structure contains information that describes an IPv6 TCP connection.

## Members

### `LocalAddr`

Type: **IN6_ADDR**

The local IPv6 address for the TCP connection on the local computer. A value of zero indicates the listener can accept a connection on any interface.

### `dwLocalScopeId`

Type: **DWORD**

The local scope ID for the TCP connection on the local computer.

### `dwLocalPort`

Type: **DWORD**

The local port number in network byte order for the TCP connection on the local computer.

The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

### `RemoteAddr`

Type: **IN6_ADDR**

The IPv6 address for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemoteScopeId`

Type: **DWORD**

The remote scope ID for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemotePort`

Type: **DWORD**

The remote port number in network byte order for the TCP connection on the remote computer. When the **State** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

 The maximum size of an IP port number is 16 bits, so only the lower 16 bits should be used. The upper 16 bits may contain uninitialized data.

### `State`

Type: **MIB_TCP_STATE**

The state of the TCP connection. This member can be one of the values from the **MIB_TCP_STATE** enumeration type defined in the *Tcpmib.h* header file.

| Value | Meaning |
| --- | --- |
| **MIB_TCP_STATE_CLOSED**<br><br>1 | The TCP connection is in the CLOSED state that represents no connection state at all. |
| **MIB_TCP_STATE_LISTEN**<br><br>2 | The TCP connection is in the LISTEN state waiting for a connection request from any remote TCP and port. |
| **MIB_TCP_STATE_SYN_SENT**<br><br>3 | The TCP connection is in the SYN-SENT state waiting for a matching connection request after having sent a connection request (SYN packet). |
| **MIB_TCP_STATE_SYN_RCVD**<br><br>4 | The TCP connection is in the SYN-RECEIVED state waiting for a confirming connection request acknowledgment after having both received and sent a connection request (SYN packet). |
| **MIB_TCP_STATE_ESTAB**<br><br>5 | The TCP connection is in the ESTABLISHED state that represents an open connection, data received can be delivered to the user. This is the normal state for the data transfer phase of the TCP connection. |
| **MIB_TCP_STATE_FIN_WAIT1**<br><br>6 | The TCP connection is FIN-WAIT-1 state waiting for a connection termination request from the remote TCP, or an acknowledgment of the connection termination request previously sent. |
| **MIB_TCP_STATE_FIN_WAIT2**<br><br>7 | The TCP connection is FIN-WAIT-1 state waiting for a connection termination request from the remote TCP. |
| **MIB_TCP_STATE_CLOSE_WAIT**<br><br>8 | The TCP connection is in the CLOSE-WAIT state waiting for a connection termination request from the local user. |
| **MIB_TCP_STATE_CLOSING**<br><br>9 | The TCP connection is in the CLOSING state waiting for a connection termination request acknowledgment from the remote TCP. |
| **MIB_TCP_STATE_LAST_ACK**<br><br>10 | The TCP connection is in the LAST-ACK state waiting for an acknowledgment of the connection termination request previously sent to the remote TCP (which includes an acknowledgment of its connection termination request). |
| **MIB_TCP_STATE_TIME_WAIT**<br><br>11 | The TCP connection is in the TIME-WAIT state waiting for enough time to pass to be sure the remote TCP received the acknowledgment of its connection termination request. |
| **MIB_TCP_STATE_DELETE_TCB**<br><br>12 | The TCP connection is in the delete TCB state that represents the deletion of the Transmission Control Block (TCB), a data structure used to maintain information on each TCP entry. |

### `dwOwningPid`

Type: **DWORD**

The PID of the process that issued a context bind for this TCP connection.

### `dwOffloadState`

Type: **TCP_CONNECTION_OFFLOAD_STATE**

The offload state for this TCP connection. This parameter can be one of the enumeration values for the [TCP_CONNECTION_OFFLOAD_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/tcpmib/ne-tcpmib-tcp_connection_offload_state) defined in the *Tcpmib.h* header.

## Remarks

The **MIB_TCP6ROW2** structure is defined on Windows Vista and later.

The [GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2) function retrieves the IPv6 TCP connection table on the local computer and returns this information in a [MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2) structure.

An array of **MIB_TCP6ROW2** structures are contained in the **MIB_TCP6TABLE2** structure.

 The **State** member indicates the state of the TCP entry in a TCP state diagram. A TCP connection progresses through a series of states during its
lifetime. The states are: LISTEN, SYN-SENT, SYN-RECEIVED,
ESTABLISHED, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, CLOSING, LAST-ACK,
TIME-WAIT, and the fictional state CLOSED. The CLOSED state is fictional
because it represents the state when there is no Transmission Control Block, and therefore,
no connection. The TCP protocol is described in RFC 793. For more information, see
[http://www.ietf.org/rfc/rfc793.txt](https://www.ietf.org/rfc/rfc793.txt).

The **dwLocalPort**, and **dwRemotePort** members are in network byte order. In order to use the **dwLocalPort** or **dwRemotePort** members, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **dwLocalScopeId**, and **dwRemoteScopeId** members are in network byte order. In order to use the **dwLocalScopeId** or **dwRemoteScopeId** members, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **LocalAddr** and **RemoteAddr** members are stored in [in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structures. The [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) or [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions may be used to convert the IPv6 address in the **LocalAddr** or **RemoteAddr** members to a string without loading the Windows Sockets DLL.

## See also

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[MIB_TCP6TABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)

[MIB_TCPTABLE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[TCP_CONNECTION_OFFLOAD_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/tcpmib/ne-tcpmib-tcp_connection_offload_state)

[in6_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)