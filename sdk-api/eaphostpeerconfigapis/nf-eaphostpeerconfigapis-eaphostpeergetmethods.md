# EapHostPeerGetMethods function

## Description

Enumerates all EAP methods installed and available for use, including legacy EAP Methods.

## Parameters

### `pEapMethodInfoArray` [out]

 A pointer to an [EAP_METHOD_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array) structure for installed EAP methods. The caller should free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)