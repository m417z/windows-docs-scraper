## Description

A structure that contains the data necessary to verify an assertion.

## Members

### `dwVersion`

The version of this structure.

### `cbAuthenticatorData`

The size of the authenticator data.

### `pbAuthenticatorData`

A pointer to the authenticator data.

### `cbSignature`

The size of the signature that was generated for this assertion.

### `pbSignature`

A pointer to the signature that was generated for this assertion.

### `Credential`

The credential that was used for this assertion.

### `cbUserId`

The size of the user Id.

### `pbUserId`

A pointer to the user Id.

### `Extensions`

A CBOR map from extension identifiers to their authenticator extension inputs, created by the client based on the extensions requested by the Relying Party, if any.

### `cbCredLargeBlob`

The size of **pbCredLargeBlob**.

### `pbCredLargeBlob`

A pointer to the credential blob.

### `dwCredLargeBlobStatus`

The status of the credential blob.

### `pHmacSecret`

A salt used to generate the HMAC secret.

## Remarks

## See also

[WebAuthNFreeAssertion](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnfreeassertion)

[WebAuthNAuthenticatorGetAssertion](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatorgetassertion)