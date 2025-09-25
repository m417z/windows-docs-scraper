# WdfDeviceGetDevicePowerPolicyState function

## Description

[Applies to KMDF only]

>[!NOTE]
>This function is for Microsoft-internal use only.

The **WdfDeviceGetDevicePowerPolicyState** method returns the current state of the framework's power policy state machine, for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetDevicePowerPolicyState** returns a [WDF_DEVICE_POWER_POLICY_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_policy_state)-typed enumerator that identifies the current state of the framework's power policy state machine for the specified device.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the framework's state machines, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

The **WdfDeviceGetDevicePowerPolicyState** method returns a meaningful value only if it is called from within the callback functions that the driver registers when it calls [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks).

#### Examples

The following code example obtains the current state of the framework's power policy state machine for a specified device.

```cpp
WDF_DEVICE_POWER_POLICY_STATE devicePowerPolicyState;

devicePowerPolicyState = WdfDeviceGetDevicePowerPolicyState(Device);
```

## See also

[WdfDevStateNormalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevstatenormalize)

[WdfDeviceGetDevicePnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepnpstate)

[WdfDeviceGetDevicePowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerstate)