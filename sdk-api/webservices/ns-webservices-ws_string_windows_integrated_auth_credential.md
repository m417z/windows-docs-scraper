# WS_STRING_WINDOWS_INTEGRATED_AUTH_CREDENTIAL structure

## Description

Type for supplying a Windows credential as username, password, domain strings.

## Members

### `credential`

The base type from which this type and all other Windows Integrated
Authentication credential types derive.

### `username`

The username as a string. This must be a valid user. To specify default credentials, use the WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL instead.

### `password`

The password for the username as a string.
To specify a blank password, the length field of the string must be set to 0.

### `domain`

The domain name or the workgroup name as a string.