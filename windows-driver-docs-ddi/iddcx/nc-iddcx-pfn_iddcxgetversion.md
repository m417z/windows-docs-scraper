# PFN_IDDCXGETVERSION callback function

## Description

**PFN_IDDCXGETVERSION** is a pointer to an OS callback function that gets the IddCx (Indirect Display Driver Class eXtension) version.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_GETVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getversion) structure in which the driver will return the current IddCx version.

## Return value

(NTSTATUS) **PFN_IDDCXGETVERSION** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion).

## See also

[**IDARG_OUT_GETVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_getversion)

[*IddCxGetVersion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxgetversion)