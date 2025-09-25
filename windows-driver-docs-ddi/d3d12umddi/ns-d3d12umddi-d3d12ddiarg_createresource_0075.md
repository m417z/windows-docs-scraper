## Description

The **D3D12DDIARG_CREATERESOURCE_0075** structure contains the information needed to create or calculate the size of a resource.

## Members

### `ReuseBufferGPUVA`

A [**D3D12DDIARG_BUFFER_PLACEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_buffer_placement) structure that specifies the GPU-side virtual address this resource should have, if it does not need a new one assigned.

### `ResourceType`

A [**D3D12DDI_RESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_type) value that identifies the type of this resource.

### `Width`

The width of the resource. This is in texels, if the resource is a texture, or bytes if the resource is a buffer.

### `Height`

The height of the resource. This applies to two-dimensional and three-dimensional textures.

### `DepthOrArraySize`

The depth, or array size of the resource used when the resource is three-dimensional, or arrayed respectively.

### `MipLevels`

The number of mip levels the resource has.

### `Format`

Specifies how the resource's data is to be interpreted, using a [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration value.

### `SampleDesc`

A [**DXGI_SAMPLE_DESC**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that describes the multi-sampling parameters for the resource.

### `Layout`

A [**D3D12DDI_TEXTURE_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_texture_layout) value that specifies details related to how the memory which comprises the resource is arranged.

### `Flags`

A [**D3D12DDI_RESOURCE_FLAGS_0003**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_flags_0003) value with bitwise-OR'd flags that describe the ways the resource is to be used.

### `InitialResourceState`

Specifies the initial resource state.

### `pRowMajorLayout`

When **Layout** is D3D12DDI_TL_ROW_MAJOR and **pRowMajorLayout** is non-null, then ***pRowMajorLayout** specifies the layout of the resource.

### `SamplerFeedbackMipRegion`

A [**D3D12DDI_MIP_REGION_0075**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_mip_region_0075) structure specifying the size of a mip region.

## Remarks

## See also