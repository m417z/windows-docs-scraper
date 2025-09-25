## Description

Specifies the supported protection schemes for encrypted samples.

## Constants

### `MF_SAMPLE_ENCRYPTION_PROTECTION_SCHEME_NONE:0`

No encryption scheme.

### `MF_SAMPLE_ENCRYPTION_PROTECTION_SCHEME_AES_CTR:1`

The encryption scheme is AES counter mode (CTR).

### `MF_SAMPLE_ENCRYPTION_PROTECTION_SCHEME_AES_CBC:2`

The encryption scheme is Cipher Block Chaining (CBC).

## Remarks

The encryption scheme for a sample is specified using the [MFSampleExtension_Encryption_ProtectionScheme](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-encryption-protectionscheme) attribute.