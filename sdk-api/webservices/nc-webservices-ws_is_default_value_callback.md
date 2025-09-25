# WS_IS_DEFAULT_VALUE_CALLBACK callback function

## Description

Determines if a value is the default value. This callback is used before a value that is handled
by a [WS_CUSTOM_TYPE](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_type) is serialized. Support
for default values is enabled by specifying
when [WS_FIELD_OPTIONAL](https://learn.microsoft.com/windows/win32/api/webservices/ne-webservices-ws_xml_reader_encoding_type) in the [WS_FIELD_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_field_description).

## Parameters

### `descriptionData` [in]

This is the value of the descriptionData field from [WS_CUSTOM_TYPE_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/webservices/ns-webservices-ws_custom_type_description).
The callback can use this to access any additional information about the type.

### `value`

A pointer to the value being serialized.

### `defaultValue`

A pointer to the default value. If no default value was specified
for the field, this parameter will be **NULL**.

If the parameter is non-**NULL**, the callback should compare the two
values field-by-field according to the custom type. If the
fields match, then the isDefault parameter should be set to **TRUE**.

If the parameter is **NULL**, the callback should compare the fields
of the value with zero. If the fields match, then the isDefault
parameter should be set to **TRUE**.

### `valueSize` [in]

The size, in bytes, of the value being serialized.

### `isDefault` [out]

Whether or not the value is the default value.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This callback function does not return a value.