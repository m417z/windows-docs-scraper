# D3D12_SAMPLER_DESC structure

## Description

Describes a sampler state.

## Members

### `Filter`

A [D3D12_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter)-typed value that specifies the filtering method to use when sampling a texture.

### `AddressU`

A [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode)-typed value that specifies the method to use for resolving a u texture coordinate that is outside the 0 to 1 range.

### `AddressV`

A [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode)-typed value that specifies the method to use for resolving a v texture coordinate that is outside the 0 to 1 range.

### `AddressW`

A [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode)-typed value that specifies the method to use for resolving a w texture coordinate that is outside the 0 to 1 range.

### `MipLODBias`

Offset from the calculated mipmap level. For example, if the runtime calculates that a texture should be sampled at mipmap level 3 and **MipLODBias** is 2, the texture will be sampled at mipmap level 5.

### `MaxAnisotropy`

Clamping value used if **D3D12_FILTER_ANISOTROPIC** or **D3D12_FILTER_COMPARISON_ANISOTROPIC** is specified in **Filter**. Valid values are between 1 and 16.

### `ComparisonFunc`

A [D3D12_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func)-typed value that specifies a function that compares sampled data against existing sampled data.

### `BorderColor`

RGBA border color to use if [D3D12_TEXTURE_ADDRESS_MODE_BORDER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) is specified for **AddressU**, **AddressV**, or **AddressW**. Range must be between 0.0 and 1.0 inclusive.

### `MinLOD`

Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.

### `MaxLOD`

Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to **MinLOD**. To have no upper limit on LOD, set this member to a large value.

## Remarks

This structure is used by [CreateSampler](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createsampler).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)