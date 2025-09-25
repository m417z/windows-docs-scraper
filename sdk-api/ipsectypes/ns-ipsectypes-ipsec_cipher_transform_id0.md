# IPSEC_CIPHER_TRANSFORM_ID0 structure

## Description

The **IPSEC_CIPHER_TRANSFORM_ID0** structure specifies information used to uniquely identify the encryption algorithm used in an IPsec SA.

## Members

### `cipherType`

The type of the encryption algorithm as specified by [IPSEC_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_cipher_type).

### `cipherConfig`

Additional configuration information for the encryption algorithm as specified by **IPSEC_CIPHER_CONFIG** which maps to a **UINT8**.

Possible values:

| IPsec encryption configuration | Meaning |
| --- | --- |
| **IPSEC_CIPHER_CONFIG_CBC_DES** | DES (Data Encryption Standard) algorithm. <br><br>CBC (Cipher Block Chaining) mode of operation. |
| **IPSEC_CIPHER_CONFIG_CBC_3DES** | 3DES algorithm. <br><br>CBC mode of operation. |
| **IPSEC_CIPHER_CONFIG_CBC_AES_128** | AES-128 (Advanced Encryption Standard) algorithm. <br><br>CBC mode of operation. |
| **IPSEC_CIPHER_CONFIG_CBC_AES_192** | AES-192 algorithm. <br><br>CBC mode of operation. |
| **IPSEC_CIPHER_CONFIG_CBC_AES_256** | AES-256 algorithm. <br><br>CBC mode of operation. |
| **IPSEC_CIPHER_CONFIG_GCM_AES_128** | AES-128 algorithm. <br><br>GCM (Galois Counter Mode) mode of operation.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_CIPHER_CONFIG_GCM_AES_192** | AES-192 algorithm. <br><br>GCM (Galois Counter Mode) mode of operation.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |
| **IPSEC_CIPHER_CONFIG_GCM_AES_256** | AES-256 algorithm.<br><br>GCM (Galois Counter Mode) mode of operation.<br><br>**Note** Available only on Windows Server 2008, Windows Vista with SP1, and later. |

## Remarks

**IPSEC_CIPHER_TRANSFORM_ID0** is a specific implementation of IPSEC_CIPHER_TRANSFORM_ID. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_CIPHER_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_cipher_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)