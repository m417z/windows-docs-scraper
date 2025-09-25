# WDF_POWER_POLICY_EVENT_CALLBACKS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_POLICY_EVENT_CALLBACKS_INIT** function initializes a driver's [WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to a driver-allocated [WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks) structure.

## Remarks

The **WDF_POWER_POLICY_EVENT_CALLBACKS_INIT** function zeros the specified [WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks) structure and sets the structures **Size** member.

#### Examples

For a code example that uses **WDF_POWER_POLICY_EVENT_CALLBACKS_INIT**, see [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks).