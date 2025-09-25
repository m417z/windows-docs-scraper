# EAP_CRED_EXPIRY_REQ structure

## Description

The **EAP_CRED_EXPIRY_REQ** structure contains both the old and new EAP credentials for credential expiry operations.

## Members

### `curCreds`

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure that contains the old EAP credentials.

### `newCreds`

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure that contains the new EAP credentials.

## Remarks

The **EAP_CRED_EXPIRY_REQ** structure can be employed to support Single-Sign-On (SSO).

The **EAP_CRED_EXPIRY_REQ** structure is identical to the [EAP_CRED_EXPIRY_RESP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb530539(v=vs.85)) structure.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EAP_CRED_EXPIRY_RESP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb530539(v=vs.85))

[EAP_CRED_REQ](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-req)

[EAP_CRED_RESP](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-resp)

[EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)