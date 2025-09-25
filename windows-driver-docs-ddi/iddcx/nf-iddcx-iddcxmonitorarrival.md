# IddCxMonitorArrival function

## Description

An indirect display driver (IDD) calls **IddCxMonitorArrival** to report a monitor arrival on the WDDM graphics adapter.

## Parameters

### `MonitorObject` [in]

The [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object for the monitor that arrived.

### `pOutArgs` [out]

Pointer to an [**IDARG_OUT_MONITORARRIVAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorarrival) structure in which to return details about the monitor that arrived.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

An IDD must first call [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate) to obtain the [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object.

## See also

[**IDARG_OUT_MONITORARRIVAL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorarrival)

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)

[**IddCxMonitorDeparture**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitordeparture)