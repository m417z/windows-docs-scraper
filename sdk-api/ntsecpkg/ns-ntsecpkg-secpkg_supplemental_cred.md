# SECPKG_SUPPLEMENTAL_CRED structure

## Description

The **SECPKG_SUPPLEMENTAL_CRED** structure contains [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) recognized by the [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

The structure is used by the
[SpAcceptCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spacceptcredentialsfn) function and the
[SECPKG_SUPPLEMENTAL_CRED_ARRAY](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_supplemental_cred_array) structure.

## Members

### `PackageName`

The name of the [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) that authenticated the [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `CredentialSize`

The size of the **Credentials** member, in bytes.

### `Credentials`

Pointer to a set of package-specific supplemental credentials.

### `Credentials.size_is`

### `Credentials.size_is.CredentialSize`