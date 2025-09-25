## Description

**PFN_IDDCXMONITORQUERYHARDWARECURSOR3** is a pointer to an OS callback function that retrieves the current hardware cursor information for the specified monitor.

## Parameters

### `DriverGlobals`

[in] Contains system-defined per-driver data.

### `MonitorObject`

[in] The monitor object that the hardware cursor information is associated with.

### `pInArgs`

[in] Input arguments of function.

### `pOutArgs`

[out] Output arguments of function.

## Return value

**PFN_IDDCXMONITORQUERYHARDWARECURSOR3** returns an NTSTATUS value that indicates the success or failure of the function.

## Remarks

An indirect display driver (IDD) shouldn't use this function pointer to directly. IDDs should instead call [**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3).

## See also

[**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3)