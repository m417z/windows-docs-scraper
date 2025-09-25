# D3D10_TEXTURE_ADDRESS_MODE enumeration

## Description

Identify a technique for resolving texture coordinates that are outside of the boundaries of a texture.

## Constants

### `D3D10_TEXTURE_ADDRESS_WRAP:1`

Tile the texture at every integer junction. For example, for u values between 0 and 3, the texture is repeated three times.

### `D3D10_TEXTURE_ADDRESS_MIRROR:2`

Flip the texture at every integer junction. For u values between 0 and 1, for example, the texture is addressed normally; between 1 and 2, the texture is flipped (mirrored); between 2 and 3, the texture is normal again; and so on.

### `D3D10_TEXTURE_ADDRESS_CLAMP:3`

Texture coordinates outside the range [0.0, 1.0] are set to the texture color at 0.0 or 1.0, respectively.

### `D3D10_TEXTURE_ADDRESS_BORDER:4`

Texture coordinates outside the range [0.0, 1.0] are set to the border color specified in [D3D10_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_sampler_desc) or HLSL code.

### `D3D10_TEXTURE_ADDRESS_MIRROR_ONCE:5`

Similar to D3D10_TEXTURE_ADDRESS_MIRROR and D3D10_TEXTURE_ADDRESS_CLAMP. Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)