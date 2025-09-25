# CRYPT_XML_KEY_VALUE structure

## Description

The **CRYPT_XML_KEY_VALUE** structure contains a single [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that may be useful in validating the signature.

## Members

### `dwType`

Specifies the key value type.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_KEY_VALUE_TYPE_DSA**<br><br>0x00000001 | The key is a DSA key. |
| **CRYPT_XML_KEY_VALUE_TYPE_RSA**<br><br>0x00000002 | The key is an [RSA](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) key. |
| **CRYPT_XML_KEY_VALUE_TYPE_ECDSA**<br><br>0x00000003 | The key is an Elliptic Curve Digital Signature Algorithm (ECDSA) key. |
| **CRYPT_XML_KEY_VALUE_TYPE_CUSTOM**<br><br>0x00000004 | The key is a custom key type. |

### `DSAKeyValue`

A [CRYPT_XML_KEY_DSA_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_dsa_key_value) structure that contains [Digital Signature Algorithm](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DSA) key data.

### `RSAKeyValue`

A [CRYPT_XML_KEY_RSA_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_rsa_key_value) structure that contains RSA key data.

### `ECDSAKeyValue`

A [CRYPT_XML_KEY_ECDSA_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_ecdsa_key_value) structure that contains ECDSA key data.

### `Custom`

A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains custom key data.