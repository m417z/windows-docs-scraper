# EapPeerGetResult function

## Description

Obtains the result of an authentication session from the EAP method.

This function is called when a method has completed authentication, or when the lower layer receives an alternative result.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

### `reason` [in]

A [EapPeerMethodResultReason](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ne-eapauthenticatoractiondefine-eappeermethodresultreason) structure that specifies the reason code for the authentication result returned in *ppResult*.

### `ppResult` [out]

A pointer to a [EapPeerMethodResult](https://learn.microsoft.com/windows/win32/api/eapmethodpeerapis/ns-eapmethodpeerapis-eappeermethodresult) structure that contains the authentication results.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)