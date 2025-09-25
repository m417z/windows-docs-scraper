# WS_HEAP_PROPERTY structure

## Description

Specifies a heap specific setting.

## Members

### `id`

Identifies the [WS_HEAP_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/webservices/ne-webservices-ws_heap_property_id).

### `value`

A pointer to the value to set.
The pointer must have an alignment compatible with the type
of the property.

### `valueSize`

The size in bytes of the memory pointed to by value.