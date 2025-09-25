# WS_FIELD_DESCRIPTION structure

## Description

Represents serialization information about a field within a structure.

## Members

### `mapping`

Identifies how the field maps to the XML. See [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for
the ways that the field can be exposed in the XML content.

### `localName`

The XML local name to use for the field.

This field is required, except in the following case, where it may be **NULL**.
If the mapping field is [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), then
this identifies the local name of the "wrapper" element that is the parent element
of the array item elements. Setting this field (and the ns field) to **NULL** will omit the wrapper element. The ns and localName fields must be either both
specified or both **NULL**.

### `ns`

The XML namespace to use for the field.

This field is required, except in the following case, where it may be **NULL**.
If the mapping field is [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), then
this identifies the namespace of the "wrapper" element that is the parent element
of the array item elements. Setting this field (and the localName field) to **NULL** will omit the wrapper element. The ns and localName fields must be either both
specified or both **NULL**.

### `type`

The type of the field. See [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) for a list of supported types.

### `typeDescription`

Additional information about the type. Each type has a different description
structure. This may be **NULL**, depending on the [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type).

### `offset`

The offset of the field within the containing structure.

### `options`

Additional flags for the field. See [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) for
a list of flags. If no flags are needed, this may be 0.

### `defaultValue`

Points to a default value for the field. This is used in the following instances:

* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) was specified, and the XML did not contain
  the value.
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) was specified.

If defaultValue is **NULL**, then it is the same as having a default value
of all zero's.

### `countOffset`

The structure offset of the ULONG field that represents the number of items in the array.

This field is used when using [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) or array types
([WS_CHAR_ARRAY_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type), **WS_UTF8_ARRAY_TYPE**, **WS_BYTE_ARRAY_TYPE**).
In other cases, it does not need to be specified (it can be 0).

### `itemLocalName`

The XML local name to use for the repeating elements when
using [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping).

In other cases this field does not need to be specified (it can be **NULL**).

### `itemNs`

The XML namespace to use for the repeating elements when
using [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping).

In other cases this field does not need to be specified (it can be **NULL**).

### `itemRange`

The minimum and maximum number of repeating elements
that may appear when using [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping),
**WS_REPEATING_ELEMENT_CHOICE_FIELD_MAPPING**,
or **WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING**.
If not specified (**NULL**), the minimum is 0, and the maximum is MAX ULONG.

In other cases this field does not need to be specified (it can be **NULL**).