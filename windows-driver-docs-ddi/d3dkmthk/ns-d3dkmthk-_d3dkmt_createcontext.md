# D3DKMT_CREATECONTEXT structure

## Description

The **D3DKMT_CREATECONTEXT** structure is used with [**D3DKMTCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext) to create a kernel-mode device context.

## Members

### `hDevice`

[in] A handle to the device that owns the context being created.

### `NodeOrdinal`

[in] The zero-based index of the node that the context is scheduled on.

### `EngineAffinity`

[in] The zero-based index for the engine, within the node that **NodeOrdinal** specifies, that the context can run in.

### `Flags`

[in] A [**D3DDDI_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags) structure that indicates, in bit-field flags, how to create the context.

### `pPrivateDriverData`

[in] A pointer to private data that is to be passed to the display miniport driver.

### `PrivateDriverDataSize`

[in] The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `ClientHint`

[in] A [**D3DKMT_CLIENTHINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_clienthint) value that indicates the type of client that is creating the context.

### `hContext`

[out] A handle to the created device context.

### `pCommandBuffer`

[out] Pointer to an array of allocated command buffers in which the OpenGL ICD can place commands into.

### `CommandBufferSize`

[out] The size, in bytes, of the memory block that **pCommandBuffer** points to.

### `pAllocationList`

[out] Pointer to an array of [**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures that the OpenGL ICD can insert referenced allocations in.

### `AllocationListSize`

[out] The number of elements in the array of allocations that **pAllocationList** points to. This quantity of allocations is available when *Dxgkrnl* submits the command buffer that is pointed to by **pCommandBuffer** to the display miniport driver.

### `pPatchLocationList`

[out] Pointer to an allocated array of [**D3DDDI_PATCHLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures that the OpenGL ICD inserts patching information in.

### `PatchLocationListSize`

[out] The number of elements in the patch-location list that **pPatchLocationList** points to. This quantity of patch locations is available when *Dxgkrnl* submits the command buffer that is pointed to by **pCommandBuffer** to the display miniport driver.

### `CommandBuffer`

[out] The GPU virtual address of the command buffer memory.

## See also

[**D3DDDI_ALLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[**D3DDDI_CREATECONTEXTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags)

[**D3DDDI_PATCHLOCATIONLIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[**D3DKMTCreateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatecontext)