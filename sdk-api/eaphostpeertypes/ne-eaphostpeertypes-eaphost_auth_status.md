# EAPHOST_AUTH_STATUS enumeration

## Description

Defines the set of possible EAP authentication session status values during the authentication process.

## Constants

### `EapHostInvalidSession:0`

The EAP authentication session is no longer valid.

### `EapHostAuthNotStarted`

The authentication session has not started yet.

### `EapHostAuthIdentityExchange`

The supplicant is providing a user identity in order to begin the EAP authentication session.

### `EapHostAuthNegotiatingType`

The supplicant is negotiating the EAP method type to use for authentication.

### `EapHostAuthInProgress`

The authentication session is in progress.

### `EapHostAuthSucceeded`

The EAP authentication session completed successfully, and authentication was successful.

### `EapHostAuthFailed`

The EAP authentication session completed successfully, but authentication failed.

### `v1_enum`

## See also

[EAPHOST_AUTH_INFO](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ns-eaphostpeertypes-eaphost_auth_info)

[EAPHost Supplicant Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-enumerations)

[EapHostPeerAuthParams](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerauthparams)

[EapHostPeerGetAuthStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetauthstatus)