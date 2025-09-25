## Description

An indirect display driver calls **IddCxMonitorUpdateModes2** to have the OS update the mode list for a monitor.

## Parameters

### `MonitorObject`

[in] An [**IDDCX_MONITOR**](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object that is the OS's context handle for the monitor. The OS provided this handle in a prior call to [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

### `pInArgs`

[in] Pointer to an [**IDARG_IN_UPDATEMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes2) structure that contains the input arguments for this function.

## Return value

**IddCxMonitorUpdateModes2** returns STATUS_SUCCESS upon success; otherwise it returns an [appropriate NTSTATUS error code](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A driver can call **IddCxMonitorUpdateModes2** to update the mode list previously reported for a monitor.

Drivers sending modes with SDR WCG or HDR parameters will fail if they have not also reported [**IDDCX_ADAPTER_FLAGS_CAN_PROCESS_FP16**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) in the [**IddCxAdapterInitAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync) call. Also, drivers reporting **IDDCX_ADAPTER_FLAGS_CAN_PROCESS_FP16** can only call **IddCxMonitorUpdateModes2**; calling **IddCxMonitorUpdateModes** is an error.

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**IDARG_IN_UPDATEMODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_updatemodes2)