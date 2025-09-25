## Description

Contains the options for the [WebAuthNGetPlatformCredentialsList](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetplatformcredentiallist) function.

## Members

### `dwVersion`

Version of this structure, to allow for modifications in the future. This field is required and should be set to **CURRENT_VERSION**.

### `pwszRpId`

The Id of the relying party that is making the request. This field is _optional_.

### `bBrowserInPrivateMode`

Is browser in-private mode. This field is _optional_ and defaults to **FALSE**.

## Remarks

## See also

[WebAuthNGetPlatformCredentialsList](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetplatformcredentiallist)