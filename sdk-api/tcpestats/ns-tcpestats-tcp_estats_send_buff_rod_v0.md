# TCP_ESTATS_SEND_BUFF_ROD_v0 structure

## Description

The **TCP_ESTATS_SEND_BUFF_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on output queuing for a TCP connection.

## Members

### `CurRetxQueue`

Type: **SIZE_T**

The current number of bytes of data occupying the
retransmit queue.

### `MaxRetxQueue`

Type: **SIZE_T**

The maximum number of bytes of data occupying the
retransmit queue.

### `CurAppWQueue`

Type: **SIZE_T**

The current number of bytes of application data buffered
by TCP, pending the first transmission (to the left of
SND.NXT or SndMax).

This data will generally be transmitted
(and SND.NXT advanced to the left) as soon as there is an
available congestion window or receiver window. This is the amount of data readily available for
transmission, without scheduling the application. TCP
performance may suffer if there is insufficient queued
write data.

### `MaxAppWQueue`

Type: **SIZE_T**

The maximum number of bytes of application data buffered
by TCP, pending the first transmission.

This is the maximum
value of the **CurAppWQueue** member. The **MaxAppWQueue** and **CurAppWQueue** members can
be used to determine if insufficient queued data is steady
state (suggesting insufficient queue space) or transient
(suggesting insufficient application performance or
excessive CPU load or scheduler latency).

## Remarks

The **TCP_ESTATS_SEND_BUFF_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_SEND_BUFF_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on output queuing for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_SEND_BUFF_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsSendBuff** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_SEND_BUFF_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **CurRetxQueue** | tcpEStatsStackCurRetxQueue |
| **MaxRetxQueue** | tcpEStatsStackMaxRetxQueue |
| **CurAppWQueue** | tcpEStatsAppCurAppWQueue |
| **MaxAppWQueue** | tcpEStatsAppMaxAppWQueue |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)