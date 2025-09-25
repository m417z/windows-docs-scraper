# D3D12_RANGE_UINT64 structure

## Description

Describes a memory range in a 64-bit address space.

## Members

### `Begin`

The offset, in bytes, denoting the beginning of a memory range.

### `End`

The offset, in bytes, denoting the end of a memory range.
**End** is one-past-the-end.

## Remarks

**End** is one-past-the-end.
When **Begin** equals **End**, the range is empty.
The size of the range is (**End** - **Begin**).

This structure is used by the [D3D12_SUBRESOURCE_RANGE_UINT64](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_range_uint64) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)