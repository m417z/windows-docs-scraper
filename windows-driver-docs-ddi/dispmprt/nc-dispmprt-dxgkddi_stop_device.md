# DXGKDDI_STOP_DEVICE callback function

## Description

The *DxgkDdiStopDevice* function resets a display adapter and frees resources allocated during [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

## Return value

*DxgkDdiStopDevice* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

For more information on how this function is used in Plug and Play (PnP) scenarios starting in Windows 8, see [Plug and Play (PnP) in WDDM 1.2 and later](https://learn.microsoft.com/windows-hardware/drivers/display/plug-and-play--pnp--start-and-stop-cases).

The *DxgkDdiStopDevice* function should be made pageable.

## See also

[DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device)