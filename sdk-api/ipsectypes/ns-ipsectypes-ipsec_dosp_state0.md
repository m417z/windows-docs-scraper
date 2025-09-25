# IPSEC_DOSP_STATE0 structure

## Description

The **IPSEC_DOSP_STATE0** structure is used to store state information for IPsec DoS Protection.

## Members

### `publicHostV6Addr`

The IPv6 address of the public host.

### `internalHostV6Addr`

The IPv6 address of the internal host.

### `totalInboundIPv6IPsecAuthPackets`

The total number of inbound IPv6 IPsec packets that have been allowed since the state entry was created.

### `totalOutboundIPv6IPsecAuthPackets`

The total number of outbound IPv6 IPsec packets that have been allowed since the state entry was created.

### `durationSecs`

The duration, in seconds, since the state entry was created.

## Remarks

**IPSEC_DOSP_STATE0** is a specific implementation of IPSEC_DOSP_STATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)