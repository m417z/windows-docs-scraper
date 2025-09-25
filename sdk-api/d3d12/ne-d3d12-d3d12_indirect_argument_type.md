# D3D12_INDIRECT_ARGUMENT_TYPE enumeration

## Description

Specifies the type of the indirect parameter.

## Constants

### `D3D12_INDIRECT_ARGUMENT_TYPE_DRAW:0`

Indicates the type is a Draw call.

### `D3D12_INDIRECT_ARGUMENT_TYPE_DRAW_INDEXED`

Indicates the type is a DrawIndexed call.

### `D3D12_INDIRECT_ARGUMENT_TYPE_DISPATCH`

Indicates the type is a Dispatch call.

### `D3D12_INDIRECT_ARGUMENT_TYPE_VERTEX_BUFFER_VIEW`

Indicates the type is a vertex buffer view.

### `D3D12_INDIRECT_ARGUMENT_TYPE_INDEX_BUFFER_VIEW`

Indicates the type is an index buffer view.

### `D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT`

Indicates the type is a constant.

### `D3D12_INDIRECT_ARGUMENT_TYPE_CONSTANT_BUFFER_VIEW`

Indicates the type is a constant buffer view (CBV).

### `D3D12_INDIRECT_ARGUMENT_TYPE_SHADER_RESOURCE_VIEW`

Indicates the type is a shader resource view (SRV).

### `D3D12_INDIRECT_ARGUMENT_TYPE_UNORDERED_ACCESS_VIEW`

Indicates the type is an unordered access view (UAV).

## Remarks

This enum is used by the [D3D12_INDIRECT_ARGUMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_indirect_argument_desc) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)