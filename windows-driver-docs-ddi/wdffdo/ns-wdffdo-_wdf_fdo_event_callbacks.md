# _WDF_FDO_EVENT_CALLBACKS structure

## Description

[Applies to KMDF only]

The **WDF_FDO_EVENT_CALLBACKS** structure contains pointers to a function driver's PnP event callback functions.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceFilterAddResourceRequirements`

A pointer to the driver's [EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) event callback function, or **NULL**.

### `EvtDeviceFilterRemoveResourceRequirements`

A pointer to the driver's [EVT_WDF_DEVICE_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) event callback function, or **NULL**.

### `EvtDeviceRemoveAddedResources`

A pointer to the driver's [EvtDeviceRemoveAddedResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_remove_added_resources) event callback function, or **NULL**.

## Remarks

The **WDF_FDO_EVENT_CALLBACKS** structure is used as input to the [WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks) method.

Drivers must call [WDF_FDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdf_fdo_event_callbacks_init) to initialize the structure.

A driver that specifies an [EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements) event callback function must also specify an [EvtDeviceRemoveAddedResources](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_remove_added_resources) event callback function.

## See also

[WDF_FDO_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdf_fdo_event_callbacks_init)

[WDF_PDO_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/ns-wdfpdo-_wdf_pdo_event_callbacks)

[WdfFdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitseteventcallbacks)

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)