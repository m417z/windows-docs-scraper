# ID3D12GraphicsCommandList::Reset

## Description

Resets a command list back to its initial state as if a new command list was just created.

## Parameters

### `pAllocator` [in]

Type: **ID3D12CommandAllocator***

A pointer to the [ID3D12CommandAllocator](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandallocator) object that the device creates command lists from.

### `pInitialState` [in, optional]

Type: **ID3D12PipelineState***

A pointer to the [ID3D12PipelineState](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12pipelinestate) object that contains the initial pipeline state for the command list. This is optional and can be NULL. If NULL, the runtime sets a dummy initial pipeline state so that drivers don't have to deal with undefined state. The overhead for this is low, particularly for a command list, for which the overall cost of recording the command list likely dwarfs the cost of one initial state setting. So there is little cost in not setting the initial pipeline state parameter if it isn't convenient.

For bundles on the other hand, it might make more sense to try to set the initial state parameter since bundles are likely smaller overall and can be reused frequently.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns **S_OK** if successful; otherwise, returns one of the following values:

* **E_FAIL** if the command list was not in the "closed" state when the **Reset** call was made, or the per-device limit would have been exceeded.
* **E_OUTOFMEMORY** if the operating system ran out of memory.
* **E_INVALIDARG** if the allocator is currently being used with another command list in the "recording" state or if the specified allocator was created with the wrong type.

See [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues) for other possible return values.

## Remarks

By using **Reset**, you can re-use command list tracking structures without any allocations. Unlike [ID3D12CommandAllocator::Reset](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandallocator-reset), you can call ID3D12GraphicsCommandList::**Reset** while the command list is still being executed.

You can use **Reset** for both direct command lists and bundles.

The command allocator passed to **Reset** cannot be associated with any other currently-recording command list. The allocator type, direct command list or bundle, must match the type of command list that is being created.

If a bundle doesn't specify a resource heap, it can't make changes to which descriptor tables are bound. Either way, bundles can't change the resource heap within the bundle. If a heap is specified for a bundle, the heap must match the calling 'parent' command list’s heap.

### Runtime validation

Before an app calls **Reset**, the command list must be in the "closed" state. **Reset** will fail if the command list isn't in the "closed" state.

**Note** If a call to [ID3D12GraphicsCommandList::Close](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-close) fails, the command list can never be reset. Calling **Reset** will result in the same error being returned that **ID3D12GraphicsCommandList::Close** returned.

After **Reset** succeeds, the command list is left in the "recording" state. **Reset** will fail if it would cause the maximum concurrently recording command list limit, which is specified at device creation, to be exceeded.

Apps must specify a command list allocator. The runtime will ensure that an allocator is never associated with more than one recording command list at the same time.

**Reset** fails for bundles that are referenced by a not yet submitted command list.

#### Examples

The [D3D12HelloTriangle](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::Reset** as follows:

```cpp
D3D12_VIEWPORT m_viewport;
D3D12_RECT m_scissorRect;
ComPtr<IDXGISwapChain3> m_swapChain;
ComPtr<ID3D12Device> m_device;
ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
ComPtr<ID3D12CommandAllocator> m_commandAllocator;
ComPtr<ID3D12CommandQueue> m_commandQueue;
ComPtr<ID3D12RootSignature> m_rootSignature;
ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
ComPtr<ID3D12PipelineState> m_pipelineState;
ComPtr<ID3D12GraphicsCommandList> m_commandList;
UINT m_rtvDescriptorSize;

```

```cpp
void D3D12HelloTriangle::PopulateCommandList()
{
    // Command list allocators can only be reset when the associated
    // command lists have finished execution on the GPU; apps should use
    // fences to determine GPU execution progress.
    ThrowIfFailed(m_commandAllocator->Reset());

    // However, when ExecuteCommandList() is called on a particular command
    // list, that command list can then be reset at any time and must be before
    // re-recording.
    ThrowIfFailed(m_commandList->Reset(m_commandAllocator.Get(), m_pipelineState.Get()));

    // Set necessary state.
    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());
    m_commandList->RSSetViewports(1, &m_viewport);
    m_commandList->RSSetScissorRects(1, &m_scissorRect);

    // Indicate that the back buffer will be used as a render target.
    m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET));

    CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart(), m_frameIndex, m_rtvDescriptorSize);
    m_commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, nullptr);

    // Record commands.
    const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
    m_commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);
    m_commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    m_commandList->IASetVertexBuffers(0, 1, &m_vertexBufferView);
    m_commandList->DrawInstanced(3, 1, 0, 0);

    // Indicate that the back buffer will now be used to present.
    m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT));

    ThrowIfFailed(m_commandList->Close());
}

```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12CommandAllocator::Reset](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandallocator-reset)

[ID3D12Device::CreateCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createcommandlist)

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)