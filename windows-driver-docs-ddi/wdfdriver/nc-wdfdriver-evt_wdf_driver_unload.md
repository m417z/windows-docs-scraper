# EVT_WDF_DRIVER_UNLOAD callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDriverUnload* event callback function performs operations that must take place before the driver is unloaded.

## Parameters

### `Driver` [in]

A handle to a framework driver object.

## Remarks

A driver registers an *EvtDriverUnload* callback function when it calls [**WdfDriverCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate).

The *EvtDriverUnload* callback function must deallocate any non-device-specific system resources that the driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine allocated.

The framework does not call a driver's *EvtDriverUnload* callback function if the driver's [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine returns an error status value.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)