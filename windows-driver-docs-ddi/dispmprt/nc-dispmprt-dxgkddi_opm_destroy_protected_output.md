# DXGKDDI_OPM_DESTROY_PROTECTED_OUTPUT callback function

## Description

The *DxgkDdiOPMDestroyProtectedOutput* function destroys the given protected output object.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. Previously, the display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `ProtectedOutputHandle` [in]

The handle to a protected output object. The [DxgkDdiOPMCreateProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output) function creates the protected output object and returns the handle to the object.

## Return value

*DxgkDdiOPMDestroyProtectedOutput* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

**Note** *DxgkDdiOPMDestroyProtectedOutput* cannot fail if the ProtectedOutputHandle parameter contains a valid protected output handle.

## Remarks

The DirectX graphics kernel subsystem calls *DxgkDdiOPMDestroyProtectedOutput* when it finishes using the protected output object.

*DxgkDdiOPMDestroyProtectedOutput* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiOPMCreateProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output)