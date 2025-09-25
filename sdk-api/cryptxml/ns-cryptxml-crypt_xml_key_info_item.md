# CRYPT_XML_KEY_INFO_ITEM structure

## Description

The **CRYPT_XML_KEY_INFO_ITEM** structure encapsulates key information data that corresponds to a **KeyInfo** element. The **KeyInfo** element enables
the recipient to obtain the key needed to validate the signature.

## Members

### `dwType`

Specifies the key information type encapsulated in this structure.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPT_XML_KEYINFO_TYPE_KEYNAME**<br><br>0x00000001 | The structure specifies a key name. |
| **CRYPT_XML_KEYINFO_TYPE_KEYVALUE**<br><br>0x00000002 | The structure specifies the key value. |
| **CRYPT_XML_KEYINFO_TYPE_RETRIEVAL**<br><br>0x00000003 | The structure specifies an XML encoded element that contains the key retrieval method. |
| **CRYPT_XML_KEYINFO_TYPE_X509DATA**<br><br>0x00000004 | The structure specifies [X.509](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) data that contains the key information. |
| **CRYPT_XML_KEYINFO_TYPE_CUSTOM**<br><br>0x00000005 | The structure specifies user defined information about the key information. |

### `wszKeyName`

A pointer to a null-terminated wide character string that contains the name of the key to retrieve.

### `KeyValue`

A [CRYPT_XML_KEY_VALUE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_value) structure that contains the key value.

### `RetrievalMethod`

A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains XML encoded information about the key retrieval method.

### `X509Data`

A [CRYPT_XML_X509DATA](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_x509data) structure that contains X.509 data that contains the key.

### `Custom`

A [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure that contains user defined key information.