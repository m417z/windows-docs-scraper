# TCP_ESTATS_REC_ROD_v0 structure

## Description

The **TCP_ESTATS_REC_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on the local receiver for a TCP connection.

## Members

### `CurRwinSent`

Type: **ULONG**

The most recent window advertisement, in bytes, that has been sent.

### `MaxRwinSent`

Type: **ULONG**

The maximum window advertisement, in bytes, that has been sent.

### `MinRwinSent`

Type: **ULONG**

The minimum window advertisement, in bytes, that has been sent.

### `LimRwin`

Type: **ULONG**

The maximum window advertisement, in bytes, that may
be sent.

### `DupAckEpisodes`

Type: **ULONG**

The number of Duplicate Acks Sent when prior Ack was not
duplicate. This is the number of times that a contiguous
series of duplicate acknowledgments have been sent.

This is an indication of the number of data segments lost
or reordered on the path from the remote TCP endpoint to
the near TCP endpoint.

### `DupAcksOut`

Type: **ULONG**

The number of duplicate ACKs sent.

The ratio of the change
in the **DupAcksOut** member to the change in
the **DupAckEpisodes** member is an indication of reorder or
recovery distance over some interval.

### `CeRcvd`

Type: **ULONG**

The number of segments received with IP headers bearing
Congestion Experienced (CE) markings.

### `EcnSent`

Type: **ULONG**

Reserved for future use. This member is always set to zero.

### `EcnNoncesRcvd`

Type: **ULONG**

Reserved for future use. This member is always set to zero.

### `CurReasmQueue`

Type: **ULONG**

The current number of bytes of sequence space spanned by
the reassembly queue.

This is generally the difference
between rcv.nxt and the sequence number of the right most
edge of the reassembly queue.

### `MaxReasmQueue`

Type: **ULONG**

The maximum number of bytes of sequence space spanned by
the reassembly queue.

This is the maximum value of the **CurReasmQueue** member.

### `CurAppRQueue`

Type: **SIZE_T**

The current number of bytes of application data that has
been acknowledged by TCP but not yet delivered to the
application.

### `MaxAppRQueue`

Type: **SIZE_T**

The maximum number of bytes of application data that has
been acknowledged by TCP but not yet delivered to the
application.

### `WinScaleSent`

Type: **UCHAR**

The value of the transmitted window scale option if one was
sent; otherwise, a value of -1.

Note that if both the **WinScaleSent** member and
the **WinScaleRcvd** member of the [TCP_ESTATS_OBS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_obs_rec_rod_v0) structure are not -1, then Rcv.Wind.Scale
will be the same as this value and used to scale receiver
window announcements from the local host to the remote
host.

## Remarks

The **TCP_ESTATS_REC_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_REC_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on the local receiver for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_REC_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsRec** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

TCP congestion control and congestion control algorithms are discussed in detail in the IETF RFC 2581 on TCP Congestion Control. For more information, see [http://www.ietf.org/rfc/rfc2581.txt](http://tools.ietf.org/html/rfc2581).

Explicit Congestion Notification in IP is discussed in detail in the IETF RFC 2581 on The Addition of Explicit Congestion Notification
(ECN) to IP. For more information, see [http://www.ietf.org/rfc/rfc3168.txt](http://tools.ietf.org/html/rfc3168).

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_REC_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **CurRwinSent** | tcpEStatsPerfCurRwinSent |
| **MaxRwinSent** | tcpEStatsPerfMaxRwinSent |
| **MinRwinSent** | No mapping to this member. |
| **LimRwin** | tcpEStatsTuneLimRwin |
| **DupAckEpisodes** | tcpEStatsPathDupAckEpisodes |
| **DupAcksOut** | tcpEStatsPathDupAcksOut |
| **CeRcvd** | tcpEStatsPathCERcvd |
| **EcnSent** | No mapping to this member. |
| **EcnNoncesRcvd** | No mapping to this member. |
| **CurReasmQueue** | tcpEStatsStackCurReasmQueue |
| **MaxReasmQueue** | tcpEStatsStackMaxReasmQueue |
| **CurAppRQueue** | tcpEStatsAppCurAppRQueue |
| **MaxAppRQueue** | tcpEStatsAppMaxAppRQueue |
| **WinScaleSent** | tcpEStatsStackWinScaleSent |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)