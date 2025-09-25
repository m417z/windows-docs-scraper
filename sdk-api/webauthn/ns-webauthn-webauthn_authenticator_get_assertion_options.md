## Description

A structure that contains the data needed to get an assertion.

## Members

### `dwVersion`

The version of this structure.

### `dwTimeoutMilliseconds`

Time that the operation is expected to complete within. This is used as guidance and can be overridden by the platform.

### `CredentialList`

The list of allowed credentials to be used in the assertion.

### `Extensions`

A CBOR map from extension identifiers to their authenticator extension inputs, created by the client based on the extensions requested by the Relying Party. These are _optional_ extensions to parse when performing the operation.

### `dwAuthenticatorAttachment`

The attachment for the assertion. _Optional_ platform vs cross-platform authenticators.

### `dwUserVerificationRequirement`

The effective user verification requirement.

### `dwFlags`

The flags for the assertion.

### `pwszU2fAppId`

_Optional_ identifier for the U2F AppId. Converted to UTF8 before being hashed. Not lower-cased.

### `pbU2fAppId`

If this is non-NULL, then, set to **TRUE** if the **pwszU2fAppid** was used instead of **PCWSTR pwszRpId**.

### `pCancellationId`

_Optional_ cancellation Id. See [WebAuthNGetCancellationId](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetcancellationid) for more information.

### `pAllowCredentialList`

An _optional_ list of public key credential descriptors describing credentials acceptable to the Relying Party (possibly filtered by the client), if any. If present, **CredentialList** will be ignored.

### `dwCredLargeBlobOperation`

The large blob operation.

### `cbCredLargeBlob`

Size of **pbCredLargeBlob**.

### `pbCredLargeBlob`

A pointer to the large credential blob.

### `pHmacSecretSaltValues`

PRF values which will be converted into HMAC-SECRET values according to the WebAuthN Spec.

### `bBrowserInPrivateMode`

Indicates whether the client is using in-private mode in the browser. An _optional_ parameter that defaults to **FALSE**.

## Remarks

## See also

[WebAuthNAuthenticatorGetAssertion](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatorgetassertion)

[WEBAUTHN_HMAC_SECRET_SALT_VALUES](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_hmac_secret_salt_values)