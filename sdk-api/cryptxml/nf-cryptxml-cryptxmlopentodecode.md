# CryptXmlOpenToDecode function

## Description

The **CryptXmlOpenToDecode** function opens an XML digital signature to decode
and returns the handle of the document context that encapsulates a [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure.
The document context can include one or more **Signature** elements.

## Parameters

### `pConfig` [in, optional]

The handle of the transform chain engine.
If this parameter is **NULL**, then a default engine will be
used to apply transforms.

### `dwFlags`

A **DWORD** value that controls which CryptXML extensions are loaded and whether the XML is serialized. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_NO_SERIALIZE**<br><br>0x80000000 | Inhibit serialization.<br><br>**Important** Do not set this flag when multiple threads are accessing a CryptXml object. Serialization ensures mutual exclusion when two or more threads attempt to simultaneously accept a CryptXml object or memory. |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

### `rgProperty` [in]

A pointer to an array of [CRYPT_XML_PROPERTY](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_property) structures that contain additional properties.

### `cProperty`

The number of items in the array pointed to by the *rgProperty* parameter.

### `pEncoded` [in]

A pointer to [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the signature to decode.

### `phCryptXml`

The handle of a Document Context object. When you have finished using the handle, release it by passing it to the [CryptXmlClose](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlclose) function.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.