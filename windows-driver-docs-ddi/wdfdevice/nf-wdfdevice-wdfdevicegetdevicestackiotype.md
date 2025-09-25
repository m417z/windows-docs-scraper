# WdfDeviceGetDeviceStackIoType function

## Description

[Applies to UMDF only]

The **WdfDeviceGetDeviceStackIoType** method retrieves the buffer access methods that the framework is using for a device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `ReadWriteIoType` [out]

A pointer to a driver-allocated location that receives a [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value. This value identifies the buffer access method that the framework is using for a device's read and write requests.

### `IoControlIoType` [out]

A pointer to a driver-allocated location that receives a [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value. This value that identifies the buffer access method that the framework is using for a device's I/O control requests.

## Remarks

If your driver calls **WdfDeviceGetDeviceStackIoType** before the PnP manager has loaded all of the device's drivers, the values that **WdfDeviceGetDeviceStackIoType** retrieves might not be the values that it actually uses.

For more information about how the framework chooses a buffer access method, see [Managing Buffer Access Methods in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-buffer-access-methods-in-umdf-drivers).

## See also

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)