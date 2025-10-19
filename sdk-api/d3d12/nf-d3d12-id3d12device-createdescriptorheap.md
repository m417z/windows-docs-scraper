# ID3D12Device::CreateDescriptorHeap

## Description

Creates a descriptor heap object.

## Parameters

### `pDescriptorHeapDesc` [in]

Type: **const [D3D12_DESCRIPTOR_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_heap_desc)***

A pointer to a [D3D12_DESCRIPTOR_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_descriptor_heap_desc) structure that describes the heap.

### `riid`

Type: **REFIID**

The globally unique identifier (**GUID**) for the descriptor heap interface. See Remarks.
An input parameter.

### `ppvHeap` [out]

Type: **void****

A pointer to a memory block that receives a pointer to the descriptor heap.
*ppvHeap* can be NULL, to enable capability testing.
When *ppvHeap* is NULL, no object will be created and S_FALSE will be returned when *pDescriptorHeapDesc* is valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns **E_OUTOFMEMORY** if there is insufficient memory to create the descriptor heap object.
See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

The **REFIID**, or **GUID**, of the interface to the descriptor heap can be obtained by using the __uuidof() macro. For example, __uuidof([ID3D12DescriptorHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12descriptorheap)) will get the **GUID** of the interface to a descriptor heap.

#### Examples

The [D3D12HelloWorld](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::CreateDescriptorHeap** as follows:

Describe and create a render target view (RTV) descriptor heap.

```cpp
// Create descriptor heaps.
{
    // Describe and create a render target view (RTV) descriptor heap.
    D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
    rtvHeapDesc.NumDescriptors = FrameCount;
    rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    ThrowIfFailed(m_device->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&m_rtvHeap)));

    m_rtvDescriptorSize = m_device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
}

// Create frame resources.
{
    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

    // Create a RTV for each frame.
    for (UINT n = 0; n < FrameCount; n++)
    {
        ThrowIfFailed(m_swapChain->GetBuffer(n, IID_PPV_ARGS(&m_renderTargets[n])));
        m_device->CreateRenderTargetView(m_renderTargets[n].Get(), nullptr, rtvHandle);
        rtvHandle.Offset(1, m_rtvDescriptorSize);
    }

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)