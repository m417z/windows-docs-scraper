# ID3D12GraphicsCommandList::ResolveQueryData

## Description

Extracts data from a query. **ResolveQueryData** works with all heap types (default, upload, and readback).

## Parameters

### `pQueryHeap` [in]

Type: **[ID3D12QueryHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12queryheap)***

Specifies the [ID3D12QueryHeap](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12queryheap) containing the queries to resolve.

### `Type` [in]

Type: **[D3D12_QUERY_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_query_type)**

Specifies the type of query, one member of [D3D12_QUERY_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_query_type).

### `StartIndex` [in]

Type: **UINT**

Specifies an index of the first query to resolve.

### `NumQueries` [in]

Type: **UINT**

Specifies the number of queries to resolve.

### `pDestinationBuffer` [in]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)***

Specifies an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) destination buffer, which must be in the state
[D3D12_RESOURCE_STATE_COPY_DEST](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states).

### `AlignedDestinationBufferOffset` [in]

Type: **UINT64**

Specifies an alignment offset into the destination buffer.
Must be a multiple of 8 bytes.

## Remarks

**ResolveQueryData** performs a batched operation that writes query data into a destination buffer. Query data is written contiguously to the destination buffer, and the parameter.
**ResolveQueryData** turns application-opaque query data in an application-opaque query heap into adapter-agnostic values usable by your application. Resolving queries within a heap that have not been completed (so have had [**ID3D12GraphicsCommandList::BeginQuery**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-beginquery) called for them, but not [**ID3D12GraphicsCommandList::EndQuery**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-endquery)), or that have been uninitialized, results in undefined behavior and might cause device hangs or removal. The debug layer will emit an error if it detects an application has resolved incomplete or uninitialized queries.

> [!NOTE]
> Resolving incomplete or uninitialized queries is undefined behavior because the driver might internally store GPUVAs or other data within unresolved queries. And so attempting to resolve these queries on uninitialized data could cause a page fault or device hang. Older versions of the debug layer didn't validate this behavior.

Binary occlusion queries write 64-bits per query. The least significant bit is either 0 (the object was entirely occluded) or 1 (at least 1 sample of the object would have been drawn). The rest of the bits are 0. Occlusion queries write 64-bits per query. The value is the number of samples that passed testing. Timestamp queries write 64-bits per query, which is a tick value that must be compared to the respective command queue frequency (see [Timing](https://learn.microsoft.com/windows/win32/direct3d12/timing)).

Pipeline statistics queries write a [**D3D12_QUERY_DATA_PIPELINE_STATISTICS**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_query_data_pipeline_statistics) structure per query. All stream-out statistics queries write a [**D3D12_QUERY_DATA_SO_STATISTICS**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_query_data_so_statistics) structure per query.

The core runtime will validate the following.

* *StartIndex* and *NumQueries* are within range.
* *AlignedDestinationBufferOffset* is a multiple of 8 bytes.
* *DestinationBuffer* is a buffer.
* The written data will not overflow the output buffer.
* The query type must be supported by the command list type.
* The query type must be supported by the query heap.

The debug layer will issue a warning if the destination buffer is not in the D3D12_RESOURCE_STATE_COPY_DEST state,
or if any queries being resolved have not had [**ID3D12GraphicsCommandList::EndQuery**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-endquery) called on them.

## Examples

The [D3D12PredicationQueries](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::ResolveQueryData** as follows:

```cpp
// Fill the command list with all the render commands and dependent state.
void D3D12PredicationQueries::PopulateCommandList()
{
    // Command list allocators can only be reset when the associated
    // command lists have finished execution on the GPU; apps should use
    // fences to determine GPU execution progress.
    ThrowIfFailed(m_commandAllocators[m_frameIndex]->Reset());

    // However, when ExecuteCommandList() is called on a particular command
    // list, that command list can then be reset at any time and must be before
    // re-recording.
    ThrowIfFailed(m_commandList->Reset(m_commandAllocators[m_frameIndex].Get(), m_pipelineState.Get()));

    // Set necessary state.
    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_cbvHeap.Get() };
    m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);

    // Indicate that the back buffer will be used as a render target.
    m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET));

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

    // Record commands.
    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->ClearDepthStencilView(dsvHandle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    // Draw the quads and perform the occlusion query.
    {
        CD3DX12_GPU_DESCRIPTOR_HANDLE cbvFarQuad(m_cbvHeap->GetGPUDescriptorHandleForHeapStart(), m_frameIndex * CbvCountPerFrame, m_cbvSrvDescriptorSize);
        CD3DX12_GPU_DESCRIPTOR_HANDLE cbvNearQuad(cbvFarQuad, m_cbvSrvDescriptorSize);

        m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);

        // Draw the far quad conditionally based on the result of the occlusion query
        // from the previous frame.
        m_commandList->SetGraphicsRootDescriptorTable(0, cbvFarQuad);
        m_commandList->SetPredication(m_queryResult.Get(), 0, D3D12_PREDICATION_OP_EQUAL_ZERO);
        m_commandList->DrawInstanced(4, 1, 0, 0);

        // Disable predication and always draw the near quad.
        m_commandList->SetPredication(nullptr, 0, D3D12_PREDICATION_OP_EQUAL_ZERO);
        m_commandList->SetGraphicsRootDescriptorTable(0, cbvNearQuad);
        m_commandList->DrawInstanced(4, 1, 4, 0);

        // Run the occlusion query with the bounding box quad.
        m_commandList->SetGraphicsRootDescriptorTable(0, cbvFarQuad);
        m_commandList->SetPipelineState(m_queryState.Get());
        m_commandList->BeginQuery(m_queryHeap.Get(), D3D12_QUERY_TYPE_BINARY_OCCLUSION, 0);
        m_commandList->DrawInstanced(4, 1, 8, 0);
        m_commandList->EndQuery(m_queryHeap.Get(), D3D12_QUERY_TYPE_BINARY_OCCLUSION, 0);

        // Resolve the occlusion query and store the results in the query result buffer
        // to be used on the subsequent frame.
        m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_queryResult.Get(), D3D12_RESOURCE_STATE_PREDICATION, D3D12_RESOURCE_STATE_COPY_DEST));
        m_commandList->ResolveQueryData(m_queryHeap.Get(), D3D12_QUERY_TYPE_BINARY_OCCLUSION, 0, 1, m_queryResult.Get(), 0);
        m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_queryResult.Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PREDICATION));
    }

    // Indicate that the back buffer will now be used to present.
    m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT));

    ThrowIfFailed(m_commandList->Close());
}

```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist)