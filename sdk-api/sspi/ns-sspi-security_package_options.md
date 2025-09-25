# SECURITY_PACKAGE_OPTIONS structure

## Description

Specifies information about a security package. This structure is used by the [AddSecurityPackage](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-addsecuritypackagea) function.

## Members

### `Size`

The size, in bytes, of this structure.

### `Type`

The type of security package. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SECPKG_OPTIONS_TYPE_UNKNOWN**<br><br>0 | The package type is not known. |
| **SECPKG_OPTIONS_TYPE_LSA**<br><br>1 | The security package is an [LSA authentication](https://learn.microsoft.com/windows/desktop/SecAuthN/lsa-authentication) package. |
| **SECPKG_OPTIONS_TYPE_SSPI**<br><br>2 | The security package is a [Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/Rpc/security-support-provider-interface-sspi-) (SSPI) package. |

### `Flags`

This member is reserved. Do not use it.

### `SignatureSize`

The size, in bytes, of a digital signature for this security package.

### `Signature`

A digital signature for this security package.