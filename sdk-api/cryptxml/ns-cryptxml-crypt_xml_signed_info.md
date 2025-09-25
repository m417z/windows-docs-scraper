# CRYPT_XML_SIGNED_INFO structure

## Description

The **CRYPT_XML_SIGNED_INFO** structure describes an XML encoded **SignedInfo** element.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `wszId`

Optional. A pointer to a null-terminated Unicode string that contains the **Id** attribute.

### `Canonicalization`

A [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the canonicalization algorithm.

### `SignatureMethod`

A [CRYPT_XML_ALGORITHM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_algorithm) structure that specifies the signature algorithm.

### `cReference`

The number of elements in the array pointed to by the **rgpReference** member.

### `rgpReference`

A pointer to an array of pointers to [CRYPT_XML_REFERENCE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_reference) structures that contain information that is encoded in **Reference** elements.

### `Encoded`

A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains the XML encoded **SignedInfo** element.