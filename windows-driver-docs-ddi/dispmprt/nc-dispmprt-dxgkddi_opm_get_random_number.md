# DXGKDDI_OPM_GET_RANDOM_NUMBER callback function

## Description

The *DxgkDdiOPMGetRandomNumber* function retrieves the given protected output object's 128-bit cryptographically secure random number.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. Previously, the display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `ProtectedOutputHandle` [in]

The handle to a protected output object. The [DxgkDdiOPMCreateProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output) function creates the protected output object and returns the handle to the object.

### `RandomNumber` [out]

A pointer to a [DXGKMDT_OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_random_number) structure that receives the protected output object's 128-bit cryptographically secure random number if *DxgkDdiOPMGetRandomNumber* returns successfully.

If *DxgkDdiOPMGetRandomNumber* fails, the value that *RandomNumber* points to is unchanged.

Each protected output object must have a different 128-bit cryptographically secure random number associated with it.

## Return value

*DxgkDdiOPMGetRandomNumber* returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes that are defined in *Ntstatus.h*.

## Remarks

*DxgkDdiOPMGetRandomNumber* is called only once for each protected output and is never called after the call to the [DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers) function occurs.

For more information about cryptographically secure random numbers, see section 2.8 in *Applied Cryptography*, Second Edition.

*DxgkDdiOPMGetRandomNumber* should be made pageable.

## See also

[DXGKMDT_OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgkmdt_opm_random_number)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiOPMCreateProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_create_protected_output)

[DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)