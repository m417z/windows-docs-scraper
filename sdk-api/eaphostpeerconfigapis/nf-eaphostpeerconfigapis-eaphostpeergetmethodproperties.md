# EapHostPeerGetMethodProperties function

## Description

The **EapHostPeerGetMethodProperties** function is used to retrieve the properties of an EAP method given the connection and user data.

## Parameters

### `dwVersion` [in]

The version number of the API. Set this parameter to zero.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the EAP method the supplicant is to use.

### `hUserImpersonationToken` [in]

A handle to the user impersonation token to use in this session.

### `dwEapConnDataSize` [in]

The size, in bytes, of the connection data buffer provided in *pbEapConnData*.

### `pbEapConnData` [in]

Connection data used for the EAP method. If set to **NULL**, the static property of the method, as configured in the registry, is returned.

### `dwUserDataSize` [in]

The size, in bytes, of the user data buffer provided in *pbUserData*.

### `pbUserData` [in]

A pointer to a byte buffer that contains the opaque user data BLOB. This parameter can be **NULL**.

### `pMethodPropertyArray` [out]

A pointer to the method properties array [EAP_METHOD_PROPERTY_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_property_array). Caller should free the inner pointers using [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory) starting
at the innermost pointer. The caller should free an **empvString** value only when the type is **empvtString**.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerfreeeaperror).

## Remarks

**EapHostPeerGetMethodProperties** allows the user to retrieve the properties of an EAP method through the EAPHost supplicant interface. The properties returned by this API may be different from properties returned by the [EapHostPeerGetMethods](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeergetmethods) function. The **EapHostPeerGetMethodProperties** function returns the properties of an EAP method for a specific connection and user data.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)