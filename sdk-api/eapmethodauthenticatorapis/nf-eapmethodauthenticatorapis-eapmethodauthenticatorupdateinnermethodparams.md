# EapMethodAuthenticatorUpdateInnerMethodParams function

## Description

Updates the EAP authentication session settings previous established by a call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession) from the server EAPHost.

**EapMethodAuthenticatorUpdateInnerMethodParams** is a function prototype.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession).

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the updated EAP authentication session behavior.

### `pwszIdentity` [in]

A zero-terminated Unicode string that contains the updated identity of the user to authenticate.

### `pAttributeArray` [in]

A pointer to an [EapAttributes](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) array structure that specifies the updated EAP attributes of the entity to authenticate.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)

[EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)