## Description

Information about the Relying Party entity.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `pwszId`

Identifier for the Relying Party. This field is required.

### `pwszName`

Contains the friendly name of the Relying Party, such as "Acme Corporation", "Widgets Inc", or "Contoso". This field is required.

### `pwszIcon`

Optional URL pointing to the Relying Party's logo.

## Remarks

## See also

[WEBAUTHN_CREDENTIAL_DETAILS](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_credential_details)