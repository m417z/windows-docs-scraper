# SCHANNEL_ALG structure

## Description

The **SCHANNEL_ALG** structure contains algorithm and key size information. It is used as the structure passed as *pbData* in [CryptSetKeyParam](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptsetkeyparam) when *dwParam* is set to KP_SCHANNEL_ALG.

## Members

### `dwUse`

Indicates the use of derived keys. The following values can be used.

| Value | Meaning |
| --- | --- |
| **SCHANNEL_MAC_KEY** | Derive keys to create or verify SSL MAC signatures. |
| **SCHANNEL_ENC_KEY** | Derive keys to encrypt or decrypt data. |

### `Algid`

Algorithms used with the derived keys. Note that no algorithm will be specified unless earlier obtained from the CSP by enumeration.

SCHANNEL_MAC_KEYs can be either MD5 or SHA.

SCHANNEL_ENC_KEYs can be RC4, DES, 3DES, or RC2.

### `cBits`

Size in bits of the derived keys.

### `dwFlags`

This flag can be set to INTERNATIONAL_USAGE (0x00000001), indicating that derived keys must follow SSL export rules.

### `dwReserved`

Reserved for future use. Should be set to zero.