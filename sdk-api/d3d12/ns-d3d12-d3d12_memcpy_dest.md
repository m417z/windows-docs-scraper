# D3D12_MEMCPY_DEST structure

## Description

Describes the destination of a memory copy operation.

## Members

### `pData`

A pointer to a memory block that receives the copied data.

### `RowPitch`

The row pitch, or width, or physical size, in bytes, of the subresource data.

### `SlicePitch`

The slice pitch, or width, or physical size, in bytes, of the subresource data.

## Remarks

This structure is used by a number of helper methods, refer to [Helper Structures and Functions for D3D12](https://learn.microsoft.com/windows/desktop/direct3d12/helper-structures-and-functions-for-d3d12).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)