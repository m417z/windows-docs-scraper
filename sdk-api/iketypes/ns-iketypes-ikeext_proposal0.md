# IKEEXT_PROPOSAL0 structure

## Description

The **IKEEXT_PROPOSAL0** structure is used to store an IKE/AuthIP main mode proposal.

## Members

### `cipherAlgorithm`

Parameters for the encryption algorithm specified by [IKEEXT_CIPHER_ALGORITHM0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cipher_algorithm0).

### `integrityAlgorithm`

Parameters for the hash algorithm specified by [IKEEXT_INTEGRITY_ALGORITHM0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_integrity_algorithm0).

### `maxLifetimeSeconds`

Main mode security association (SA) lifetime in seconds.

### `dhGroup`

The Diffie Hellman group specified by [IKEEXT_DH_GROUP](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_dh_group).

### `quickModeLimit`

Maximum number of IPsec quick mode SAs that can be generated from this
main mode SA. 0 (zero) means infinite.

## Remarks

The proposal describes the
various parameters of the IKE/AuthIP main mode SA that is potentially generated
from this proposal.

**IKEEXT_PROPOSAL0** is a specific implementation of IKEEXT_PROPOSAL. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IKEEXT_CIPHER_ALGORITHM0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_cipher_algorithm0)

[IKEEXT_DH_GROUP](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_dh_group)

[IKEEXT_INTEGRITY_ALGORITHM0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_integrity_algorithm0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)