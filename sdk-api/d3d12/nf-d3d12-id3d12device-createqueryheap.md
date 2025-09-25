# ID3D12Device::CreateQueryHeap

## Description

Creates a query heap.
A query heap contains an array of queries.

## Parameters

### `pDesc` [in]

Type: **const [D3D12_QUERY_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_query_heap_desc)***

Specifies the query heap in a [D3D12_QUERY_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_query_heap_desc) structure.

### `riid`

Type: **REFIID**

Specifies a REFIID that uniquely identifies the heap.

### `ppvHeap` [out, optional]

Type: **void****

Specifies a pointer to the heap, that will be returned on successful completion of the method.
*ppvHeap* can be NULL, to enable capability testing.
When *ppvHeap* is NULL, no object will be created and S_FALSE will be returned when *pDesc* is valid.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Refer to [Queries](https://learn.microsoft.com/windows/desktop/direct3d12/queries) for more information.

#### Examples

The [D3D12PredicationQueries](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12Device::CreateQueryHeap** as follows:

Create a query heap and a query result buffer.

```cpp
// Pipeline objects.
D3D12_VIEWPORT m_viewport;
D3D12_RECT m_scissorRect;
ComPtr<IDXGISwapChain3> m_swapChain;
ComPtr<ID3D12Device> m_device;
ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
ComPtr<ID3D12CommandAllocator> m_commandAllocators[FrameCount];
ComPtr<ID3D12CommandQueue> m_commandQueue;
ComPtr<ID3D12RootSignature> m_rootSignature;
ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
ComPtr<ID3D12DescriptorHeap> m_cbvHeap;
ComPtr<ID3D12DescriptorHeap> m_dsvHeap;
ComPtr<ID3D12QueryHeap> m_queryHeap;
UINT m_rtvDescriptorSize;
UINT m_cbvSrvDescriptorSize;
UINT m_frameIndex;

// Synchronization objects.
ComPtr<ID3D12Fence> m_fence;
UINT64 m_fenceValues[FrameCount];
HANDLE m_fenceEvent;

// Asset objects.
ComPtr<ID3D12PipelineState> m_pipelineState;
ComPtr<ID3D12PipelineState> m_queryState;
ComPtr<ID3D12GraphicsCommandList> m_commandList;
ComPtr<ID3D12Resource> m_vertexBuffer;
ComPtr<ID3D12Resource> m_constantBuffer;
ComPtr<ID3D12Resource> m_depthStencil;
ComPtr<ID3D12Resource> m_queryResult;
D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;

```

```cpp
// Describe and create a heap for occlusion queries.
D3D12_QUERY_HEAP_DESC queryHeapDesc = {};
queryHeapDesc.Count = 1;
queryHeapDesc.Type = D3D12_QUERY_HEAP_TYPE_OCCLUSION;
ThrowIfFailed(m_device->CreateQueryHeap(&queryHeapDesc, IID_PPV_ARGS(&m_queryHeap)));

```

Refer to the [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)