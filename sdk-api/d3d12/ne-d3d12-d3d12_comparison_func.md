# D3D12_COMPARISON_FUNC enumeration

## Description

Specifies comparison options.

## Constants

### `D3D12_COMPARISON_FUNC_NEVER:1`

Never pass the comparison.

### `D3D12_COMPARISON_FUNC_LESS:2`

If the source data is less than the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_EQUAL:3`

If the source data is equal to the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_LESS_EQUAL:4`

If the source data is less than or equal to the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_GREATER:5`

If the source data is greater than the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_NOT_EQUAL:6`

If the source data is not equal to the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_GREATER_EQUAL:7`

If the source data is greater than or equal to the destination data, the comparison passes.

### `D3D12_COMPARISON_FUNC_ALWAYS:8`

Always pass the comparison.

## Remarks

A comparison option determines how the runtime compares source (new) data against destination (existing) data before storing the new data. The comparison option is declared in a description before an object is created. The API allows you to set a comparison option for

* a depth-stencil buffer ([D3D12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc))
* depth-stencil operations ([D3D12_DEPTH_STENCILOP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_depth_stencilop_desc))
* sampler state ([D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc))

## See also

[CD3DX12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-depth-stencil-desc)

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)