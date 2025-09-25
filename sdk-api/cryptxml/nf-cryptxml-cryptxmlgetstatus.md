# CryptXmlGetStatus function

## Description

The **CryptXmlGetStatus** function returns a [CRYPT_XML_STATUS](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_status) structure that contains status information about the object specified by the supplied handle.

## Parameters

### `hCryptXml`

A handle to a [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure, an array
of **CRYPT_XML_SIGNATURE** structures , a [CRYPT_XML_REFERENCE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_reference) structure, or a Manifest object about which to get status information.

### `pStatus`

A pointer to a [CRYPT_XML_STATUS](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_status) structure to receive the returned status information.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.