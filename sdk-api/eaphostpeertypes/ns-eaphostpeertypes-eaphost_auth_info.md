# EAPHOST_AUTH_INFO structure

## Description

 The **EAPHOST_AUTH_INFO** structure describes current authentication information throughout different stages of the EAP authentication process.

## Members

### `status`

An [EAPHOST_AUTH_STATUS](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphost_auth_status) enumeration value that specifies the current status of the authentication session.

### `dwErrorCode`

An error value, either from winerror.h or elsewhere (Raserror.h), that indicates the last error raised during the authentication process.

### `dwReasonCode`

A reason code that specifies the reason the error in **dwErrorCode** was raised.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EapHostPeerAuthParams](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerauthparams)

[EapHostPeerGetAuthStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetauthstatus)