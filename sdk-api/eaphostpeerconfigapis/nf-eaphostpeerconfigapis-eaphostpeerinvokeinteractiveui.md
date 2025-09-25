# EapHostPeerInvokeInteractiveUI function

## Description

Raises an interactive user interface used to get credentials from the user. For example, this function can be used to raise a UI that retrieves credentials from a smart card, and prompts the user to enter the corresponding PIN.

**EapHostPeerInvokeInteractiveUI** must be called on threads that have COM initialized for [Single Threaded Apartment](https://learn.microsoft.com/previous-versions/ms810413(v=msdn.10)). This can be achieved by calling COM API [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize); when the supplicant has finished with the STA thread [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) must be called before exiting.

## Parameters

### `hwndParent` [in]

The handle of the parent window under which configuration dialog appears.

### `dwSizeofUIContextData` [in]

The size, in bytes, of the buffer pointed to by the *pUIContextData* parameter.

### `pUIContextData` [in]

A pointer to a buffer that contains the supplicant UI context data from EAPHost. The context data is returned by [EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext). The buffer is of size *dwSizeOfUIContextData*.

### `pdwSizeOfDataFromInteractiveUI` [out]

A pointer to a DWORD that represents the size, in bytes, of the buffer pointed to by the *ppDataFromInteractiveUI* parameter.

### `ppDataFromInteractiveUI` [out]

A pointer to a pointer to a byte buffer that contains data from the interactive UI necessary for authentication to continue. The parameter *ppDataFromInteractiveUI* should be passed to [EapHostPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeersetuicontext) as the IN parameter *pUIContextData*. After consuming the data, this memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory). The buffer is of size *pdwSizeofDataFromInteractiveUI*.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## Remarks

The supplicant should call [EAP_E_EAPHOST_METHOD_OPERATION_NOT_SUPPORTED](https://learn.microsoft.com/windows/win32/eaphost/eap-related-error-and-information-constants) is returned, the supplicant should resort to the traditional model of invoking method interactive UI by calling **EapHostPeerInvokeInteractiveUI**.

If called,**EapHostPeerInvokeInteractiveUI** raises the user interface for the EAP method after the supplicant calls [EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext). This occurs when a call to [EapHostPeerProcessReceivedPacket](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerprocessreceivedpacket)
returns the **EapHostPeerResponseInvokeUi** action code. **EapHostPeerGetUIContext** returns UI context that
the supplicant then passes to **EapHostPeerInvokeInteractiveUI** to raise the UI.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext)

[EapHostPeerQueryInteractiveUIInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryinteractiveuiinputfields)

[EapHostPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeersetuicontext)