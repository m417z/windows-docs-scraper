# CRYPT_XML_KEY_RSA_KEY_VALUE structure

## Description

The **CRYPT_XML_KEY_RSA_KEY_VALUE** structure defines an RSA key value. The **CRYPT_XML_KEY_RSA_KEY_VALUE** structure is used as element of the key value union in the [CRYPT_XML_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_value) structure.

## Members

### `Modulus`

A [CRYPT_XML_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_blob) structure that contains the [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) modulus data.

### `Exponent`

A [CRYPT_XML_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_data_blob) structure that contains the public key exponent data.