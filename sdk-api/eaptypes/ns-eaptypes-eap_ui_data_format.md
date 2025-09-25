# EAP_UI_DATA_FORMAT structure overview

## Description

The **EAP_UI_DATA_FORMAT** union specifies the value of the attribute stored in the *pbUiData* member of the [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_interactive_ui_data_type) structure. The structure of the **EAP_UI_DATA_FORMAT** union depends on the value of *dwDataType* as specified in [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data).

## Members

### `credData`

case(*EapCredReq*)

If [EAP_CRED_REQ](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-req)structure.

case(*EapCredResp*)

If [EAP_CRED_RESP](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-resp) structure

### `case`

### `case.EapCredReq`

### `case.EapCredResp`

### `credExpiryData`

case(*eapCredExpiryReq*)

If *dwDataType* specifies a credential expiry request (*eapCredExpiryReq*), then the data pointed to by this parameter is defined by [EAP_CRED_EXPIRY_REQ](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_cred_expiry_req)  structure.

case(*eapCredExpiryResp*)

If *dwDataType* specifies a credential expiry response type (*eapCredExpiryResp*), then this parameter is defined by [EAP_CRED_EXPIRY_RESP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb530539(v=vs.85)) structure

### `case.EapCredExpiryReq`

### `case.EapCredExpiryResp`

### `credLogonData`

case(*EapCredLogonReq*)

If [EAP_CRED_LOGON_REQ](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-logon-req) structure.

case(*EapCredLogonResp*)

If [EAP_CRED_LOGON_RESP](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-logon-resp) structure

### `case.EapCredLogonReq`

### `case.EapCredLogonResp`

### `EAP_INTERACTIVE_UI_DATA_TYPE`

## See also

[EAP_CRED_EXPIRY_REQ](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_cred_expiry_req)

[EAP_CRED_EXPIRY_RESP](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb530539(v=vs.85))

[EAP_CRED_REQ](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-req)

[EAP_CRED_RESP](https://learn.microsoft.com/windows/win32/eaphost/eap-cred-resp)

[EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data)

[EAP_INTERACTIVE_UI_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ne-eaptypes-eap_interactive_ui_data_type)