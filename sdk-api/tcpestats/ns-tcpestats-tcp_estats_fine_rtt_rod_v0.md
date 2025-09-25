# TCP_ESTATS_FINE_RTT_ROD_v0 structure

## Description

The **TCP_ESTATS_FINE_RTT_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on fine-grained round-trip time (RTT) estimation for a TCP connection.

## Members

### `RttVar`

Type: **ULONG**

The round trip time variation, in microseconds, used in receive window auto-tuning when the TCP extended statistics feature is enabled.

### `MaxRtt`

Type: **ULONG**

The maximum sampled round trip time, in microseconds.

### `MinRtt`

Type: **ULONG**

The minimum sampled round trip time, in microseconds.

### `SumRtt`

Type: **ULONG**

A smoothed value round trip time, in microseconds, computed from all sampled round trip times. The smoothing is a weighted additive function that uses the **RttVar** member.

## Remarks

The **TCP_ESTATS_FINE_RTT_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_FINE_RTT_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on fine-grained round-trip time estimation for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_FINE_RTT_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsFineRtt** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The TCP retransmission timer is discussed in detail in the IETF RFC 2988 on Computing TCP's Retransmission Timer For more information, see [http://www.ietf.org/rfc/rfc2988.txt](http://tools.ietf.org/html/rfc2988).

The members of this structure are not defined in the IETF RFC on the TCP Extended Statistics MIB. However, there are members in the [TCP_ESTATS_PATH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rod_v0) structure that provide similar time measurements in milliseconds. For more information, see the **TCP_ESTATS_PATH_ROD_v0** structure and [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_PATH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_path_rod_v0)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)