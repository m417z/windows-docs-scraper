# WS_CUSTOM_TYPE_DESCRIPTION structure

## Description

Represents a custom mapping between a C data type and an XML element.User-defined callbacks are invoked to do the actual reading and
writing.

## Members

### `size`

The size of the custom type, in bytes.

### `alignment`

The alignment requirement of the custom type. This must be a
power of two between 1 and 8.

### `readCallback`

A pointer to a callback which is invoked to read the type.

### `writeCallback`

A pointer to a callback which is invoked to write the type.

### `descriptionData`

This can be used to point to additional user-defined data
specific to the type. It is optional and may be **NULL**.

The pointer to this data is passed
to the [WS_READ_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_read_type_callback) and the
[WS_WRITE_TYPE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/webservices/nc-webservices-ws_write_type_callback). This allows the
callback to access information that is specific to this
particular usage of the callback.

### `isDefaultValueCallback`