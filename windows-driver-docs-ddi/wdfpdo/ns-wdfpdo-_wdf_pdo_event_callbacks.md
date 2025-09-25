# _WDF_PDO_EVENT_CALLBACKS structure

## Description

[Applies to KMDF only]

The **WDF_PDO_EVENT_CALLBACKS** structure is the dispatch table for a bus driver's event callback functions.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceResourcesQuery`

A pointer to the driver's [EvtDeviceResourcesQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resources_query) event callback function, or **NULL**.

### `EvtDeviceResourceRequirementsQuery`

A pointer to the driver's [EvtDeviceResourceRequirementsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_resource_requirements_query) event callback function, or **NULL**.

### `EvtDeviceEject`

A pointer to the driver's [EvtDeviceEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_eject) event callback function, or **NULL**.

### `EvtDeviceSetLock`

A pointer to the driver's [EvtDeviceSetLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_set_lock) event callback function, or **NULL**.

### `EvtDeviceEnableWakeAtBus`

A pointer to the driver's [EvtDeviceEnableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_enable_wake_at_bus) event callback function, or **NULL**.

### `EvtDeviceDisableWakeAtBus`

A pointer to the driver's [EvtDeviceDisableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_disable_wake_at_bus) event callback function, or **NULL**.

### `EvtDeviceReportedMissing`

A pointer to the driver's [EvtDeviceReportedMissing](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_reported_missing) event callback function, or **NULL**. The **EvtDeviceReportedMissing** member is available in version 1.11 and later versions of KMDF.

## Remarks

The **WDF_PDO_EVENT_CALLBACKS** structure is used as input to [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

Drivers must call [WDF_PDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdf_pdo_event_callbacks_init) to initialize this structure.

## See also

[WDF_FDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/ns-wdffdo-_wdf_fdo_event_callbacks)

[WDF_PDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdf_pdo_event_callbacks_init)

[WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks)

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)