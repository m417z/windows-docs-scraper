# WdfDeviceInitSetPowerPolicyOwnership function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetPowerPolicyOwnership** method establishes whether the calling driver is, or is not, the power policy owner for a specified device.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `IsPowerPolicyOwner` [in]

A Boolean value that indicates whether the calling driver is the power policy owner. If **TRUE**, the calling driver is the power policy owner. If **FALSE**, it is not the power policy owner.

## Remarks

If you are writing a framework-based function driver, the framework automatically establishes your driver as the power policy owner. (If the device operates in raw mode, the bus driver is the default power policy owner.)

To change the default power policy owner, the following two drivers must call **WdfDeviceInitSetPowerPolicyOwnership**:

* The default power policy owner must call **WdfDeviceInitSetPowerPolicyOwnership** with *IsPowerPolicyOwner* set to **FALSE**.
* The driver that you want to be the power policy owner must call **WdfDeviceInitSetPowerPolicyOwnership** with *IsPowerPolicyOwner* set to **TRUE**.

If you are writing a framework-based bus driver or filter driver, and if the device does not operate in raw mode, your driver will not be the power policy owner unless it calls **WdfDeviceInitSetPowerPolicyOwnership**.

Only one driver in each stack can be the power policy owner, so you must ensure that only one driver calls **WdfDeviceInitSetPowerPolicyOwnership** with *IsPowerPolicyOwner* set to **TRUE**.

If your driver calls **WdfDeviceInitSetPowerPolicyOwnership**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about calling **WdfDeviceInitSetPowerPolicyOwnership**, see [Power Policy Ownership](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership).

#### Examples

The following code example is from the [Serial](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example checks a registry value to determine if a driver should be the power policy owner. If the driver should not be the power policy owner, the example calls **WdfDeviceInitSetPowerPolicyOwnership**.

```cpp
//
// Call subroutine that checks a registry value.
//
SerialGetFdoRegistryKeyValue(
                             DeviceInit,
                             L"SerialRelinquishPowerPolicy",
                             &relinquishPowerPolicy
                             );
//
// If the registry value is TRUE, do not own power policy.
//
if(relinquishPowerPolicy) {
    WdfDeviceInitSetPowerPolicyOwnership(
                                         DeviceInit,
                                         FALSE
                                         );
}
```

## See also

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)