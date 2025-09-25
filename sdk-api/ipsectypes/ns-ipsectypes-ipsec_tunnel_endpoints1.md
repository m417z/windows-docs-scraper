## Description

The **IPSEC_TUNNEL_ENDPOINTS1** structure is used to store end points of a tunnel mode SA.
[IPSEC_TUNNEL_ENDPOINTS2](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints2) is available.

## Members

### `ipVersion`

An [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) value that specifies the IP version. In tunnel mode, this is the version of the outer header.

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

### `localIfLuid`

Optional LUID of the local interface corresponding to the local address specified above.

## Remarks

For the unnamed union containing the local tunnel end point address, switch_type(FWP_IP_VERSION), switch_is(ipVersion).

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)