# D3D12DDI_INDIRECT_ARGUMENT_TYPE enumeration

## Description

The **D3D12DDI_INDIRECT_ARGUMENT_TYPE** enumeration specifies the type of the indirect parameter for indirect dispatch.

## Constants

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_DRAW`

Indicates the type is a Draw call.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED`

Indicates the type is a DrawIndexed call.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_DISPATCH`

Indicates the type is a Dispatch call.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW`

Indicates the type is a vertex buffer view.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW`

Indicates the type is an index buffer view.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_CONSTANT`

Indicates the type is a constant.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW`

Indicates the type is a constant buffer view (CBV).

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW`

Indicates the type is a shader resource view (SRV).

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW`

Indicates the type is an unordered access view (UAV).

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_DISPATCH_RAYS`

Indicates the type is a DispatchRays call. Available starting with Windows 10, version 2004.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_DISPATCH_MESH`

Indicates the type is a DispatchMesh call. Available starting with Windows 10, version 2004.

### `D3D12DDI_INDIRECT_ARGUMENT_TYPE_INCREMENTING_CONSTANT`

Indicates the type is an incrementing constant.

## Remarks

**D3D12DDI_INDIRECT_ARGUMENT_TYPE** is a member of [**D3D12DDI_INDIRECT_ARGUMENT_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_indirect_argument_desc).

See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also

[**D3D12DDI_INDIRECT_ARGUMENT_DESC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_indirect_argument_desc)