# CryptXmlOpenToEncode function

## Description

If **CryptXmlOpenToEncode** function opens an XML digital signature to encode and returns a handle of the opened **Signature** element. The handle encapsulates a document context with a single [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure and remains open until the [CryptXmlClose](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlclose) function is called.

## Parameters

### `pConfig` [in, optional]

The handle of the transform chain engine. If this parameter is **NULL**, then a default engine is used to apply transforms.

### `dwFlags`

A **DWORD** value that controls which CryptXML extensions are loaded and whether the XML is serialized. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_NO_SERIALIZE**<br><br>0x80000000 | Inhibit serialization.<br><br>**Note** Do not set this flag when multiple threads are accessing a CryptXml object. Serialization ensures mutual exclusion when two or more threads attempt to simultaneously accept a CryptXml object or memory. |
| **CRYPT_XML_FLAG_DISABLE_EXTENSIONS**<br><br>0x10000000 | Only default implementations for the signature and digest are used. When this flag is set, no other registered extensions are loaded. |

### `wszId` [in, optional]

A pointer to a null-terminated Unicode string that contains the **Id** attribute of the **Signature** element.
If this parameter is **NULL**, then a new GUID is generated. If this parameter is an empty string, then no **Id** attribute is produced.

### `rgProperty` [in]

A pointer to an array of [CRYPT_XML_PROPERTY](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_property) structures that specify additional properties.

### `cProperty` [in]

The number of elements in the array pointed to by the *rgProperty* parameter.

### `pEncoded` [in, optional]

A pointer to a [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the signature to encode.

### `phSignature` [optional]

The handle to the **Signature** element.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.