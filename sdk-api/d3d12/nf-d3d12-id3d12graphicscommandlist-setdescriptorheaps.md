## Description

Changes the currently bound descriptor heaps that are associated with a command list.

## Parameters

### `NumDescriptorHeaps`

Type: [in] **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of descriptor heaps to bind.

### `ppDescriptorHeaps`

Type: [in] **[ID3D12DescriptorHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12descriptorheap)***

A pointer to an array of [ID3D12DescriptorHeap](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12descriptorheap) objects for the heaps to set on the command list.

You can only bind descriptor heaps of type [**D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setdescriptorheaps) and [**D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setdescriptorheaps).

Only one descriptor heap of each type can be set at one time, which means a maximum of 2 heaps (one sampler, one CBV/SRV/UAV) can be set at one time.

## Remarks

**SetDescriptorHeaps** can be called on a bundle, but the bundle descriptor heaps must match the calling command list descriptor heap. For more information on bundle restrictions, refer to [Creating and Recording Command Lists and Bundles](https://learn.microsoft.com/windows/desktop/direct3d12/recording-command-lists-and-bundles).

All previously set heaps are unset by the call. At most one heap of each shader-visible type can be set in the call.

Changing descriptor heaps can incur a pipeline flush on some hardware. Because of this, it is recommended to use a single shader-visible heap of each type, and set it once per frame, rather than regularly changing the bound descriptor heaps. Instead, use [**ID3D12Device::CopyDescriptors**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-copydescriptors) and [**ID3D12Device::CopyDescriptorsSimple**](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-copydescriptorssimple) to copy the required descriptors from shader-opaque heaps to the single shader-visible heap as required during rendering.

## Examples

The [D3D12Bundles](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::SetDescriptorHeaps** as follows:

```cpp
void D3D12Bundles::PopulateCommandList(FrameResource* pFrameResource)
{
    // Command list allocators can only be reset when the associated
    // command lists have finished execution on the GPU; apps should use
    // fences to determine GPU execution progress.
    ThrowIfFailed(m_pCurrentFrameResource->m_commandAllocator->Reset());

    // However, when ExecuteCommandList() is called on a particular command
    // list, that command list can then be reset at any time and must be before
    // re-recording.
    ThrowIfFailed(m_commandList->Reset(m_pCurrentFrameResource->m_commandAllocator.Get(), m_pipelineState1.Get()));

    // Set necessary state.
    m_commandList->SetGraphicsRootSignature(m_rootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_cbvSrvHeap.Get(), m_samplerHeap.Get() };
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
    m_commandList->ClearDepthStencilView(m_dsvHeap->GetCPUDescriptorHandleForHeapStart(), D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr);

    if (UseBundles)
    {
        // Execute the prebuilt bundle.
        m_commandList->ExecuteBundle(pFrameResource->m_bundle.Get());
    }
    else
    {
        // Populate a new command list.
        pFrameResource->PopulateCommandList(m_commandList.Get(), m_pipelineState1.Get(), m_pipelineState2.Get(), m_currentFrameResourceIndex, m_numIndices, &m_indexBufferView,
            &m_vertexBufferView, m_cbvSrvHeap.Get(), m_cbvSrvDescriptorSize, m_samplerHeap.Get(), m_rootSignature.Get());
    }

    // Indicate that the back buffer will now be used to present.
    m_commandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(m_renderTargets[m_frameIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT));

    ThrowIfFailed(m_commandList->Close());
}
```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[Descriptor Heaps](https://learn.microsoft.com/windows/desktop/direct3d12/descriptor-heaps)

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)