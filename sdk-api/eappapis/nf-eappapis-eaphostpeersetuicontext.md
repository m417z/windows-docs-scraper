# EapHostPeerSetUIContext function

## Description

Provides a new or updated user interface context to the EAP peer method loaded on EAPHost after the UI has been raised. For more information about raising the UI, see [EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext).

**EapHostPeerSetUIContext** sets the UI context data that was received from a call to [EapHostPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeinteractiveui).

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSIONID** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionId* parameter in a previous call to [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession).

### `dwSizeOfUIContextData` [in]

The size, in bytes, of the user interface context data buffer provided in *pUIContextData*.

### `pUIContextData` [in]

A pointer to a byte buffer that contains the new supplicant UI context data to be set on EAPHost. The data is returned from the [EapHostPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeinteractiveui) OUT parameter.

### `pEapOutput` [out]

A pointer to an [EapHostPeerResponseAction](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerresponseaction) enumeration value that specifies the action code for the next step the supplicant must take as a response.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure. The address should be set to **NULL** before calling this function. If error data is available, a pointer to the address of an **EAP_ERROR** structure that contains any errors raised during the execution of this function call is received. After using the error data, free this memory by calling [EapHostPeerFreeEapError](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## See also

[EAPHost Supplicant Run-time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext)

[EapHostPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeinteractiveui)