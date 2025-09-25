## Description

Data about a credential with extra information, such as *dwTransports**.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `cbId`

The size of **pbID**.

### `pbId`

Unique ID for this particular credential.

### `pwszCredentialType`

Well-known credential type specifying the type of this particular credential.

### `dwTransports`

The transports. **0** implies no transport restrictions.

## Remarks

## See also

[WEBAUTHN_CREDENTIAL](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential)