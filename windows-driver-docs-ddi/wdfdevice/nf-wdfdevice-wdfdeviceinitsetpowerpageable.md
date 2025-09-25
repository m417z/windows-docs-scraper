# WdfDeviceInitSetPowerPageable function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetPowerPageable** method informs the power manager that the driver must be able to access [pageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver) data while the system is transitioning between a sleeping state and the working (S0) state.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

If your function driver or bus driver calls **WdfDeviceInitSetPowerPageable**, the system ensures that the paging file's device is in its working (D0) state when your driver's device [enters a low-power state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-enters-a-low-power-state) or [returns to its working state](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state). This allows your driver to access files, the registry, and paged pool during your device's power transitions.

By default, the framework enables access to pageable data for function drivers. The framework uses the parent device's setting for each child device that a bus driver enumerates, unless the bus driver calls either **WdfDeviceInitSetPowerPageable** or [WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable) for the child device. If you write a bus driver that calls **WdfDeviceInitSetPowerPageable** for a child device, no drivers in the child device's stack can call **WdfDeviceInitSetPowerNotPageable**.

Calling **WdfDeviceInitSetPowerPageable** or [WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable) from a filter driver has no effect. The framework uses the setting that the next-lower driver specifies.

Most drivers do not need to call **WdfDeviceInitSetPowerPageable** or [WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable). Instead, you should let the framework use the default setting that is appropriate for your driver. However, your driver should call **WdfDeviceInitSetPowerNotPageable** if the driver is part of a driver stack that must not access pageable data during power transitions (such as the storage stack or the video stack), or if the driver is a bus driver that enumerates devices that might be storage or video devices.

If your driver calls [WdfDeviceInitSetPowerInrush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerinrush), it must not call **WdfDeviceInitSetPowerPageable**.

Your driver must call **WdfDeviceInitSetPowerPageable** before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example informs the power manager that a driver must be able to access pageable data while the system is transitioning between a sleeping state and the working (S0) state.

```cpp
WdfDeviceInitSetPowerPageable(DeviceInit);
```

## See also

[WdfDeviceInitSetPowerNotPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowernotpageable)