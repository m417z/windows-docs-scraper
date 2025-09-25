# CRYPT_XML_BLOB structure

## Description

The **CRYPT_XML_BLOB** structure contains an arbitrary array of bytes.

## Members

### `dwCharset`

Specifies the character set used to encode the signature.

### `cbData`

The size, in bytes, of this structure.

Range: 0–CRYPT_XML_BLOB_MAX) (value is 0x7FFFFFF8)

### `pbData`

A pointer to encoded XML data.