# EapPeerQueryCredentialInputFields function

## Description

Defines the implementation of an EAP method-specific function that obtains the EAP Single-Sign-On (SSO) credential input fields for an EAP method.

## Parameters

### `hUserImpersonationToken` [in]

An impersonation token for the user whose credentials are to be requested and obtained.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwEapConnDataSize` [in]

The size of the EAP SSO configuration byte data pointed to by *pbEapConnData*, in bytes.

### `pbEapConnData` [in]

A Pointer to an opaque byte buffer that contains the EAP configuration data BLOB.

### `pEapConfigFieldsArray` [out]

A Pointer to an [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure that contains the input fields to display to the supplicant user. The **pwszData** fields in the individual [EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data) elements are initialized to **NULL**.

### `ppEapError` [out]

 A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

**EapPeerQueryCredentialInputFields** supports SSO. This peer method function, like [EapPeerQueryUserBlobFromCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerqueryuserblobfromcredentialinputfields), is used only in an SSO scenario.

 The EAP method-specific implementation of this function is called by EAPHost whenever a supplicant application calls [EapHostPeerQueryCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerquerycredentialinputfields). The implementer of this function is responsible for ensuring that the [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) returned by this function contains input field definitions for each piece of credential data the EAP methods will request from the supplicant user.

## See also

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)