# CryptXmlEncode function

## Description

The **CryptXmlEncode** function encodes signature data by using the supplied XML writer callback function.

## Parameters

### `hCryptXml` [in]

The handle of the object to be serialized. The handle can be of **Signature**, **Object**, or **Reference** types.

### `dwCharset`

A value of the [CRYPT_XML_CHARSET](https://learn.microsoft.com/windows/desktop/api/cryptxml/ne-cryptxml-crypt_xml_charset) enumeration that specifies the character set of the encoded XML.

### `rgProperty` [in]

A pointer to an array of [CRYPT_XML_PROPERTY](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_property) structures that contain additional properties.

### `cProperty` [in]

A **ULONG** value that specifies the number of entries in the array pointed to by the *rgProperty* parameter.

### `pvCallbackState` [in, out]

A pointer to an application defined argument that is passed to the XML writer callback function pointed to by the *pfnWrite* parameter.

### `pfnWrite` [in]

An XML writer callback function to receive the application defined argument pointed to by the *pvCallbackState* parameter.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.