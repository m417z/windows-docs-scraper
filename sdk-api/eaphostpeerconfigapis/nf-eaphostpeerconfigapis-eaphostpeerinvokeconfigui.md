# EapHostPeerInvokeConfigUI function

## Description

Starts the configuration user interface of the specified EAP method.

**EapHostPeerInvokeConfigUI** must be called on threads that have COM initialized for [Single Threaded Apartment](https://learn.microsoft.com/previous-versions/ms810413(v=msdn.10)) (STA). This can be achieved by calling COM API [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize); when the supplicant has finished with the STA thread [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) must be called before exiting.

## Parameters

### `hwndParent` [in]

The handle of the parent window under which configuration dialog appears.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the EAP method.

### `dwSizeOfConfigIn` [in]

The size of input configuration. May be set to 0 (zero).

### `pConfigIn` [in]

A pointer to a byte buffer that contains configuration elements. The buffer is of size *dwSizeOfConfigIn*. This parameter can be **NULL**, if *dwSizeOfConfigIn* is set to 0 (zero).

### `pdwSizeOfConfigOut` [out]

A pointer to a DWORD that specifies the size of the buffer pointed to by *ppConfigOut*.

### `ppConfigOut` [out]

A pointer to a pointer to a byte buffer that contains updated configuration data from the user. After consuming the data, this memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory).

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)