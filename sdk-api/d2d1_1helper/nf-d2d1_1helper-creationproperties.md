# CreationProperties function

## Description

Returns a [D2D1_CREATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_creation_properties) that describes root-level creation details.

## Parameters

### `threadingMode`

Type: **[D2D1_THREADING_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_threading_mode)**

The threading mode with which the corresponding root objects are created.

### `debugLevel`

Type: **[D2D1_DEBUG_LEVEL](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_debug_level)**

The debug level that the root objects should be created with.

### `options`

Type: **[D2D1_DEVICE_CONTEXT_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_device_context_options)**

The device context options that the root objects should be created with.

## Return value

Type: **[D2D1_CREATION_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_creation_properties)**

The filled creation properties structure.