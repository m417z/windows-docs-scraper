# EapHostPeerInvokeIdentityUI function

## Description

This function is called by tunnel methods to invoke the identity UI of the inner methods. This function returns the identity as well as credentials to use in order to start the authentication.

## Parameters

### `dwVersion` [in]

The version number of the API. Must be set to zero.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the type of EAP authentication to use for this session.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `hwndParent` [in]

Handle of the parent window under which the configuration dialog will show up.

### `dwSizeofConnectionData` [in]

Size of the buffer indicated by the *pConnectionData* parameter, in bytes.

### `pConnectionData` [in]

Pointer to configuration data that is used for the EAP method.

### `dwSizeofUserData` [in]

Size of the buffer indicated by the *pUserData* parameter, in bytes.

### `pUserData` [in]

Pointer to user credential information that pertains to this authentication.

### `pdwSizeOfUserDataOut` [in, out]

Size of the buffer set to receive the user data returned by the *ppUserDataOut* parameter, in bytes.

### `ppUserDataOut` [out]

A pointer to a pointer to a buffer that contains user data information returned by the method. After use, this memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory).

### `ppwszIdentity` [out]

A pointer to a NULL-terminated user identity string. After use, this memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory).

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future use.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)