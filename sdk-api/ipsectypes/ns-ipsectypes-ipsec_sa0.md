# IPSEC_SA0 structure

## Description

The **IPSEC_SA0** structure is used to store information about an IPsec security association (SA).

## Members

### `spi`

Security parameter index (SPI) of the IPsec SA. **IPSEC_SA_SPI** is defined in ipsectypes.h as UINT32.

### `saTransformType`

Transform type of the SA specifying the IPsec security protocol.

See [IPSEC_TRANSFORM_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_transform_type) for more information.

### `ahInformation`

Security algorithms of the SA transform. Available when **saTransformType** is **IPSEC_TRANSFORM_AH**.

See [IPSEC_SA_AUTH_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_information0) for more information.

### `espAuthInformation`

Security algorithms of the SA transform. Available when **saTransformType** is **IPSEC_TRANSFORM_ESP_AUTH**.

See [IPSEC_SA_AUTH_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_information0) for more information.

### `espCipherInformation`

Security algorithms of the SA transform. Available when **saTransformType** is **IPSEC_TRANSFORM_ESP_CIPHER**.

See [IPSEC_SA_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_cipher_information0) for more information.

### `espAuthAndCipherInformation`

Security algorithms of the SA transform. Available when **saTransformType** is **IPSEC_TRANSFORM_ESP_AUTH_AND_CIPHER**.

See [IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_and_cipher_information0) for more information.

### `espAuthFwInformation`

Security algorithms of the SA transform. Available when **saTransformType** is **IPSEC_TRANSFORM_ESP_AUTH_FW**.

**Note** Available only on Windows Server 2008 R2, Windows 7, or later.

## Remarks

**IPSEC_SA0** is a specific implementation of IPSEC_SA. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_SA_AUTH_AND_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_and_cipher_information0)

[IPSEC_SA_AUTH_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_auth_information0)

[IPSEC_SA_CIPHER_INFORMATION0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_cipher_information0)

[IPSEC_TRANSFORM_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_transform_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)