# CryptXmlAddObject function

## Description

The **CryptXmlAddObject** function adds the **Object** element to the Signature in the Document Context opened for encoding.

## Parameters

### `hSignatureOrObject` [in]

The handle of a Signature returned by the [CryptXmlOpenToEncode](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlopentoencode) function or the handle of a Reference returned by the [CryptXmlCreateReference](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlcreatereference) function with the **CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT** flag set.

### `dwFlags`

Specifies flags that control the manner in which the object is added.

Currently defined *dwFlags* values are shown in the following table .

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_ADD_OBJECT_CREATE_REFERENCE** | When set, an in-memory copy of the XML part is created and included in the **Object** element. |

### `rgProperty` [in, optional]

A pointer to a [CRYPT_XML_PROPERTY](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_property) structure that specifies additional properties used to decode the **Object** element.

### `cProperty` [in]

The number of elements in the array pointed to by the *rgProperty* property.

### `pEncoded` [in]

A pointer to a [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the **Object** element.

### `ppObject` [out, optional]

A pointer to a pointer to a [CRYPT_XML_OBJECT](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_object) structure to receive the decoded structure.
This parameter must be **NULL** when the *hSignatureOrObject* parameter contains a handle to the Object.

## Return value

If the function succeeds, the function returns zero.

If the function fails, it returns an **HRESULT** value that indicates the error.

## Remarks

 When the *hSignatureOrObject* parameter specifies a handle to a Reference returned
by the [CryptXmlCreateReference](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlcreatereference) function, the *pEncoded* parameter specifies XML content that is included
in the **Object** node after the optional **Manifest** element.
The pointer contained in the *pEncoded* parameter must be valid until the signature is complete.
Otherwise, use the **CRYPT_XML_FLAG_ADD_OBJECT_CREATE_COPY** flag to create an in-memory copy.