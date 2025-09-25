# IPSEC_SA_TRANSFORM0 structure

## Description

The **IPSEC_SA_TRANSFORM0** structure is used to store an IPsec security association (SA) transform in an IPsec quick mode policy.

## Members

### `ipsecTransformType`

Type of the SA transform.

See [IPSEC_TRANSFORM_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_transform_type) for more information.

### `ahTransform`

SA transform data. Available when **ipsecTransformType** is **IPSEC_TRANSFORM_AH**.

See [IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0) for more information.

### `espAuthTransform`

SA transform data. Available when **ipsecTransformType** is **IPSEC_TRANSFORM_ESP_AUTH**.

See [IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0) for more information.

### `espCipherTransform`

SA transform data. Available when **ipsecTransformType** is **IPSEC_TRANSFORM_ESP_CIPHER**.

See [IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0) for more information.

### `espAuthAndCipherTransform`

SA transform data. Available when **ipsecTransformType** is **IPSEC_TRANSFORM_ESP_AUTH_AND_CIPHER**.

See [IPSEC_AUTH_AND_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_auth_and_cipher_transform0) for more information.

### `espAuthFwTransform`

SA transform data. Available when **ipsecTransformType** is **IPSEC_TRANSFORM_ESP_AUTH_FW**.

See [IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0) for more information.

**Note** Available only on Windows Server 2008 R2, Windows 7, or later.

## Remarks

**IPSEC_SA_TRANSFORM0** is a specific implementation of IPSEC_SA_TRANSFORM. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_AUTH_AND_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_auth_and_cipher_transform0)

[IPSEC_AUTH_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform0)

[IPSEC_CIPHER_TRANSFORM0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform0)

[IPSEC_TRANSFORM_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_transform_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)