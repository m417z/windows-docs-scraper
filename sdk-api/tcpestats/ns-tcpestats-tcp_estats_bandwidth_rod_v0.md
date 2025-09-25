# TCP_ESTATS_BANDWIDTH_ROD_v0 structure

## Description

The **TCP_ESTATS_BANDWIDTH_ROD_v0** structure contains read-only dynamic information for extended TCP statistics on bandwidth estimation for a TCP connection.

## Members

### `OutboundBandwidth`

Type: **ULONG64**

The computed outbound bandwidth estimate, in bits per second, for the network path for the TCP connection.

### `InboundBandwidth`

Type: **ULONG64**

The computed inbound bandwidth estimate, in bits per second, for the network path for the TCP connection.

### `OutboundInstability`

Type: **ULONG64**

A measure, in bits per second, of the instability of the outbound bandwidth estimate for the network path for the TCP connection.

### `InboundInstability`

Type: **ULONG64**

A measure, in bits per second, of the instability of the inbound bandwidth estimate for the network path for the TCP connection.

### `OutboundBandwidthPeaked`

Type: **BOOLEAN**

A boolean value that indicates if the computed outbound bandwidth estimate for the network path for the TCP connection has reached its peak value.

### `InboundBandwidthPeaked`

Type: **BOOLEAN**

A boolean value that indicates if the computed inbound bandwidth estimate for the network path for the TCP connection has reached its peak value.

## Remarks

The **TCP_ESTATS_BANDWIDTH_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_BANDWIDTH_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on bandwidth estimation for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_BANDWIDTH_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsBandwidth** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The members of this structure are not defined in the IETF RFC on the TCP Extended Statistics MIB. For more information on this RFC, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

## See also

[GetIpNetworkConnectionBandwidthEstimates](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetworkconnectionbandwidthestimates)

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[NL_BANDWIDTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_bandwidth_information)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)