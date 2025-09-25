# IKEEXT_SA_DETAILS0 structure

## Description

The **IKEEXT_SA_DETAILS0** structure is used to store information returned when enumerating IKE, AuthIP, or IKEv2 security associations (SAs).
[IKEEXT_SA_DETAILS2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_sa_details2) is available.

## Members

### `saId`

LUID identifying the security association.

### `keyModuleType`

Key module type.

See [IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type) for more information.

### `ipVersion`

IP version specified by [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version).

### `v4UdpEncapsulation`

Points to an [IPSEC_V4_UDP_ENCAPSULATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_v4_udp_encapsulation0) structure, which, if a NAT is detected, stores the UDP ports corresponding to the
Main Mode.

Available when **ipVersion** is **FWP_IP_VERSION_V4**.

### `ikeTraffic`

The traffic corresponding to this IKE SA specified by [IKEEXT_TRAFFIC0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_traffic0).

### `ikeProposal`

The main mode proposal corresponding to this IKE SA specified by [IKEEXT_PROPOSAL0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_proposal0).

### `cookiePair`

SA cookies specified by [IKEEXT_COOKIE_PAIR0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cookie_pair0).

### `ikeCredentials`

Credentials information for the SA specified by [IKEEXT_CREDENTIALS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_credentials0).

### `ikePolicyKey`

GUID of the main mode policy provider context corresponding to this SA.

### `virtualIfTunnelId`

ID/Handle to virtual interface tunneling state.

Applicable only to IKEv2.

Available only on Windows 7, Windows Server 2008 R2, and later.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)