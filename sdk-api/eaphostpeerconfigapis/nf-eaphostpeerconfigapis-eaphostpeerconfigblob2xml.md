# EapHostPeerConfigBlob2Xml function

## Description

Converts the configuration BLOB to XML.

The configuration BLOB is returned when the supplicant called one of the following methods.

* [EapHostPeerConfigXml2Blob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerconfigxml2blob)
* [EapHostPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeconfigui)
* [EapHostPeerGetResult](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ns-eaphostpeertypes-eaphostpeermethodresult) - via the [EapHostPeerMethodResult](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ns-eaphostpeertypes-eaphostpeermethodresult) structure

## Parameters

### `dwFlags` [in]

Not used. Set to 0.

### `eapMethodType` [in]

Refers to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure that is referred to in the XML document.

### `dwSizeOfConfigIn` [in]

The size, in bytes, of the configuration BLOB.

### `pConfigIn` [in]

A pointer to a buffer that contains the configuration BLOB to convert. The buffer is of size *dwSizeOfConfigIn*.

### `ppConfigDoc` [out]

A pointer to a pointer to an XML document that contains the converted configuration. If the EAP method does not support
the [EapHostConfig Schema](https://learn.microsoft.com/windows/win32/eaphost/eaphostconfigschema-schema) element.

### `ppEapError` [out]

A pointer to a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EapHostPeerConfigXml2Blob](https://learn.microsoft.com/windows/win32/eaphost/eaphostconfigschema-schema)

[EapHostPeerGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresult)

[EapHostPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeconfigui)