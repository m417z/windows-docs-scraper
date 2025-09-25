# TCP_ESTATS_SND_CONG_RW_v0 structure

## Description

The **TCP_ESTATS_SND_CONG_RW_v0** structure contains read/write configuration information for extended TCP statistics on sender congestion for a TCP connection.

## Members

### `EnableCollection`

A value that indicates if extended statistics on a TCP connection should be collected for sender congestion.

If this member is set to **TRUE**, extended statistics on the TCP connection are enabled. If this member is set to **FALSE**, extended statistics on the TCP connection are disabled.

The default state for this member when not set is disabled.

## Remarks

The **TCP_ESTATS_SND_CONG_RW_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_SND_CONG_RW_v0** is defined as version 0 of the structure for read/write configuration information on sender congestion for a TCP connection.

Extended TCP statistics on sender congestion for a TCP connection are enabled and disabled using this structure and the [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) and [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) functions when **TcpConnectionEstatsSndCongs** is passed in the *EstatsType* parameter.

The **TCP_ESTATS_SND_CONG_RW_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsSndCong** is passed in the *EstatsType* parameter.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats)

[SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)