# IKEEXT_IPV6_CGA_AUTHENTICATION0 structure

## Description

The **IKEEXT_IPV6_CGA_AUTHENTICATION0** structure is used to specify various parameters for IPV6 cryptographically generated address (CGA) authentication.

## Members

### `keyContainerName`

Key container name of the public key/private key pair that was used to generate the CGA.

Same semantics as the **pwszContainerName** member of the [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

### `cspName`

Name of the CSP that stores the key container. If **NULL**, default provider will be used.

Same semantics as the **pwszProvName** member of the [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

### `cspType`

Type of the CSP that stores the key container.

Same semantics as the **dwProvType** member of the [CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info) structure.

### `cgaModifier`

A [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure containing a modifier used during CGA generation.

See CGA RFC for more information.

### `cgaCollisionCount`

Collision count used during CGA generation.

See CGA RFC for more information.

## Remarks

**IKEEXT_IPV6_CGA_AUTHENTICATION0** is a specific implementation of IKEEXT_IPV6_CGA_AUTHENTICATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[CRYPT_KEY_PROV_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_key_prov_info)

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)