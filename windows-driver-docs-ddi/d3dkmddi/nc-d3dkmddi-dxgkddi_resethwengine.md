## Description

*Dxgkrnl* calls the display miniport driver's (KMD's) **DxgkDdiResetHwEngine** function when a GPU engine reset is required.

## Parameters

### `hAdapter`

[in] A handle to the context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pResetHwEngine`

[in/out] Pointer to a [**DXGKARG_RESETHWENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resumehwengine) structure that contains information to reset the hardware engine.

## Return value

**DxgkDdiResetHwEngine** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it should return an appropriate NTSTATUS error code.

## Remarks

A **DxgkDdiResetHwEngine** implementation should call the [**DxgkCbInvalidateHwContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_invalidatehwcontext) callback to inform the OS of all running contexts that were affected by the GPU engine reset operation. The OS will invalidate these context devices (set them in error) and won't perform future submissions.

The engine isn't considered resumed yet after **DxgkDdiResetHwEngine** is called, so contexts that weren't invalidated aren't allowed to be submitted. The OS needs to re-enable interrupts from this engine and synchronize its state with the reset GPU engine. After that, the OS will enable interrupts and call [**DxgkDdiResumeHwEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resumehwengine), which instructs the GPU engine to start scheduling all runnable contexts that weren't affected by the engine reset.

Register your implementation of this callback function in the [**DRIVER_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data) structure.

## See also

[**DXGKARG_RESETHWENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resumehwengine)

[**DxgkDdiResumeHwEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resumehwengine)