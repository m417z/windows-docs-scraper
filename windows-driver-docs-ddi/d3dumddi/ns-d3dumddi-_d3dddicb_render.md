# D3DDDICB_RENDER structure

## Description

The **D3DDDICB_RENDER** structure describes the current command buffer to be rendered.

## Members

### `CommandLength`

[in] The size, in bytes, of the command buffer, starting from offset zero.

### `CommandOffset`

[in] The offset, in bytes, to the first command in the command buffer.

### `NumAllocations`

[in] The number of elements in the allocation list.

### `NumPatchLocations`

[in] The number of elements in the patch-location list.

### `pNewCommandBuffer`

[out] A pointer to a command buffer that the user-mode display driver receives to use in its next call to the [**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

### `NewCommandBufferSize`

[in/out] The size, in bytes, that the user-mode display driver requests for the next command buffer.

The driver receives the size, in bytes, of the next command buffer to use.

### `pNewAllocationList`

[out] An array of [**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures that the user-mode display driver receives to use as the allocation list in its next call to the [**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

### `NewAllocationListSize`

[in/out] The number of elements that the user-mode display driver requests for the next allocation list.

The driver receives the number of elements for the allocation list that will be available when the next command buffer is submitted.

### `pNewPatchLocationList`

[out] An array of [**D3DDDI_PATCHLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures that the user-mode display driver receives to use as the patch-location list in its next call to the [**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function.

### `NewPatchLocationListSize`

[in/out] The number of elements that the user-mode display driver requests for the next patch-location list.

The driver receives the number of elements for the patch-location list that will be available when the next command buffer is submitted.

### `Flags`

[in] A [**D3DDDICB_RENDERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_renderflags) structure that indicates information about a command buffer to be rendered.

### `hContext`

[in] A handle to the context that the driver submits the rendering operation to. The user-mode display driver previously created this context by calling the [**pfnCreateContextCb**](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function.

### `BroadcastContextCount`

[in] The number of additional contexts in the array that the **BroadcastContext** member specifies.

### `BroadcastContext`

[in] An array of handles to the additional contexts to broadcast the current command buffer to. The D3DDDI_MAX_BROADCAST_CONTEXT constant, which is defined as 64, defines the maximum number of additional contexts that the user-mode display driver can broadcast the current command buffer to.

The original context that the **hContext** member specifies and that owns the command buffer is not an element in the **BroadcastContext** array. For example, if the **BroadcastContext** array contains one element, the user-mode display driver sends the command buffer to the owning context (**hContext**) and broadcasts to that one additional context.

### `QueuedBufferCount`

[out] The number of DMA buffers that are queued to the context that the **hContext** member specifies after the current submission occurs.

### `NewCommandBuffer`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `pPrivateDriverData`

[in] This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `PrivateDriverDataSize`

[in] This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

### `MarkerLogType`

A [**D3DDDI_MARKERLOGTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_markerlogtype) enumeration that indicates the type of marker in the Event Tracing for Windows (ETW) log that the user-mode display driver supports.

### `RenderCBSequence`

A unique identifier for each [**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb) function call. Starts at a value of 1 for contexts associated with single-threaded user-mode DDIs and ranges to a value of 0x80000001 for contexts associated with free-threaded user mode DDIs. The user-mode display driver must increment the value for each pfnRenderCb call it makes on any engine.

### `FirstAPISequenceNumberHigh`

Used by the driver to pass the context's API sequence number.

### `CompletedAPISequenceNumberLow0Size`

Used by the driver to pass the context's API sequence number.

### `CompletedAPISequenceNumberLow1Size`

Used by the driver to pass the context's API sequence number.

### `BegunAPISequenceNumberLow0Size`

Used by the driver to pass the context's API sequence number.

### `BegunAPISequenceNumberLow1Size`

Used by the driver to pass the context's API sequence number.

### `pCompletedAPISequenceNumberLow0`

A pointer used by the driver to pass the context's API sequence number.

### `pCompletedAPISequenceNumberLow1`

A pointer used by the driver to pass the context's API sequence number.

### `pBegunAPISequenceNumberLow0`

A pointer used by the driver to pass the context's API sequence number.

### `pBegunAPISequenceNumberLow1`

A pointer used by the driver to pass the context's API sequence number.

## See also

[**D3DDDICB_RENDERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_renderflags)

[**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[**D3DDDI_PATCHLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[**pfnRenderCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rendercb)