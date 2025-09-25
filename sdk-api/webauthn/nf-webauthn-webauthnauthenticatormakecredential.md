## Description

The WebAuthNAuthenticatorMakeCredential operation creates a public key credential source bound to a managing authenticator and returns the credential public key associated with its credential private key. The Relying Party can use this credential public key to verify the authentication assertions created by this public key credential source.

## Parameters

### `hWnd`

The handle for the window that will be used to display the UI.

### `pRpInformation`

The Relying Party's **WEBAUTHN_RP_ENTITY_INFORMATION**.

### `pUserInformation`

The user account’s **WEBAUTHN_USER_ENTITY_INFORMATION**, containing the user handle given by the Relying Party.

### `pPubKeyCredParams`

A sequence of pairs of public key credential type and public key algorithms requested by the Relying Party. This sequence is ordered from most preferred to least preferred. The authenticator makes a best-effort to create the most preferred credential that it can.

### `pWebAuthNClientData`

The client data to be sent to the authenticator for the Relying Party.

### `pWebAuthNMakeCredentialOptions`

Provides the options to use when creating the public key credential source.

### `ppWebAuthNCredentialAttestation`

On successful completion of this operation, the authenticator returns the attestation object to the client.

## Return value

Returns an **HRESULT** indicating success or failure.

## Remarks

## See also

[WEBAUTHN_USER_ENTITY_INFORMATION](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_user_entity_information)

[WebAuthNGetPlatformCredentialList](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetplatformcredentiallist)