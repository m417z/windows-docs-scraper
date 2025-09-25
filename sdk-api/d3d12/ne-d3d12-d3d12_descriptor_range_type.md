# D3D12_DESCRIPTOR_RANGE_TYPE enumeration

## Description

Specifies a range so that, for example, if part of a descriptor table has 100 shader-resource views (SRVs) that range can be declared in one entry rather than 100.

## Constants

### `D3D12_DESCRIPTOR_RANGE_TYPE_SRV:0`

Specifies a range of SRVs.

### `D3D12_DESCRIPTOR_RANGE_TYPE_UAV`

Specifies a range of unordered-access views (UAVs).

### `D3D12_DESCRIPTOR_RANGE_TYPE_CBV`

Specifies a range of constant-buffer views (CBVs).

### `D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER`

Specifies a range of samplers.

## Remarks

This enum is used by the [D3D12_DESCRIPTOR_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)