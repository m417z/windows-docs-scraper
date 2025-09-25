# _D3DKMT_RENDER structure

## Description

The D3DKMT_RENDER structure describes the current command buffer to be rendered.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that the command buffer is rendered to. A device handle is supplied to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function in the union that D3DKMT_RENDER contains for compatibility with Microsoft Direct3D version 10.

### `hContext` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device context that the command buffer is rendered to.

### `CommandOffset` [in]

The offset, in bytes, to the first command in the command buffer.

### `CommandLength` [in]

The size, in bytes, of the command buffer starting from offset zero.

### `AllocationCount` [in]

The number of elements in the submitted allocation list.

### `PatchLocationCount` [in]

The number of elements in the submitted patch-location list.

### `pNewCommandBuffer` [out]

A pointer to a command buffer that the OpenGL ICD receives to use in its next call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function. The driver must always update its pointer to the command buffer after any call to **D3DKMTRender** regardless of whether the call is successful.

Supported in Windows 7 and later versions:

[in] A pointer to the command buffer to be rendered if the **RenderKm** flag is set in the **Flags** member.

### `NewCommandBufferSize` [in/out]

The size, in bytes, that the OpenGL ICD requests for the next command buffer if the **ResizeCommandBuffer** bit-field flag is specified in the **Flags** member. If **ResizeCommandBuffer** is not specified, the value in **NewCommandBufferSize** is ignored. On output, the driver receives the size, in bytes, of the next command buffer to use.

Depending on current memory conditions the output size might not match the input size.

### `pNewAllocationList` [out]

An array of [D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures that the OpenGL ICD receives to use as the allocation list in its next call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function. The driver must always update its pointer to the allocation list after any call to **D3DKMTRender** regardless of whether the call is successful.

Supported in Windows 7 and later versions:

[in] A pointer to the allocation list to be rendered if the **RenderKm** flag is set in the **Flags** member.

### `NewAllocationListSize` [in/out]

The number of elements that the OpenGL ICD requests for the next allocation list if the **ResizeAllocationList** bit-field flag is specified in the **Flags** member. If **ResizeAllocationList** is not specified, the value in **NewAllocationListSize** is ignored. On output, the driver receives the number of elements that will be available in an array of allocations when the next command buffer is submitted.

Depending on current memory conditions the output size might not match the input size.

### `pNewPatchLocationList` [out]

An array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures that the OpenGL ICD receives to use as the patch-location list in its next call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function. The driver must always update its pointer to the patch-location list after any call to **D3DKMTRender** regardless of whether the call is successful.

### `NewPatchLocationListSize` [in/out]

The number of elements that the OpenGL ICD requests for the next patch-location list if the **ResizePatchLocationList** bit-field flag is specified in the **Flags** member. If **ResizePatchLocationList** is not specified, the value in **NewPatchLocationListSize** is ignored. On output, the driver receives the number of elements that will be available in an array of patch locations when the next command buffer is submitted.

Depending on current memory conditions the output size might not match the input size.

### `Flags` [in]

A [D3DKMT_RENDERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_renderflags) structure that indicates the type of command buffer, in bit-field flags, to be rendered.

### `PresentHistoryToken` [in]

The present history token for redirected calls to the display miniport driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function.

A *present history token* is a data packet that the rendering app submits to inform the Desktop Window Manager (DWM) that rendering is complete and the swap chain back buffer is ready to be presented.

### `BroadcastContextCount` [in]

The number of additional contexts in the array that **BroadcastContext** specifies.

### `BroadcastContext` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the additional contexts to broadcast the current command buffer to. The D3DDDI_MAX_BROADCAST_CONTEXT constant, which is defined as 64, defines the maximum number of contexts that the OpenGL ICD can broadcast the current command buffer to.

The original context that the **hContext** member specifies and that owns the command buffer is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the OpenGL ICD sends the command buffer to the owning context (**hContext**) and broadcasts to that one additional context.

### `QueuedBufferCount` [out]

The number of DMA buffers that are queued to the context that the **hContext** member specifies after the submission.

### `NewCommandBuffer` [out]

A pointer to a command buffer that the OpenGL ICD receives to use in its next call to the [D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender) function. The driver must always update its pointer to the command buffer after any call to **D3DKMTRender** regardless of whether the call is successful.

Supported in Windows 7 and later versions:

[in] A pointer to the command buffer to be rendered if the **RenderKm** flag is set in the **Flags** member.

### `pPrivateDriverData`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `PrivateDriverDataSize`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[D3DKMTRender](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtrender)

[D3DKMT_RENDERFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_renderflags)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)