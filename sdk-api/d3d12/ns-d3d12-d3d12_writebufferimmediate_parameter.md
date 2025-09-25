# D3D12_WRITEBUFFERIMMEDIATE_PARAMETER structure

## Description

Specifies the immediate value and destination address written using [ID3D12GraphicsCommandList2::WriteBufferImmediate](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist2-writebufferimmediate).

## Members

### `Dest`

The GPU virtual address at which to write the value. The address must be aligned to a 32-bit (4-byte) boundary.

### `Value`

The 32-bit value to write.

## Remarks

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)