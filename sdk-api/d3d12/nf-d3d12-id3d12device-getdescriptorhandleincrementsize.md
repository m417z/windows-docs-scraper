# ID3D12Device::GetDescriptorHandleIncrementSize

## Description

Gets the size of the handle increment for the given type of descriptor heap. This value is typically used to increment a handle into a descriptor array by the correct amount.

## Parameters

### `DescriptorHeapType` [in]

The [D3D12_DESCRIPTOR_HEAP_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_descriptor_heap_type)-typed value that specifies the type of descriptor heap to get the size of the handle increment for.

## Return value

Returns the size of the handle increment for the given type of descriptor heap, including any necessary padding.

## Remarks

The descriptor size returned by this method is used as one input to the helper structures [CD3DX12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-cpu-descriptor-handle) and [CD3DX12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-gpu-descriptor-handle).

#### Examples

The [D3D12PredicationQueries](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::GetDescriptorHandleIncrementSize** as follows:

Create the descriptor heap for the resources. The `m_rtvDescriptorSize` variable stores the render target view descriptor handle increment size, and is used in the **Create frame resources** section of the code.

```cpp
// Create descriptor heaps.
{
    // Describe and create a render target view (RTV) descriptor heap.
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = FrameCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));

    // Describe and create a depth stencil view (DSV) descriptor heap.
    D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
    dsvHeapDesc.NumDescriptors = 1;
    dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    ThrowIfFailed(m_device->CreateDescriptorHeap(&dsvHeapDesc, IID_PPV_ARGS(&m_dsvHeap)));

    // Describe and create a constant buffer view (CBV) descriptor heap.
    D3D12_DESCRIPTOR_HEAP_DESC cbvHeapDesc = {};
    cbvHeapDesc.NumDescriptors = CbvCountPerFrame * FrameCount;
    cbvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    ThrowIfFailed(m_device->CreateDescriptorHeap(&cbvHeapDesc, IID_PPV_ARGS(&m_cbvHeap)));

    // Describe and create a heap for occlusion queries.
    D3D12_QUERY_HEAP_DESC queryHeapDesc = {};
    queryHeapDesc.Count = 1;
    queryHeapDesc.Type = D3D12_QUERY_HEAP_TYPE_OCCLUSION;
    ThrowIfFailed(m_device->CreateQueryHeap(&queryHeapDesc, IID_PPV_ARGS(&m_queryHeap)));

    m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
    m_cbvSrvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
}

// Create frame resources.
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    // Create a RTV and a command allocator for each frame.
    for (UINT n = 0; n < FrameCount; n++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
        m_device->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);

        ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_commandAllocators[n])));
    }
}

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)