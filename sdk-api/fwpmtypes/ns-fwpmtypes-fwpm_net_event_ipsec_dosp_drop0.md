# FWPM_NET_EVENT_IPSEC_DOSP_DROP0 structure

## Description

The **FWPM_NET_EVENT_IPSEC_DOSP_DROP0** structure contains information that describes an IPsec DoS Protection drop event.

## Members

### `ipVersion`

Internet Protocol (IP) version.

See [FWP_IP_VERSION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_ip_version) for more information.

### `publicHostV4Addr`

The public IPv4 address of the Internet host.

Specified when **ipVersion** is **FWP_IP_VERSION_V4**.

### `publicHostV6Addr`

The public IPv6 address of the Internet host.

Specified when **ipVersion** is **FWP_IP_VERSION_V6**.

### `internalHostV4Addr`

The internal IPv4 address of the Internet host.

Specified when **ipVersion** is **FWP_IP_VERSION_V4**.

### `internalHostV6Addr`

The internal IPv6 address of the Internet host.

Specified when **ipVersion** is **FWP_IP_VERSION_V6**.

### `failureStatus`

Contains the error code for the failure.

### `direction`

An [FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction) value that specifies whether the dropped packet is inbound or outbound.

## Remarks

**FWPM_NET_EVENT_IPSEC_DOSP_DROP0** is a specific implementation of FWPM_NET_EVENT_IPSEC_DOSP_DROP. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)