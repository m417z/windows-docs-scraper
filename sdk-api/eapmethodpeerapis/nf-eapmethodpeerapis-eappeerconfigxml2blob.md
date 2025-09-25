# EapPeerConfigXml2Blob function

## Description

 Converts XML into the configuration BLOB.

## Parameters

### `dwFlags` [in]

A combination of [EAP flags](https://learn.microsoft.com/windows/win32/eaphost/eap-method-flags) that describe the EAP authentication session behavior. May be set to 0.

### `eapMethodType` [in]

An [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that contains vendor and author information about the EAP method used for authenticating the connection.

### `pConfigDoc` [in]

Sends a pointer to the XML configuration to be converted.

### `ppConfigOut` [out]

A pointer to a pointer to a byte buffer that contains the configuration data converted from XML. The configuration data is created inside the [EapHostConfig Schema](https://learn.microsoft.com/windows/win32/eaphost/eaphostconfigschema-schema) element. The buffer is of size *pdwSizeOfConfigOut*. After consuming the data, this memory must be freed by calling [EapPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreememory).

### `pdwSizeOfConfigOut` [out]

A pointer to the size, in bytes, of the configuration BLOB in *ppConfigBlob*.

### `ppEapError` [out]

A pointer to the address of an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eapmethodpeerapis/nf-eapmethodpeerapis-eappeerfreeerrormemory).

## See also

[EAPHost Peer Method Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eaphost-peer-method-configuration-functions)