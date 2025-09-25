# EapMethodAuthenticatorInvokeConfigUI function

## Description

Defines a function that raises the EAP method's connection configuration user interface dialog box on the client.

**EapMethodAuthenticatorInvokeConfigUI** is a function prototype.

**EapHostAuthenticatorInvokeConfigUI** must be called on threads that have COM initialized for [Single Threaded Apartment](https://learn.microsoft.com/previous-versions/ms810413(v=msdn.10)). This can be achieved by calling COM API [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize); when the supplicant has finished with the STA thread [CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize) must be called before exiting.

## Parameters

### `pEapMethodType` [in]

A pointer to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `hwndParent` [in]

A handle to the parent window which will launch the connection configuration user interface dialog box.

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `pwszMachineName` [in]

The name of the target machine being configured. **NULL** means that the local machine is being configured.

### `dwSizeOfConfigIn` [in]

Specifies the size, in bytes, of *pConfigIn*. May be set to 0.

### `pConfigIn` [in]

A pointer to a byte buffer that contains configuration elements. The buffer is of size *dwSizeOfConfigIn*. This parameter can be **NULL** if *dwSizeOfConfigIn* is set to 0.

### `pdwSizeOfConfigOut` [out]

Specifies the size, in bytes, of the configuration data returned in *ppConfigOut*.

### `ppConfigOut` [out]

A pointer to a pointer to a byte buffer that contains updated configuration data from the user. After consuming the data, this memory must be freed by calling [EapMethodAuthenticatorFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreememory).

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)