# TCP_ESTATS_BANDWIDTH_RW_v0 structure

## Description

The **TCP_ESTATS_BANDWIDTH_RW_v0** structure contains read/write configuration information for extended TCP statistics on bandwidth estimation for a TCP connection.

## Members

### `EnableCollectionOutbound`

A value that indicates if extended statistics on a TCP connection should be collected for outbound bandwidth estimation.

If this member is set to **TcpBoolOptEnabled**, extended statistics on the TCP connection for outbound bandwidth estimation are enabled. If this member is set to **TcpBoolOptDisabled**, extended statistics on the TCP connection for outbound bandwidth estimation are disabled. If this member is set to **TcpBoolOptUnchanged**, extended statistics on the TCP connection for outbound bandwidth estimation are left unchanged.

The default state for this member when not set is disabled.

### `EnableCollectionInbound`

A value that indicates if extended statistics on a TCP connection should be collected for inbound bandwidth estimation.

If this member is set to **TcpBoolOptEnabled**, extended statistics on the TCP connection for inbound bandwidth estimation are enabled. If this member is set to **TcpBoolOptDisabled**, extended statistics on the TCP connection for inbound bandwidth estimation are disabled. If this member is set to **TcpBoolOptUnchanged**, extended statistics on the TCP connection for inbound bandwidth estimation are unchanged.

The default state for this member when not set is disabled.

## Remarks

The **TCP_ESTATS_BANDWIDTH_RW_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_BANDWIDTH_RW_v0** is defined as version 0 of the structure for read/write configuration information on bandwidth estimation for a TCP connection.

Extended TCP statistics on bandwidth estimation for a TCP connection are enabled and disabled using this structure and the [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) and [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) functions when **TcpConnectionEstatsBandwidth** is passed in the *EstatsType* parameter.

The *Offset* parameter passed to the [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) and [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) functions is currently unused and must be set to 0. Consequently, the **TCP_ESTATS_BANDWIDTH_RW_v0** structure pointed to by the *Rw* parameter when the *EstatsType* parameter is set to **TcpConnectionEstatsBandwidth** must have both the **EnableCollectionOutbound** and **EnableCollectionInbound** structure members set to the preferred values in a single call to the **SetPerTcp6ConnectionEStats** and **SetPerTcpConnectionEStats** functions.

The **TCP_ESTATS_BANDWIDTH_RW_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsBandwidth** is passed in the *EstatsType* parameter.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats)

[SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats)

[TCP_BOOLEAN_OPTIONAL](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_boolean_optional)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)