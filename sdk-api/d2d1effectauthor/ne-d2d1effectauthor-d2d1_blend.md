# D2D1_BLEND enumeration

## Description

Specifies how one of the color sources is to be derived and optionally specifies a preblend operation on the color source.

## Constants

### `D2D1_BLEND_ZERO:1`

The data source is black (0, 0, 0, 0). There is no preblend operation.

### `D2D1_BLEND_ONE:2`

The data source is white (1, 1, 1, 1). There is no preblend operation.

### `D2D1_BLEND_SRC_COLOR:3`

The data source is color data (RGB) from the second input of the blend transform. There is not a preblend operation.

### `D2D1_BLEND_INV_SRC_COLOR:4`

The data source is color data (RGB) from second input of the blend transform. The preblend operation inverts the data, generating 1 - RGB.

### `D2D1_BLEND_SRC_ALPHA:5`

The data source is alpha data (A) from second input of the blend transform. There is no preblend operation.

### `D2D1_BLEND_INV_SRC_ALPHA:6`

The data source is alpha data (A) from the second input of the blend transform. The preblend operation inverts the data, generating 1 - A.

### `D2D1_BLEND_DEST_ALPHA:7`

The data source is alpha data (A) from the first input of the blend transform. There is no preblend operation.

### `D2D1_BLEND_INV_DEST_ALPHA:8`

The data source is alpha data (A) from the first input of the blend transform. The preblend operation inverts the data, generating 1 - A.

### `D2D1_BLEND_DEST_COLOR:9`

The data source is color data from the first input of the blend transform. There is no preblend operation.

### `D2D1_BLEND_INV_DEST_COLOR:10`

The data source is color data from the first input of the blend transform. The preblend operation inverts the data, generating 1 - RGB.

### `D2D1_BLEND_SRC_ALPHA_SAT:11`

The data source is alpha data from the second input of the blend transform. The preblend operation clamps the data to 1 or less.

### `D2D1_BLEND_BLEND_FACTOR:14`

The data source is the blend factor. There is no preblend operation.

### `D2D1_BLEND_INV_BLEND_FACTOR:15`

The data source is the blend factor. The preblend operation inverts the blend factor, generating 1 - blend_factor.

### `D2D1_BLEND_FORCE_DWORD:0xffffffff`

## Remarks

This enumeration has the same numeric values as [D3D10_BLEND](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_blend).

## See also

[D2D1_BLEND_DESCRIPTION](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ns-d2d1effectauthor-d2d1_blend_description)

[ID2D1BlendTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1blendtransform)