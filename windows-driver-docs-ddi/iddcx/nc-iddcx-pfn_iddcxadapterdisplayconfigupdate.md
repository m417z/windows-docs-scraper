# PFN_IDDCXADAPTERDISPLAYCONFIGUPDATE callback function

## Description

**PFN_IDDCXADAPTERDISPLAYCONFIGUPDATE** is a pointer to an OS callback function that updates the display configuration for the remote session.

## Parameters

### `DriverGlobals` [in]

Pointer to an [**IDD_DRIVER_GLOBALS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idd_driver_globals) structure containing system-defined per-driver data.

### `AdapterObject` [in]

The adapter object of the remote adapter that the display configuration is specified for.

### `pInArgs` [in]

Input arguments.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS Values error code.

## Remarks

An indirect display driver (IDD) should not use this pointer to directly call the function that it points to. IDDs should instead call [**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate).

## See also

[**IddCxAdapterDisplayConfigUpdate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterdisplayconfigupdate)