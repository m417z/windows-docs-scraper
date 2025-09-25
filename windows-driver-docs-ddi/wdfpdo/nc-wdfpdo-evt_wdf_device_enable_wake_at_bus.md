# EVT_WDF_DEVICE_ENABLE_WAKE_AT_BUS callback function

## Description

[Applies to KMDF only]

A bus driver's *EvtDeviceEnableWakeAtBus* event callback function performs bus-level operations that enable one of the bus's devices to trigger a wake-up signal on the bus.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PowerState` [in]

A SYSTEM_POWER_STATE-typed enumerator that identifies the system power state that the system or device will wake from.

## Return value

If the *EvtDeviceEnableWakeAtBus* callback function encountered no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceDisableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_disable_wake_at_bus) callback function.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register this callback function, the bus driver must call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

For more information about this callback function, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

## See also

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)

[EvtDeviceDisableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_disable_wake_at_bus)