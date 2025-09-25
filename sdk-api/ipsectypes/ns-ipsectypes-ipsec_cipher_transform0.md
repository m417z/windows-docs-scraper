# IPSEC_CIPHER_TRANSFORM0 structure

## Description

The **IPSEC_CIPHER_TRANSFORM0** structure is used to store encryption specific information for an SA transform in an IPsec quick mode policy.

## Members

### `cipherTransformId`

The identifier of the encryption algorithm as specified by [IPSEC_CIPHER_TRANSFORM_ID0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform_id0).

Possible values:

| Value | Meaning |
| --- | --- |
| **IPSEC_CIPHER_TRANSFORM_ID_CBC_DES** | IPSEC_CIPHER_TYPE_DES, IPSEC_CIPHER_CONFIG_CBC_DES |
| **IPSEC_CIPHER_TRANSFORM_ID_CBC_3DES** | IPSEC_CIPHER_TYPE_3DES, IPSEC_CIPHER_CONFIG_CBC_3DES |
| **IPSEC_CIPHER_TRANSFORM_ID_AES_128** | IPSEC_CIPHER_TYPE_AES_128, IPSEC_CIPHER_CONFIG_CBC_AES_128 |
| **IPSEC_CIPHER_TRANSFORM_ID_AES_192** | IPSEC_CIPHER_TYPE_AES_192, IPSEC_CIPHER_CONFIG_CBC_AES_192 |
| **IPSEC_CIPHER_TRANSFORM_ID_AES_256** | IPSEC_CIPHER_TYPE_AES_256, IPSEC_CIPHER_CONFIG_CBC_AES_256 |
| **IPSEC_CIPHER_TRANSFORM_ID_GCM_AES_128** | IPSEC_CIPHER_TYPE_AES_128, IPSEC_CIPHER_CONFIG_GCM_AES_128<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_CIPHER_TRANSFORM_ID_GCM_AES_192** | IPSEC_CIPHER_TYPE_AES_192, IPSEC_CIPHER_CONFIG_GCM_AES_192<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_CIPHER_TRANSFORM_ID_GCM_AES_256** | IPSEC_CIPHER_TYPE_AES_256, IPSEC_CIPHER_CONFIG_GCM_AES_256<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |

### `cryptoModuleId`

Unused parameter, always set this to **NULL**.

## Remarks

**IPSEC_CIPHER_TRANSFORM0** is a specific implementation of IPSEC_CIPHER_TRANSFORM. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_CIPHER_TRANSFORM_ID0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_cipher_transform_id0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)