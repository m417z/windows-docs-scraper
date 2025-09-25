# SECPKG_SUPPLEMENTAL_CRED_ARRAY structure

## Description

The **SECPKG_SUPPLEMENTAL_CRED_ARRAY** structure contains [supplemental credentials](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) information. This structure is used by the
[LsaApLogonUserEx2](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_ap_logon_user_ex2) and
[UpdateCredentials](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_update_primary_credentials) functions.

## Members

### `CredentialCount`

The number of supplemental credentials in the **Credentials** member.

### `Credentials.size_is`

### `Credentials.size_is.CredentialCount`

### `Credentials`

An array containing supplemental credentials.