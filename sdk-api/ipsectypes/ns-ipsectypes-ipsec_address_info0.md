# IPSEC_ADDRESS_INFO0 structure

## Description

The **IPSEC_ADDRESS_INFO0** structure is used to store mobile additional address information.

## Members

### `numV4Addresses`

The number of IPv4 addresses stored in the **v4Addresses** member.

### `v4Addresses`

Array of IPv4 local addresses to indicate to peer.

### `numV6Addresses`

The number of IPv6 addresses stored in the **v6Addresses** member.

### `v6Addresses`

Array of IPv6 local addresses to indicate to peer.

## Remarks

**IPSEC_ADDRESS_INFO0** is a specific implementation of IPSEC_ADDRESS_INFO. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)