# NL_BANDWIDTH_INFORMATION structure

## Description

The **NL_BANDWIDTH_INFORMATION** structure contains read-only information on the available bandwidth estimates and associated variance as determined by the TCP/IP stack.

## Members

### `Bandwidth`

The estimated maximum available bandwidth, in bits per second.

### `Instability`

A measure of the variation based on recent bandwidth samples, in bits per second.

### `BandwidthPeaked`

A value that indicates if the bandwidth estimate in the **Bandwidth** member has peaked and reached its maximum value for the given network conditions.

The TCP/IP stack uses a heuristic to set this variable. Until this variable is set, there is no guarantee that the true available maximum bandwidth is not higher than the estimated bandwidth in the **Bandwidth** member. However, it is safe to assume that maximum available bandwidth is not lower than the estimate reported in the **Bandwidth** member.

## Remarks

The **NL_BANDWIDTH_INFORMATION** structure is defined in the *Nldef.h* header file which is automatically included by the *Iptypes.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Nldef.h* and *Iptypes.h* header files should never be used directly.

## See also

[GetIpNetworkConnectionBandwidthEstimates](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetworkconnectionbandwidthestimates)

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-mib_ip_network_connection_bandwidth_estimates)

[TCP_ESTATS_BANDWIDTH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rod_v0)