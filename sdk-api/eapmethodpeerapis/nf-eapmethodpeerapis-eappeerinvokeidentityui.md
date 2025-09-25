# EapPeerInvokeIdentityUI function

## Description

Raises a custom interactive user interface dialog to obtain user identity information for the EAP method on the client.

## Parameters

### `pEapType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `hwndParent` [in]

A handle to the parent window which will spawn the interactive user interface dialog to obtain the identity data.

### `dwSizeOfConnectionData` [in]

The size, in bytes, of the user interface context data specified by *pUIContextData*.

### `pConnectionData` [in]

A pointer to an opaque byte buffer that contains the connection data.

### `dwSizeOfUserData` [out]

Specifies the size, in bytes, of the user identity data returned in *dwSizeOfUserData*.

### `pUserData` [in]

A pointer to the user data specific to this authentication used to pre-populate the user data.
When this API is called for the first time, or when a new authentication session starts, this parameter is **NULL**.
Otherwise, set this parameter to the **pUserData** member of the structure pointed to by the *ppResult* parameter received by **EapPeerGetResult**.

### `pdwSizeOfUserDataOut` [out]

Specifies the size, in bytes, of the *ppUserDataOut* buffer.

### `ppUserDataOut` [out]

A pointer to the pointer of the returned user data. The data is passed to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession) as input *pUserData*.

### `ppwszIdentity` [out]

 A pointer to the returned user identity. The pointer will be included in the identity response packet and returned to the server.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)

[EapPeerInvokeIdentityUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeidentityui)