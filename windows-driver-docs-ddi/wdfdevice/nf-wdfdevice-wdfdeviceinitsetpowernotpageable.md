# WdfDeviceInitSetPowerNotPageable function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetPowerNotPageable** method informs the power manager that the driver will not access [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver) data while the system is transitioning between a sleeping state and the working (S0) state.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

If your function driver or bus driver calls **WdfDeviceInitSetPowerNotPageable**, the system paging file's device might not be in its working (D0) state when your driver's device [enters a low-power state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state) or [returns to its working state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state). Therefore, during your device's power transitions, your driver must not perform any operations that might cause the operating system to access the paging file. Such operations include accessing files, the registry, or paged pool.

By default, the framework enables access to pageable data for function drivers. The framework uses the parent device's setting for each child device that a bus driver enumerates, unless the bus driver calls either [WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable) or **WdfDeviceInitSetPowerNotPageable** for the child device. If you write a bus driver that calls **WdfDeviceInitSetPowerPageable** for a child device, no drivers in the child device's stack can call **WdfDeviceInitSetPowerNotPageable**.

Calling [WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable) or **WdfDeviceInitSetPowerNotPageable** from a filter driver has no effect. The framework uses the setting that the next-lower driver specifies.

Most drivers do not need to call [WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable) or **WdfDeviceInitSetPowerNotPageable**. Instead, you should let the framework use the default setting that is appropriate for your driver. However, your driver should call **WdfDeviceInitSetPowerNotPageable** if the driver is part of a driver stack that must not access pageable data during power transitions (such as the storage stack or the video stack), or if the driver is a bus driver that enumerates devices that might be storage or video devices.

If your driver calls **WdfDeviceInitSetPowerNotPageable**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example informs the power manager that a driver will not access pageable data while the system is transitioning between a sleeping state and the working (S0) state.

```cpp
WdfDeviceInitSetPowerNotPageable(DeviceInit);
```

## See also

[WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable)