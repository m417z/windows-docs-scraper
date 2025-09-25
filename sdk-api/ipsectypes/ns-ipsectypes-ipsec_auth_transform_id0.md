# IPSEC_AUTH_TRANSFORM_ID0 structure

## Description

The **IPSEC_AUTH_TRANSFORM_ID0** structure is used to uniquely identify the hash algorithm used in an IPsec security association (SA).

## Members

### `authType`

The type of the hash algorithm as specified by [IPSEC_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_auth_type).

### `authConfig`

Additional configuration information for the IPsec SA hash algorithm as specified by a **IPSEC_AUTH_CONFIG** which maps to a **UINT8**.

Possible values:

| IPsec authentication configuration | Meaning |
| --- | --- |
| **IPSEC_AUTH_CONFIG_HMAC_MD5_96** | HMAC (Hash Message Authentication Code) secret key authentication algorithm.<br><br>MD5 (Message Digest) data integrity and data origin authentication algorithm. |
| **IPSEC_AUTH_CONFIG_HMAC_SHA_1_96** | HMAC secret key authentication algorithm. <br><br>SHA-1 (Secure Hash Algorithm) data integrity and data origin authentication algorithm. |
| **IPSEC_AUTH_CONFIG_HMAC_SHA_256_128** | HMAC secret key authentication algorithm. <br><br>SHA-256 data integrity and data origin authentication algorithm.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_CONFIG_GCM_AES_128** | GCM (Galois Counter Mode) secret key authentication algorithm. <br><br>AES(Advanced Encryption Standard) data integrity and data origin authentication algorithm, with 128-bit key.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_CONFIG_GCM_AES_192** | GCM secret key authentication algorithm. <br><br>AES data integrity and data origin authentication algorithm, with 192-bit key.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_AUTH_CONFIG_GCM_AES_256** | GCM secret key authentication algorithm. <br><br>AES data integrity and data origin authentication algorithm, with 256-bit key.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |

## Remarks

**IPSEC_AUTH_TRANSFORM_ID0** is a specific implementation of IPSEC_AUTH_TRANSFORM_ID. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)