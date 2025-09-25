# EapPeerInvokeInteractiveUI function

## Description

Raises a custom interactive user interface dialog for the EAP method on the client.

## Parameters

### `pEapType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `hwndParent` [in]

A handle to the parent window which will spawn the interactive user interface dialog.

### `dwSizeofUIContextData` [in]

The size, in bytes, of the user interface context data specified by *pUIContextData*.

### `pUIContextData` [in]

 A pointer to an opaque byte buffer that contains the context data used to create the user interface dialog.

### `pdwSizeOfDataFromInteractiveUI` [out]

A pointer to the size, in bytes, of the data returned in *ppDataFromInteractiveUI*.

### `ppDataFromInteractiveUI` [out]

A pointer to the address of an opaque byte buffer that contains data obtained from the interactive user interface dialog.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This API is used when EAPHost must obtain specific data from the user to continue.

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)