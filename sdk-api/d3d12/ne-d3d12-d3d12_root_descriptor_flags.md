# D3D12_ROOT_DESCRIPTOR_FLAGS enumeration

## Description

Specifies the volatility of the data referenced by descriptors in a Root Signature 1.1 description, which can enable some driver optimizations.

## Constants

### `D3D12_ROOT_DESCRIPTOR_FLAG_NONE:0`

Default assumptions are made for data (for SRV/CBV: DATA_STATIC_WHILE_SET_AT_EXECUTE, and for UAV: DATA_VOLATILE).

### `D3D12_ROOT_DESCRIPTOR_FLAG_DATA_VOLATILE:0x2`

Data is volatile. Equivalent to Root Signature Version 1.0.

### `D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE:0x4`

Data is static while set at execute.

### `D3D12_ROOT_DESCRIPTOR_FLAG_DATA_STATIC:0x8`

Data is static. The best potential for driver optimization.

## Remarks

This enum is used by the [D3D12_ROOT_DESCRIPTOR1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1) structure.

To specify the volatility of both descriptors and data, refer to [D3D12_DESCRIPTOR_RANGE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_range_flags).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)