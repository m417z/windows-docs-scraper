## Description

An indirect display driver calls **IddCxMonitorQueryHardwareCursor3** to retrieve the current hardware cursor information for the specified monitor. This function version adds the SDR white level which a driver must apply to the cursor if the monitor is in an HDR mode.

## Parameters

### `MonitorObject`

[in] An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object which is the monitor's OS context handle created by [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs`

Pointer to an [**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor) structure containing this function's input arguments.

### `pOutArgs`

Pointer to an [**IDARG_OUT_QUERY_HWCURSOR3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor3) structure in which the monitor's current hardware cursor information is returned.

## Return value

**IddCxMonitorQueryHardwareCursor2** returns STATUS_SUCCESS upon success; otherwise it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values). An error code of STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY is a transient error indicating that the **MonitorObject** is not currently in an active path.

## Remarks

**IddCxMonitorQueryHardwareCursor3** retrieves the current hardware cursor information for the specified monitor and places it into the caller-supplied buffer that **pOutArgs** points to. This function is very similar to [**IddCxMonitorQueryHardwareCursor2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorqueryhardwarecursor2), but additionally provides the SDR white level value. The SDR white level is required because all cursor images are in SDR format and the driver needs to ensure they are displayed at the correct brightness.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects)

[**IDARG_IN_QUERY_HWCURSOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_query_hwcursor)

[**IDARG_OUT_QUERY_HWCURSOR3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_query_hwcursor3)

[**IddCxMonitorSetupHardwareCursor**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorsetuphardwarecursor)