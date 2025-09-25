# IPSEC_AUTH_TRANSFORM0 structure

## Description

The **IPSEC_AUTH_TRANSFORM0** structure specifies hash specific information for an SA transform.

## Members

### `authTransformId`

The identifier of the hash algorithm as specified by [IPSEC_AUTH_TRANSFORM_ID0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform_id0).

Possible values:

| Value | Meaning |
| --- | --- |
| **IPSEC_AUTH_TRANSFORM_ID_HMAC_MD5_96** | IPSEC_AUTH_MD5, IPSEC_AUTH_CONFIG_HMAC_MD5_96 |
| **IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_1_96** | IPSEC_AUTH_SHA_1, IPSEC_AUTH_CONFIG_HMAC_SHA_1_96 |
| **IPSEC_AUTH_TRANSFORM_ID_HMAC_SHA_256_128** | IPSEC_AUTH_SHA_256, IPSEC_AUTH_CONFIG_HMAC_SHA_256_128<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_TRANSFORM_ID_GCM_AES_128** | IPSEC_AUTH_AES_128, IPSEC_AUTH_CONFIG_GCM_AES_128<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_TRANSFORM_ID_GCM_AES_192** | IPSEC_AUTH_AES_192, IPSEC_AUTH_CONFIG_GCM_AES_192<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_TRANSFORM_ID_GCM_AES_256** | IPSEC_AUTH_AES_256, IPSEC_AUTH_CONFIG_GCM_AES_256<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |

### `cryptoModuleId`

Unused parameter, always set this to **NULL**.

## Remarks

**IPSEC_AUTH_TRANSFORM0** is a specific implementation of IPSEC_AUTH_TRANSFORM. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_AUTH_TRANSFORM_ID0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_auth_transform_id0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)