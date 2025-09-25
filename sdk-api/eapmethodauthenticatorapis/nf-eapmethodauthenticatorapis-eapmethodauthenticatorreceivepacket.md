# EapMethodAuthenticatorReceivePacket function

## Description

Processes an EAP authentication packet received by the server EAPHost and returns a response action.

**EapMethodAuthenticatorReceivePacket** is a function prototype.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession).

### `cbReceivePacket` [in]

The size, in bytes, of *pReceivePacket*.

### `pReceivePacket` [in]

A pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains an EAP authentication session packet received from the supplicant by the server EAPHost.

### `pEapOutput` [out]

A pointer to an [EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ne-eapauthenticatoractiondefine-eap_method_authenticator_response_action) enumeration that indicates the next action the supplicant must take in the EAP authentication session.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## Remarks

This call is performed by a authenticator-based EAPHost using a function pointer to this API. This API must be implemented on the EAP authenticator method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)

[EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)