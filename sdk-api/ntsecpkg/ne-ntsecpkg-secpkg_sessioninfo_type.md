# SECPKG_SESSIONINFO_TYPE enumeration

## Description

Specifies the format of session information. This enumeration is used by the [CreateTokenEx](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_create_token_ex) function to specify the format of the *SessionInformation* parameter.

## Constants

### `SecSessionPrimaryCred`

The session information is contained in a [SECPKG_PRIMARY_CRED](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-secpkg_primary_cred) structure.