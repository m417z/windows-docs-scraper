# EapHostPeerQueryInteractiveUIInputFields function

## Description

The **EapHostPeerQueryInteractiveUIInputFields** function obtains the input fields for interactive UI components to be raised on the supplicant.

## Parameters

### `dwVersion` [in]

The version number of the API.

| Value | Meaning |
| --- | --- |
| **EAPHOST_PEER_API_VERSION**<br><br>1 | The version of the EAPHost peer API. |

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeofUIContextData` [in]

The size of the context data in *pUIContextData*, in bytes.

### `pUIContextData` [in]

Pointer to a BLOB that contains UI context data, represented as inner pointers to field data. These inner pointers must be freed by passing them to [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting with the innermost pointer.

### `pEapInteractiveUIData` [out]

Pointer that receives an [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data) structure that contains configuration information for interactive UI components raised on an EAP supplicant. The caller should free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future use. This parameter must be set to 0.

## Remarks

**EapHostPeerQueryInteractiveUIInputFields** can be employed to support Single-Sign-On (SSO). The supplicant uses the **EAP_FLAG_PRE_LOGON** flag in [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession) to indicate to EAPHost that SSO should be provided. If the [EapHostPeerResponseInvokeUI](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) action code is received after calling **EapHostPeerBeginSession**, EAPHost then calls **EapHostPeerQueryInteractiveUIInputFields**, and later calls [EapHostPeerQueryUIBlobFromInteractiveUIInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryuiblobfrominteractiveuiinputfields).

The supplicant should call the [EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED](https://learn.microsoft.com/windows/win32/eaphost/eap-related-error-and-information-constants) is returned, the supplicant should resort to the traditional model of invoking method interactive UI by calling [EapHostPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeinteractiveui). If there is an error, **EapHostPeerQueryInteractiveUIInputFields** will return a return code other than **NULL**.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)