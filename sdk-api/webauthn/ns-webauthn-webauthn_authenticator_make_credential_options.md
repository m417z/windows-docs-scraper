## Description

The options for the [WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential) operation.

## Members

### `dwVersion`

Version of this structure.

### `dwTimeoutMilliseconds`

Time that the operation is expected to complete within. This is used as guidance, and can be overridden by the platform.

### `CredentialList`

Credentials used for exclusion.

### `Extensions`

_Optional_ extensions to parse when performing the operation.

### `dwAuthenticatorAttachment`

_Optional_ platform vs cross-platform authenticators.

### `bRequireResidentKey`

Require key to be resident or not. This is _optional_ and defaults to **FALSE**.

### `dwUserVerificationRequirement`

The user verification requirement.

### `dwAttestationConveyancePreference`

The attestation conveyance preference.

### `dwFlags`

The flags (_reserved for future use_).

### `pCancellationId`

The _optional_ cancellation Id. See [WebAuthNGetCancellationId](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetcancellationid) for more information.

### `pExcludeCredentialList`

The exclude credential list. If present, **CredentialList** will be ignored.

### `dwEnterpriseAttestation`

The enterprise attestation.

### `dwLargeBlobSupport`

The requested large blob support: **none**, **required** or **preferred**. User will receive **NTE_INVALID_PARAMETER** when large blob is set to **required** or **preferred** and **bRequireResidentKey** isn't set to **TRUE**.

### `bPreferResidentKey`

Prefer key to be resident. Optional parameter, defaulting to **FALSE**. When **TRUE**, overrides **bRequireResidentKey**.

### `bBrowserInPrivateMode`

Indicates whether the client is using in-private mode in the browser. An _optional_ parameter that defaults to **FALSE**.

## Remarks

## See also

[WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential)

[WebAuthNGetCancellationId](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetcancellationid)