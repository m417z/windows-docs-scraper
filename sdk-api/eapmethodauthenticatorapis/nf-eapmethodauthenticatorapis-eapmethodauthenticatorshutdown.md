# EapMethodAuthenticatorShutdown function

## Description

Shuts down the EAP authenticator method and prepares to unload it from the server EAPHost.

**EapMethodAuthenticatorShutdown** is a function prototype.

## Parameters

### `pEapType` [in]

A pointer to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) enumeration that specifies the type of EAP authentication used in the session.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by passing a pointer to the error data to [EapMethodAuthenticatorFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodauthenticatorapis/nf-eapmethodauthenticatorapis-eapmethodauthenticatorfreeerrormemory).

## Remarks

This call is performed by a authenticator-based EAPHost using a function pointer to this API. This API must be implemented on the EAP authenticator method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAPHost Authenticator Method Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-authenticator-method-functions)