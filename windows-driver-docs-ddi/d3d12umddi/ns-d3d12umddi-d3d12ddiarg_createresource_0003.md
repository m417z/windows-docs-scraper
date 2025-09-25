## Description

The **D3D12DDIARG_CREATERESOURCE_0003** structure contains information needed to describe the creation or size calculation of a resource.

## Members

### `ReuseBufferGPUVA`

The GPU virtual address that this resource should have, if it does not need a new one assigned.

### `ResourceType`

A [**D3D12DDI_RESOURCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_type) that specifies the type of resource.

### `Width`

The width of the resource. This value is in texels if the resource is a texture, or in bytes if the resource is a buffer.

### `Height`

The height of the resource. This member applies to two-dimensional and three-dimensional textures only.

### `DepthOrArraySize`

The depth, or array size of the resource used when the resource is three-dimensional, or arrayed respectively.

### `MipLevels`

The number of mip levels the resource has.

### `Format`

Specifies how the resource's data is to be interpreted, using a [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) enumeration value.

### `SampleDesc`

A [**DXGI_SAMPLE_DESC**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that specifies the sample count and quality level of this resource, as it relates to multisampling.

### `Layout`

A [**D3D12_TEXTURE_LAYOUT**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_texture_layout) that specifies details related to how the memory which comprises the resource is arranged.

### `Flags`

A bitwise-OR-ed value of [**D3D12_RESOURCE_FLAGS**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) flags which describe the ways the resource is to be used.

### `InitialResourceState`

A bitwise-OR-ed value of [**D3D12_RESOURCE_STATES**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) values that describe the initial resource state.

### `pRowMajorLayout`

When **Layout** is D3D12DDI_TL_ROW_MAJOR and **pRowMajorLayout** is non-null, then ***pRowMajorLayout** points to a [**D3D12DDIARG_ROW_MAJOR_RESOURCE_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_row_major_resource_layout) structure that specifies the layout of the resource.

## See also

[**D3D12DDIARG_CREATERESOURCE_0088**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_createresource_0088)