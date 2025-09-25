# EapHostPeerGetIdentity function

## Description

This function is called by tunnel methods to request identity information from the inner methods. This function returns the identity and user credential information.

## Parameters

### `dwVersion` [in]

The version number of the API. Must be set to zero.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the type of EAP authentication to use for this session.

### `dwSizeofConnectionData` [in]

Size of the buffer indicated by the *pConnectionData* parameter, in bytes.

### `pConnectionData` [in]

Pointer to configuration data that is used for the EAP method.

### `dwSizeofUserData` [in]

Size of the buffer indicated by the *pUserData* parameter, in bytes.

### `pUserData` [in]

Pointer to user credential information that pertains to this authentication session.

### `hTokenImpersonateUser` [in]

Impersonation token for a logged-on user to collect user-related information.

### `pfInvokeUI` [out]

Returns **TRUE** if the user identity and user data blob aren't returned successfully, and the method seeks to collect the information from the user through the user interface dialog.

### `pdwSizeOfUserDataOut` [in, out]

Size of the buffer indicated by the *ppUserDataOut* parameter, in bytes.

### `ppUserDataOut` [out]

User data information returned by the method. After use, this memory must be freed by calling [EapHostPeerFreeRuntimeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeruntimememory).

### `ppwszIdentity` [out]

A pointer to a NULL-terminated user identity string. After use, this memory must be freed by calling [EapHostPeerFreeRuntimeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeruntimememory).

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

### `ppvReserved` [in, out]

Reserved for future use

## See also

[EAPHost Supplicant Run-Time Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-run-time-functions)

[EapHostPeerGetUIContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetuicontext)