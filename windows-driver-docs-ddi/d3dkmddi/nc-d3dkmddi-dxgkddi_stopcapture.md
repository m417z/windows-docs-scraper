# DXGKDDI_STOPCAPTURE callback function

## Description

The *DxgkDdiStopCapture* function stops the capture hardware from using the given allocation as a capture buffer.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pStopCapture` [in]

A pointer to a [DXGKARG_STOPCAPTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_stopcapture) structure that contains the handle to the allocation that is used as a capture buffer.

## Return value

*DxgkDdiStopCapture* returns STATUS_SUCCESS, or an appropriate error result if the allocation is not successfully stopped.

## Remarks

When a capture buffer is destroyed, the DirectX graphics kernel subsystem calls the *DxgkDdiStopCapture* function to inform the display miniport driver to stop the capture hardware from using the allocation as the capture buffer. If the capture hardware already stopped using the allocation, the driver should ignore the call.

*DxgkDdiStopCapture* should be made pageable.

## See also

[DXGKARG_STOPCAPTURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_stopcapture)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)