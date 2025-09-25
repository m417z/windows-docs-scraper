## Description

A structure containing the client data that is sent to the authenticator.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `cbClientDataJSON`

The size of the **pbClientDataJSON** field.

### `pbClientDataJSON`

UTF-8 encoded JSON serialization of the client data.

### `pwszHashAlgId`

Hash algorithm ID used to hash the **pbClientDataJSON** field.

## Remarks

## See also

[WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential)