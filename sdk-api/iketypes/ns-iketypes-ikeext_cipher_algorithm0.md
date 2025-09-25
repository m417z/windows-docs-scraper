# IKEEXT_CIPHER_ALGORITHM0 structure

## Description

The **IKEEXT_CIPHER_ALGORITHM0** structure stores information about the IKE/AuthIP encryption algorithm.

## Members

### `algoIdentifier`

The type of encryption algorithm.

See [IKEEXT_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cipher_type) for more information.

### `keyLen`

Unused parameter, always set it to 0.

### `rounds`

Unused parameter, always set it to 0.

## Remarks

**IKEEXT_CIPHER_ALGORITHM0** is a specific implementation of IKEEXT_CIPHER_ALGORITHM. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IKEEXT_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_cipher_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)