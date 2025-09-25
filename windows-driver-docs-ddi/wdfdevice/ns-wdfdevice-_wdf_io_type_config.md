# _WDF_IO_TYPE_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TYPE_CONFIG** structure specifies the driver's preferred buffer access method for read and write requests, and for device I/O control requests.

## Members

### `Size`

Size of this structure in bytes.

### `ReadWriteIoType`

**KMDF** A [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed enumerator that identifies the method that the driver will use to access data buffers
that it receives for read and write requests.

**UMDF** A [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed enumerator that identifies the method that you prefer the driver use to access data buffers of read and write requests. Valid values include **WdfDeviceIoBuffered** and **WdfDeviceIoDirect**.

### `DeviceControlIoType`

This member does not apply to KMDF.

**UMDF** A [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed enumerator that identifies the method that you prefer the driver use for the data
buffers of IOCTL requests. Valid values include **WdfDeviceIoBuffered** and **WdfDeviceIoDirect**.

### `DirectTransferThreshold`

This member does not apply to KMDF.

**UMDF** An optional value that specifies the smallest buffer size, in bytes, for which
the framework will use direct I/O for a device. For example, set
**DirectTransferThreshold** to 12288 to indicate that the framework should use buffered I/O for all buffers that are smaller than 12 kilobytes, and direct I/O for buffers that are equal to or larger than 12 kilobytes. Typically, you
do not need to provide this value because the framework uses settings that provide
the best performance.

## Remarks

The **WDF_IO_TYPE_CONFIG** structure is used as input to the [WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex) method.

To initialize a **WDF_IO_TYPE_CONFIG** structure, your driver should call [WDF_IO_TYPE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_io_type_config_init).

If you are writing a driver using UMDF version 2.0 or later, see [Managing Buffer Access Methods in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/managing-buffer-access-methods-in-umdf-drivers) for more information about specifying preferred buffer access methods.

If you are writing a driver using UMDF version 1.*x*, your driver calls  [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference) to specify preferred buffer access methods.

## See also

[WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)

[WDF_IO_TYPE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_io_type_config_init)

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)