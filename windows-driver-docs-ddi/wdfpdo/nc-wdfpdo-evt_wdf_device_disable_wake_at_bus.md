# EVT_WDF_DEVICE_DISABLE_WAKE_AT_BUS callback function

## Description

[Applies to KMDF only]

A bus driver's *EvtDeviceDisableWakeAtBus* event callback function performs bus-level operations that disable the ability of one of the bus's devices to trigger a wake-up signal on the bus.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Remarks

To register this callback function, the bus driver must call [WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks).

For more information about this callback function, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

## See also

[WdfPdoInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitseteventcallbacks)

[EvtDeviceEnableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_enable_wake_at_bus)