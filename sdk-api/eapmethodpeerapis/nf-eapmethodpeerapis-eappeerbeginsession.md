# EapPeerBeginSession function

## Description

Starts an EAP authentication session on the peer EAPHost using the EAP method.

## Parameters

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the new EAP authentication session behavior.

### `pAttributeArray` [in]

A pointer to an [EAP_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_attributes) array structure that specifies the EAP attributes of the entity to authenticate.

### `hTokenImpersonateUser` [in]

Specifies a handle to the user impersonation token to use in this session.

### `dwSizeofConnectionData` [in]

Specifies the size, in bytes, of the connection data buffer provided in *pConnectionData*.

### `pConnectionData` [in]

Connection data specific to this method used to decide the user data returned from this API, where the user data depends on certain connection data configuration. When this parameter is **NULL** the method implementation should use default values for connection.

### `dwSizeofUserData` [in]

Specifies the size in bytes of the user data buffer provided in *pUserData*.

### `pUserData` [in]

A pointer to a byte buffer that contains the opaque user data BLOB.

### `dwMaxSendPacketSize` [in]

Specifies the maximum size in bytes of an EAP packet sent during the session. If the method needs to
send a packet larger than the maximum size, the method must accommodate fragmentation and reassembly.

### `pSessionHandle` [out]

A pointer to an **EAP_SESSION_HANDLE** structure that contains the unique handle for this EAP authentication session on the EAPHost server.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Peer Method Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-run-time-functions)

[EapPeerEndSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerendsession)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)