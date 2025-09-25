# D3D12_INDEX_BUFFER_VIEW structure

## Description

Describes the index buffer to view.

## Members

### `BufferLocation`

The GPU virtual address of the index buffer.
D3D12_GPU_VIRTUAL_ADDRESS is a typedef'd synonym of UINT64.

### `SizeInBytes`

The size in bytes of the index buffer.

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the index-buffer format.

## Remarks

This structure is passed into [ID3D12GraphicsCommandList::IASetIndexBuffer](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-iasetindexbuffer).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)