# WS_XML_BUFFER_PROPERTY structure

## Description

Specifies an XML buffer–specific setting.

## Members

### `id`

Identifies the [WS_XML_BUFFER_PROPERTY_ID](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_property_id).

### `value`

A pointer to the value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize`

The size in bytes of the memory pointed to by value.