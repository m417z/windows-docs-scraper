# EapPeerQueryUIBlobFromInteractiveUIInputFields function

## Description

The **EapPeerQueryUIBlobFromInteractiveUIInputFields** function converts user information into a user BLOB that can be consumed by EAPHost run-time functions.

## Parameters

### `dwVersion` [in]

The version number of the API. Must be set to zero.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeofUIContextData` [in]

The size of the context data in the *pUIContextData* parameter, in bytes.

### `pUIContextData` [in]

A pointer to a BLOB that contains UI context data, represented as inner pointers to field data. The supplicant obtained these inner pointers from EAPHost run-time functions.

### `pEapInteractiveUIData` [in]

Pointer that receives an [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data) structure that contains configuration information for interactive user interface components raised on an EAP supplicant.

### `pdwSizeOfDataFromInteractiveUI` [out]

A pointer to a DWORD that specifies the size of the buffer pointed to by the *ppDataFromInteractiveUI* parameter, in bytes. If this value is not set to 0, then a pointer to a buffer of the size specified in this parameter must be supplied in the *ppDataFromInteractiveUI* parameter.

### `ppDataFromInteractiveUI` [out]

 A pointer that receives a credentials BLOB that can be used in authentication.
The caller should free the inner pointers
using the function [EapPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreememory), starting at the innermost pointer. If a non-NULL value is supplied for this parameter, meaning that an existing data BLOB is passed to it, the supplied data BLOB will be updated and returned in this parameter.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future use. This parameter must be set to 0.

## Remarks

[Peer Method API Call Sequence](https://learn.microsoft.com/windows/win32/eaphost/peer-method-api-call-sequence).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)