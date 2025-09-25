# SECPKG_SUPPLIED_CREDENTIAL structure

## Description

Specifies the supplied credentials.

## Members

### `cbHeaderLength`

The length of the header.

### `cbStructureLength`

Pay load length, including the header.

### `UserName`

The user name for Unicode only.

### `DomainName`

The domain name for Unicode only.

### `PackedCredentials`

The credentials in the [SEC_WINNT_AUTH_PACKED_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/sspi/ns-sspi-sec_winnt_auth_packed_credentials) structure.

### `CredFlags`

The authentication identity flags.