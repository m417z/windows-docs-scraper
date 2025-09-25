# EVT_WDF_DEVICE_REPORTED_MISSING callback function

## Description

[Applies to KMDF only]

 A bus driver's *EvtDeviceReportedMissing* event callback function informs the driver that the framework has reported the physical device object (PDO) missing to the Plug and Play manager.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

Framework-based bus drivers can provide an *EvtDeviceReportedMissing* callback function. To register this callback function, the bus driver must call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

The framework calls *EvtDeviceReportedMissing* when processing a [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request for **BusRelations** from the PnP manager.

Most framework-based bus drivers do not need to provide this callback function.

## See also

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)