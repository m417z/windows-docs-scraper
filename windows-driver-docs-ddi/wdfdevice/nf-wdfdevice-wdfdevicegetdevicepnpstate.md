# WdfDeviceGetDevicePnpState function

## Description

[Applies to KMDF only]

>[!NOTE]
>This function is for Microsoft-internal use only.

The **WdfDeviceGetDevicePnpState** method returns the current state of the framework's Plug and Play state machine for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetDevicePnpState** returns a [WDF_DEVICE_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_pnp_state)-typed enumerator that identifies the current state of the framework's Plug and Play state machine for the specified device.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about the framework's state machines, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

#### Examples

The following code example obtains the current state of the framework's Plug and Play state machine for a specified device.

```cpp
WDF_DEVICE_PNP_STATE state;

state = WdfDeviceGetDevicePnpState(Device);
```

## See also

[WdfDevStateNormalize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevstatenormalize)

[WdfDeviceGetDevicePowerPolicyState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerpolicystate)

[WdfDeviceGetDevicePowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerstate)