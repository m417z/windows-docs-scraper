# IPSEC_GETSPI1 structure

## Description

The **IPSEC_GETSPI1** structure contains information that must be supplied when requesting a security parameter index (SPI) from the IPsec driver.
[IPSEC_GETSPI0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_getspi0) is available.

## Members

### `inboundIpsecTraffic`

An [IPSEC_TRAFFIC1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic1) structure that describes traffic characteristics of the inbound IPsec SA.

### `ipVersion`

An [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) value that indicates the IP version of the inbound IPsec traffic.

### `inboundUdpEncapsulation`

Optional [IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0) structure that specifies the IPsec NAT Traversal (NATT) UDP encapsulation ports.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `rngCryptoModuleID`

Not used. An **IPSEC_CRYPTO_MODULE_ID** is a **GUID** value.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)