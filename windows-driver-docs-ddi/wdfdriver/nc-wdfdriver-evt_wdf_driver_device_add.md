# EVT_WDF_DRIVER_DEVICE_ADD callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDriverDeviceAdd* event callback function performs device initialization operations when the Plug and Play (PnP) manager reports the existence of a device.

## Parameters

### `Driver` [in]

A handle to a framework driver object that represents the driver.

### `DeviceInit` [in, out]

A pointer to a framework-allocated [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Return value

The*EvtDriverDeviceAdd* callback function must return STATUS_SUCCESS if the operation succeeds. Otherwise, this callback function must return one of the error status values that are defined in *Ntstatus.h*. For more information, see the following Remarks section.

## Remarks

Each framework-based driver that supports PnP devices must provide the *EvtDriverDeviceAdd* callback function. The driver must place the callback function's address in its [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure before calling [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate).

The framework calls your driver's *EvtDriverDeviceAdd* callback function after a bus driver detects a device that has a hardware identifier (ID) that matches a hardware ID that your driver supports. You specify the hardware IDs that your driver supports by providing an INF file, which the operating system uses to install drivers the first time that one of your devices is connected to the computer. For more information about how the system uses INF files and hardware IDs, see [How Setup Selects Drivers](https://learn.microsoft.com/windows-hardware/drivers/install/how-setup-selects-drivers).

A driver's *EvtDriverDeviceAdd* callback function typically performs at least some of the following initialization operations:

* [Create a framework device object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object) to represent the device.
* [Create I/O queues](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-i-o-queues) so the driver can receive I/O requests.
* [Create device interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces) that applications use to communicate with the device.
* [Create driver-defined interfaces](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-driver-defined-interfaces) that other drivers can use.
* Initialize [Windows Management Instrumentation (WMI)](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers) support.
* [Create interrupt objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-an-interrupt-object), if the driver handles device interrupts.
* [Enable direct memory access (DMA) transactions](https://learn.microsoft.com/windows-hardware/drivers/wdf/enabling-dma-transactions), if the driver handles DMA operations.

Some drivers, especially filter drivers, might not create device objects for some devices. If an *EvtDriverDeviceAdd* callback function does not create a device object, it must still return STATUS_SUCCESS unless an error was encountered.

If a driver's *EvtDriverDeviceAdd* callback function creates a device object but does not return STATUS_SUCCESS, the framework deletes the device object and its child devices.

If a function driver's *EvtDriverDeviceAdd* callback function does not return STATUS_SUCCESS, the I/O manager does not build a device stack for the device.

If a filter driver's *EvtDriverDeviceAdd* callback function does not return STATUS_SUCCESS, the framework converts the return value to STATUS_SUCCESS, and the I/O manager builds the device stack without the filter driver.

## See also

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)