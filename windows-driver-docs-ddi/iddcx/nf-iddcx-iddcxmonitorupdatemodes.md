# IddCxMonitorUpdateModes function

## Description

An indirect display driver calls **IddCxMonitorUpdateModes** to have the OS update the mode list for a monitor. A driver that reports HDR support must use [**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2) instead.

## Parameters

### `MonitorObject`

[in] An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that is the OS's context handle for the monitor. The OS provided this handle in a prior call to [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs`

[in] Pointer to an [**IDARG_IN_UPDATEMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes) structure that contains the input arguments for this function.

## Return value

**IddCxMonitorUpdateModes** returns STATUS_SUCCESS upon success; otherwise it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A driver can call **IddCxMonitorUpdateModes** to update the mode list previously reported for a monitor.

## See also

[**IDARG_IN_UPDATEMODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes)

[**IddCxMonitorUpdateModes2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorupdatemodes2)