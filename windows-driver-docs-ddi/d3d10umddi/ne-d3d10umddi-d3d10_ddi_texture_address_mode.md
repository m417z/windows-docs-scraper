# D3D10_DDI_TEXTURE_ADDRESS_MODE enumeration

## Description

The D3D10_DDI_TEXTURE_ADDRESS_MODE enumeration type contains values that identify the texture address mode of a sampler.

## Constants

### `D3D10_DDI_TEXTURE_ADDRESS_WRAP`

Tile the texture at every integer junction. For example, for u values between 0 and 3, the texture is repeated three times; no mirroring is performed.

### `D3D10_DDI_TEXTURE_ADDRESS_MIRROR`

Similar to D3D10_DDI_TEXTURE_ADDRESS_WRAP, except that the texture is flipped at every integer junction. For u values between 0 and 1, for example, the texture is addressed normally; between 1 and 2, the texture is flipped (mirrored); and between 2 and 3, the texture is normal again, and so on.

### `D3D10_DDI_TEXTURE_ADDRESS_CLAMP`

Texture coordinates outside the range [0.0, 1.0] are set to the texture color at 0.0 or 1.0, respectively.

### `D3D10_DDI_TEXTURE_ADDRESS_BORDER`

Texture coordinates outside the range [0.0, 1.0] are set to the border color.

### `D3D10_DDI_TEXTURE_ADDRESS_MIRRORONCE`

Similar to D3D10_DDI_TEXTURE_ADDRESS_MIRROR and D3D10_DDI_TEXTURE_ADDRESS_CLAMP. Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value. The most common usage of D3D10_DDI_TEXTURE_ADDRESS_MIRRORONCE is for volume textures, where support for the full D3D10_DDI_TEXTURE_ADDRESS_MIRRORONCE texture-addressing mode is not necessary, but the data is symmetric around the one axis.

## See also

[D3D10_DDI_SAMPLER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_sampler_desc)