# IKEEXT_SA_ENUM_TEMPLATE0 structure

## Description

The **IKEEXT_SA_ENUM_TEMPLATE0** structure is an enumeration template used for enumerating IKE/AuthIP security associations (SAs).

## Members

### `localSubNet`

Matches SAs whose local address is on the specified subnet. Must be of one of the following types.

* FWP_UINT32
* FWP_BYTE_ARRAY16_TYPE
* FWP_V4_ADDR_MASK
* FWP_V6_ADDR_MASK

See [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) for more information.

### `remoteSubNet`

Matches SAs whose remote address is on the specified subnet. Must be of one of the following types.

* FWP_UINT32
* FWP_BYTE_ARRAY16_TYPE
* FWP_V4_ADDR_MASK
* FWP_V6_ADDR_MASK

See [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) for more information.

### `localMainModeCertHash`

Matches SAs with a matching local main mode SHA thumbprint. If none exist, this member will have a length of zero.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

## Remarks

**IKEEXT_SA_ENUM_TEMPLATE0** is a specific implementation of IKEEXT_SA_ENUM_TEMPLATE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)