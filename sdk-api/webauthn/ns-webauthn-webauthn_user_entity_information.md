## Description

Information about a user entity.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `cbId`

The size of **pbId**.

### `pbId`

Identifier for the user. This field is required.

### `pwszName`

Contains a detailed name for this account, such as "john.p.smith@example.com".

### `pwszIcon`

Optional URL that can be used to retrieve an image containing the user's current avatar or a data URI that contains the image data.

### `pwszDisplayName`

Contains the friendly name associated with the user account by the Relying Party, such as "John P. Smith".

## Remarks

## See also

[WEBAUTHN_CREDENTIAL_DETAILS](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential_details)