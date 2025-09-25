# IPSEC_SA_CONTEXT_ENUM_TEMPLATE0 structure

## Description

The **IPSEC_SA_CONTEXT_ENUM_TEMPLATE0** structure is an enumeration template used to enumerate security association (SA) contexts.

## Members

### `localSubNet`

An [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) structure that specifies a subnet from which SA contexts that contain a local address will be returned. This member may be empty.

Acceptable type values for this member are: [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask).

### `remoteSubNet`

An [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) structure that specifies a subnet from which SA contexts that contain a remote address will be returned. This member may be empty.

Acceptable type values for this member are: [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask).

## Remarks

**IPSEC_SA_CONTEXT_ENUM_TEMPLATE0** is a specific implementation of IPSEC_SA_CONTEXT_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0)