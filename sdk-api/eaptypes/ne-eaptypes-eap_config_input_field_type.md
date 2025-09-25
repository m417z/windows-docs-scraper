# EAP_CONFIG_INPUT_FIELD_TYPE enumeration

## Description

 The **EAP_CONFIG_INPUT_FIELD_TYPE** enumeration defines a set of possible input field types available when querying for user credentials.

## Constants

### `EapConfigInputUsername`

The input field contains a user's application logon name.

### `EapConfigInputPassword`

The input field contains a user's application logon password.

### `EapConfigInputNetworkUsername`

The input field contains a user's network logon name. This is used as an alternate logon user name for **EapConfigInputUsername**.

### `EapConfigInputNetworkPassword`

The input field contains a user's network login password. This is used as an alternate logon password for **EapConfigInputPassword**.

### `EapConfigInputPin`

The input field contains the user's network access PIN.

### `EapConfigInputPSK`

The input field contains the user's Flexible Authentication via Secure Tunneling (EAP-FAST) Pre-Shared Key(PSK).

### `EapConfigInputEdit`

The input field contains a generic logon token string.

### `EapConfigSmartCardUsername`

Windows 7 or later: The input field contains the username from a smartcard certificate.

### `EapConfigSmartCardError`

Windows 7 or later: If an authentication using a smartcard did not succeed in the previous attempt of the current session, this input field contains an error message citing the failure reason.

## Remarks

The **EAP_CONFIG_INPUT_FIELD_TYPE** enumeration can be employed to support Single-Sign-On (SSO).

## See also

[Common EAPHost API Enumerations](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-enumerations)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)