# WdfDeviceInitSetIoType function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetIoType** method sets the method or preference for how a driver will access the data buffers that are included in read and write requests for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `IoType` [in]

A [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed enumerator that identifies the method that the driver will use to access data buffers that it receives for read and write requests.

## Remarks

**KMDF** If you are writing a new driver using KMDF version 1.13 or later, you should instead use [WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex). Calling **WdfDeviceInitSetIoType** from a KMDF filter driver has no effect. For filter drivers, the framework uses the I/O type specified by the next-lower driver in the driver stack.

**UMDF** If you are converting a KMDF driver that calls **WdfDeviceInitSetIoType** to UMDF version 2.0 or later, your converted driver can continue to call **WdfDeviceInitSetIoType** without issue. However, if you are writing an entirely new driver using UMDF version 2.0 or later, you should instead use [WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex).

If a driver calls **WdfDeviceInitSetIoType**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information about calling **WdfDeviceCreate**, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

If the driver does not call **WdfDeviceInitSetIoType**, the framework sets the driver's buffer-access method to **WdfDeviceIoBuffered**, for the specified device.

For more information about buffer-access methods, see [Accessing Data Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example indicates that a driver will use the direct I/O method when it accesses the device.

```cpp
WdfDeviceInitSetIoType(
                       DeviceInit,
                       WdfDeviceIoDirect
                       );
```

## See also

 [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference)

[WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)