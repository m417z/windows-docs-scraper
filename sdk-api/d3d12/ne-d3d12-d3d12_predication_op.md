# D3D12_PREDICATION_OP enumeration

## Description

Specifies the predication operation to apply.

## Constants

### `D3D12_PREDICATION_OP_EQUAL_ZERO:0`

Enables predication if all 64-bits are zero.

### `D3D12_PREDICATION_OP_NOT_EQUAL_ZERO:1`

Enables predication if at least one of the 64-bits are not zero.

## Remarks

This enum is used by [SetPredication](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setpredication).

Predication is decoupled from queries.
Predication can be set based on the value of 64-bits within a buffer.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Predication](https://learn.microsoft.com/windows/desktop/direct3d12/predication)