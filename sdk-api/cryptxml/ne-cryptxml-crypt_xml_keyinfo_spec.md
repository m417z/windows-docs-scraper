# CRYPT_XML_KEYINFO_SPEC enumeration

## Description

The **CRYPT_XML_KEYINFO_SPEC** enumeration specifies values for the *dwKeyInfoSpec* parameter in the [CryptXmlSign](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlsign) function.

## Constants

### `CRYPT_XML_KEYINFO_SPEC_NONE:0`

The value of the **KeyInfo** member in the [CRYPT_XML_SIGNATURE](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_signature) structure is null.

### `CRYPT_XML_KEYINFO_SPEC_ENCODED:1`

The value of the encoded [CRYPT_XML_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_info) structure is specified in a [CRYPT_XML_BLOB](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_blob) structure pointed to in the *pvKeyInfoSpec* parameter.

### `CRYPT_XML_KEYINFO_SPEC_PARAM:2`

The members of the [CRYPT_XML_KEY_INFO](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_key_info) structure to be encoded are specified in a [CRYPT_XML_KEYINFO_PARAM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_keyinfo_param) structure pointed by the *pvKeyInfoSpec* parameter.