# EAP_METHOD_AUTHENTICATOR_RESPONSE_ACTION enumeration

## Description

Defines the set of response instructions sent by the authenticator to the supplicant or EAP peer method.

## Constants

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_DISCARD:0`

The supplicant should discard the response as it is not usable by EAPHost.

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_SEND`

The supplicant should send the indicated packet to the authenticator.

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_RESULT`

The supplicant should act on EAP attributes returned by the authenticator.

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_RESPOND`

The supplicant should generate a context-specific response to the authenticator request.

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_AUTHENTICATE`

The authenticator method has started authentication of the supplicant.

### `EAP_METHOD_AUTHENTICATOR_RESPONSE_HANDLE_IDENTITY`

The peer method should return the handle for the user identity of the supplicant.

### `v1_enum`

## See also

[EAP Host Authenticator Method Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-enumerations)