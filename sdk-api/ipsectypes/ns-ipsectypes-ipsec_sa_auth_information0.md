# IPSEC_SA_AUTH_INFORMATION0 structure

## Description

The **IPSEC_SA_AUTH_INFORMATION0** structure stores information about the authentication algorithm of an IPsec security association (SA).

## Members

### `authTransform`

Authentication algorithm details as specified by [IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0).

### `authKey`

Key used for the authentication algorithm stored in a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

## Remarks

**IPSEC_SA_AUTH_INFORMATION0** is a specific implementation of IPSEC_SA_AUTH_INFORMATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)