# CRYPT_XML_SIGNATURE structure

## Description

The **CRYPT_XML_SIGNATURE** structure contains information used to populate the **Signature** element.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `hSignature`

The handle of the signature to encode.

### `wszId`

A pointer to a null-terminated Unicode string that contains the value of the **Id** attribute.

### `SignedInfo`

A [CRYPT_XML_SIGNED_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signed_info) structure that contains the canonicalization algorithm,
a signature algorithm, and one or more references.
The **SignedInfo** element can contain an optional ID attribute that will allow
the structure to be referenced by other signatures and objects.

### `SignatureValue`

A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains a cryptographic signature value used to populate the **Signature** element.

### `pKeyInfo`

Optional. A pointer to a [CRYPT_XML_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_info) structure that contains information that is encoded in the **KeyInfo** element.

### `cObject`

The number of items in the array pointed to by the **rgpObject** member.

### `rgpObject`

Optional. A pointer to an array of pointers to [CRYPT_XML_OBJECT](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_object) structures that contain information that is encoded in **Object** elements.