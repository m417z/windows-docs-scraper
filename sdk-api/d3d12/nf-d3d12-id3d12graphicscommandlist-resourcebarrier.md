## Description

Notifies the driver that it needs to synchronize multiple accesses to resources.

## Parameters

### `NumBarriers` [in]

Type: **UINT**

The number of submitted barrier descriptions.

### `pBarriers` [in]

Type: **const [D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_barrier)***

Pointer to an array of barrier descriptions.

## Remarks

> [!NOTE]
> A resource to be used for the [D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) state must be created in that state, and then never transitioned out of it. Nor may a resource that was created not in that state be transitioned into it. For more info, see [Acceleration structure memory restrictions](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html#acceleration-structure-memory-restrictions) in the DirectX raytracing (DXR) functional specification on GitHub.

There are three types of barrier descriptions:

* [D3D12_RESOURCE_TRANSITION_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_transition_barrier) - Transition barriers indicate that a set of subresources transition between different usages. The caller must specify the *before* and *after* usages of the subresources. The D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES flag is used to transition all subresources in a resource at the same time.
* [D3D12_RESOURCE_ALIASING_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_aliasing_barrier) - Aliasing barriers indicate a transition between usages of two different resources which have mappings into the same heap. The application can specify both the before and the after resource. Note that one or both resources can be NULL (indicating that any tiled resource could cause aliasing).
* [D3D12_RESOURCE_UAV_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_uav_barrier) - Unordered access view barriers indicate all UAV accesses (read or writes) to a particular resource must complete before any future UAV accesses (read or write) can begin. The specified resource may be NULL. It is not necessary to insert a UAV barrier between two draw or dispatch calls which only read a UAV. Additionally, it is not necessary to insert a UAV barrier between two draw or dispatch calls which write to the same UAV if the application knows that it is safe to execute the UAV accesses in any order. The resource can be NULL (indicating that any UAV access could require the barrier).

When **ID3D12GraphicsCommandList::ResourceBarrier** is passed an array of resource barrier descriptions, the API behaves as if it was called N times (1 for each array element), in the specified order.
Transitions should be batched together into a single API call when possible, as a performance optimization.

For descriptions of the usage states a subresource can be in, see the [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states) enumeration and the [Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12) section.

All subresources in a resource must be in the RENDER_TARGET state, or DEPTH_WRITE state, for render targets/depth-stencil resources respectively, when [ID3D12GraphicsCommandList::DiscardResource](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-discardresource) is called.

When a back buffer is presented, it must be in the D3D12_RESOURCE_STATE_PRESENT state. If [IDXGISwapChain1::Present1](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiswapchain1-present1) is called on a resource which is not in the PRESENT state, a debug layer warning will be emitted.

The resource usage bits are group into two categories, read-only and read/write.

The following usage bits are read-only:

* D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER
* D3D12_RESOURCE_STATE_INDEX_BUFFER
* D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE
* D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE
* D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT
* D3D12_RESOURCE_STATE_COPY_SOURCE
* D3D12_RESOURCE_STATE_DEPTH_READ

The following usage bits are read/write:

* D3D12_RESOURCE_STATE_UNORDERED_ACCESS
* D3D12_RESOURCE_STATE_DEPTH_WRITE

The following usage bits are write-only:

* D3D12_RESOURCE_STATE_COPY_DEST
* D3D12_RESOURCE_STATE_RENDER_TARGET
* D3D12_RESOURCE_STATE_STREAM_OUT

At most one write bit can be set.
If any write bit is set, then no read bit may be set.
If no write bit is set, then any number of read bits may be set.

At any given time, a subresource is in exactly one state (determined by a set of flags). The application must ensure that the states are matched when making a sequence of **ResourceBarrier** calls. In other words, the before and after states in consecutive calls to **ResourceBarrier** must agree.

To transition all subresources within a resource, the application can set the subresource index to D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES, which implies that all subresources are changed.

For improved performance, applications should use split barriers (refer to
[Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)). Your application should also batch multiple transitions into a single call whenever possible.

### Runtime validation

The runtime will validate that the barrier type values are valid members of the [D3D12_RESOURCE_BARRIER_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_barrier_type) enumeration.

In addition, the runtime checks the following:

* The resource pointer is non-NULL.
* The subresource index is valid
* The before and after states are supported by the [D3D12_RESOURCE_BINDING_TIER](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_binding_tier) and [D3D12_RESOURCE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_flags) flags of the resource.
* Reserved bits in the state masks are not set.
* The before and after states are different.
* The set of bits in the before and after states are valid.
* If the D3D12_RESOURCE_STATE_RESOLVE_SOURCE bit is set, then the resource sample count must be greater than 1.
* If the D3D12_RESOURCE_STATE_RESOLVE_DEST bit is set, then the resource sample count must be equal to 1.

For aliasing barriers the runtime will validate that, if either resource pointer is non-NULL, it refers to a tiled resource.

For UAV barriers the runtime will validate that, if the resource is non-NULL, the resource has the D3D12_RESOURCE_STATE_UNORDERED_ACCESS bind flag set.

Validation failure causes [ID3D12GraphicsCommandList::Close](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-close) to return E_INVALIDARG.

### Debug layer

The debug layer normally issues errors where runtime validation fails:

* If a subresource transition in a command list is inconsistent with previous transitions in the same command list.
* If a resource is used without first calling **ResourceBarrier** to put the resource into the correct state.
* If a resource is illegally bound for read and write at the same time.
* If the *before* states passed to the **ResourceBarrier** do not match the *after* states of previous calls to **ResourceBarrier**, including the aliasing case.

Whereas the debug layer attempts to validate the runtime rules, it operates conservatively so that debug layer errors are real errors, and in some cases real errors may not produce debug layer errors.

The debug layer will issue warnings in the following cases:

* All of the cases where the D3D12 debug layer would issues warnings for [ID3D12GraphicsCommandList::ResourceBarrier](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resourcebarrier).
* If a depth buffer is used in a non-read-only mode while the resource has the D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE usage bit set.

## Examples

The [D3D12HelloTriangle](https://learn.microsoft.com/windows/win32/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::ResourceBarrier** as follows:

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

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/win32/direct3d12/notes-on-example-code).

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)