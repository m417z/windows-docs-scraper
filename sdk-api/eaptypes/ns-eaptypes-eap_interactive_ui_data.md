# EAP_INTERACTIVE_UI_DATA structure

## Description

The **EAP_INTERACTIVE_UI_DATA** structure contains configuration information for interactive UI components raised on an EAP supplicant.

## Members

### `dwVersion`

The version of this data structure.

| Value | Meaning |
| --- | --- |
| **EAP_INTERACTIVE_UI_DATA_VERSION**<br><br>0 | The version of the EAP interactive UI data. |

### `dwSize`

The size of this entire structure, in bytes.

### `dwDataType`

An [EAP_INTERACTIVE_UI_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_interactive_ui_data_type) value that specifies the type of data pointed to by *pbUiData*.

### `cbUiData`

The size of the data pointed to by *pbUiData*, in bytes.

### `pbUiData`

A pointer to an [EAP_UI_DATA_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaptypes/ns-eaptypes-eap_ui_data_format) union that contains information about specific user interface components that correspond to the type specified in *dwDataType*.

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[EAP_CRED_EXPIRY_REQ](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_cred_expiry_req)

[EAP_CRED_EXPIRY_RESP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb530539(v=vs.85))

[EAP_CRED_REQ](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-req)

[EAP_CRED_RESP](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-resp)

[EAP_UI DATA_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaptypes/ns-eaptypes-eap_ui_data_format)

[SSO Password Change Behavior](https://learn.microsoft.com/windows/win32/eaphost/sso-password-change-behavior-)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)