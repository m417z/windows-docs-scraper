# CRED_PROTECTION_TYPE enumeration

## Description

The **CRED_PROTECTION_TYPE** enumeration specifies the security context in which credentials are encrypted when using the [CredProtect](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-credprotecta) function.

## Constants

### `CredUnprotected`

The credentials are not encrypted.

### `CredUserProtection`

The credentials are encrypted and can be decrypted only in the security context in which they were encrypted or in the security context of a trusted component.

### `CredTrustedProtection`

The credentials are encrypted and can only be decrypted by a trusted component.

### `CredForSystemProtection`