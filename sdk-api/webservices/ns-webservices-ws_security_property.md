# WS_SECURITY_PROPERTY structure

## Description

Specifies a channel-wide security setting.

## Members

### `id`

Identifies the [WS_SECURITY_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_security_property_id).

### `value`

A pointer to the value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize`

The size in bytes of the memory pointed to by value.