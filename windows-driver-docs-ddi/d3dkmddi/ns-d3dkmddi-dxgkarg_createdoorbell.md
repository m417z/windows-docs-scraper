## Description

The **DXGKARG_CREATEDOORBELL** structure contains parameters for KMD's [**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell) callback function.

## Members

### `hHwQueue`

[in] Handle to a KMD hardware queue object, which was created in a previous call to [**DxgkddiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue).

### `hDoorbell`

[in/out] As input, contains the runtime's handle to the doorbell. KMD can store the input handle in its tracking structures. As output, when KMD finishes creating the doorbell, **hDoorbell** contains KMD's kernel-mode handle to the doorbell.

### `PrivateDriverDataSize`

[in] Size, in bytes, of the driver's private data that is associated with the doorbell.

### `PrivateDriverData`

[in/out] Pointer to the driver's private data that is associated with the doorbell.

### `hRingBuffer`

[in] Handle to the ring buffer allocation [previously created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) by UMD. This allocation is GPU visible and already resident. The [**ResizeRingBufferOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell_flags) flag is a hint from UMD to KMD that a doorbell is being recreated for this hardware queue with a new, resized ring buffer.

### `hRingBufferControl`

[in] KMD handle to a ring buffer control allocation [previously created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation) by UMD. UMD and KMD can use this allocation as a control area to store ring buffer read/write pointer locations if required. The allocation must be GPU visible and already resident.

### `Flags`

A bit field of [**DXGKARG_CREATEDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell_flags) values specifying the doorbell creation flags.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMTCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreateallocation)

[**DXGKARG_CREATEDOORBELL_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell_flags)

[**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)