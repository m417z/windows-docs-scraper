# D3D12_TEXTURE_ADDRESS_MODE enumeration

## Description

Identifies a technique for resolving texture coordinates that are outside of the boundaries of a texture.

## Constants

### `D3D12_TEXTURE_ADDRESS_MODE_WRAP:1`

Tile the texture at every (u,v) integer junction.
For example, for u values between 0 and 3, the texture is repeated three times.

### `D3D12_TEXTURE_ADDRESS_MODE_MIRROR:2`

Flip the texture at every (u,v) integer junction.
For u values between 0 and 1, for example, the texture is addressed normally; between 1 and 2, the texture is flipped (mirrored); between 2 and 3, the texture is normal again; and so on.

### `D3D12_TEXTURE_ADDRESS_MODE_CLAMP:3`

Texture coordinates outside the range [0.0, 1.0] are set to the texture color at 0.0 or 1.0, respectively.

### `D3D12_TEXTURE_ADDRESS_MODE_BORDER:4`

Texture coordinates outside the range [0.0, 1.0] are set to the border color specified in [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc) or HLSL code.

### `D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE:5`

Similar to
[D3D12_TEXTURE_ADDRESS_MODE_MIRROR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode)
and
[D3D12_TEXTURE_ADDRESS_MODE_CLAMP](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode).
Takes the absolute value of the texture coordinate (thus, mirroring around 0), and then clamps to the maximum value.

## Remarks

This enum is used by the [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)