# TCP_ESTATS_SYN_OPTS_ROS_v0 structure

## Description

The **TCP_ESTATS_SYN_OPTS_ROS_v0** structure contains read-only static information for extended TCP statistics on SYN exchange for a TCP connection.

## Members

### `ActiveOpen`

Type: **BOOLEAN**

A value that indicates if the TCP connection was an active open.

If the local connection traversed the SYN-SENT
state, then this member is set to **TRUE**. Otherwise, this member is set to **FALSE**.

### `MssRcvd`

Type: **ULONG**

The value received in an Maximum Segment Size (MSS) option during the SYN exchange, or zero if no MSS option was received.

This value is the maximum data in a single TCP datagram that the remote host can receive.

### `MssSent`

Type: **ULONG**

The value sent in an MSS option during the SYN exchange, or zero if no MSS option was sent.

## Remarks

The **TCP_ESTATS_SYN_OPTS_ROS_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_SYN_OPTS_ROS_v0** is defined as version 0 of the structure for read-only static information on SYN exchange for a TCP connection. The TCP protocol does not permit the members of this structure to change after the SYN exchange. This information is available after the SYN exchange has completed.

The **TCP_ESTATS_SYN_OPTS_ROS_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsSynOpts** is passed in the *EstatsType* parameter. Extended TCP statistics do not need to be enabled to retrieve this structure.

The MSS in the **MssRcvd** and **MssSent** members is the maximum data in a single TCP datagram. The MSS can be a very large value.

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_SYN_OPTS_ROS_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **ActiveOpen** | tcpEStatsStackActiveOpen |
| **MssRcvd** | tcpEStatsStackMSSRcvd |
| **MssSent** | tcpEStatsStackMSSSent |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)