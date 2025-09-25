# DXGKDDI_OPM_GET_SRM_LIST_VERSION callback function

## Description

The *DxgkDdiOPMGetSrmListVersion* function retrieves the version number of the output protection manager (OPM) system renewability message (SRM) list currently being used.

## Parameters

### `MiniportDeviceContext`

Handle to a context block associated with a display adapter. Previously, the display miniport driver's [*DxgkDdiAddDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `SrmListVersionSize`

The size, in bytes, of the buffer that **SrmListVersionBuffer** points to.

### `SrmListVersionBuffer`

Pointer to a buffer containing the SRM list version.

## Return value

*DxgkDdiOPMGetSrmListVersion* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

## Remarks

## See also

[**DXGK_OPM_INTERFACE_3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_opm_interface_3)

[*DxgkDdiOPMSetSrmList*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_srm_list)