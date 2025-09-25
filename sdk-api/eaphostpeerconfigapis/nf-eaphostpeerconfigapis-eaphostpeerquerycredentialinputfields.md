# EapHostPeerQueryCredentialInputFields function

## Description

Allows the user to determine what kind of credentials are required by the methods to perform authentication in a Single-Sign-On (SSO) scenario.

## Parameters

### `hUserImpersonationToken` [in]

A handle to the user impersonation token to use in this session.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that identifies the EAP method the supplicant is to use.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwEapConnDataSize` [in]

The size, in bytes, of the connection data buffer provided in *pbEapConnData.*

### `pbEapConnData` [in]

Connection data used for the EAP method.

### `pEapConfigInputFieldArray` [out]

A pointer to an [EAP_METHOD_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_info_array) structure for installed EAP methods. The caller should free the inner pointers
using the function [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory), starting at the innermost pointer.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## Remarks

**EapHostPeerQueryCredentialInputFields** supports Single-Sign-On (SSO). This supplicant function, like [EapHostPeerQueryUserBlobFromCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerqueryuserblobfromcredentialinputfields), is used only in an SSO scenario.

**EapHostPeerQueryCredentialInputFields** obtains the fields to be displayed in the UI during the session. The input fields are obtained to display data entered by the user in the SSO UI. The [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure returned contains details on how to display the input fields.

After **EapHostPeerQueryCredentialInputFields**, EAPHost calls [EapHostPeerQueryUserBlobFromCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryuserblobfromcredentialinputfields).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)