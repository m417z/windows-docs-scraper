## Description

The OS calls a display driver's **DXGKDDI_SETINTERRUPTTARGETPRESENTID** function to specify the target PresentId that should result in a Vsync interrupt being raised when the corresponding flip is completed.

## Parameters

### `hAdapter`

[in] A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetInterruptTargetPresentId`

[in] Pointer to a [**DXGKARG_SETINTERRUPTTARGETPRESENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setinterrupttargetpresentid) structure containing the parameters for this function.

## Return value

**DXGKDDI_SETINTERRUPTTARGETPRESENTID** returns STATUS_SUCCESS. The driver should always return a success code.

## Remarks

**DXGKDDI_SETINTERRUPTTARGETPRESENTID** is called at the device interrupt level to synchronize with [**DXGKDDI_SETVIDPNSOURCEADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddress) and the VSync interrupt.

See [Specifying Vsync interrupt behavior](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior) for more information.

## See also

[**DXGKARG_SETINTERRUPTTARGETPRESENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setinterrupttargetpresentid)