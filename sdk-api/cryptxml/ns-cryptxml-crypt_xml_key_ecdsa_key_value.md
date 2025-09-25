# CRYPT_XML_KEY_ECDSA_KEY_VALUE structure

## Description

The **CRYPT_XML_KEY_ECDSA_KEY_VALUE** structure defines an Elliptic Curve Digital Signature Algorithm (ECDSA) key value. The **CRYPT_XML_KEY_ECDSA_KEY_VALUE** structure is used as an element of the key value union in the [CRYPT_XML_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_value) structure.

## Members

### `wszNamedCurve`

A pointer to a null-terminated Unicode string that contains the [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) of the named curve.

### `X`

Defines the X value of an ECDSA curve.

### `Y`

Defines the Y value of an ECDSA curve.

### `ExplicitPara`

A **CRYPT_XML_BLOB** value that defines the encoded parameters of an ECDSA curve.