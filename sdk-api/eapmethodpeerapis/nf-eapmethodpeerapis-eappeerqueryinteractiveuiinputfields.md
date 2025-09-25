# EapPeerQueryInteractiveUIInputFields function

## Description

The **EapPeerQueryInteractiveUIInputFields** function defines the implementation of an EAP method API that provides the input fields for interactive UI components to be raised on the supplicant.

## Parameters

### `dwVersion` [in]

The version number of the API. Must be set to zero.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeofUIContextData` [in]

The size of the context data in *pUIContextData*, in bytes.

### `pUIContextData` [in]

A pointer to a BLOB that contains UI context data, represented as inner pointers to field data. The supplicant obtained these inner pointers from EAPHost run-time APIs.

### `pEapInteractiveUIData` [out]

Pointer that receives an [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data) structure that contains configuration information for interactive UI components raised on an EAP supplicant.

### `ppEapError` [out]

 A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future usage. Must be set to **NULL**

## Remarks

[EapPeerQueryInteractiveUIInputFields](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap) can be employed to support Single-Sign-On (SSO). The **EAP_FLAG_PRE_LOGON** flag in [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession) indicates to EAPHost that SSO should be provided. If the **EapPeerResponseInvokeUI** action code is received after calling **EapPeerBeginSession**, EAPHost then calls **EapPeerQueryInteractiveUIInputFields**, and later calls [EapPeerQueryUIBlobFromInteractiveUIInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerqueryuiblobfrominteractiveuiinputfields).

The supplicant should call always call the [EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED](https://learn.microsoft.com/windows/win32/eaphost/eap-related-error-and-information-constants) is returned, the supplicant should resort to the traditional model of invoking method interactive UI by calling [EapPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeinteractiveui). If there is an error, **EapPeerQueryInteractiveUIInputFields** will return a return code other than **NULL**.

## See also

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)