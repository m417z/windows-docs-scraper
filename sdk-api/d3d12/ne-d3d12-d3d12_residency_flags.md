# D3D12_RESIDENCY_FLAGS enumeration

## Description

Used with the EnqueuMakeResident function to choose how residency operations proceed when the memory budget is exceeded.

## Constants

### `D3D12_RESIDENCY_FLAG_NONE:0`

Specifies the default residency policy, which allows residency operations to succeed regardless of the application's current memory budget. EnqueueMakeResident returns E_OUTOFMEMORY only when there is no memory available.

### `D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET:0x1`

Specifies that the EnqueueMakeResident function should return E_OUTOFMEMORY when the residency operation would exceed the application's current memory budget.

## Remarks

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)