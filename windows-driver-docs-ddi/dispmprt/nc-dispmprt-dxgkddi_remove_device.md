# DXGKDDI_REMOVE_DEVICE callback function

## Description

The *DxgkDdiRemoveDevice* function frees any resources allocated during [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device).

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

## Return value

*DxgkDdiRemoveDevice* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DxgkDdiRemoveDevice* must free the context block represented by *MiniportDeviceContext*.

*DxgkDdiRemoveDevice* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)