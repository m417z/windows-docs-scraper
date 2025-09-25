# IddCxMonitorQueryHardwareCursor function

## Description

An indirect display driver calls **IddCxMonitorQueryHardwareCursor** to obtain updated hardware cursor information for the specified monitor. A driver that reports HDR support must use [**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3) instead.

## Parameters

### `MonitorObject` [in]

An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object which is the monitor's OS context handle created by [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs` [in]

An [**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor) structure containing this function's input arguments.

### `pOutArgs` [out]

An [**IDARG_OUT_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor) structure in which the monitor's current hardware cursor information is returned.

## Return value

**IddCxMonitorQueryHardwareCursor** returns STATUS_SUCCESS if the operation succeeds; otherwise, it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The driver normally only calls this function when [the event that signals cursor update](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_setup_hwcursor) has triggered.

For additional cursor information beyond what this function returns, call [**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2) or [**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3).

## See also

[**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects)

[**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor)

[**IDARG_OUT_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor)

[**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2)

[**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3)

[**IddCxMonitorSetupHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetuphardwarecursor)