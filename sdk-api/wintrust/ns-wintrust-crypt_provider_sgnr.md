# CRYPT_PROVIDER_SGNR structure

## Description

[The **CRYPT_PROVIDER_SGNR** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPT_PROVIDER_SGNR** structure provides information about a signer or countersigner.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `sftVerifyAsOf`

The current time, or the time stamp.

### `csCertChain`

Number of elements in the **pasCertChain** array.

### `pasCertChain`

Array of [CRYPT_PROVIDER_CERT](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_cert) structures.

### `dwSignerType`

Signer type, if known by the policy. This value is zero, if the signer type is unknown, or the following value.

| Value | Meaning |
| --- | --- |
| **SGNR_TYPE_TIMESTAMP**<br><br>0x00000010 | Time stamp signer. |

### `psSigner`

A pointer to a [CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmsg_signer_info) structure.

### `dwError`

Error value, if any, while building or verifying the signer.

### `csCounterSigners`

Number of elements in the **pasCounterSigners** array.

### `pasCounterSigners`

A pointer to an array of **CRYPT_PROVIDER_SGNR** structures that represent the countersigners.

### `pChainContext`

A pointer to a [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structure.