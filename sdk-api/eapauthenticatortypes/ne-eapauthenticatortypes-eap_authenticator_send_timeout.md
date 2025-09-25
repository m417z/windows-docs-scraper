# EAP_AUTHENTICATOR_SEND_TIMEOUT enumeration

## Description

Indicates to the authenticator method the amount of time to wait for user input after the packet is sent. The timeout value can be set to none.

## Constants

### `EAP_AUTHENTICATOR_SEND_TIMEOUT_NONE:0`

 Sends the packet and never times out; the user can enter a response at any time.

### `EAP_AUTHENTICATOR_SEND_TIMEOUT_BASIC`

Sends the packet and waits for a standard period of time for a response.

### `EAP_AUTHENTICATOR_SEND_TIMEOUT_INTERACTIVE`

Sends the packet and waits for a response for a longer period of time to allow for an interactive session.

## See also

[EAPHost Authenticator Method Enumerations](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-enumerations)