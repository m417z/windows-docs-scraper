# CRYPT_XML_PROPERTY structure

## Description

The **CRYPT_XML_PROPERTY** structure contains information about a CryptXML property.

## Members

### `dwPropId`

A value of the [CRYPT_XML_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/cryptxml/ne-cryptxml-crypt_xml_property_id) enumeration that specifies the property type.

### `pvValue`

A pointer to a buffer that contains the property value.

### `cbValue`

The size, in bytes, of the property value buffer pointed to by the **pvValue** member.