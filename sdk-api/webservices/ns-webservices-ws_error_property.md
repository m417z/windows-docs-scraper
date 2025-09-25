# WS_ERROR_PROPERTY structure

## Description

Specifies an error specific setting.

## Members

### `id`

Identifies the [WS_ERROR_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_error_property_id).

### `value`

A pointer to the value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize`

The size, in bytes, of the memory pointed to by value.