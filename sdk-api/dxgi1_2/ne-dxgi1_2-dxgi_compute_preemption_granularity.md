# DXGI_COMPUTE_PREEMPTION_GRANULARITY enumeration

## Description

Identifies the granularity at which the graphics processing unit (GPU) can be preempted from performing its current compute task.

## Constants

### `DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY:0`

Indicates the preemption granularity as a compute packet.

### `DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY:1`

Indicates the preemption granularity as a dispatch (for example, a call to the [ID3D11DeviceContext::Dispatch](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-dispatch) method). A dispatch is a part of a compute packet.

### `DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY:2`

Indicates the preemption granularity as a thread group. A thread group is a part of a dispatch.

### `DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY:3`

Indicates the preemption granularity as a thread in a thread group. A thread is a part of a thread group.

### `DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY:4`

Indicates the preemption granularity as a compute instruction in a thread.

## Remarks

You call the [IDXGIAdapter2::GetDesc2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgiadapter2-getdesc2) method to retrieve the granularity level at which the GPU can be preempted from performing its current compute task. The operating system specifies the compute granularity level in the **ComputePreemptionGranularity** member of the [DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2) structure.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[DXGI_ADAPTER_DESC2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/ns-dxgi1_2-dxgi_adapter_desc2)