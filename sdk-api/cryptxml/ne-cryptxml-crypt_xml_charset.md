# CRYPT_XML_CHARSET enumeration

## Description

The **CRYPT_XML_CHARSET** enumeration is used to specify the character set used in the XML.

## Constants

### `CRYPT_XML_CHARSET_AUTO:0`

This value is only supported in the [CryptXmlOpenToDecode](https://learn.microsoft.com/windows/desktop/api/cryptxml/nf-cryptxml-cryptxmlopentodecode) function. The encoded XML character set is determined by the parser and is based on the XML declaration or the best guess on the characters.

### `CRYPT_XML_CHARSET_UTF8:1`

Specifies the UTF-8 character set.

### `CRYPT_XML_CHARSET_UTF16LE:2`

Specifies the UTF-16 little-endian character set.

### `CRYPT_XML_CHARSET_UTF16BE:3`

Specifies the UTF-16 big-endian character set.