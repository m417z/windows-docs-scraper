# WS_CALL_PROPERTY structure

## Description

Specifies a proxy property.

## Members

### `id`

Identifies the [WS_CALL_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_call_property_id).

### `value`

Pointer to a buffer for the value of the property.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize`

The size of buffer in bytes.