# _D3DKMT_CREATEDEVICE structure

## Description

The D3DKMT_CREATEDEVICE structure describes a kernel-mode device context.

## Members

### `hAdapter` [in]

A handle to the graphics adapter that the device context is created on. This handle identifies the adapter for user-mode creation.

### `pAdapter` [in]

A pointer to a block of memory for the graphics adapter that the device context is created on. This pointer identifies the adapter for kernel-mode creation.

### `Flags` [in]

A [D3DKMT_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdeviceflags) structure that indicates, in bit-field flags, the type of device context to be created.

### `hDevice` [out]

A handle to the device context that the Microsoft DirectX graphics kernel subsystem (*Dxgkrnl.sys*) supplied and that is returned from the call to the [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function.

### `pCommandBuffer` [out]

A pointer to command buffer memory that the OpenGL ICD places commands into. The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this memory pointer.

### `CommandBufferSize` [out]

The size, in bytes, of the memory block that **pCommandBuffer** points to. The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this size value.

### `pAllocationList` [out]

An array of [D3DDDI_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_allocationlist) structures that the OpenGL ICD inserts referenced allocations in.

The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this value.

### `AllocationListSize` [out]

The number of elements in the array of allocations that is pointed to by **pAllocationList**. This quantity of allocations is available when submitting the command buffer that is pointed to by **pCommandBuffer** to the display miniport driver.

The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this value.

### `pPatchLocationList` [out]

An array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures that the OpenGL ICD inserts patching information in.

The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this value.

### `PatchLocationListSize` [out]

The number of elements in the patch-location list that is pointed to by **pPatchLocationList**. This quantity of patch locations is available when submitting the command buffer that is pointed to by **pCommandBuffer** to the display miniport driver.

The [D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice) function returns this value.

## See also

[D3DKMTCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatedevice)

[D3DKMT_CREATEDEVICEFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createdeviceflags)