# D3D10_DDI_BLEND enumeration

## Description

The D3D10_DDI_BLEND enumeration type contains values that identify blend modes in a call to the driver's [**CreateBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate) function.

## Constants

### `D3D10_DDI_BLEND_ZERO:1`

Blend factor is (0, 0, 0, 0).

### `D3D10_DDI_BLEND_ONE:2`

Blend factor is (1, 1, 1, 1).

### `D3D10_DDI_BLEND_SRC_COLOR:3`

Blend factor is (Rₛ,Gₛ,Bₛ,Aₛ).

### `D3D10_DDI_BLEND_INV_SRC_COLOR:4`

Blend factor is (1 - Rₛ, 1 - Gₛ, 1 - Bₛ, 1 - Aₛ).

### `D3D10_DDI_BLEND_SRC_ALPHA:5`

Blend factor is (Aₛ, Aₛ, Aₛ, Aₛ).

### `D3D10_DDI_BLEND_INV_SRC_ALPHA:6`

Blend factor is ( 1 - Aₛ, 1 - Aₛ, 1 - Aₛ, 1 - Aₛ).

### `D3D10_DDI_BLEND_DEST_ALPHA:7`

Blend factor is (Ad, Ad, Ad, Ad) of the current render target that is being blended.

### `D3D10_DDI_BLEND_INV_DEST_ALPHA:8`

Blend factor is (1 - Ad, 1 - Ad, 1 - Ad, 1 - Ad) of the current render target that is being blended.

### `D3D10_DDI_BLEND_DEST_COLOR:9`

Blend factor is (Rd, Gd, Bd, Ad) of the current render target that is being blended.

### `D3D10_DDI_BLEND_INV_DEST_COLOR:10`

Blend factor is (1 - Rd, 1 - Gd, 1 - Bd, 1 - Ad) of the current render target that is being blended.

### `D3D10_DDI_BLEND_SRC_ALPHASAT:11`

Blend factor is (f, f, f, 1); f = min(A, 1 - Ad).

### `D3D10_DDI_BLEND_BLEND_FACTOR:14`

Constant color-blending factor that the frame-buffer blender uses.

### `D3D10_DDI_BLEND_INVBLEND_FACTOR:15`

Inverted constant color-blending factor that the frame-buffer blender uses.

### `D3D10_DDI_BLEND_SRC1_COLOR:16`

Blend factor is the red, green, and blue (RGB) components of a pixel shader output register (PS output o1.rgb).

### `D3D10_DDI_BLEND_INV_SRC1_COLOR:17`

Blend factor is the inversion of the RGB components of a pixel shader output register (1.0f - PS output o1.rgb).

### `D3D10_DDI_BLEND_SRC1_ALPHA:18`

Blend factor is the alpha component of a pixel shader output register (PS output o1.a).

### `D3D10_DDI_BLEND_INV_SRC1_ALPHA:19`

Blend factor is the inversion of the alpha component of a pixel shader output register (1.0f - PS output o1.a).

### `D3D10_DDI_BLEND_ALPHA_FACTOR:20`

Blend factor is the alpha component of the color-blending factor that the frame-buffer blender uses.

### `D3D10_DDI_BLEND_INVALPHA_FACTOR:21`

Blend factor is 1 minus the alpha component of the color-blending factor that the frame-buffer blender uses.

## Remarks

A *blend mode* is an algorithm that is used to determine how a texture is blended with the colors of the surface that the texture is applied to. A *blend factor* is a description of how each color component is blended in texture blending.

## See also

[**CreateBlendState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createblendstate)