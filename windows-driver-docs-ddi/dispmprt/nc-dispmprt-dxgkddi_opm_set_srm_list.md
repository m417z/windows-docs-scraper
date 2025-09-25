# DXGKDDI_OPM_SET_SRM_LIST callback function

## Description

The **DxgkDdiOPMSetSrmList** function sets the output protection manager (OPM) system renewability message (SRM) list.

## Parameters

### `MiniportDeviceContext`

Handle to a context block associated with a display adapter. Previously, the display miniport driver's [*DxgkDdiAddDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `SrmListSize`

The size, in bytes, of the buffer that **SrmListBuffer** points to.

### `SrmListBuffer`

Pointer to a buffer containing the updated SRM list.

## Return value

*DxgkDdiOPMSetSrmList* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

## Remarks

## See also

[**DXGK_OPM_INTERFACE_3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_opm_interface_3)

[*DxgkDdiOPMGetSrmListVersion*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_srm_list_version)