## Description

When this operation is invoked by the client in an authenticator session, it has the effect of terminating any [WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential) or [WebAuthNAuthenticatorGetAssertion](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatorgetassertion) operation currently in progress in that authenticator session. The authenticator stops prompting for, or accepting, any user input related to authorizing the canceled operation. The client ignores any further responses from the authenticator for the canceled operation.

## Parameters

### `pCancellationId`

The **GUID** returned, representing the ID of the cancelled operation.

## Return value

Returns an **HRESULT** indicating success or failure.

## Remarks

This operation is ignored if it is invoked in an authenticator session which does not have an **WebAuthNAuthenticatorMakeCredential** or **WebAuthNAuthenticatorGetAssertion** operation currently in progress.

## See also

[WebAuthNGetCancellationId](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthngetcancellationid)

[WebAuthNAuthenticatorMakeCredential](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatormakecredential)

[WebAuthNAuthenticatorGetAssertion](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthnauthenticatorgetassertion)