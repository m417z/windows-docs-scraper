## Description

**PFN_IDDCXMONITORUPDATEMODES2** is a pointer to an OS callback function that updates the mode list for a monitor.

## Parameters

### `DriverGlobals`

[in] Contains system-defined per-driver data.

### `MonitorObject`

[in] The monitor object that the mode list is associated with.

### `pInArgs`

[in] Input arguments for the function.

## Return value

**PFN_IDDCXMONITORUPDATEMODES2** returns an NTSTATUS value that indicates the success or failure of the function.

## Remarks

An indirect display driver (IDD) shouldn't use this function pointer directly. IDDs should instead call [**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2).

## See also

[**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)