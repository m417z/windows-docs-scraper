# WS_VOID_DESCRIPTION structure

## Description

Specifies information about a field which is neither serialized nor
deserialized.

This is used with [WS_VOID_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) and [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type description is only required when [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is not
being used.

## Members

### `size`

The size of the field.