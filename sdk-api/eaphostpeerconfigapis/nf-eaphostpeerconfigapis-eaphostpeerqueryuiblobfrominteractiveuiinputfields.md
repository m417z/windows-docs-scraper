# EapHostPeerQueryUIBlobFromInteractiveUIInputFields function

## Description

The **EapHostPeerQueryUIBlobFromInteractiveUIInputFields** function converts user information into a user BLOB that can be consumed by EAPHost run-time functions.

## Parameters

### `dwVersion` [in]

The version number of the API.

| Value | Meaning |
| --- | --- |
| **EAPHOST_PEER_API_VERSION**<br><br>1 | The version of the EAPHost Peer APIs. |

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeofUIContextData` [in]

The size of the context data in *pUIContextData*, in bytes.

### `pUIContextData` [in]

Pointer to a BLOB that contains UI context data, represented as inner pointers to field data. These inner pointers must be freed by passing them to [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting with the innermost pointer.

### `pEapInteractiveUIData` [in]

Pointer that receives an [EAP_INTERACTIVE_UI_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_interactive_ui_data) structure that contains configuration information for interactive UI components raised on an EAP supplicant.

### `pdwSizeOfDataFromInteractiveUI` [in, out]

A pointer to a DWORD that specifies the size, in bytes, of the buffer pointed to by *ppDataFromInteractiveUI*. If this value is not set to zero, then a pointer to a buffer of the size specified in this parameter must be supplied to *ppDataFromInteractiveUI*.

### `ppDataFromInteractiveUI` [in, out]

 Pointer that receives a credentials BLOB that can be used in authentication.
The caller should free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer. If a non-null value is supplied for this parameter (meaning that an existing data BLOB is passed to it), the supplied data BLOB will be updated and returned in this parameter. If a non-NULL BLOB value is supplied, the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function should be used.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future use. This parameter must be set to 0.

## Remarks

[Supplicant API Call Sequence](https://learn.microsoft.com/windows/win32/eaphost/supplicant-api-call-sequence).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)