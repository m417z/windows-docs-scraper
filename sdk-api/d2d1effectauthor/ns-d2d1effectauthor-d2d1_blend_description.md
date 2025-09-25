# D2D1_BLEND_DESCRIPTION structure

## Description

Defines a blend description to be used in a particular blend transform.

## Members

### `sourceBlend`

Specifies the first RGB data source and includes an optional preblend operation.

### `destinationBlend`

Specifies the second RGB data source and includes an optional preblend operation.

### `blendOperation`

Specifies how to combine the RGB data sources.

### `sourceBlendAlpha`

Specifies the first alpha data source and includes an optional preblend operation. Blend options that end in _COLOR are not allowed.

### `destinationBlendAlpha`

Specifies the second alpha data source and includes an optional preblend operation. Blend options that end in _COLOR are not allowed.

### `blendOperationAlpha`

Specifies how to combine the alpha data sources.

### `blendFactor`

Parameters to the blend operations. The blend must use **D2D1_BLEND_BLEND_FACTOR** for this to be used.

## Remarks

This description closely matches the [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc) struct with some omissions and the addition of the blend factor in the description.

## See also

[D2D1_BLEND](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_blend)

[D2D1_BLEND_OPERATION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_blend_operation)