# D3D12_RANGE structure

## Description

Describes a memory range.

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

This structure is used by the [Map](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-map) and [Unmap](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-unmap) methods.

## See also

[CD3DX12_RANGE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-range)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)