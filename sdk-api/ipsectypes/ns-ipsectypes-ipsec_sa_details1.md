# IPSEC_SA_DETAILS1 structure

## Description

The **IPSEC_SA_DETAILS1** structure is used to store information returned when enumerating IPsec security associations (SAs).
[IPSEC_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details0) is available.

## Members

### `ipVersion`

An [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) value that specifies the IP version. In tunnel mode, this is the version of the outer header.

### `saDirection`

An [FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction) value that indicates the direction of the IPsec SA.

### `traffic`

An [IPSEC_TRAFFIC1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic1) structure that specifies the traffic being secured by this IPsec SA. In tunnel mode, this contains both the tunnel endpoints and Quick Mode (QM) traffic selectors.

### `saBundle`

An [IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1) structure that specifies various parameters of the SA .

### `udpEncapsulation`

An [IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0) structure that stores the UDP
encapsulation ports if UDP-ESP encapsulation is enabled on the SA.

Available if **ipVersion** is **FWP_IP_VERSION_V4**.

### `transportFilter`

An [FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0) structure that specifies the transport layer filter that corresponds to this IPsec SA.

### `virtualIfTunnelInfo`

An [IPSEC_VIRTUAL_IF_TUNNEL_INFO0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-ipsec_virtual_if_tunnel_info0) structure that specifies the virtual interface tunnel information. Only supported by Internet Key Exchange version 2 (IKEv2).

## See also

[FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0)

[FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction)

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IPSEC_SA_BUNDLE1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle1)

[IPSEC_TRAFFIC1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic1)

[IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0)

[IPSEC_VIRTUAL_IF_TUNNEL_INFO0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-ipsec_virtual_if_tunnel_info0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)