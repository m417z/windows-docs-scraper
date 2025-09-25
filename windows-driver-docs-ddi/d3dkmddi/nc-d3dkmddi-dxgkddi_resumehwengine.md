# DXGKDDI_RESUMEHWENGINE callback function

## Description

*Dxgkrnl* calls **DxgkDdiResumeHwEngine** after a GPU engine has been successfully [reset](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resethwengine) to instruct the GPU scheduler to resubmit contexts that weren't invalidated by the reset.

## Parameters

### `hAdapter`

[in] A handle to the context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pResumeHwEngine`

[in/out] Pointer to a [**DXGKARG_RESUMEHWENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resumehwengine) structure that contains information to resume the hardware engine.

## Return value

**DxgkDdiResumeHwEngine** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it should return an appropriate NTSTATUS error code. If the call fails, the OS will perform a full GPU reset.

## Remarks

The engine isn't considered resumed yet after [**DxgkDdiResetHwEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resethwengine) is called, so even contexts that weren't invalidated aren't allowed to be submitted. The OS needs to re-enable interrupts from this engine and synchronize its state with the reset GPU engine. After that, the OS will enable interrupts and call **DxgkDdiResumeHwEngine**, which instructs the GPU engine to start scheduling all runnable contexts that weren't affected by the engine reset.

Register your implementation of this callback function in the [**DRIVER_INITIALIZATION_DATA **](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_driver_initialization_data) structure.

## See also

[**DXGKARG_RESUMEHWENGINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_resumehwengine)

[**DxgkDdiResetHwEngine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resethwengine)