# CRYPT_XML_TRANSFORM_CHAIN_CONFIG structure

## Description

The **CRYPT_XML_TRANSFORM_CHAIN_CONFIG** structure contains application defined transforms that are allowed for use in the XML digital signature.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `cTransformInfo`

The number of elements in the array pointed to by the **rgpTransformInfo** member.

### `rgpTransformInfo`

A pointer to an array of pointers to [CRYPT_XML_TRANSFORM_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_transform_info) structures that contain the transform parameters.