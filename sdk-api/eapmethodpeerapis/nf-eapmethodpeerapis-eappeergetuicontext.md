# EapPeerGetUIContext function

## Description

Obtains the user interface context from the EAP method. This function is always followed by the [EapPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeinteractiveui) function, which is followed by the [EapPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetuicontext) function.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

### `pdwSizeOfUIContextData` [out]

A pointer to a value that specifies the size of the user interface context data byte buffer returned in *ppUIContextData*.

### `ppUIContextData` [out]

A pointer to an address that contains a byte buffer with the supplicant user interface context data from EAPHost.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

**EapPeerGetUIContext** is called by EAPHost when a prior call indicates that a user interface context is available.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)

[EapPeerInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeinteractiveui)

[EapPeerSetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeersetuicontext)