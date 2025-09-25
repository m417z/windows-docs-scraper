# IPSEC_DOSP_STATE_ENUM_TEMPLATE0 structure

## Description

The **IPSEC_DOSP_STATE_ENUM_TEMPLATE0** structure is used to enumerate IPsec DoS Protection state entries.

## Members

### `publicV6AddrMask`

An [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask) structure that specifies the public IPv6 address.

### `internalV6AddrMask`

An [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask) structure that specifies the internal IPv6 address.

## Remarks

**IPSEC_DOSP_STATE_ENUM_TEMPLATE0** is a specific implementation of IPSEC_DOSP_STATE_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)