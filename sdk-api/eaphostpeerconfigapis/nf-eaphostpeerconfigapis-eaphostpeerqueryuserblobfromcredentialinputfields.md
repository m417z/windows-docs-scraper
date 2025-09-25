# EapHostPeerQueryUserBlobFromCredentialInputFields function

## Description

The **EapHostPeerQueryUserBlobFromCredentialInputFields** function obtains
a credential BLOB that can be used to start authentication from user input received from the Single-Sign-On (SSO) UI.

## Parameters

### `hUserImpersonationToken` [in]

A handle to the user impersonation token to use in this session.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that specifies the type of EAP authentication to use for this session.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwEapConnDataSize` [in]

The size, in bytes, of the connection data buffer provided in *pConnectionData.*

### `pbEapConnData` [in]

Connection data used for the EAP method.

### `pEapConfigInputFieldArray` [in]

A pointer to an [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure the contains the UI input field data. The caller should free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer.

### `pdwUserBlobSize` [in, out]

A pointer to a DWORD that specifies the size, in bytes, of the buffer pointed to by *ppbUserBlob*. If this value is not set to zero, then a pointer to a buffer of the size specified in this parameter must be supplied to *ppbUserBlob*.

### `ppbUserBlob` [in, out]

A pointer to the credential BLOB that can be used in authentication.
Memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory). If a non-null value is supplied for this parameter (meaning that an existing data BLOB is passed to it), the supplied data BLOB will be updated and returned in this parameter. If a non-NULL BLOB value is supplied, the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function should be used.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## Remarks

**EapHostPeerQueryUserBlobFromCredentialInputFields** supports SSO. This supplicant function, like [EapHostPeerQueryCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerquerycredentialinputfields), is used only in an SSO scenario.

After **EapHostPeerQueryUserBlobFromCredentialInputFields**, EAPHost calls [EapHostPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeerbeginsession). The supplicant uses the **EAP_FLAG_PRE_LOGON** flag in **EapHostPeerBeginSession** to indicate that EAPHost should provide SSO.

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)