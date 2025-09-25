# D3D10_SAMPLER_DESC structure

## Description

Describes a sampler state.

## Members

### `Filter`

Type: **[D3D10_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_filter)**

Filtering method to use when sampling a texture (see [D3D10_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_filter)).

### `AddressU`

Type: **[D3D10_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_texture_address_mode)**

Method to use for resolving a u texture coordinate that is outside the 0 to 1 range (see [D3D10_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_texture_address_mode)).

### `AddressV`

Type: **[D3D10_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_texture_address_mode)**

Method to use for resolving a v texture coordinate that is outside the 0 to 1 range.

### `AddressW`

Type: **[D3D10_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_texture_address_mode)**

Method to use for resolving a w texture coordinate that is outside the 0 to 1 range.

### `MipLODBias`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from the calculated mipmap level. For example, if Direct3D calculates that a texture should be sampled at mipmap level 3 and MipLODBias is 2, then the texture will be sampled at mipmap level 5.

### `MaxAnisotropy`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Clamping value used if D3D10_FILTER_ANISOTROPIC or D3D10_FILTER_COMPARISON_ANISOTROPIC is specified in Filter. Valid values are between 1 and 16.

### `ComparisonFunc`

Type: **[D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func)**

A function that compares sampled data against existing sampled data. The function options are listed in [D3D10_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_comparison_func).

### `BorderColor`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Border color to use if D3D10_TEXTURE_ADDRESS_BORDER is specified for AddressU, AddressV, or AddressW. Range must be between 0.0 and 1.0 inclusive.

### `MinLOD`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.

### `MaxLOD`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to MinLOD. To have no upper limit on LOD set this to a large value such as D3D10_FLOAT32_MAX.

## Remarks

These are the default values for sampler state.

| State | Default Value |
| --- | --- |
| Filter | Min_Mag_Mip_Point |
| AddressU | Clamp |
| AddressV | Clamp |
| AddressW | Clamp |
| MinLOD | 0.0f |
| MaxLOD | 3.402823466e+38F (FLT_MAX) |
| MipMapLODBias | 0.0f |
| MaxAnisotropy | 16 |
| ComparisonFunc | Never |
| BorderColor | float4(0.0f, 0.0f, 0.0f, 0.0f) |
| Texture | N/A |

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)