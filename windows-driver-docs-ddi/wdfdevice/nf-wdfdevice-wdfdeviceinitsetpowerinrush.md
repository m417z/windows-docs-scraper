# WdfDeviceInitSetPowerInrush function

## Description

[Applies to KMDF only]

The **WdfDeviceInitSetPowerInrush** method informs the power manager that the specified device requires an inrush of current when it starts.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

To avoid overloading the system's power supply, the system starts devices that require an inrush of current one at a time.

If your driver calls **WdfDeviceInitSetPowerInrush**, the framework makes it [nonpageable](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-pageable-code-in-a-kmdf-driver) during power state transitions and the driver must not call [WdfDeviceInitSetPowerPageable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpageable).

Your driver must call **WdfDeviceInitSetPowerInrush** before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

Calling **WdfDeviceInitSetPowerInrush** from a filter driver has no effect. For filter drivers, the framework uses the setting that the next-lower driver in the driver stack specifies.

#### Examples

The following code example informs the power manager that a device requires an inrush of current when it starts.

```cpp
WdfDeviceInitSetPowerInrush(DeviceInit);
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)