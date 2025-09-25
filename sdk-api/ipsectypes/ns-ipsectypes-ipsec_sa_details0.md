# IPSEC_SA_DETAILS0 structure

## Description

The **IPSEC_SA_DETAILS0** structure is used to store information returned when enumerating IPsec security associations (SAs).
[IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) is available.

## Members

### `ipVersion`

Internet Protocol (IP) version as specified by [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version).

### `saDirection`

Indicates direction of the IPsec SA as specified by [FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction).

### `traffic`

The traffic being secured by this IPsec SA as specified by [IPSEC_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic0).

### `saBundle`

Various parameters of the SA as specified by [IPSEC_SA_BUNDLE0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_bundle0).

### `udpEncapsulation`

An [IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0) structure that stores the UDP
encapsulation ports if UDP-ESP encapsulation is enabled on the SA.

Available if **ipVersion** is **FWP_IP_VERSION_V4**.

### `transportFilter`

The transport layer filter corresponding to this IPsec SA as specified by [FWPM_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_filter0).

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)