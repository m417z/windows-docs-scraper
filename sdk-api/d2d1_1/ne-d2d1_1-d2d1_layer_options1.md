# D2D1_LAYER_OPTIONS1 enumeration

## Description

Specifies how the layer contents should be prepared.

## Constants

### `D2D1_LAYER_OPTIONS1_NONE:0`

Default layer behavior. A premultiplied layer target is pushed and its contents are cleared to transparent black.

### `D2D1_LAYER_OPTIONS1_INITIALIZE_FROM_BACKGROUND:1`

 The layer is not cleared to transparent black.

### `D2D1_LAYER_OPTIONS1_IGNORE_ALPHA:2`

 The layer is always created as ignore alpha. All content rendered into the layer will be treated as opaque.

### `D2D1_LAYER_OPTIONS1_FORCE_DWORD:0xffffffff`