# IPSEC_TRAFFIC0 structure

## Description

The **IPSEC_TRAFFIC0** structure specifies parameters to describe IPsec traffic.
[IPSEC_TRAFFIC1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic1) is available.

## Members

### `ipVersion`

Internet Protocol (IP) version.

See [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) for more information.

### `localV4Address`

The local IPv4 address of the IPsec traffic.

Specified when **ipVersion** is **FWP_IP_VERSION_V4**.

### `localV6Address`

The local IPv6 address of the IPsec traffic.

Specified when **ipVersion** is **FWP_IP_VERSION_V6**.

### `remoteV4Address`

The remote IPv4 address of the IPsec traffic.

Specified when **ipVersion** is **FWP_IP_VERSION_V4**.

### `remoteV6Address`

The remote IPv6 address of the IPsec traffic.

Specified when **ipVersion** is **FWP_IP_VERSION_V6**.

### `trafficType`

Type of IPsec traffic.

See [IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type) for more information.

### `ipsecFilterId`

The LUID of the FWPS transport
layer filter corresponding to this traffic.

Available if **trafficType** is **IPSEC_TRAFFIC_TYPE_TRANSPORT**.

### `tunnelPolicyId`

The LUID of the associated Quick Mode (QM) tunnel policy.

Available if **trafficType** is **IPSEC_TRAFFIC_TYPE_TUNNEL**.

### `remotePort`

The remote TCP/UDP port for this traffic. This is used when the remote port condition in the transport
layer filter is more generic than the actual remote port.

## Remarks

The **IPSEC_TRAFFIC0** type describes the characteristics of the traffic that will match the SA.

For IPsec transport mode, the **localV*Address** and **remoteV*Address** members specify the IP addresses. The **ipsecFilterId** member specifies (as part of the transport layer filter conditions) the transport protocol information (such as IP protocol, ports, etc), of the matching traffic. However, if the **remotePort** member is nonzero, its value will override the remote port specified in the transport layer filter.

For IPsec tunnel mode, the **localV*Address** and **remoteV*Address** members specify the outer IP header tunnel endpoints. The **tunnelPolicyId** member specifies (as part of the filter conditions specified via [FwpmIPsecTunnelAdd0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmipsectunneladd0)) the inner IP header addresses, transport protocol information, of the matching traffic. The **remotePort** member should not be specified for tunnel mode.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)