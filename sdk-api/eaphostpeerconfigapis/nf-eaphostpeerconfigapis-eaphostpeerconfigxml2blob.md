# EapHostPeerConfigXml2Blob function

## Description

 Converts XML into the configuration BLOB. When the supplicant starts authentication or calls [EapHostPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeconfigui), the supplicant calls **EapHostPeerConfigXml2Blob** to convert the XML configuration into a BLOB.

The XML data to be converted could originate from a **EapHostPeerConfigBlob2Xml** call, or the data could originate from a XML created by a system administrator or other XML author.

## Parameters

### `dwFlags` [in]

Not used. Set to 0.

### `pConfigDoc` [in]

Sends a pointer to the XML configuration to be converted.

### `pdwSizeOfConfigOut` [out]

A pointer to the size, in bytes, of the configuration BLOB.

### `ppConfigOut` [out]

A pointer to a pointer to a byte buffer that contains the configuration data converted from XML. The configuration data is created inside [EapHostConfig Schema](https://learn.microsoft.com/windows/win32/eaphost/eaphostconfigschema-schema) element. The buffer is of size *pdwSizeOfConfigOut*. After consuming the data, this memory must be freed by calling [EapHostPeerFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreememory).

### `pEapMethodType` [out]

A pointer to an [EAP_METHOD_TYPE](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_method_type) structure referred to in the XML document.

### `ppEapError` [out]

A pointer a pointer to an [EAP_ERROR](https://learn.microsoft.com/windows/desktop/api/eaptypes/ns-eaptypes-eap_error) structure that contains any errors raised by EAPHost during the execution of this function call. After consuming the error data, this memory must be freed by calling [EapHostPeerFreeErrorMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerfreeerrormemory).

## See also

[EAPHost Supplicant Configuration Functions](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-configuration-functions)

[EapHostPeerConfigXml2Blob](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerconfigxml2blob)

[EapHostPeerGetResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetresult)

[EapHostPeerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/eaphostpeerconfigapis/nf-eaphostpeerconfigapis-eaphostpeerinvokeconfigui)