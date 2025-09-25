# D3D12_DISPATCH_RAYS_DESC structure

## Description

Describes the properties of a ray dispatch operation initiated with a call to [ID3D12GraphicsCommandList4::DispatchRays](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-dispatchrays).

## Members

### `RayGenerationShaderRecord`

The shader record for the ray generation shader to use.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

The address must be aligned to 64 bytes, defined as [D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), and in the range [0...4096] bytes.

### `MissShaderTable`

The shader table for miss shaders.

The stride is record stride, and must be aligned to 32 bytes, defined as [D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), and in the range [0...4096] bytes. 0 is allowed.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

The address must be aligned to 64 bytes, defined as [D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

### `HitGroupTable`

The shader table for hit groups.

The stride is record stride, and must be aligned to 32 bytes, defined as [D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), and in the range [0...4096] bytes. 0 is allowed.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

The address must be aligned to 64 bytes, defined as [D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

### `CallableShaderTable`

The shader table for callable shaders.

The stride is record stride, and must be aligned to 32 bytes, defined as [D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants). 0 is allowed.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

The address must be aligned to 64 bytes, defined as [D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

### `Width`

The width of the generation shader thread grid.

### `Height`

The height of the generation shader thread grid.

### `Depth`

The depth of the generation shader thread grid.