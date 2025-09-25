# D3D12_DESCRIPTOR_RANGE_FLAGS enumeration

## Description

Specifies the volatility of both descriptors and the data they reference in a Root Signature 1.1 description, which can enable some driver optimizations.

## Constants

### `D3D12_DESCRIPTOR_RANGE_FLAG_NONE:0`

Default behavior. Descriptors are static, and default assumptions are made for data (for SRV/CBV: DATA_STATIC_WHILE_SET_AT_EXECUTE, and for UAV: DATA_VOLATILE).

### `D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_VOLATILE:0x1`

If this is the only flag set, then descriptors are volatile and default assumptions are made about data (for SRV/CBV: DATA_STATIC_WHILE_SET_AT_EXECUTE, and for UAV: DATA_VOLATILE).

If this flag is combined with DATA_VOLATILE, then both descriptors and data are volatile, which is equivalent to Root Signature Version 1.0.

If this flag is combined with DATA_STATIC_WHILE_SET_AT_EXECUTE, then descriptors are volatile. This still doesn’t allow them to change during command list execution so it is valid to combine the additional declaration that data is static while set via root descriptor table during execution – the underlying descriptors are effectively static for longer than the data is being promised to be static.

### `D3D12_DESCRIPTOR_RANGE_FLAG_DATA_VOLATILE:0x2`

Descriptors are static and the data is volatile.

### `D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC_WHILE_SET_AT_EXECUTE:0x4`

Descriptors are static and data is static while set at execute.

### `D3D12_DESCRIPTOR_RANGE_FLAG_DATA_STATIC:0x8`

Both descriptors and data are static. This maximizes the potential for driver optimization.

### `D3D12_DESCRIPTOR_RANGE_FLAG_DESCRIPTORS_STATIC_KEEPING_BUFFER_BOUNDS_CHECKS:0x10000`

Provides the same benefits as static descriptors (see **D3D12_DESCRIPTOR_RANGE_FLAG_NONE**), except that the driver is not allowed to promote buffers to root descriptors as an optimization, because they must maintain bounds checks and root descriptors do not have those.

## Remarks

This enum is used by the [D3D12_DESCRIPTOR_RANGE1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_range1) structure.

To specify the volatility of just the data referenced by descriptors, refer to [D3D12_ROOT_DESCRIPTOR_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)