# D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC structure

## Description

Describes a set of triangles used as raytracing geometry. The geometry pointed to by this struct are always in triangle list form, indexed or non-indexed. Triangle strips are not supported.

## Members

### `Transform3x4`

Address of a 3x4 affine transform matrix in row-major layout to be applied to the vertices in the *VertexBuffer* during an acceleration structure build. The contents of *VertexBuffer* are not modified. If a 2D vertex format is used, the transformation is applied with the third vertex component assumed to be zero.

If *Transform3x4* is NULL the vertices will not be transformed. Using *Transform3x4* may result in increased computation and/or memory requirements for the acceleration structure build.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states). The address must be aligned to 16 bytes, defined as [D3D12_RAYTRACING_TRANSFORM3X4_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

### `IndexFormat`

Format of the indices in the *IndexBuffer*. Must be one of the following:

* **DXGI_FORMAT_UNKNOWN** - when IndexBuffer is NULL
* **DXGI_FORMAT_R32_UINT**
* **DXGI_FORMAT_R16_UINT**

### `VertexFormat`

Format of the vertices in *VertexBuffer*. Must be one of the following:

* **DXGI_FORMAT_R32G32_FLOAT** - third component is assumed 0
* **DXGI_FORMAT_R32G32B32_FLOAT**
* **DXGI_FORMAT_R16G16_FLOAT** - third component is assumed 0
* **DXGI_FORMAT_R16G16B16A16_FLOAT**  - A16 component is ignored, other data can be packed there, such as setting vertex stride to 6 bytes.
* **DXGI_FORMAT_R16G16_SNORM**  - third component is assumed 0
* **DXGI_FORMAT_R16G16B16A16_SNORM**   - A16 component is ignored, other data can be packed there, such as setting vertex stride to 6 bytes.

Tier 1.1 devices support the following additional formats:

* **DXGI_FORMAT_R16G16B16A16_UNORM**   - A16 component is ignored, other data can be packed there, such as setting vertex stride to 6 bytes
* **DXGI_FORMAT_R16G16_UNORM**   - third component assumed 0
* **DXGI_FORMAT_R10G10B10A2_UNORM**   - A2 component is ignored, stride must be 4 bytes
* **DXGI_FORMAT_R8G8B8A8_UNORM**   - A8 component is ignored, other data can be packed there, such as setting vertex stride to 3 bytes
* **DXGI_FORMAT_R8G8_UNORM**   - third component assumed 0
* **DXGI_FORMAT_R8G8B8A8_SNORM**  - A8 component is ignored, other data can be packed there, such as setting vertex stride to 3 bytes
* **DXGI_FORMAT_R8G8_SNORM**   - third component assumed 0

### `IndexCount`

Number of indices in *IndexBuffer*. Must be 0 if *IndexBuffer* is NULL.

### `VertexCount`

Number of vertices in *VertexBuffer*.

### `IndexBuffer`

Array of vertex indices. If NULL, triangles are non-indexed. Just as with graphics, the address must be aligned to the size of *IndexFormat*.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states). Note that if an app wants to share index buffer inputs between graphics input assembler and raytracing acceleration structure build input, it can always put a resource into a combination of read states simultaneously, e.g. **D3D12_RESOURCE_STATE_INDEX_BUFFER** | **D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE**.

### `VertexBuffer`

Array of vertices including a stride. The alignment on the address and stride must be a multiple of the component size, so 4 bytes for formats with 32bit components and 2 bytes for formats with 16bit components. Unlike graphics, there is no constraint on the stride, other than that the bottom 32bits of the value are all that are used – the field is UINT64 purely to make neighboring fields align cleanly/obviously everywhere. Each vertex position is expected to be at the start address of the stride range and any excess space is ignored by acceleration structure builds. This excess space might contain other app data such as vertex attributes, which the app is responsible for manually fetching in shaders, whether it is interleaved in vertex buffers or elsewhere.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states). Note that if an app wants to share vertex buffer inputs between graphics input assembler and raytracing acceleration structure build input, it can always put a resource into a combination of read states simultaneously, e.g. **D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER** | **D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE**