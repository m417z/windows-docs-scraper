# CRYPT_XML_X509DATA structure

## Description

The **CRYPT_XML_X509DATA** structure represents the sequence of choices in the **X509Data** element.

## Members

### `cX509Data`

The size, in bytes, of the buffer pointed to by the **rgX509Data** member.

### `rgX509Data`

A pointer to a [CRYPT_XML_X509DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/cryptxml/ns-cryptxml-crypt_xml_x509data_item) structure that contains data to encode.