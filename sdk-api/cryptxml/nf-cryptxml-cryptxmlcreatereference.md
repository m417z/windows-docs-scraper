# CryptXmlCreateReference function

## Description

The **CryptXmlCreateReference** function creates a reference to an XML signature.

## Parameters

### `hCryptXml` [in]

The handle of the XML signature.

### `dwFlags`

Specifies flags that affect how the reference is created.

Currently defined *dwFlags* values are shown in the following table.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT**<br><br>0x00000001 | Set this flag to create an **Object** node and add it to the **Signature** element. A reference to the **Object** node is created in the **SignedInfo** element.<br><br>The returned handle is an encapsulated **Object** node and can be used in subsequent calls to the **CryptXmlCreateReference** function to create references in the **Manifest** node. |

### `wszId` [in, optional]

 A pointer to a **null**-terminated Unicode string that contains the value of the ID attribute of the **Reference** element of the signature.
If this parameter is **NULL**, then the **ID** attribute is not created.
If this parameter is an empty string, then the **ID** attribute with empty
value is created.

### `wszURI` [in, optional]

A pointer to a **null**-terminated Unicode string that contains the value of the URI attribute of the **Reference** element of the signature.
If this parameter is an empty string,
then the URI attribute with an empty value is created.

### `wszType` [in, optional]

A pointer to a **null**-terminated Unicode string that contains the value of the Type attribute of the **Reference** element of the signature.
The processing engine does not check or use this attribute.

### `pDigestMethod` [in]

A pointer to a [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that contains the digest method.

### `cTransform`

The number of elements in the array pointed to by the *rgTransform* parameter.

### `rgTransform` [in]

A pointer to an ordered array of [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structures that contain transform algorithms to be applied to
the reference data before the digest calculation.

### `phReference` [out]

A pointer to a reference handle.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.