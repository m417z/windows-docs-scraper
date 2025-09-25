# IPSEC_AUTH_AND_CIPHER_TRANSFORM0 structure

## Description

The **IPSEC_AUTH_AND_CIPHER_TRANSFORM0** structure is used to store hash and encryption specific information together for an SA
transform in an IPsec quick mode policy.

## Members

### `authTransform`

Hash specific information as specified by [IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0).

### `cipherTransform`

Encryption specific information as specified by [IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0).

## Remarks

**IPSEC_AUTH_AND_CIPHER_TRANSFORM0** is a specific implementation of IPSEC_AUTH_AND_CIPHER_TRANSFORM. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0)

[IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)