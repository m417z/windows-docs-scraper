# D3D12_STATIC_SAMPLER_DESC structure

## Description

Describes a static sampler.

## Members

### `Filter`

The filtering method to use when sampling a texture, as a [D3D12_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) enumeration constant.

### `AddressU`

Specifies the [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) mode to use for resolving a *u* texture coordinate that is outside the 0 to 1 range.

### `AddressV`

Specifies the [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) mode to use for resolving a *v* texture coordinate that is outside the 0 to 1 range.

### `AddressW`

Specifies the [D3D12_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_texture_address_mode) mode to use for resolving a *w* texture coordinate that is outside the 0 to 1 range.

### `MipLODBias`

Offset from the calculated mipmap level. For example, if Direct3D calculates that a texture should be sampled at mipmap level 3 and MipLODBias is 2, then the texture will be sampled at mipmap level 5.

### `MaxAnisotropy`

Clamping value used if D3D12_FILTER_ANISOTROPIC or D3D12_FILTER_COMPARISON_ANISOTROPIC is specified as the filter. Valid values are between 1 and 16.

### `ComparisonFunc`

A function that compares sampled data against existing sampled data.
The function options are listed in [D3D12_COMPARISON_FUNC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_comparison_func).

### `BorderColor`

One member of [D3D12_STATIC_BORDER_COLOR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_static_border_color), the border color to use if D3D12_TEXTURE_ADDRESS_MODE_BORDER is specified for AddressU, AddressV, or AddressW.
Range must be between 0.0 and 1.0 inclusive.

### `MinLOD`

Lower end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed.

### `MaxLOD`

Upper end of the mipmap range to clamp access to, where 0 is the largest and most detailed mipmap level and any level higher than that is less detailed. This value must be greater than or equal to MinLOD. To have no upper limit on LOD set this to a large value such as D3D12_FLOAT32_MAX.

### `ShaderRegister`

The *ShaderRegister* and *RegisterSpace* parameters correspond to the binding syntax of HLSL. For example, in HLSL:

``` syntax
Texture2D<float4> a : register(t2, space3);
```

This corresponds to a *ShaderRegister* of 2 (indicating the type is SRV), and *RegisterSpace* is 3.

The *ShaderRegister* and *RegisterSpace* pair is needed to establish correspondence between shader resources and runtime heap descriptors, using the root signature data structure.

### `RegisterSpace`

See the description for *ShaderRegister*.
Register space is optional; the default register space is 0.

### `ShaderVisibility`

Specifies the visibility of the sampler to the pipeline shaders, one member of [D3D12_SHADER_VISIBILITY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility).

## Remarks

Use this structure with the [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) structure.

## See also

[CD3DX12_STATIC_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-static-sampler-desc)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)