## Description

An indirect display driver calls **IddCxMonitorQueryHardwareCursor2** to retrieve the current hardware cursor information for the specified monitor. A driver that reports HDR support must use [**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3) instead.

## Parameters

### `MonitorObject`

[in] An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object which is the monitor's OS context handle created by [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs`

[in] Pointer to an [**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor) structure containing this function's input arguments.

### `pOutArgs`

[out] Pointer to an [**IDARG_OUT_QUERY_HWCURSOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor2) structure in which the monitor's current hardware cursor information is returned.

## Return value

**IddCxMonitorQueryHardwareCursor2** returns STATUS_SUCCESS upon success; otherwise it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The driver normally only calls this function when the event that signals cursor update has triggered.

Although **IddCxMonitorQueryHardwareCursor2** can be used by both console and remote drivers, the additional information provided when compared to [**IddCxMonitorQueryHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor) is only useful for remote drivers.

## See also

[**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects)

[**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor)

[**IDARG_OUT_QUERY_HWCURSOR2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor2)

[**IddCxMonitorQueryHardwareCursor3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor3)

[**IddCxMonitorSetupHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetuphardwarecursor)