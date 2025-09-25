# EapMethodAuthenticatorSendPacket function

## Description

Obtains an authentication packet from the EAP authenticator method to send to the supplicant.

**EapMethodAuthenticatorSendPacket** is a function prototype.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession).

### `bPacketId` [in]

Specifies a numeric ID value for the packet to send.

### `pcbSendPacket` [in, out]

Specifies the maximum size, in bytes, of the packet to send. On return, this parameter receives the size, in bytes, of the packet returned in *pEapPacket*.

### `pSendPacket` [out]

A pointer to an [EapPacket](https://learn.microsoft.com/windows/desktop/api/eapmethodtypes/ns-eapmethodtypes-eappacket) structure that contains the packet to send to the supplicant.

### `pTimeout` [out]

A pointer to an [EAP_AUTHENTICATOR_SEND_TIMEOUT](https://learn.microsoft.com/windows/win32/api/eapauthenticatortypes/ne-eapauthenticatortypes-eap_authenticator_send_timeout) enumeration that specifies the timeout for the packet.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## Remarks

This call is performed by a authenticator-based EAPHost using a function pointer to this API. This API must be implemented on the EAP authenticator method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)

[EapMethodAuthenticatorBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorbeginsession)