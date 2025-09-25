# CRYPT_XML_KEY_DSA_KEY_VALUE structure

## Description

The **CRYPT_XML_KEY_DSA_KEY_VALUE** structure defines a [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) key value. The **CRYPT_XML_KEY_DSA_KEY_VALUE** structure is used as an element of the key value union in the [CRYPT_XML_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_value) structure.

## Members

### `P`

Defines the P part of the DSA key.

### `Q`

Defines the Q part of the DSA key.

### `G`

Defines the G part of the DSA key.

### `Y`

Defines the Y part of the DSA key.

### `J`

Defines the J part of the DSA key.

### `Seed`

The seed value, in big-endian format.

### `Counter`

The count value, in big-endian format.