## Description

The **IPSEC_TUNNEL_ENDPOINT0** structure is used to store address information for an end point of a tunnel mode SA.

## Members

### `ipVersion`

Type: [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

Specifies the IP version. In tunnel mode, this is the version of the outer header.

### `v4Address`

Type: **UINT32**

case(FWP_IP_VERSION_V4)

### `v6Address`

Type: **UINT8[16]**

case(FWP_IP_VERSION_V6)

## Remarks

For the unnamed union containing the tunnel end point address, switch_type(FWP_IP_VERSION), switch_is(ipVersion).

**IPSEC_TUNNEL_ENDPOINT0** is a specific implementation of IPSEC_TUNNEL_ENDPOINT. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[IPSEC_TUNNEL_ENDPOINTS2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints2)

[Windows Filtering Platform API structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)