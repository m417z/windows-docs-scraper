# IPSEC_PROPOSAL0 structure

## Description

The **IPSEC_PROPOSAL0** structure is used to store an IPsec quick mode proposal.

## Members

### `lifetime`

Lifetime of the IPsec security association (SA) as specified by [IPSEC_SA_LIFETIME0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_lifetime0). Cannot be zero.

### `numSaTransforms`

Number of IPsec SA transforms. The only possible values are 1 and 2. Use 2 only when specifying AH plus ESP transforms.

### `saTransforms`

Array of IPsec SA transforms as specified by [IPSEC_SA_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_transform0).

### `pfsGroup`

Perfect forward secrecy (PFS) group of the IPsec SA as specified by [IPSEC_PFS_GROUP](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_pfs_group).

## Remarks

The proposal describes the
various parameters of the IPsec SA that is potentially generated from this
proposal.

**IPSEC_PROPOSAL0** is a specific implementation of IPSEC_PROPOSAL. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_PFS_GROUP](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_pfs_group)

[IPSEC_SA_LIFETIME0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_lifetime0)

[IPSEC_SA_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_transform0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)