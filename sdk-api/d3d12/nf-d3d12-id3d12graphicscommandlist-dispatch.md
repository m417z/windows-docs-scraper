# ID3D12GraphicsCommandList::Dispatch

## Description

Executes a command list from a thread group.

## Parameters

### `ThreadGroupCountX` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the x direction. *ThreadGroupCountX* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).

### `ThreadGroupCountY` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the y direction. *ThreadGroupCountY* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).

### `ThreadGroupCountZ` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of groups dispatched in the z direction. *ThreadGroupCountZ* must be less than or equal to D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION (65535).
In feature level 10 the value for *ThreadGroupCountZ* must be 1.

## Remarks

You call the **Dispatch** method to execute commands in a compute shader. A compute shader can be run on many threads in parallel, within a thread group. Index a particular thread, within a thread group using a 3D vector
given by (x,y,z).

#### Examples

The [D3D12nBodyGravity](https://learn.microsoft.com/windows/desktop/direct3d12/working-samples) sample uses **ID3D12GraphicsCommandList::Dispatch** as follows:

```cpp
// Run the particle simulation using the compute shader.
void D3D12nBodyGravity::Simulate(UINT threadIndex)
{
    ID3D12GraphicsCommandList* pCommandList = m_computeCommandList[threadIndex].Get();

    UINT srvIndex;
    UINT uavIndex;
    ID3D12Resource *pUavResource;
    if (m_srvIndex[threadIndex] == 0)
    {
        srvIndex = SrvParticlePosVelo0;
        uavIndex = UavParticlePosVelo1;
        pUavResource = m_particleBuffer1[threadIndex].Get();
    }
    else
    {
        srvIndex = SrvParticlePosVelo1;
        uavIndex = UavParticlePosVelo0;
        pUavResource = m_particleBuffer0[threadIndex].Get();
    }

    pCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(pUavResource, D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE, D3D12_RESOURCE_STATE_UNORDERED_ACCESS));

    pCommandList->SetPipelineState(m_computeState.Get());
    pCommandList->SetComputeRootSignature(m_computeRootSignature.Get());

    ID3D12DescriptorHeap* ppHeaps[] = { m_srvUavHeap.Get() };
    pCommandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

    CD3DX12_GPU_DESCRIPTOR_HANDLE srvHandle(m_srvUavHeap->GetGPUDescriptorHandleForHeapStart(), srvIndex + threadIndex, m_srvUavDescriptorSize);
    CD3DX12_GPU_DESCRIPTOR_HANDLE uavHandle(m_srvUavHeap->GetGPUDescriptorHandleForHeapStart(), uavIndex + threadIndex, m_srvUavDescriptorSize);

    pCommandList->SetComputeRootConstantBufferView(RootParameterCB, m_constantBufferCS->GetGPUVirtualAddress());
    pCommandList->SetComputeRootDescriptorTable(RootParameterSRV, srvHandle);
    pCommandList->SetComputeRootDescriptorTable(RootParameterUAV, uavHandle);

    pCommandList->Dispatch(static_cast<int>(ceil(ParticleCount / 128.0f)), 1, 1);

    pCommandList->ResourceBarrier(1, &CD3DX12_RESOURCE_BARRIER::Transition(pUavResource, D3D12_RESOURCE_STATE_UNORDERED_ACCESS, D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE));
}

```

See [Example Code in the D3D12 Reference](https://learn.microsoft.com/windows/desktop/direct3d12/notes-on-example-code).

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)