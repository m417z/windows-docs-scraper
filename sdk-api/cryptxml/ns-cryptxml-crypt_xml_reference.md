# CRYPT_XML_REFERENCE structure

## Description

The **CRYPT_XML_REFERENCE** structure contains information used to populate the **Reference** element.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hReference`

The handle of the **Reference** element.

### `wszId`

Optional. A pointer to a null-terminated Unicode string that contains the value of the **Id** attribute.

### `wszUri`

 A pointer to a null-terminated Unicode string that contains a **URI** attribute.

### `wszType`

A pointer to a null-terminated Unicode string that contains the value of the **Type** attribute.

### `DigestMethod`

A [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the digest method.

### `DigestValue`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/windows/win32/api/dpapi/ns-dpapi-crypt_integer_blob) structure that specifies the hash value.

### `cTransform`

The number of elements in the array pointed to by the **rgTransform** member.

### `rgTransform`

An array of [CRYPT_XML_TRANSFORM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_transform_info) structures that contain information about the transform applied to the signed data.