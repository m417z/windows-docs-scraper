# _WDF_PNPPOWER_EVENT_CALLBACKS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_PNPPOWER_EVENT_CALLBACKS** structure contains pointers to a driver's Plug and Play and power event callback functions.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceD0Entry`

A pointer to the driver's [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) event callback function, or **NULL**.

### `EvtDeviceD0EntryPostInterruptsEnabled`

A pointer to the driver's [EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled) event callback function, or **NULL**.

### `EvtDeviceD0Exit`

A pointer to the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) event callback function, or **NULL**.

### `EvtDeviceD0ExitPreInterruptsDisabled`

A pointer to the driver's [EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled) event callback function, or **NULL**.

### `EvtDevicePrepareHardware`

A pointer to the driver's [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) event callback function, or **NULL**.

### `EvtDeviceReleaseHardware`

A pointer to the driver's [EvtDeviceReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_release_hardware) event callback function, or **NULL**.

### `EvtDeviceSelfManagedIoCleanup`

A pointer to the driver's [EvtDeviceSelfManagedIoCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) event callback function, or **NULL**.

### `EvtDeviceSelfManagedIoFlush`

A pointer to the driver's [EvtDeviceSelfManagedIoFlush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_flush) event callback function, or **NULL**.

### `EvtDeviceSelfManagedIoInit`

A pointer to the driver's [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init) event callback function, or **NULL**.

### `EvtDeviceSelfManagedIoSuspend`

A pointer to the driver's [EvtDeviceSelfManagedIoSuspend](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_suspend) event callback function, or **NULL**.

### `EvtDeviceSelfManagedIoRestart`

A pointer to the driver's [EvtDeviceSelfManagedIoRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_restart) event callback function, or **NULL**.

### `EvtDeviceSurpriseRemoval`

A pointer to the driver's [EvtDeviceSurpriseRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_surprise_removal) event callback function, or **NULL**.

### `EvtDeviceQueryRemove`

A pointer to the driver's [EvtDeviceQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_query_remove) event callback function, or **NULL**.

### `EvtDeviceQueryStop`

A pointer to the driver's [EvtDeviceQueryStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_query_stop) event callback function, or **NULL**.

### `EvtDeviceUsageNotification`

A pointer to the driver's [EvtDeviceUsageNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification) event callback function, or **NULL**.

### `EvtDeviceRelationsQuery`

A pointer to the driver's [EvtDeviceRelationsQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_relations_query) event callback function, or **NULL**.

### `EvtDeviceUsageNotificationEx`

A pointer to the driver's [EvtDeviceUsageNotificationEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification_ex) event callback function, or **NULL**. The **EvtDeviceUsageNotificationEx** member is available in version 1.11 and later versions of KMDF.
A driver can register either **EvtDeviceRelationsQuery** or **EvtDeviceUsageNotificationEx**, but not both.

## Remarks

The **WDF_PNPPOWER_EVENT_CALLBACKS** structure is used as input to the [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks) method.

Your driver should initialize its WDF_PNPPOWER_EVENT_CALLBACKS structure by calling [WDF_PNPPOWER_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_pnppower_event_callbacks_init).

## See also

[WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks)