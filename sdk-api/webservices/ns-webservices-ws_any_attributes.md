# WS_ANY_ATTRIBUTES structure

## Description

This type is used to store a set of attributes
that have not been directly mapped to field of
a structure.

## Members

### `attributes`

An array of attributes. This field may
be **NULL** if attributeCount is zero.

### `attributeCount`

The number of attributes in the array.

## Remarks

This structure is typically used to preserve unknown attributes
when deserializing a structure.
See [WS_ANY_ATTRIBUTES_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) and [WS_ANY_ATTRIBUTES_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) for more
information.