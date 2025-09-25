# EapPeerQueryUserBlobFromCredentialInputFields function

## Description

The **EapPeerQueryUserBlobFromCredentialInputFields** function defines the implementation of an EAP method function that obtains the user BLOB data provided in an interactive Single-Sign-On (SSO) UI raised on the supplicant.

## Parameters

### `hUserImpersonationToken` [in]

An impersonation token for the user whose credentials are to be requested and obtained.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `dwEapConnDataSize` [in]

The size of the EAP SSO configuration data pointed to by *pbEapConnData*, in bytes.

### `pbEapConnData` [in]

A pointer to an opaque byte buffer that contains the EAP SSO configuration data BLOB.

### `pEapConfigInputFieldArray` [in]

A pointer to an [EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array) structure that contains the input fields to display to the supplicant user. The **pwszData** fields in the individual [EAP_CONFIG_INPUT_FIELD_DATA](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_data) elements are initialized to **NULL**.

### `pdwUserBlobSize` [in, out]

A pointer to a buffer that contains the size, in bytes, of the opaque user configuration data BLOB in *ppUserBlob*.

### `ppbUserBlob` [in, out]

A pointer that contains the opaque user data BLOB.

### `ppEapError` [out]

 A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Remarks

**EapPeerQueryUserBlobFromCredentialInputFields** supports Single-Sign-On (SSO). This peer method function, like [EapPeerQueryCredentialInputFields](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerquerycredentialinputfields), is used only in an SSO scenario.

After **EapPeerQueryUserBlobFromCredentialInputFields**, EAPHost calls [EapPeerBeginSession](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerbeginsession). The supplicant uses the **EAP_FLAG_PRE_LOGON** flag in **EapHostPeerBeginSession** to indicate that EAPHost should provide SSO.

## See also

[EAP_CONFIG_INPUT_FIELD_ARRAY](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_config_input_field_array)

[SSO and PLAP](https://learn.microsoft.com/windows/win32/eaphost/understanding-sso-and-plap)