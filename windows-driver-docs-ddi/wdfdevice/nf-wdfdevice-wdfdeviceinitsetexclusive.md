# WdfDeviceInitSetExclusive function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetExclusive** method indicates whether a specified device is an exclusive device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `IsExclusive` [in]

A Boolean value which, if **TRUE**, indicates that the device is an exclusive device. If **FALSE**, the device is not an exclusive device.

## Remarks

If a driver calls **WdfDeviceInitSetExclusive**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

If a driver calls **WdfDeviceInitSetExclusive**, only that driver's device object is exclusive. To make a device's entire device stack exclusive, the device's INF file should include an [INF AddReg directive](https://learn.microsoft.com/windows-hardware/drivers/install/inf-addreg-directive) that sets an **Exclusive** entry to **TRUE** in the registry.

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

If you are writing a UMDF driver, you must modify your driver's INF file or make registry changes to indicate whether the device is exclusive. For more information about using the registry, see [Setting Device Object Registry Properties During Installation](https://learn.microsoft.com/windows-hardware/drivers/kernel/setting-device-object-registry-properties-during-installation).

#### Examples

The following code example indicates that a device is an exclusive device.

```cpp
WdfDeviceInitSetExclusive(
                          DeviceInit,
                          TRUE
                          );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)