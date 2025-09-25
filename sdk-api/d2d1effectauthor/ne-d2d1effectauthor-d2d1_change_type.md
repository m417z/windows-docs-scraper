# D2D1_CHANGE_TYPE enumeration

## Description

Describes flags that influence how the renderer interacts with a custom vertex shader.

## Constants

### `D2D1_CHANGE_TYPE_NONE:0`

There were no changes.

### `D2D1_CHANGE_TYPE_PROPERTIES:1`

The properties of the effect changed.

### `D2D1_CHANGE_TYPE_CONTEXT:2`

The context state changed.

### `D2D1_CHANGE_TYPE_GRAPH:3`

The effect’s transform graph has changed. This happens only when an effect supports a variable input count.

### `D2D1_CHANGE_TYPE_FORCE_DWORD:0xffffffff`

## See also

[ID2D1EffectImpl::PrepareForRender](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectimpl-prepareforrender)