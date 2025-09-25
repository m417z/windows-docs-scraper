## Description

The **IPSEC_TUNNEL_ENDPOINTS0** structure is used to store end points of a tunnel mode SA.
[IPSEC_TUNNEL_ENDPOINTS2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints2) is available.

## Members

### `ipVersion`

IP version of the addresses.

See [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) for more information.

### `localV4Address`

case(FWP_IP_VERSION_V4)

### `localV6Address`

case(FWP_IP_VERSION_V6)

switch_type(FWP_IP_VERSION), switch_is(ipVersion)

Tagged union containing the remote tunnel end point address.

### `remoteV4Address`

case(FWP_IP_VERSION_V4)

### `remoteV6Address`

case(FWP_IP_VERSION_V6)

## Remarks

For the unnamed union containing the local tunnel end point address, switch_type(FWP_IP_VERSION), switch_is(ipVersion).

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[Windows Filtering Platform API structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)