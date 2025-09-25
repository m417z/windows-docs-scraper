## Description

Defines constants that specify a shading rate combiner (for variable-rate shading, or VRS). For more info, see [Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs).

## Constants

### `D3D12_SHADING_RATE_COMBINER_PASSTHROUGH:0`

Specifies the combiner `C.xy = A.xy`, for combiner (C) and inputs (A and B).

### `D3D12_SHADING_RATE_COMBINER_OVERRIDE:1`

Specifies the combiner `C.xy = B.xy`, for combiner (C) and inputs (A and B).

### `D3D12_SHADING_RATE_COMBINER_MIN:2`

Specifies the combiner `C.xy = max(A.xy, B.xy)`, for combiner (C) and inputs (A and B).

### `D3D12_SHADING_RATE_COMBINER_MAX:3`

Specifies the combiner `C.xy = min(A.xy, B.xy)`, for combiner (C) and inputs (A and B).

### `D3D12_SHADING_RATE_COMBINER_SUM:4`

Specifies the combiner C.xy = min(maxRate, A.xy + B.xy)`, for combiner (C) and inputs (A and B).

## Remarks

## See also

[Variable-rate shading (VRS)](https://learn.microsoft.com/windows/desktop/direct3d12/vrs)