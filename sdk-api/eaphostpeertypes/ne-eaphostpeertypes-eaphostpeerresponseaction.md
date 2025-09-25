## Description

Defines the set of actions an EAP authenticator or peer method can indicate to a supplicant during authentication.

## Constants

### `EapHostPeerResponseDiscard:0`

The supplicant should discard the request as it is not usable by EAP.

### `EapHostPeerResponseSend`

The supplicant should send the indicated packet to the authenticator.

### `EapHostPeerResponseResult`

The supplicant should act on EAP attributes returned by the EAP authenticator.

### `EapHostPeerResponseInvokeUi`

The supplicant should invoke a user interface dialog on the client.

### `EapHostPeerResponseRespond`

The supplicant should generate a context-specific response to the EAP authenticator request.

### `EapHostPeerResponseStartAuthentication`

The EAPHost has started authentication.

### `EapHostPeerResponseNone`

The supplicant should generate no response to the EAP authenticator request.

## See also

[EAPHost Supplicant Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-enumerations)