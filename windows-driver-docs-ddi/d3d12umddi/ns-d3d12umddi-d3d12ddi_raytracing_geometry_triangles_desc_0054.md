# D3D12DDI_RAYTRACING_GEOMETRY_TRIANGLES_DESC_0054 structure

## Description

Describes a ray tracing triangle geometry.

## Members

### `ColumnMajorTransform3x4`

Address of a 3x4 affine transform matrix in row major layout to be applied to the vertices in the *VertexBuffer* during an acceleration structure build. The contents of *VertexBuffer* are not modified. If a 2D vertex format is used, the transformation is applied with the third vertex component assumed to be zero.

If ColumnMajorTransform3x4 is NULL the vertices will not be transformed. Using ColumnMajorTransform3x4 may result in increased computation and/or memory requirements for the acceleration structure build.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.

### `IndexFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format), representing the format of the indices in *IndexBuffer*. This value must be one of the following:

* DXGI_FORMAT_UNKNOWN (when *IndexBuffer* is NULL)
* DXGI_FORMAT_R32_UINT
* DXGI_FORMAT_R16_UINT

### `VertexFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format), representing the format of the vertices (positions) in *VertexBuffer*. This value must be one of the following:

* DXGI_FORMAT_R32G32_FLOAT (third component assumed 0)
* DXGI_FORMAT_R32G32B32_FLOAT
* DXGI_FORMAT_R16G16_FLOAT (third component assumed 0)
* DXGI_FORMAT_R16G16B16A16_FLOAT

### `IndexCount`

Number of indices in *IndexBuffer*. Must be 0 if *IndexBuffer* is NULL.

### `VertexCount`

Number of vertices (positions) in *VertexBuffer*.

### `IndexBuffer`

Array of vertex indices. If NULL, triangles are non-indexed. The address must be aligned to the size of *IndexFormat*.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.

### `VertexBuffer`

Array of vertices including a stride. The alignment on the address and stride must be a multiple of the component size, meaning, 4 bytes for formats with 32-bit components and 2 bytes for formats with 16-bit components. There is no constraint on the stride (whereas there is a limit for graphics), other than that the bottom 32-bits of the value are all that are used. This means that the field is UINT64 purely to make neighboring fields align cleanly and obviously everywhere. Each vertex position is expected to be at the start address of the stride range and any excess space is ignored by acceleration structure builds. This excess space might contain other app data such as vertex attributes, which the app is responsible for manually fetching in shaders, whether it is interleaved in vertex buffers or elsewhere.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE.

## Remarks

The geometry pointed to by this structure is always in triangle list from (indexed or non-indexed form). Strips are not supported.

## See also