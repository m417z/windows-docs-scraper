# D3D12_RESIDENCY_PRIORITY enumeration

## Description

Specifies broad residency priority buckets useful for quickly establishing an application priority scheme.

Applications can assign priority values other than the five values present in this enumeration.

## Constants

### `D3D12_RESIDENCY_PRIORITY_MINIMUM:0x28000000`

Indicates a minimum priority.

### `D3D12_RESIDENCY_PRIORITY_LOW:0x50000000`

Indicates a low priority.

### `D3D12_RESIDENCY_PRIORITY_NORMAL:0x78000000`

Indicates a normal, medium, priority.

### `D3D12_RESIDENCY_PRIORITY_HIGH:0xa0010000`

Indicates a high priority. Applications are discouraged from using priories greater than this. For more information see [ID3D12Device1::SetResidencyPriority](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-setresidencypriority).

### `D3D12_RESIDENCY_PRIORITY_MAXIMUM:0xc8000000`

Indicates a maximum priority. Applications are discouraged from using priorities greater than this; **D3D12_RESIDENCY_PRIORITY_MAXIMUM** is not guaranteed to be available. For more information see [ID3D12Device1::SetResidencyPriority](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-setresidencypriority)

## Remarks

This enum is used by the [SetResidencyPriority](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device1-setresidencypriority) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)