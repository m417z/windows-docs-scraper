# D3D10_DDI_SAMPLER_DESC structure

## Description

The D3D10_DDI_SAMPLER_DESC structure describes a sampler.

## Members

### `Filter` [in]

A [D3D10_DDI_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_filter)-typed value that indicates the filter property for a sampler.

### `AddressU` [in]

A [D3D10_DDI_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_texture_address_mode)-typed value that indicates the texture-address mode for the u coordinate.

### `AddressV` [in]

A [D3D10_DDI_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_texture_address_mode)-typed value that indicates the texture-address mode for the v coordinate.

### `AddressW` [in]

A [D3D10_DDI_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_texture_address_mode)-typed value that indicates the texture-address mode for the w coordinate.

### `MipLODBias` [in]

A single-precision float that affects the level that the driver selects for MIP-map level of detail (LOD).

### `MaxAnisotropy` [in]

The maximum valid value for the anisotropy texture-stage state.

### `ComparisonFunc` [in]

A [D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)-typed value that indicates the sampler-comparison function to perform.

### `BorderColor` [in]

A four-element array of single-precision float vectors for RGBA, where Red == 0. The border color is used when the D3D10_DDI_TEXTURE_ADDRESS_BORDER value is specified in the **AddressU**, **AddressV**, or **AddressW** member. The float should be converted to the appropriate resource format.

### `MinLOD` [in]

A single-precision float vector for the minimum level of detail (LOD) for the sampler.

### `MaxLOD` [in]

A single-precision float vector for the maximum level of detail (LOD) for the sampler.

## See also

[CalcPrivateSamplerSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_calcprivatesamplersize)

[CreateSampler](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createsampler)

[D3D10_DDI_COMPARISON_FUNC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_comparison_func)

[D3D10_DDI_FILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_filter)

[D3D10_DDI_TEXTURE_ADDRESS_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_texture_address_mode)