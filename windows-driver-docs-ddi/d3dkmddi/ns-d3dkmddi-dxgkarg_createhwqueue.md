## Description

The **DXGKARG_CREATEHWQUEUE** structure is used with [**DxgkDdiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue) to create a hardware queue.

## Members

### `hHwQueue`

[in/out] On input, *Dxgkrnl*'s handle to the hardware queue. On output, the driver's handle to the hardware queue.

### `Flags`

[in] A [**D3DDDI_CREATEHWQUEUEFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createhwqueueflags) structure containing the queue creation flags.

### `PrivateDriverDataSize`

[in] Size in bytes of the private driver data that **pPrivateDriverData** points to.

### `pPrivateDriverData`

[in/out] Pointer to the private driver data that was passed by the user-mode driver's [**pfnCreateHwContextCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createhwcontextcb) function. Since **pPrivateDriverData** is an in-out parameter, KMD can also return private data back to the UMD.

### `hHwQueueProgressFence`

[in] Handle to the GPU synchronization object created by the OS for this hardware queue. The progress fence is used to synchronize DMA buffer completion on this hardware queue. See Remarks.

### `HwQueueProgressFenceCPUVirtualAddress`

[in] Kernel-mode CPU virtual address that can be used to read the currently signaled value of the hardware queue progress fence.

### `HwQueueProgressFenceGPUVirtualAddress`

[in] GPU virtual address that can be used to read or write the value of the hardware queue progress fence. The queue progress fence value must monotonically increase with each new submission to the hardware queue. GPU instructions to update the queue progress fence must be inserted by the user-mode driver at the end of the DMA buffer being tracked.

## Remarks

For kernel submission HWQueues, the OS will allocate the progress fence as a native fence type on GPUs that support native fences. When the [**NativeProgressFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_createhwqueueflags) flag is set, KMD's [**DxgkDdiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue) must read the corresponding **hHwQueueNativeProgressFence** field that specifies the driver handle to the native fence object previously created in [**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence). If the **NativeProgressFence** flag is FALSE then this HWQueue's progress fence is a regular monitored fence object, and KMD must read the legacy **hHwQueueProgressFence** field like before.

Upon creating a native fence for a HWQueue, the OS will also set **D3DKMT_CREATEHWQUEUE::Flags.NativeProgressFence** to TRUE, so that the runtime is also aware that the HWQueue's progress fence was allocated as a native fence.

For user submission HWQueues, OS will allocate its progress fence as a native fence in **DxgkDdiCreateHwQueueForUserModeSubmission**() by definition.

Note on driver compatibility: *Dxgkrnl* will only write to the **hHwQueueNativeProgressFence** field on drivers that support the **NativeGpuFence** cap. This ensures that OS will only reference this field on in-development and future drivers that are compiled with this updated header. KMD will only read this field if **DXGKARG_CREATEHWQUEUE.Flags.NativeProgressFence** is TRUE. This ensures that KMD only references this field on the latest OS builds that support native progress fence and this updated header.

## See also

[**DxgkDdiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue)