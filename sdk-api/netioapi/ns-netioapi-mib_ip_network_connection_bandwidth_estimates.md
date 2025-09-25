# MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES structure

## Description

The
**MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES** structure contains read-only information for the bandwidth estimates computed by the TCP/IP stack for a network connection.

## Members

### `InboundBandwidthInformation`

Bandwidth estimates for the data being received by the host from the IP network.

### `OutboundBandwidthInformation`

Bandwidth estimates for the data being sent from the host to the IP network.

## Remarks

The
**MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES** structure provides bandwidth estimates computed by the TCP/IP stack for a network connection. These bandwidth estimates are for the point of attachment of the host system to the underlying IP network.

The **MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES** structure is used with the [GetIpNetworkConnectionBandwidthEstimates](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetworkconnectionbandwidthestimates) function to return bandwidth estimates obtained for the point of attachment to the IP network. It is possible to have asymmetric deployments and network conditions where the estimates observed inbound and outbound differ from each other.

The **MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES** structure is defined in the *Netioapi.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIpNetworkConnectionBandwidthEstimates](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetworkconnectionbandwidthestimates)

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[NL_BANDWIDTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_bandwidth_information)

[TCP_ESTATS_BANDWIDTH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rod_v0)