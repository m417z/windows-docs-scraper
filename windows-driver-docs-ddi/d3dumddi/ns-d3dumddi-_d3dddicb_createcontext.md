# _D3DDDICB_CREATECONTEXT structure

## Description

The D3DDDICB_CREATECONTEXT structure describes a context to create.

## Members

### `NodeOrdinal` [in]

The zero-based index for the node that the context is scheduled on.

### `EngineAffinity` [in]

The zero-based index for the engine, within the node that **NodeOrdinal** specifies, that the context can run in.

### `Flags` [in]

A [D3DDDI_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags) structure that indicates, in bit-field flags, how to create the context.

### `pPrivateDriverData` [in]

A pointer to private data that is passed to a display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `hContext` [out]

A handle to the context that the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function creates.

### `pCommandBuffer` [out]

A pointer to the first command buffer for the created context.

### `CommandBufferSize` [out]

The size, in bytes, of the first command buffer for the created context, which **pCommandBuffer** points to.

### `pAllocationList` [out]

An array of [D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures for the first allocation list for the created context.

### `AllocationListSize` [out]

The number of elements in the allocation-list array that **pAllocationList** specifies.

### `pPatchLocationList` [out]

An array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the first patch-location list for the created context.

### `PatchLocationListSize` [out]

The number of elements in the patch-location-list array that **pPatchLocationList** specifies.

### `CommandBuffer`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist)

[D3DDDI_CREATECONTEXTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createcontextflags)

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85))