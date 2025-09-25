## Description

Produces an assertion signature representing an assertion by the authenticator that the user has consented to a specific transaction, such as logging in or completing a purchase.

## Parameters

### `hWnd`

The handle for the window that will be used to display the UI.

### `pwszRpId`

The ID of the Relying Party.

### `pWebAuthNClientData`

The client data to be sent to the authenticator for the Relying Party.

### `pWebAuthNGetAssertionOptions`

The options for the **WebAuthNAuthenticatorGetAssertion** operation.

### `ppWebAuthNAssertion`

A pointer to a **WEBAUTHN_ASSERTION** that receives the assertion.

## Return value

Returns an **HRESULT** indicating success or failure.

## Remarks

> Note:
> Before performing this operation, all other operations in progress in the authenticator session MUST be aborted by running the [WebAuthNCancelCurrentOperation](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthncancelcurrentoperation) operation.

If the authenticator cannot find any credential corresponding to the specified Relying Party that matches the specified criteria, it terminates the operation and returns an error.

## See also

[WebAuthNCancelCurrentOperation](https://learn.microsoft.com/windows/win32/api/webauthn/nf-webauthn-webauthncancelcurrentoperation)

[WEBAUTHN_ASSERTION](https://learn.microsoft.com/windows/win32/api/webauthn/ns-webauthn-webauthn_assertion)