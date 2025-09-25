# IddCxMonitorDeparture function

## Description

An indirect display driver (IDD) calls **IddCxMonitorDeparture** to report a monitor departure from the WDDM graphics adapter.

## Parameters

### `MonitorObject` [in]

The [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object for the monitor that is departing.

## Return value

(NTSTATUS) The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method may return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate) creates the [IDDCX_MONITOR](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx-objects) object for an arriving monitor.

## See also

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)