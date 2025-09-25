# D3D10_DDI_FILTER enumeration

## Description

The D3D10_DDI_FILTER enumeration type contains values that identify filter properties of a sampler in a call to the driver's [CreateSampler](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createsampler) function.

## Constants

### `D3D10_DDI_FILTER_MIN_MAG_MIP_POINT`

The sampler uses point filtering for the min (minifying), mag (magnifying), and mip filters. For more information about these types of filters, see Remarks.

### `D3D10_DDI_FILTER_MIN_MAG_POINT_MIP_LINEAR`

 The sampler uses point filtering for the min and mag filters and uses linear filtering for the mip filter.

### `D3D10_DDI_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT`

The sampler uses point filtering for the min and mip filters and uses linear filtering for the mag filter.

### `D3D10_DDI_FILTER_MIN_POINT_MAG_MIP_LINEAR`

 The sampler uses point filtering for the min filter and uses linear filtering for the mag and mip filters.

### `D3D10_DDI_FILTER_MIN_LINEAR_MAG_MIP_POINT`

The sampler uses linear filtering for the min filter and uses point filtering for the mag and mip filters.

### `D3D10_DDI_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR`

 The sampler uses linear filtering for the min and mip filters and uses point filtering for the mag filter.

### `D3D10_DDI_FILTER_MIN_MAG_LINEAR_MIP_POINT`

The sampler uses linear filtering for the min and mag filters and uses point filtering for the mip filter.

### `D3D10_DDI_FILTER_MIN_MAG_MIP_LINEAR`

 The sampler uses linear filtering for the min, mag, and mip filters.

### `D3D10_DDI_FILTER_ANISOTROPIC`

The sampler uses anisotropic filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_MAG_MIP_POINT`

 The sampler uses point filtering for the min, mag, and mip filters. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR`

The sampler uses point filtering for the min and mag filters and uses linear filtering for the mip filter. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT`

 The sampler uses point filtering for the min and mip filters and uses linear filtering for the mag filter. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR`

The sampler uses point filtering for the min filter and uses linear filtering for the mag and mip filters. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT`

 The sampler uses linear filtering for the min filter and uses point filtering for the mag and mip filters. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR`

The sampler uses linear filtering for the min and mip filters and uses point filtering for the mag filter. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT`

The sampler uses linear filtering for the min and mag filters and uses point filtering for the mip filter. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR`

 The sampler uses linear filtering for the min, mag, and mip filters. The sampler also uses comparison filtering.

### `D3D10_DDI_FILTER_COMPARISON_ANISOTROPIC`

The sampler uses anisotropic and comparison filtering.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_MAG_MIP_POINT`

The sampler uses point filtering for the min (minifying), mag (magnifying), and mip filters. For more information about these types of filters, see Remarks.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR`

 The sampler uses point filtering for the min and mag filters and uses linear filtering for the mip filter.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT`

The sampler uses point filtering for the min and mip filters and uses linear filtering for the mag filter.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR`

 The sampler uses point filtering for the min filter and uses linear filtering for the mag and mip filters.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT`

The sampler uses linear filtering for the min filter and uses point filtering for the mag and mip filters.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR`

 The sampler uses linear filtering for the min and mip filters and uses point filtering for the mag filter.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT`

The sampler uses linear filtering for the min and mag filters and uses point filtering for the mip filter.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR`

 The sampler uses linear filtering for the min, mag, and mip filters.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MINIMUM_ANISOTROPIC`

The sampler uses anisotropic filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_MAG_MIP_POINT`

 The sampler uses point filtering for the min, mag, and mip filters. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR`

The sampler uses point filtering for the min and mag filters and uses linear filtering for the mip filter. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT`

 The sampler uses point filtering for the min and mip filters and uses linear filtering for the mag filter. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR`

The sampler uses point filtering for the min filter and uses linear filtering for the mag and mip filters. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT`

 The sampler uses linear filtering for the min filter and uses point filtering for the mag and mip filters. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR`

The sampler uses linear filtering for the min and mip filters and uses point filtering for the mag filter. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT`

The sampler uses linear filtering for the min and mag filters and uses point filtering for the mip filter. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR`

 The sampler uses linear filtering for the min, mag, and mip filters. The sampler also uses comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3DWDDM1_3DDI_FILTER_MAXIMUM_ANISOTROPIC`

The sampler uses anisotropic and comparison filtering.

Supported starting with Windows 8.1, and used by WDDM 1.3 and later drivers.

### `D3D10_DDI_FILTER_TEXT_1BIT`

A special case of filtering mode that is intended only for text filtering and the DXGI_FORMAT_R1_UNORM texture format. For more information about text filtering, see the [SetTextFilterSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_settextfiltersize) function.

## Remarks

Filtering determines a representative value from the sample coordinates of a texture and derivatives for those coordinates. The magnitude of the derivative determines the level of detail (LOD) on the texture to read.

If the LOD is positive (which indicates that the region that is sampled is smaller than roughly the size of a texel in the largest active MIP-map level of the texture), the filter is a *magnifying* filter. Otherwise, the filter is a *minifying* filter. When magnifying, the largest active MIP-map level of the texture is used. When minifying, the two MIP-map levels that are closest to the LOD are used. For a given MIP-map level that is accessed on a texture, filtering can be *point* or *linear*. Point filtering returns the nearest texel to the lookup coordinates. Linear filtering returns the linear-weighted blend of the nearest 4 texels to the sample location.

When the driver chooses between two MIP-map levels, the driver uses the *mip* filter. The mip filter can also be point or linear. Point mip filtering returns the result of sampling from the nearest mip to the calculated LOD. Linear mip filtering returns the linear-weighted blend between the nearest two MIP-map levels to the calculated LOD.

The values of the D3D10_DDI_FILTER enumeration describe many of the possible combinations of min, mag, and mip filtering that can also be point or linear. For example, D3D10_DDI_FILTER_MIN_MAG_POINT_MIP_LINEAR means to use point filtering for the min and mag filters and to use linear filtering for the mip filter.

Another type of filtering is *anisotropic*. This takes into account anisotropy in the derivatives of the texture coordinates to perform an area sampling of the texture. For example, if a texture is being viewed at a slope, anisotropic filtering accounts for this when computing what the filtered result should be, at greater processing power than the min, mag, or mip filters. No value is derived in mixing anisotropic filtering with other filtering modes for magnifying and minifying. For anisotropic filtering, the mip filter is always linear. Therefore, the anisotropic filtering values of D3D10_DDI_FILTER do not expose choices of min, mag, or mip.

Filtering can also be described by a comparison component. By default (no comparison filtering), the result of a sampling operation is a blend of a number of samples. Comparison filtering performs identically to the default mode in terms of which set of texels are read from the texture except for one difference. Just before blending the values together to produce a final result, each individual value read from the texture is compared against a reference value that is provided from the shader. The type of comparison (greater than, less than, equal to, and so on) is determined by the selected sampler state. The result of each comparison is true (1.0) or false (0.0). Comparison filtering then blends these true and false results together rather than the original values read from the texture. Therefore, the final result of a comparison filter is always in the range 0.0 to 1.0. The primary use for comparison filtering is for shadow-buffer filtering.

## See also

[CreateSampler](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createsampler)

[D3D10_DDI_SAMPLER_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_ddi_sampler_desc)