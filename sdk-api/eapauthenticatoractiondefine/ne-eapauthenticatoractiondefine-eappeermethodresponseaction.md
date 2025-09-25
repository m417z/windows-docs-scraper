# EapPeerMethodResponseAction enumeration

## Description

Defines the set of actions an EAP authenticator can indicate to a supplicant or EAP peer method during authentication.

## Constants

### `EapPeerMethodResponseActionDiscard:0`

The supplicant should discard the request as it is not usable by EAP.

### `EapPeerMethodResponseActionSend`

The supplicant should send the indicated packet to the authenticator.

### `EapPeerMethodResponseActionResult`

The supplicant should act on EAP attributes returned by the EAP authenticator.

### `EapPeerMethodResponseActionInvokeUI`

The EAP peer method should invoke a user interface dialog on the client.

### `EapPeerMethodResponseActionRespond`

The supplicant should generate a context-specific response to the EAP authenticator request.

### `EapPeerMethodResponseActionNone`

The supplicant should generate no response to the EAP authenticator request.

### `v1_enum`

## See also

[EAPHost Peer Method Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-peer-method-enumerations)