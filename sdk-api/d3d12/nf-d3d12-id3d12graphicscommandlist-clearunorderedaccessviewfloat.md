## Description

Sets all of the elements in an unordered-access view (UAV) to the specified float values.

> [!IMPORTANT]
> This behaves like a compute operation in that it isn't ordered with respect to surrounding work such as **Dispatch** calls. To ensure ordering, barrier calls must be issued before and/or after the **ClearUnorderedAccessViewXxx** call as needed. It might appear on some drivers that such barriers aren't necessary. But implicit barriers are not a spec guarantee; so they can't be relied upon. This is in contrast to **ClearDepthStencilView** and **ClearRenderTargetView** which (like **DrawXxx** commands), respect command list ordering.

## Parameters

### `ViewGPUHandleInCurrentHeap`

Type: [in] **[D3D12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle)**

A [D3D12_GPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_gpu_descriptor_handle) that references an initialized descriptor for the unordered-access view (UAV) that is to be cleared. This descriptor must be in a shader-visible descriptor heap, which must be set on the command list via [SetDescriptorHeaps](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-setdescriptorheaps).

### `ViewCPUHandle`

Type: [in] **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

A [D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle) in a non-shader visible descriptor heap that references an initialized descriptor for the unordered-access view (UAV) that is to be cleared.
> [!IMPORTANT]
> This descriptor must not be in a shader-visible descriptor heap. This is to allow drivers that implement the clear as a fixed-function hardware operation (rather than as a dispatch) to efficiently read from the descriptor, as shader-visible heaps may be created in **WRITE_COMBINE** memory (similar to **D3D12_HEAP_TYPE_UPLOAD** heap types), and CPU reads from this type of memory are prohibitively slow.

### `pResource`

Type: [in] **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)\***

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) interface that represents the unordered-access-view (UAV) resource to clear.

### `Values`

Type: [in] **const FLOAT[4]**

A 4-component array that containing the values to fill the unordered-access-view resource with.

### `NumRects`

Type: [in] **UINT**

The number of rectangles in the array that the *pRects* parameter specifies.

### `pRects`

Type: [in] **const [D3D12_RECT](https://learn.microsoft.com/windows/win32/direct3d12/d3d12-rect)\***

An array of **D3D12_RECT** structures for the rectangles in the resource view to clear. If **NULL**, **ClearUnorderedAccessViewFloat** clears the entire resource view.

## Remarks

### Runtime validation

For floating-point inputs, the runtime sets denormalized values to 0 (while preserving NANs).

If you want to clear the UAV to a specific bit pattern, consider using [ID3D12GraphicsCommandList::ClearUnorderedAccessViewUint](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-clearunorderedaccessviewuint).

Validation failure results in the call to [ID3D12GraphicsCommandList::Close](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-close) returning **E_INVALIDARG**.

### Debug layer

The debug layer issues errors if the input values are outside of a normalized range.

The debug layer issues an error if the subresources referenced by the view aren't in the appropriate state. For **ClearUnorderedAccessViewFloat**, the state must be [D3D12_RESOURCE_STATE_UNORDERED_ACCESS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_resource_states).

## See also

[ID3D12GraphicsCommandList interface](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist)