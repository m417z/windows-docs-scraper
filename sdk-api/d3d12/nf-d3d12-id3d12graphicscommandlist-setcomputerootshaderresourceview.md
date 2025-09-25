# ID3D12GraphicsCommandList::SetComputeRootShaderResourceView

## Description

Sets a CPU descriptor handle for the shader resource in the compute root signature.

## Parameters

### `RootParameterIndex` [in]

Type: **UINT**

The slot number for binding.

### `BufferLocation` [in]

Type: **D3D12_GPU_VIRTUAL_ADDRESS**

The GPU virtual address of the buffer.
D3D12_GPU_VIRTUAL_ADDRESS is a typedef'd alias of UINT64.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)