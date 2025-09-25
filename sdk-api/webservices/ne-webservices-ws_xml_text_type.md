# WS_XML_TEXT_TYPE enumeration

## Description

The type of [WS_XML_TEXT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_text) structure.

## Constants

### `WS_XML_TEXT_TYPE_UTF8:1`

Characters encoded as UTF-8 bytes.

### `WS_XML_TEXT_TYPE_UTF16:2`

Characters encoded as UTF-16 bytes.

### `WS_XML_TEXT_TYPE_BASE64:3`

Bytes that represent base64 encoded text.

### `WS_XML_TEXT_TYPE_BOOL:4`

A Boolean value that represents the text "true" or "false"

### `WS_XML_TEXT_TYPE_INT32:5`

A signed 32 bit integer value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_INT64:6`

A signed 64 bit integer value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_UINT64:7`

An unsigned 64 bit integer value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_FLOAT:8`

An 4 byte floating point value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_DOUBLE:9`

An 8 byte floating point value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_DECIMAL:10`

A 12 byte fixed point value that represents the text of the value as base 10 characters.

### `WS_XML_TEXT_TYPE_GUID:11`

A GUID that represents the text "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx".

### `WS_XML_TEXT_TYPE_UNIQUE_ID:12`

A GUID that represents the text "urn:uuid:xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx".

### `WS_XML_TEXT_TYPE_DATETIME:13`

A datetime.

### `WS_XML_TEXT_TYPE_TIMESPAN:14`

A timespan.

### `WS_XML_TEXT_TYPE_QNAME:15`

A qualified name.

### `WS_XML_TEXT_TYPE_LIST:16`

A list of values that represent their text forms separated by a single whitespace character.