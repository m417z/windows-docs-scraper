## Description

> [!NOTE]
> This structure is supported by the Direct3D 11.2 runtime, which is available on Windows 8.1 and later operating systems.

Describes Direct3D 11.2 feature options in the current graphics driver.

## Members

### `TiledResourcesTier`

Type: **[D3D11_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_tiled_resources_tier)**

Specifies whether the hardware and driver support tiled resources. The runtime sets this member to a [D3D11_TILED_RESOURCES_TIER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_tiled_resources_tier)-typed value that indicates if the hardware and driver support tiled resources and at what tier level.

### `MinMaxFiltering`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the hardware and driver support the filtering options ([D3D11_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_filter)) of comparing the result to the minimum or maximum value during texture sampling. The runtime sets this member to **TRUE** if the hardware and driver support these filtering options.

### `ClearViewAlsoSupportsDepthOnlyFormats`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the hardware and driver also support the [ID3D11DeviceContext1::ClearView](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11devicecontext1-clearview) method on depth formats. For info about valid depth formats, see [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc).

### `MapOnDefaultBuffers`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies support for creating [ID3D11Buffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11buffer) resources that can be passed to the [ID3D11DeviceContext::Map](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-map) and [ID3D11DeviceContext::Unmap](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-unmap) methods. This means that the **CPUAccessFlags** member of the [D3D11_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_desc) structure may be set with the desired [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag) elements when the **Usage** member of **D3D11_BUFFER_DESC** is set to **D3D11_USAGE_DEFAULT**. The runtime sets this member to **TRUE** if the hardware is capable of at least **D3D_FEATURE_LEVEL_11_0** and the graphics device driver supports mappable default buffers.

## Remarks

If the Direct3D API is the Direct3D 11.2 runtime and can support 11.2 features, [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) for **D3D11_FEATURE_D3D11_OPTIONS1** will return a SUCCESS code when valid parameters are passed. The members of **D3D11_FEATURE_DATA_D3D11_OPTIONS1** will be set appropriately based on the system's graphics hardware and graphics driver.

### Mappable default buffers

When creating a default buffer with [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag), only the **D3D11_BIND_SHADER_RESOURCE** and **D3D11_BIND_UNORDERED_ACCESS** [bind flags](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag) may be used.

The [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) cannot be used when creating resources with **D3D11_CPU_ACCESS** flags.

On non-unified memory architecture systems (discrete GPUs), apps should not use mappable default buffers if the compute shader code accesses the same byte in a default buffer more than once - sending the data across the bus multiple times eliminates the performance gained by mapping the default buffer instead of copying it.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)