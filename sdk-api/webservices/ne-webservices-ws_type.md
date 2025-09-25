## Description

The types supported for serialization.

## Constants

### `WS_BOOL_TYPE:0`

Used when serializing a **BOOL** value.

The [WS_BOOL_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_bool_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_INT8_TYPE:1`

Used when serializing a signed 8-bit integer (**char**).

The [WS_INT8_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_int8_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_INT16_TYPE:2`

Used when serializing a signed 16-bit integer (**short**).

The [WS_INT16_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_int16_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_INT32_TYPE:3`

Used when serializing a signed 32-bit integer.

The [WS_INT32_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_int32_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_INT64_TYPE:4`

Used when serializing a signed 64-bit integer.

The [WS_INT64_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_int64_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UINT8_TYPE:5`

Used when serializing an unsigned 8-bit integer (**BYTE**).

The [WS_UINT8_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint8_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UINT16_TYPE:6`

Used when serializing an unsigned 16-bit integer.

The [WS_UINT16_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint16_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UINT32_TYPE:7`

Used when serializing an unsigned 32-bit integer.

The [WS_UINT32_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint32_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UINT64_TYPE:8`

Used when serializing an unsigned 64-bit integer.

The [WS_UINT64_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_uint64_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_FLOAT_TYPE:9`

Used when serializing a **float**.

The [WS_FLOAT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_float_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_DOUBLE_TYPE:10`

Used when serializing a **double**.

The [WS_DOUBLE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_double_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_DECIMAL_TYPE:11`

Used when serializing a **DECIMAL**.

The [WS_DECIMAL_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_decimal_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_DATETIME_TYPE:12`

Used when serializing a [WS_DATETIME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime).

The [WS_DATETIME_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_datetime_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_TIMESPAN_TYPE:13`

Used when serializing a [WS_TIMESPAN](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_timespan).

The [WS_TIMESPAN_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_timespan_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_GUID_TYPE:14`

Used when serializing a **GUID**.

The [WS_GUID_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_guid_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UNIQUE_ID_TYPE:15`

Used when serializing a [WS_UNIQUE_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_unique_id).

The [WS_UNIQUE_ID_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_unique_id_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_STRING_TYPE:16`

Used when serializing a [WS_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string).

The [WS_STRING_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_string_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_XML_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented by setting the chars field to **NULL** and specifying a length of 0.
A nil string is distinguished from an empty string based on whether or not the chars field
is **NULL** when the length is zero.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_WSZ_TYPE:17`

Used when serializing a zero-terminated **WCHAR***.

The [WS_WSZ_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_wsz_description) type description can optionally be
specified for this type in order to constrain the allowed values.

Deserialization will return an error if the wire form of the string
contains an embedded zero.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_XML_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.
The default value should point to the address of a WCHAR*, and
the size should be sizeof(WCHAR*).

### `WS_BYTES_TYPE:18`

Used when serializing a [WS_BYTES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_bytes).

The [WS_BYTES_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_bytes_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented by setting the bytes field to **NULL** and specifying a length of 0.
A nil array is distinguished from an empty array based on whether or not the bytes field is
**NULL** when the length is zero.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_XML_STRING_TYPE:19`

Used when serializing a [WS_XML_STRING](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string).

The [WS_XML_STRING_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_string_description) type description can optionally be
specified for this type in order to constrain the allowed values.

Embedded zeros are allowed in the array of utf8 bytes.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented by setting the bytes field to **NULL** and specifying a length of 0.
A nil string is distinguished from an empty string based on whether or not the bytes field is
**NULL** when the length is zero.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_XML_QNAME_TYPE:20`

Used when serializing a [WS_XML_QNAME](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_qname).

The [WS_XML_QNAME_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_xml_qname_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**.
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_XML_BUFFER_TYPE:21`

Used when serializing an [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer)*.

This type has no associated type description structure.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ANY_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ANY_CONTENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

The interpretation of the contents of the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) is as follows:

* When used at the top level or with [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), the
  [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) should contain a single element which represents
  the attribute and element content. The local name and namespace of the
  element in the buffer is ignored; it is replaced with actual element
  name and namespace when the buffer is written. For example:

  ```
  // Element in WS_XML_BUFFER
  <PrefixInBuffer:LocalNameInBuffer xmlns:PrefixInBuffer="namespace-in-buffer" other-attributes>
  text-and-or-element-content
  </PrefixInBuffer:LocalNameInBuffer>

  // Element that is written
  <NewPrefix:NewLocalName xmlns:NewPrefix="new-namespace" other-attributes>
  text-and-or-element-content
  </NewPrefix:NewLocalName>
  ```

  To avoid problems with namespace collisions, it is a best practice to follow one of the
  following rules when selecting a namespace for the element in the buffer:

  + Use a namespace other than "" that is not otherwise used in the buffer.
  + Use the same namespace as the element that will be written.When the value is deserialized, the element name and namespace will correspond
  to the element that was read.
* When used with [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), the
  [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) should contain a single element which
  represents a single element in the XML content.
* When used with [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), each
  of the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer)s that are serialized in the array
  has the same convention as with **WS_ELEMENT_FIELD_MAPPING** described above (each WS_XML_BUFFER represents a single element
  in the XML content).
* When used with [WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), each
  of the [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer)s that are serialized in the array
  represents a single element in the XML content.
* When used with [WS_ANY_CONTENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), the
  [WS_XML_BUFFER](https://learn.microsoft.com/windows/desktop/wsw/ws-xml-buffer) may contain zero or more top level elements
  or text. This content corresponds to the remaining XML content of the
  containing structure.

### `WS_CHAR_ARRAY_TYPE:22`

Used when serializing two fields of a structure as a unit: a **WCHAR*** field which
points to an array of WCHARs, and a ULONG field which contains the number
of characters in the array. This type may only be used within a
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

```
struct
{
    ULONG count;    // array length, in characters
    WCHAR* chars;   // array of unicode characters
} value;
```

The fields can be anywhere in the contained structure and in any order, since
their offsets within the structure are specified separately as part of the
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).
The offset of the count field is specified in the countOffset field, and the
offset of the chars field is specified in the offset field.

Embedded zeros are allowed in the array of characters.

The [WS_CHAR_ARRAY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_char_array_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type may only be used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_XML_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**
* [WS_FIELD_NILLABLE_ITEM](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil string is represented by setting the chars field to **NULL** and specifying a length of 0.
A nil string is distinguished from an empty string based on whether or not the chars field is
**NULL** (in both cases the length is zero).

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_UTF8_ARRAY_TYPE:23`

Used when serializing two fields of a structure as a unit: a BYTE* field which
points to an array of UTF8 bytes, and a ULONG field which contains the number
of bytes in the array. This type may only be used within a
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

```
struct
{
    ULONG count; // array length, in bytes
    BYTE* bytes; // array of utf8 characters
} value;
```

The fields can be anywhere in the contained structure and in any order, since
their offsets within the structure are specified separately as part of the
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).
The offset of the count field is specified in the countOffset field, and the
offset of the bytes field is specified in the offset field.

Embedded zeros are allowed in the array of utf8 bytes.

The [WS_UTF8_ARRAY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_utf8_array_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type may only be used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**

A nil string is represented by setting the bytes field to **NULL** and specifying a length of 0.
A nil string is distinguished from an empty string based on whether or not the bytes field is
**NULL** (in both cases the length is zero).

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_BYTE_ARRAY_TYPE:24`

Used when serializing two fields of a structure as a unit: a BYTE* field which
points to an array bytes, and a ULONG field which contains the number
of bytes in the array. This type may only be used within a
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

```
struct
{
    ULONG count;    // array length, in bytes
    BYTE* bytes;    // array of bytes
} value;
```

The fields can be anywhere in the contained structure and in any order, since
their offsets within the structure are specified separately as part of the
[WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).
The offset of the count field is specified in the countOffset field, and the
offset of the bytes field is specified in the offset field.

The [WS_BYTE_ARRAY_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_byte_array_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type may only be used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL**

A nil array is represented by setting the array pointer field to **NULL** and specifying a length of 0.
A nil array is distinguished from an empty array based on whether or not the array pointer field is
**NULL** (in both cases the length is zero).

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_DESCRIPTION_TYPE:25`

Used to represent the XML type of the structure being serialized. This can be used
to identify sub-types using the xsi:type attribute from XML Schema. The field of
the structure must be of type [WS_STRUCT_DESCRIPTION*](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description).

This type does not have an associated type description.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type may only be used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_TYPE_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0

### `WS_STRUCT_TYPE:26`

Used when serializing a user-defined structure. The associated type description points to a
[WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description) which provides information about how to serialize
the fields of the structure.

This type requires a [WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description) type description
to be supplied which provides information about how to serialize the type.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values,
as long as the fields defined by the structure follow the stated restrictions:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping). All field mappings are supported.
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).
  Only the following mappings are supported:
  + [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
  + [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping).
  Only the following mappings are supported:
  + [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
  + [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
  + [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
  + [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_CUSTOM_TYPE:27`

Used when serializing a custom type. The associated type description points to a
[WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description) which provides information about how to serialize the type.

This type requires a [WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description) type description
to be supplied which provides information about how to serialize the type, including
a [WS_READ_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_type_callback) and [WS_WRITE_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_type_callback) which
are used to read and write the type.

The callbacks are passed the [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) and make the determination
as to whether the mapping is supported.

The support for each [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) value is dependent on the
[WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) support determined by the callback. The rules
are as follows:

* If [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) is supported, then the following field mappings are supported:
  + [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
  + [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* If [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) is supported, then the following field mappings are supported:
  + [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* If [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) is supported, then the following field mappings are supported:
  + [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* If [WS_ANY_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) is supported, then the following field mappings are supported:
  + [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

Regardless of what [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values are supported, the type
can always be used with [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping).

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_ENDPOINT_ADDRESS_TYPE:28`

Used when serializing [WS_ENDPOINT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_endpoint_address) . The associated type description points to a
[WS_ENDPOINT_ADDRESS_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_endpoint_address_description) which provides information about how to serialize the endpoint address.

This type requires a [WS_ENDPOINT_ADDRESS_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/webservices/ns-webservices-ws_endpoint_address_description) type description
to be supplied which provides information about the serialization format.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_FAULT_TYPE:29`

Used when serializing a [WS_FAULT](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault). The associated type description points to a
[WS_FAULT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault_description) which provides information about how to serialize the fault.

This type requires a [WS_FAULT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_fault_description) type description
to be supplied which provides information about the serialization format.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

### `WS_VOID_TYPE:30`

This type is used to specify an arbitrary size field.

A [WS_VOID_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_void_description) can optionally be supplied in order
to specify the size of the type.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type can only be used within the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description) of a
[WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description).

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping). This is used to initialize a field of a structure
  to a default value when deserializing. This is used for the case where the
  particular field does not have a mapping to the XML content, and the type
  is not one of the other [WS_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type)s. The value will be initialized as
  follows:
  + If [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is specified, then the field will
    be set to **NULL**.
  + If [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) is not specified, then the field will
    be set to the [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) if allowed for the type and
    specified, otherwise it will be set to all zeros. The size of the field is specified as part of
    the [WS_VOID_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_void_description). If a **WS_VOID_DESCRIPTION** is not specified, the field is interpreted as being size 0.
* [WS_ANY_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping), **WS_REPEATING_ANY_ELEMENT_FIELD_MAPPING**,
  **WS_ELEMENT_FIELD_MAPPING**, **WS_ATTRIBUTE_FIELD_MAPPING**,
  **WS_ANY_CONTENT_FIELD_MAPPING** or
  **WS_ANY_ATTRIBUTES_FIELD_MAPPING**. This is
  used to discard the XML content when deserializing, or ignore the field when serializing.
  Since the values are not stored, a field of the structure is not required. The field
  offset should be zero and the field size should be zero (which is the default if a
  [WS_VOID_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_void_description) is not specified). The [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
  option should not be used.

### `WS_ENUM_TYPE:31`

Used when serializing a signed 32-bit integer which corresponds
to an enumerated value.

This type requires a [WS_ENUM_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_enum_description) type description
to be supplied which provides information about the enumeration values
and their corresponding serialized form.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_DURATION_TYPE:32`

Used when serializing a [WS_DURATION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration).

The [WS_DURATION_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_duration_description) type description can optionally be
specified for this type in order to constrain the allowed values.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ATTRIBUTE_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_ATTRIBUTE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_TEXT_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_NO_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE**
* [WS_FIELD_NILLABLE](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_POINTER**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**
* [WS_FIELD_POINTER](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) | **WS_FIELD_NILLABLE** | **WS_FIELD_OPTIONAL** | **WS_FIELD_NILLABLE_ITEM**

A nil value is represented using a **NULL** pointer.

A [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value) may be specified for this type.
See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) to see
which field mapping values allow a default value to be specified.

### `WS_UNION_TYPE:33`

Used when serializing a set of choices which correspond to a tagged union.

```
enum EnumType
{
// values identifying each choice
} value;
struct StructType
{
// value indicating which choice is set currently
EnumType selector;
union
{
// values corresponding to each choice
} value;
};
```

This type requires a [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_union_description) type description
to be supplied which provides information about the choices and
their corresponding serialized form.

This type can be used with the following [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values:

* [WS_ELEMENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)
* [WS_ELEMENT_CONTENT_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping)

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ELEMENT_CHOICE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)
* [WS_REPEATING_ELEMENT_CHOICE_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0
* [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type)

This type does not support nil values.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).
When used with [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type), the default value in the
union is specified using the nonEnumValue of the [WS_UNION_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_union_description).

### `WS_ANY_ATTRIBUTES_TYPE:34`

Used when serializing a set of attributes that are not mapped to fields
using [WS_ANY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_any_attributes).

This type does not have an associated type description.

This type cannot be used with any [WS_TYPE_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type_mapping) values.

This type may only be used within a [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

This type can be used with the following [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) values:

* [WS_ANY_ATTRIBUTES_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping)

This type can be used with the following [WS_FIELD_OPTIONS](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) values. See the documentation for [WS_FIELD_MAPPING](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_field_mapping) for which options are supported for a given field mapping value:

* 0

This type does not support nil values.

This type does not support specifying a [WS_DEFAULT_VALUE](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_default_value).

## Remarks

Many of the **WS_TYPE**s have a corresponding type description structure
which allows for additional information used to serialize or deserialize the
type.

For example, the **WS_INT32_TYPE** has a [WS_INT32_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_int32_description) structure which allows for constraints on the deserialized values. This is an optional
type description (if not specified, the full 32-bit integer space is allowed).

Another example is the **WS_STRUCT_TYPE**, which allows for the specification of
a user-defined structure with fields. The fields are described in a
[WS_STRUCT_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_struct_description). This type description is required.

Type description pointers accompany **WS_TYPE** in the various APIs and structures
that are based on serialization. This should be **NULL** or non-**NULL** based on whether or not
the type description is not defined, optional or required.