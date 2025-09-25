# MIB_TCP6ROW_OWNER_MODULE structure

## Description

The **MIB_TCP6ROW_OWNER_MODULE** structure contains information that describes an IPv6 TCP connection bound to a specific process ID (PID) with ownership data.

## Members

### `ucLocalAddr`

Type: **UCHAR[16]**

The IPv6 address for the local endpoint of the TCP connection on the local computer. A value of zero indicates the listener can accept a connection on any interface.

### `dwLocalScopeId`

Type: **DWORD**

The scope ID in network byte order for the local IPv6 address.

### `dwLocalPort`

Type: **DWORD**

The port number in network byte order for the local endpoint of the TCP connection on the local computer.

### `ucRemoteAddr`

Type: **UCHAR[16]**

The IPv6 address of the remote endpoint of the TCP connection on the remote computer. When the **dwState** member is **MIB_TCP_STATE_LISTEN**, this value has no meaning.

### `dwRemoteScopeId`

Type: **DWORD**

The scope ID in network byte order for the remote IPv6 address.

### `dwRemotePort`

Type: **DWORD**

The port number in network byte order for the remote endpoint of the TCP connection on the remote computer.

### `dwState`

Type: **DWORD**

The state of the TCP connection. This member can be one of the values from the **MIB_TCP_STATE** enumeration defined in the *Tcpmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

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

The PID of the local process that issued a context bind for this TCP connection.

### `liCreateTimestamp`

Type: **LARGE_INTEGER**

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that indicates when the context bind operation that created this TCP connection occurred.

### `OwningModuleInfo`

Type: **ULONGLONG[TCPIP_OWNING_MODULE_SIZE]**

An array of opaque data that contains ownership information.

## Remarks

The [MIB_TCP6TABLE_OWNER_MODULE](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table_owner_module) structure is returned by a call to [GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable) with the *TableClass* parameter set to a **TCP_TABLE_OWNER_MODULE_LISTENER**, **TCP_TABLE_OWNER_MODULE_CONNECTIONS**, or **TCP_TABLE_OWNER_MODULE_ALL** from the [TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class) enumeration and the *ulAf* parameter set to **AF_INET6**. The **MIB_TCP6TABLE_OWNER_MODULE** structure contains an array of **MIB_TCP6ROW_OWNER_MODULE** structures.

 The **dwState** member indicates the state of the TCP entry in a TCP state diagram. A TCP connection progresses through a series of states during its
lifetime. The states are: LISTEN, SYN-SENT, SYN-RECEIVED,
ESTABLISHED, FIN-WAIT-1, FIN-WAIT-2, CLOSE-WAIT, CLOSING, LAST-ACK,
TIME-WAIT, and the fictional state CLOSED. The CLOSED state is fictional
because it represents the state when there is no Transmission Control Block, and therefore,
no connection. The TCP protocol is described in RFC 793. For more information, see
[http://www.ietf.org/rfc/rfc793.txt](https://www.ietf.org/rfc/rfc793.txt).

The **ucLocalAddr** and **ucRemoteAddr** members are stored in a character array in network byte order. The [RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa) or [RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw) functions may be used to convert the IPv6 address in the **ucLocalAddr** or **ucRemoteAddr** members to a string without loading the Windows Sockets DLL.

The **dwLocalScopeId**, and **dwRemoteScopeId** members are in network byte order. In order to use the **dwLocalScopeId** or **dwRemoteScopeId** members, the [ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

The **dwLocalPort** and **dwRemotePort** members are in network byte order. In order to use the **dwLocalPort** or **dwRemotePort** members, the [ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs) or [inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa) functions in Windows Sockets or similar functions may be needed.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetExtendedTcpTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getextendedtcptable)

[RtlIpv6AddressToString](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringa)

[RtlIpv6AddressToStringEx](https://learn.microsoft.com/windows/desktop/api/ip2string/nf-ip2string-rtlipv6addresstostringexw)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[TCP_TABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/iprtrmib/ne-iprtrmib-tcp_table_class)

[inet_ntoa](https://learn.microsoft.com/windows/desktop/api/wsipv6ok/nf-wsipv6ok-inet_ntoa)

[ntohl](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohl)

[ntohs](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-ntohs)