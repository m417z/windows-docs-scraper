# IPSEC_SA_CIPHER_INFORMATION0 structure

## Description

The **IPSEC_SA_CIPHER_INFORMATION0** structure stores information about the encryption algorithm of an IPsec security association (SA).

## Members

### `cipherTransform`

Encryption algorithm specific details as specified by [IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0).

### `cipherKey`

Key used for the encryption algorithm as specified by [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob).

## Remarks

**IPSEC_SA_CIPHER_INFORMATION0** is a specific implementation of IPSEC_SA_CIPHER_INFORMATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)