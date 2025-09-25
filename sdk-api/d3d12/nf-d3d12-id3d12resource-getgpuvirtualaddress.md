# ID3D12Resource::GetGPUVirtualAddress

## Description

This method returns the GPU virtual address of a buffer resource.

## Return value

Type: **D3D12_GPU_VIRTUAL_ADDRESS**

This method returns the GPU virtual address.
D3D12_GPU_VIRTUAL_ADDRESS is a typedef'd synonym of UINT64.

## Remarks

This method is only useful for buffer resources, it will return zero for all texture resources.

For more information on the use of GPU virtual addresses, refer to [Indirect Drawing](https://learn.microsoft.com/windows/desktop/direct3d12/indirect-drawing).

#### Examples

The [D3D1211on12](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Resource::GetGPUVirtualAddress** as follows:

```cpp
// Initialize the vertex buffer view.
m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
m_vertexBufferView.StrideInBytes = sizeof(Vertex);
m_vertexBufferView.SizeInBytes = vertexBufferSize;

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)