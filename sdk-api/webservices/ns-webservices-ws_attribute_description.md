# WS_ATTRIBUTE_DESCRIPTION structure

## Description

Represents a mapping between a C data type and an XML attribute.

## Members

### `attributeLocalName`

The local name of the XML attribute.

### `attributeNs`

The namespace of the XML attribute.

### `type`

The type that corresponds to the XML attribute.

Not all types support being read and written as attributes. If the
documentation for the [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) indicates it supports
[WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping), then it can be used with this structure.

### `typeDescription`

Additional information about the type. Each type has a different description
structure. This may be **NULL**, depending on the [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).