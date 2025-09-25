# CRYPT_XML_DATA_BLOB structure

## Description

The **CRYPT_XML_DATA_BLOB** structure contains XML encoded data.

## Members

### `cbData`

The size, in bytes, of the data buffer pointed to by the **pbData** member.

### `pbData`

A pointer to the XML data. The maximum length in the buffer cannot exceed **CRYPT_XML_BLOB_MAX** bytes.