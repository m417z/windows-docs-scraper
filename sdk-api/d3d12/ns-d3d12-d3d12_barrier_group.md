## Description

Describes a group of barriers of a given type.

## Members

### `Type`

The type of barriers in the group.

### `NumBarriers`

The number of barriers in the group.

### `pGlobalBarriers`

A pointer to an array of [D3D12_GLOBAL_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_global_barrier) structures, if *Type* is **D3D12_BARRIER_TYPE::D3D12_BARRIER_TYPE_GLOBAL**.

### `pTextureBarriers`

A pointer to an array of [D3D12_TEXTURE_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_texture_barrier) structures, if *Type* is **D3D12_BARRIER_TYPE::D3D12_BARRIER_TYPE_TEXTURE**.

### `pBufferBarriers`

A pointer to an array of [D3D12_BUFFER_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_buffer_barrier) structures, if *Type* is **D3D12_BARRIER_TYPE::D3D12_BARRIER_TYPE_BUFFER**.

## Remarks

## See also