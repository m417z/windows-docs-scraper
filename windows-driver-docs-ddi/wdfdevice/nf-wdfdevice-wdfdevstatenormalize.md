# WdfDevStateNormalize function

## Description

[Applies to KMDF and UMDF]

The **WdfDevStateNormalize** method removes extra bits from a specified framework state machine value so that the driver can use the value as an index into an array of machine states.

## Parameters

### `State` [in]

A state machine value that is returned from [WdfDeviceGetDevicePnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepnpstate), [WdfDeviceGetDevicePowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerstate), or [WdfDeviceGetDevicePowerPolicyState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerpolicystate).

## Return value

**WdfDevStateNormalize** returns the specified *State* value with extra bits removed.