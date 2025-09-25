# EapPeerGetIdentity function

## Description

Returns the user data and user identity after being called by EAPHost.

## Parameters

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwSizeofConnectionData` [in]

Specifies the size, in bytes, of the connection data buffer provided in *pConnectionData*

### `pConnectionData` [in]

A pointer to a byte buffer that contains the opaque configuration data BLOB.

### `dwSizeofUserData` [in]

Specifies the size, in bytes, of the user data buffer provided in *pUserData*.

### `pUserData` [in]

A pointer to the user data specific to this authentication used to pre-populate the user data.
When this API is called for the first time, or when a new authentication session starts, this parameter is **NULL**.
Otherwise, set this parameter to the **pUserData** member of the structure pointed to by the *ppResult* parameter received by **EapPeerGetResult**.

### `hTokenImpersonateUser` [in]

Specifies a handle to the impersonation token of the user being authenticated. This handle will be **NULL** when doing machine authentication. By using this handle an EAP method can impersonate the user for the purpose of obtaining user specific information such as user name, domain name and credentials.

### `pfInvokeUI` [out]

Returns **TRUE** if the user identity and user data blob aren't returned successfully, and the method seeks to collect the information from the user through the user interface dialog.

### `pdwSizeOfUserDataOut` [in, out]

Specifies the size, in bytes, of the *ppUserDataOut* buffer.

### `ppUserDataOut` [out]

A pointer to a pointer to the returned user data. The data is passed to [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession) as input *pUserData*.

### `ppwszIdentity` [out]

 A pointer to the returned user identity. The pointer will be included in the identity response packet and returned to the server.

### `ppEapError` [out]

A pointer to the pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)

[EapPeerInvokeIdentityUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeidentityui)