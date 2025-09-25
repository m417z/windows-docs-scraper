# WdfDevStateIsNP function

## Description

[Applies to KMDF and UMDF]

The **WdfDevStateIsNP** method returns a Boolean value that indicates whether a specified power state or power policy state is a [nonpageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver) state.

## Parameters

### `State` [in]

A [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state)-typed enumerator or a [WDF_DEVICE_POWER_POLICY_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_policy_state)-typed enumerator.

## Return value

If the calling driver is currently nonpageable, the **WdfDevStateIsNP** method returns **TRUE**. Otherwise, the method returns **FALSE**.

## Remarks

To obtain the current state of the framework's power state machine, a driver can call [WdfDeviceGetDevicePowerState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerstate) from within a PnP or power callback function. To obtain the current state of the framework's power policy state machine, a driver can call [WdfDeviceGetDevicePowerPolicyState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicepowerpolicystate) from within a power policy callback function. After the driver has called **WdfDeviceGetDevicePowerState** or **WdfDeviceGetDevicePowerPolicyState**, it can call **WdfDevStateIsNP** to determine if the returned state represents a pageable or nonpageable state. If the framework's state machine is in a nonpageable state, the driver is not pageable and must not perform any operations that might cause the operating system to access the paging file. Such operations include accessing files, the registry, or paged pool.

#### Examples

The following code example sets the **nonpageable** value to **TRUE** if the framework's power state machine is currently in a nonpageable state.

```cpp
BOOLEAN nonpageable;

nonpageable = WdfDevStateIsNP(WdfDeviceGetDevicePowerState(device));
```

## See also

[WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable)

[WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable)