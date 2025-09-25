# ID3D12GraphicsCommandList::ExecuteIndirect

## Description

Apps perform indirect draws/dispatches using the **ExecuteIndirect** method.

## Parameters

### `pCommandSignature` [in]

Type: **[ID3D12CommandSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandsignature)***

Specifies a [ID3D12CommandSignature](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandsignature). The data referenced by *pArgumentBuffer* will be interpreted depending on the contents of the command signature. Refer to [Indirect Drawing](https://learn.microsoft.com/windows/desktop/direct3d12/indirect-drawing) for the APIs that are used to create a command signature.

### `MaxCommandCount` [in]

Type: **UINT**

There are two ways that command counts can be specified:

* If *pCountBuffer* is not NULL, then *MaxCommandCount* specifies the maximum number of operations which will be performed. The actual number of operations to be performed are defined by the minimum of this value, and a 32-bit unsigned integer contained in *pCountBuffer* (at the byte offset specified by *CountBufferOffset*).
* If *pCountBuffer* is NULL, the *MaxCommandCount* specifies the exact number of operations which will be performed.

### `pArgumentBuffer` [in]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

Specifies one or more [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) objects, containing the command arguments.

### `ArgumentBufferOffset` [in]

Type: **UINT64**

Specifies an offset into *pArgumentBuffer* to identify the first command argument.

### `pCountBuffer` [in, optional]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

Specifies a pointer to a [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource).

### `CountBufferOffset` [in]

Type: **UINT64**

Specifies a UINT64 that is the offset into *pCountBuffer*, identifying the argument count.

## Remarks

The semantics of this API are defined with the following pseudo-code:

Non-NULL pCountBuffer:

``` syntax
// Read draw count out of count buffer
UINT CommandCount = pCountBuffer->ReadUINT32(CountBufferOffset);

CommandCount = min(CommandCount, MaxCommandCount)

// Get pointer to first Commanding argument
BYTE* Arguments = pArgumentBuffer->GetBase() + ArgumentBufferOffset;

for(UINT CommandIndex = 0; CommandIndex < CommandCount; CommandIndex++)
{
  // Interpret the data contained in *Arguments
  // according to the command signature
  pCommandSignature->Interpret(Arguments);

  Arguments += pCommandSignature->GetByteStride();
}

```

NULL pCountBuffer:

``` syntax
// Get pointer to first Commanding argument
BYTE* Arguments = pArgumentBuffer->GetBase() + ArgumentBufferOffset;

for(UINT CommandIndex = 0; CommandIndex < MaxCommandCount; CommandIndex++)
{
  // Interpret the data contained in *Arguments
  // according to the command signature
  pCommandSignature->Interpret(Arguments);

  Arguments += pCommandSignature->GetByteStride();
}

```

The debug layer will issue an error if either the count buffer or the argument buffer are not in the D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT state. The core runtime will validate:

* *CountBufferOffset* and *ArgumentBufferOffset* are 4-byte aligned
* *pCountBuffer* and *pArgumentBuffer* are buffer resources (any heap type)
* The offset implied by *MaxCommandCount*, *ArgumentBufferOffset*, and the drawing program stride do not exceed the bounds of *pArgumentBuffer* (similarly for count buffer)
* The command list is a direct command list or a compute command list (not a copy or JPEG decode command list)
* The root signature of the command list matches the root signature of the command signature

The functionality of two APIs from earlier versions of Direct3D, `DrawInstancedIndirect` and `DrawIndexedInstancedIndirect`, are encompassed by **ExecuteIndirect**.

### Bundles

**ID3D12GraphicsCommandList::ExecuteIndirect** is allowed inside of bundle command lists only if all of the following are true:

* CountBuffer is NULL (CPU-specified count only).
* The command signature contains exactly one operation. This implies that the command signature does not contain root arguments changes, nor contain VB/IB binding changes.

### Obtaining buffer virtual addresses

The [ID3D12Resource::GetGPUVirtualAddress](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12resource-getgpuvirtualaddress) method enables an app to retrieve the GPU virtual address of a buffer.

Apps are free to apply byte offsets to virtual addresses before placing them in an indirect argument buffer. Note that all of the D3D12 alignment requirements for VB/IB/CB still apply to the resulting GPU virtual address.

#### Examples

The [D3D12ExecuteIndirect](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::ExecuteIndirect** as follows:

```cpp
// Data structure to match the command signature used for ExecuteIndirect.
struct IndirectCommand
{
    D3D12_GPU_VIRTUAL_ADDRESS cbv;
    D3D12_DRAW_ARGUMENTS drawArguments;
};

```

The call to **ExecuteIndirect** is near the end of this listing, below the comment "Draw the triangles that have not been culled."

```cpp
// Fill the command list with all the render commands and dependent state.
void D3D12ExecuteIndirect::PopulateCommandLists()
{
    // Command list allocators can only be reset when the associated
    // command lists have finished execution on the GPU; apps should use
    // fences to determine GPU execution progress.
    ThrowIfFailed(m_computeCommandAllocators[m_frameIndex]->Reset());
    ThrowIfFailed(m_commandAllocators[m_frameIndex]->Reset());

    // However, when ExecuteCommandList() is called on a particular command
    // list, that command list can then be reset at any time and must be before
    // re-recording.
    ThrowIfFailed(m_computeCommandList->Reset(m_computeCommandAllocators[m_frameIndex].Get(), m_computeState.Get()));
    ThrowIfFailed(m_commandList->Reset(m_commandAllocators[m_frameIndex].Get(), m_pipelineState.Get()));

    // Record the compute commands that will cull triangles and prevent them from being processed by the vertex shader.
    if (m_enableCulling)
    {
        UINT frameDescriptorOffset = m_frameIndex * CbvSrvUavDescriptorCountPerFrame;
        D3D12_GPU_DESCRIPTOR_HANDLE cbvSrvUavHandle = m_cbvSrvUavHeap->GetGPUDescriptorHandleForHeapStart();

        m_computeCommandList->SetComputeRootSignature(m_computeRootSignature.Get());

        ID3D12DescriptorHeap* ppHeaps[] = { m_cbvSrvUavHeap.Get() };
        m_computeCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

        m_computeCommandList->SetComputeRootDescriptorTable(
            SrvUavTable,
            CD3DX12_GPU_DESCRIPTOR_HANDLE(cbvSrvUavHandle, CbvSrvOffset + frameDescriptorOffset, m_cbvSrvUavDescriptorSize));

        m_computeCommandList->SetComputeRoot32BitConstants(RootConstants, 4, reinterpret_cast<void*>(&m_csRootConstants), 0);

        // Reset the UAV counter for this frame.
        m_computeCommandList->CopyBufferRegion(m_processedCommandBuffers[m_frameIndex].Get(), CommandBufferSizePerFrame, m_processedCommandBufferCounterReset.Get(), 0, sizeof(UINT));

        D3D12_RESOURCE_BARRIER barrier = CD3DX12_RESOURCE_BARRIER::Transition(m_processedCommandBuffers[m_frameIndex].Get(), D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
        m_computeCommandList->ResourceBarrier(1, &barrier);

        m_computeCommandList->Dispatch(static_cast<UINT>(ceil(TriangleCount / float(ComputeThreadBlockSize))), 1, 1);
    }

    ThrowIfFailed(m_computeCommandList->Close());

    // Record the rendering commands.
    {
        // Set necessary state.
        m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

        ID3D12DescriptorHeap* ppHeaps[] = { m_cbvSrvUavHeap.Get() };
        m_commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

        m_commandList->RSSetViewports(1, &m_viewport);
        m_commandList->RSSetScissorRects(1, m_enableCulling ? &m_cullingScissorRect : &m_scissorRect);

        // Indicate that the command buffer will be used for indirect drawing
        // and that the back buffer will be used as a render target.
        D3D12_RESOURCE_BARRIER barriers[2] = {
            CD3DX12_RESOURCE_BARRIER::Transition(
                m_enableCulling ? m_processedCommandBuffers[m_frameIndex].Get() : m_commandBuffer.Get(),
                m_enableCulling ? D3D12_RESOURCE_STATE_UNORDERED_ACCESS : D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE,
                D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT),
            CD3DX12_RESOURCE_BARRIER::Transition(
                m_renderTargets[m_frameIndex].Get(),
                D3D12_RESOURCE_STATE_PRESENT,
                D3D12_RESOURCE_STATE_RENDER_TARGET)
        };

        m_commandList->ResourceBarrier(_countof(barriers), barriers);

        CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
        CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(m_dsvHeap->GetCPUDescriptorHandleForHeapStart());
        m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

        // Record commands.
        const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
        m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
        m_commandList->ClearDepthStencilView(dsvHandle, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

        m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
        m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);

        if (m_enableCulling)
        {
            // Draw the triangles that have not been culled.
            m_commandList->ExecuteIndirect(
                m_commandSignature.Get(),
                TriangleCount,
                m_processedCommandBuffers[m_frameIndex].Get(),
                0,
                m_processedCommandBuffers[m_frameIndex].Get(),
                CommandBufferSizePerFrame);
        }
        else
        {
            // Draw all of the triangles.
            m_commandList->ExecuteIndirect(
                m_commandSignature.Get(),
                TriangleCount,
                m_commandBuffer.Get(),
                CommandBufferSizePerFrame * m_frameIndex,
                nullptr,
                0);
        }

        // Indicate that the command buffer may be used by the compute shader
        // and that the back buffer will now be used to present.
        barriers[0].Transition.StateBefore = D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT;
        barriers[0].Transition.StateAfter = m_enableCulling ? D3D12_RESOURCE_STATE_COPY_DEST : D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE;
        barriers[1].Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
        barriers[1].Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;

        m_commandList->ResourceBarrier(_countof(barriers), barriers);

        ThrowIfFailed(m_commandList->Close());
    }
}

```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)

[Indirect Drawing](https://learn.microsoft.com/windows/desktop/direct3d12/indirect-drawing)