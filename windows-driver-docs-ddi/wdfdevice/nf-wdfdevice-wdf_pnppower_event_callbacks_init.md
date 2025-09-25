# WDF_PNPPOWER_EVENT_CALLBACKS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_PNPPOWER_EVENT_CALLBACKS_INIT** function initializes a driver's [WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to a driver-allocated [WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks) structure.

## Remarks

The **WDF_PNPPOWER_EVENT_CALLBACKS_INIT** function zeros the specified [WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks) structure and sets the structure's **Size** member.

#### Examples

For a code example that uses **WDF_PNPPOWER_EVENT_CALLBACKS_INIT**, see [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).