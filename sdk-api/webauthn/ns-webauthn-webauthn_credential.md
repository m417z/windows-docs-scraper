## Description

Contains information about a credential.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `cbId`

The size of **pbId**.

### `pbId`

Unique ID for this particular credential.

### `pwszCredentialType`

Well-known credential type specifying the type of this particular credential.

## Remarks

## See also

[WEBAUTHN_CREDENTIALS](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credentials)