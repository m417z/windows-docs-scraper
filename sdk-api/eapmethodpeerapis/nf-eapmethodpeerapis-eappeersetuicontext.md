# EapPeerSetUIContext function

## Description

Provides a user interface context to the EAP method. This function is called after the UI has been raised through the [EapPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetuicontext) function.

## Parameters

### `sessionHandle` [in]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server. This handle is returned in the *pSessionHandle* parameter in a previous call to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession).

### `dwSizeOfUIContextData` [in]

A pointer to a value that specifies the size of the UI context data byte buffer provided in *pUIContextData*.

### `pUIContextData` [in]

A pointer to an address that contains a byte buffer with the new supplicant UI context data to set on EAPHost.

### `pEapOutput` [in]

 A pointer to an [EapPeerMethodOutput](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ns-eapauthenticatoractiondefine-eappeermethodoutput) structure that contains the output of the packet process operation.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)

[EapPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeergetuicontext)