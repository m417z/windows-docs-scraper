# IddCxMonitorSetupHardwareCursor function

## Description

An indirect display driver calls **IddCxMonitorSetupHardwareCursor** to setup hardware cursor support for the path.

## Parameters

### `MonitorObject` [in]

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object which is the monitor's OS context handle created by [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs` [in]

An [**IDARG_IN_SETUP_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setup_hwcursor) structure containing this function's input arguments.

## Return value

**IddCxMonitorSetupHardwareCursor** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

By default, software cursor is enabled when a mode is committed on a path. If the driver wants to accelerate the cursor on that path it uses this callback to enable hardware cursor support.

## See also

[**IDARG_IN_SETUP_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setup_hwcursor)

[**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor)

[**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2)