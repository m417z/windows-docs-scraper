## Description

The **IPSEC_TUNNEL_ENDPOINTS2** structure is used to store end points of a tunnel mode SA.
[IPSEC_TUNNEL_ENDPOINTS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints1) is available. For Windows Vista, [IPSEC_TUNNEL_ENDPOINTS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoints0) is available.

## Members

### `ipVersion`

Type: [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

Specifies the IP version. In tunnel mode, this is the version of the outer header.

### `localV4Address`

Type: **UINT32**

case(FWP_IP_VERSION_V4)

### `localV6Address`

Type: **UINT8[16]**

case(FWP_IP_VERSION_V6)

switch_type(FWP_IP_VERSION), switch_is(ipVersion)

Tagged union containing the remote tunnel end point address.

### `remoteV4Address`

Type: **UINT32**

case(FWP_IP_VERSION_V4)

### `remoteV6Address`

Type: **UINT8[16]**

case(FWP_IP_VERSION_V6)

### `localIfLuid`

Type: **UINT64**

Optional LUID of the local interface corresponding to the local address specified above.

### `remoteFqdn`

Type: **wchar_t***

Configuration of multiple remote addresses and fully qualified domain names for asymmetric tunneling support.

### `numAddresses`

Type: **UINT32**

The number of remote tunnel addresses.

### `remoteAddresses`

Type: [IPSEC_TUNNEL_ENDPOINT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_endpoint0)*

[size_is(numAddresses)]

The remote tunnel end point address information.

## Remarks

For the unnamed union containing the local tunnel end point address, switch_type(FWP_IP_VERSION), switch_is(ipVersion).

## See also

[FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version)

[Windows Filtering Platform API structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)