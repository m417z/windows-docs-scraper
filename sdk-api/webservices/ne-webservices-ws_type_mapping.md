## Description

How a [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) maps to or from XML when serialized
or deserialized.

## Constants

### `WS_ELEMENT_TYPE_MAPPING:1`

This is used when reading or writing an element where the type
corresponds to the type of the element.
The definition of the type may include mappings to attributes,
text, or child elements of the element.

The following calling sequence is used when writing an element:

```
WsWriteStartElement(...)
WsWriteType(..., WS_ELEMENT_TYPE_MAPPING, ...)
WsWriteEndElement(...)
```

The following calling sequence is used when reading an element:

```
WsReadToStartElement(...)?
WsReadType(..., WS_ELEMENT_TYPE_MAPPING, ...)
```

### `WS_ATTRIBUTE_TYPE_MAPPING:2`

This is used when reading or writing the value of a single attribute. The definition
of the type must not require any mappings to attributes or child elements.

The following calling sequence is used when writing an attribute value.

```
WsWriteStartAttribute(...)
WsWriteType(..., WS_ATTRIBUTE_TYPE_MAPPING, ...)
WsWriteEndAttribute(...)
```

The following calling sequence is used when reading an attribute value.

```
WsFindAttribute(...)
WsReadStartAttribute(...)
WsReadType(..., WS_ATTRIBUTE_TYPE_MAPPING, ...)
WsReadEndAttribute(...)
```

### `WS_ELEMENT_CONTENT_TYPE_MAPPING:3`

This is used when the type corresponds to all or part of the
content (text and child elements) of an element.
The definition of the type may include mappings to text or child
elements, but must not include any attributes.

The following calling sequence is used when writing the contents
of an element:

```
WsWriteStartElement(...)
// Write attributes, if any
// Write other element content, if any
WsWriteType(..., WS_ELEMENT_CONTENT_TYPE_MAPPING, ...)
// Write other element content, if any
WsWriteEndElement(...)
```

The following calling sequence is used when reading the contents of
an element:

```
WsReadToStartElement(...)
// Read attributes, if any
WsReadStartElement(...)
// Read other element content, if any
WsReadType(..., WS_ELEMENT_CONTENT_TYPE_MAPPING, ...)
// Read other element content, if any
WsReadEndElement(...)
```

### `WS_ANY_ELEMENT_TYPE_MAPPING:4`

This is used when the type corresponds to the complete
element, including the name and namespace of the element.
The definition may include attributes and child elements
and text.

The following calling sequence is used when writing
an element:

```
WsWriteType(..., WS_ANY_ELEMENT_TYPE_MAPPING, ...)
```

The following calling sequence is used when reading the contents of
an element:

```
WsReadToStartElement(...)?
WsReadType(..., WS_ANY_ELEMENT_TYPE_MAPPING, ...)
```

## Remarks

See the documentation for each [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)
for which **WS_TYPE_MAPPING** values are supported.