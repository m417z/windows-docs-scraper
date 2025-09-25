# IKEEXT_SA_DETAILS2 structure

## Description

The **IKEEXT_SA_DETAILS2** structure is used to store information returned when enumerating IKE, AuthIP, and IKEv2 security associations (SAs).
[IKEEXT_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details1) is available. For Windows Vista, [IKEEXT_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details0) is available.

## Members

### `saId`

Type: **UINT64**

LUID identifying the security association.

### `keyModuleType`

Type: [IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type)

Key module type.

### `ipVersion`

Type: [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

 The IP version.

### `v4UdpEncapsulation`

Type: [IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0)*

Stores the UDP ports corresponding to the
Main Mode, if a NAT is detected.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `ikeTraffic`

Type: [IKEEXT_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_traffic0)

The traffic corresponding to this IKE SA.

### `ikeProposal`

Type: [IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0)

The main mode proposal corresponding to this IKE SA.

### `cookiePair`

Type: [IKEEXT_COOKIE_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cookie_pair0)

The SA cookies.

### `ikeCredentials`

Type: [IKEEXT_CREDENTIALS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials2)

Credentials information for the SA.

### `ikePolicyKey`

Type: **GUID**

GUID of the main mode policy provider context corresponding to this SA.

### `virtualIfTunnelId`

Type: **UINT64**

ID/Handle to virtual interface tunneling state. Applicable only to IKEv2.

### `correlationKey`

Type: [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

Key derived from authentications to allow external applications to cryptographically bind
their exchanges with this SA.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IKEEXT_COOKIE_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cookie_pair0)

[IKEEXT_CREDENTIALS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials2)

[IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type)

[IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0)

[IKEEXT_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_traffic0)

[IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0)