# ID3D12GraphicsCommandList::SetGraphicsRootConstantBufferView

## Description

Sets a CPU descriptor handle for the constant buffer in the graphics root signature.

## Parameters

### `RootParameterIndex` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The slot number for binding.

### `BufferLocation` [in]

Type: **D3D12_GPU_VIRTUAL_ADDRESS**

The GPU virtual address of the constant buffer.
D3D12_GPU_VIRTUAL_ADDRESS is a typedef'd alias of UINT64.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)