# D3D12_CACHED_PIPELINE_STATE structure

## Description

Stores a pipeline state.

## Members

### `pCachedBlob`

Specifies pointer that references the memory location of the cache.

### `CachedBlobSizeInBytes`

Specifies the size of the cache in bytes.

## Remarks

This structure is used by the [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure, and the [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structure.

This structure is intended to be filled with the data retrieved from [ID3D12PipelineState::GetCachedBlob](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12pipelinestate-getcachedblob). This cached PSO contains data specific to the hardware, driver, and machine that it was retrieved from. Compilation using this data should be faster than compilation without. The rest of the data in the PSO needs to still be valid, and needs to match the cached PSO, otherwise E_INVALIDARG might be returned.

If the driver has been upgraded to a D3D12 driver after the PSO was cached, you might see a D3D12_ERROR_DRIVER_VERSION_MISMATCH return code, or if you’re running on a different GPU, the D3D12_ERROR_ADAPTER_NOT_FOUND return code.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)