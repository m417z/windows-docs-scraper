# D3D12_CONSTANT_BUFFER_VIEW_DESC structure

## Description

Describes a constant buffer to view.

## Members

### `BufferLocation`

The D3D12_GPU_VIRTUAL_ADDRESS of the constant buffer.
D3D12_GPU_VIRTUAL_ADDRESS is a typedef'd alias of UINT64.

### `SizeInBytes`

The size in bytes of the constant buffer.

## Remarks

This structure is used by [CreateConstantBufferView](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createconstantbufferview).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)