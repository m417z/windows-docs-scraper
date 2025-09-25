# ID3D12GraphicsCommandList::OMSetRenderTargets

## Description

Sets CPU descriptor handles for the render targets and depth stencil.

## Parameters

### `NumRenderTargetDescriptors` [in]

Type: **UINT**

The number of entries in the *pRenderTargetDescriptors* array (ranges between 0 and **D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT**). If this parameter is nonzero, the number of entries in the array to which pRenderTargetDescriptors points must equal the number in this parameter.

### `pRenderTargetDescriptors` [in, optional]

Type: **const [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)***

Specifies an array of [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle) structures that describe the CPU descriptor handles that represents the start of the heap of render target descriptors. If this parameter is NULL and NumRenderTargetDescriptors is 0, no render targets are bound.

### `RTsSingleHandleToDescriptorRange` [in]

Type: **BOOL**

**True** means the handle passed in is the pointer to a contiguous range of *NumRenderTargetDescriptors* descriptors. This case is useful if the set of descriptors to bind already happens to be contiguous in memory (so all that’s needed is a handle to the first one). For example, if *NumRenderTargetDescriptors* is 3 then the memory layout is taken as follows:

![Memory layout with parameter set to true](https://learn.microsoft.com/windows/win32/api/d3d12/images/oms_true.png)
In this case the driver dereferences the handle and then increments the memory being pointed to.

**False** means that the handle is the first of an array of *NumRenderTargetDescriptors* handles. The false case allows an application to bind a set of descriptors from different locations at once. Again assuming that *NumRenderTargetDescriptors* is 3, the memory layout is taken as follows:

![Memory layout with parameter set to false](https://learn.microsoft.com/windows/win32/api/d3d12/images/oms_false.png)
In this case the driver dereferences three handles that are expected to be adjacent to each other in memory.

### `pDepthStencilDescriptor` [in, optional]

Type: **const [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)***

A pointer to a [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle) structure that describes the CPU descriptor handle that represents the start of the heap that holds the depth stencil descriptor. If this parameter is NULL, no depth stencil descriptor is bound.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)