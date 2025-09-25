# EapPeerGetConfigBlobAndUserBlob function

## Description

The **EapPeerGetConfigBlobAndUserBlob** method allows EAP method developers to provide the various connection properties and user properties supported by the method. EAPHost invokes this function to create the connection property and user property of the EAP method.

## Parameters

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior.

### `eapMethodType` [in]

The [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `eapCredential` [in]

An [EapCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcredential) structure that contains the credential type and the appropriate credentials.

### `pdwConfigBlobSize` [out]

Receives a pointer to the size, in bytes, of the *ppConfigBlob* parameter.

### `ppConfigBlob` [out]

Receives a pointer to a pointer that contains a byte buffer with configured connection data.

### `pdwUserBlobSize` [out]

Receives a pointer to the size, in bytes, of the *ppUserBlob* parameter.

### `ppUserBlob` [out]

Receives a pointer to a pointer that contains a byte buffer with the methods' user data.

### `ppEapError` [out]

 A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## Return value

This function should return **ERROR_SUCCESS** when it is able to generate the correct connection and user blob. In all other cases, it returns the appropriate windows error.

## Remarks

This call is performed by a peer-based EAPHost using a function pointer to this API. This API must be implemented on the EAP method loaded by EAPHost, and must strictly conform to the syntax and parameter types specified in the documentation.

## See also

[EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags)

[EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error)

[EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type)

[EapCredential](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eapcredential)

[EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory)