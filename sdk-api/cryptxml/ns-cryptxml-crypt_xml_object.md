# CRYPT_XML_OBJECT structure

## Description

The **CRYPT_XML_OBJECT** structure describes an **Object** element in the signature.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hObject`

The handle of the object.

### `wszId`

Optional. A pointer to a null-terminated wide character string that contains the value of the unique identifier attribute of the **Object** element.

### `wszMimeType`

Optional. A pointer to a null-terminated wide character string that contains the value of the MIME-type attribute of the **Object** element.

### `wszEncoding`

Optional. A pointer to a null-terminated wide character string that contains the value of the encoding method attribute of the **Object** element.

### `Manifest`

Optional. A [CRYPT_XML_REFERENCES](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_references) structure that specifies an array of references.

### `Encoded`

Optional. A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the XML part of the entire **Object** element.

**Note** This field is empty when the **Object** element does not contain
any elements.
Applications can use the **CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT** flag
to always receive an encoded **Object** element.