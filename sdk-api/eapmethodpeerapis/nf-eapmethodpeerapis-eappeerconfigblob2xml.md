# EapPeerConfigBlob2Xml function

## Description

Converts the configuration BLOB to XML. The configuration BLOB is returned in the *ppConnectionDataOut* parameter of the [EapPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerinvokeconfigui) function.

## Parameters

### `dwFlags` [in]

Not used. Set to 0.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `pConfigIn` [in]

A pointer to a buffer that contains the configuration BLOB to convert. The buffer is of size *dwSizeOfConfigIn*

### `dwSizeOfConfigIn` [in]

The size, in bytes, of the configuration BLOB.

### `ppConfigDoc` [out]

A pointer to a pointer to an XML document that contains the converted configuration. If the EAP method does not support
the [EapHostConfig Schema](https://learn.microsoft.com/windows/win32/eaphost/eaphostconfigschema-schema) configuration element.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)