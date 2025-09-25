# CRYPT_XML_PROPERTY_ID enumeration

## Description

The **CRYPT_XML_PROPERTY_ID** enumeration
specifies the type and usage of the XML property.

## Constants

### `CRYPT_XML_PROPERTY_MAX_HEAP_SIZE:1`

Specifies the maximum heap size, in bytes, that the XML layer can use.
This property is applied to intermediate buffers used to parse or construct XML parts.
By default, the limit is equal to **CRYPT_XML_BLOB_MAX**.

### `CRYPT_XML_PROPERTY_SIGNATURE_LOCATION:2`

Specifies the location in the XML document where the signature is to be created.

The following formats are supported:

#id

The Id attribute of the element to insert the signature.

/a/b/c

The absolute path of the element to insert the signature.

### `CRYPT_XML_PROPERTY_MAX_SIGNATURES:3`

Specifies the maximum number of **Signature** elements when parsing an XML document.
This property overrides the default **CRYPT_XML_SIGNATURES_MAX** value.

### `CRYPT_XML_PROPERTY_DOC_DECLARATION:4`

Specifies whether to write an XML document declaration. This property is used with the
[CryptXmlEncode](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlencode) function. The default property is **TRUE**.

### `CRYPT_XML_PROPERTY_XML_OUTPUT_CHARSET:5`

Specifies an encoding character set of XML fragments for custom elements. This property is used with the
[CryptXmlOpenToDecode](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlopentodecode) function.
The default character set is inherited from the opened document.

## Remarks

If a property value is defined as a pointer to data, then the pointer must be valid
for the entire period of the signature operation.