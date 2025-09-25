# EapPeerInvokeConfigUI function

## Description

Raises the EAP method's specific connection configuration user interface dialog on the client.

## Parameters

### `pEapType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `hwndParent` [in]

A handle to the parent window which will spawn the connection configuration user interface dialog.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeOfConnectionDataIn` [in]

Specifies the size, in bytes, of the *pConnectionDataIn* buffer.

### `pConnectionDataIn` [in]

A pointer to the connection data specific to this authentication used to pre-populate the configuration user interface.
When this API is called for the first time, or when a new authentication session starts, this parameter is **NULL**.

### `pdwSizeOfConnectionDataOut` [out]

Receives a pointer to the size, in bytes, of the *ppConnectionDataOut* parameter.

### `ppConnectionDataOut` [out]

Receives a pointer to a pointer that contains a byte buffer with the user-configured connection data.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)