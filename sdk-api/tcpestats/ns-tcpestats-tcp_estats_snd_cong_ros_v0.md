# TCP_ESTATS_SND_CONG_ROS_v0 structure

## Description

The **TCP_ESTATS_SND_CONG_ROS_v0** structure contains read-only static information for extended TCP statistics on the maximum congestion window for a TCP connection.

## Members

### `LimCwnd`

The maximum size, in bytes, of the congestion window that may be
used.

## Remarks

The **TCP_ESTATS_SND_CONG_ROS_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_SND_CONG_ROS_v0** is defined as version 0 of the structure for read-only dynamic information on basic sender congestion data for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_SND_CONG_ROS_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsSndCong** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

TCP congestion control and congestion control algorithms are discussed in detail in the IETF RFC on TCP Congestion Control. For more information, see [http://www.ietf.org/rfc/rfc2581.txt](http://tools.ietf.org/html/rfc2581).

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_SND_CONG_ROS_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **LimCwnd** | tcpEStatsTuneLimCwnd |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)