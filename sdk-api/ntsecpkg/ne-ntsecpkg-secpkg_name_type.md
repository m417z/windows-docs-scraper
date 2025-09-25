# SECPKG_NAME_TYPE enumeration

## Description

The **SECPKG_NAME_TYPE** enumeration is used to describe the type of name specified for an account.

The **SECPKG_NAME_TYPE** enumeration is used by the
[GetAuthDataForUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_get_auth_data_for_user) and
[OpenSamUser](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_open_sam_user) functions.

## Constants

### `SecNameSamCompatible`

The account name is compatible with the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM). An example of a name in SAM-compatible format is **"***ExampleDomain***\\***UserName***"**.

### `SecNameAlternateId`

The account name is in the AltSecId property of the SAM account.

### `SecNameFlat`

The account name is a flat user principal name (UPN) style account name.

### `SecNameDN`

The account name is the distinguished name of the object.

### `SecNameSPN`