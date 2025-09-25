# D3D12_COMPUTE_PIPELINE_STATE_DESC structure

## Description

Describes a compute pipeline state object.

## Members

### `pRootSignature`

A pointer to the [ID3D12RootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12rootsignature) object.

### `CS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the compute shader.

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set bits to identify the nodes (the device's physical adapters) for which the compute pipeline state is to apply.
Each bit in the mask corresponds to a single node.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `CachedPSO`

A cached pipeline state object, as a [D3D12_CACHED_PIPELINE_STATE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cached_pipeline_state) structure. pCachedBlob and CachedBlobSizeInBytes may be set to NULL and 0 respectively.

### `Flags`

A [D3D12_PIPELINE_STATE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_pipeline_state_flags) enumeration constant such as for "tool debug".

## Remarks

This structure is used by [CreateComputePipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-createcomputepipelinestate).

## See also

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)