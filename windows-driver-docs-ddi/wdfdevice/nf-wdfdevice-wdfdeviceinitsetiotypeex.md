# WdfDeviceInitSetIoTypeEx function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetIoTypeEx** method sets the method or preference for how a driver will access the data buffers that are included in read and write requests, as well as device I/O control requests, for a specified device.

## Parameters

### `DeviceInit` [in]

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `IoTypeConfig` [in]

Pointer to [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure initialized using WDF_IO_TYPE_CONFIG_INIT macro.

## Remarks

If you are writing a driver using KMDF version 1.11 or earlier, you must instead use [WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype).

**KMDF** A KMDF driver calls **WdfDeviceInitSetIoTypeEx** to set a buffer-access method for read and write requests. For device I/O control requests, the framework uses the buffer type that is encoded in the I/O control code (IOCTL).

**UMDF** A UMDF driver calls **WdfDeviceInitSetIoTypeEx** to register preferences for read and write requests, as well as device I/O control requests. The values that a UMDF driver provides to **WdfDeviceInitSetIoTypeEx** are only preferences, and are not guaranteed to be used by the framework. Your driver can call [WdfDeviceGetDeviceStackIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicestackiotype) to determine the buffer access methods that UMDF has assigned to a device's read/write requests and I/O control requests. For I/O control requests, the access method that the framework uses might differ from the access method specified in the IOCTL and the access method requested by the driver.

If a driver calls **WdfDeviceInitSetIoTypeEx**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

If the driver does not call **WdfDeviceInitSetIoTypeEx**, the framework sets the driver's buffer-access method to **WdfDeviceIoBuffered**, for the specified device.

Calling **WdfDeviceInitSetIoTypeEx** from a KMDF filter driver has no effect. For KMDF filter drivers, the framework uses the I/O type that the next-lower driver in the driver stack specifies.

A UMDF filter driver can, however, register preferences for buffer-access method by calling **WdfDeviceInitSetIoTypeEx**.

All UMDF drivers in a driver stack must use the same method for accessing a device's buffers. If UMDF determines that some drivers prefer either buffered I/O or direct I/O for a device while other drivers prefer only buffered I/O for the device, UMDF uses buffered I/O for all drivers. If one or more of a stack's drivers prefer only buffered I/O while others prefer only direct I/O, UMDF logs an event to the system event log and does not start the driver stack.

For more information about buffer-access methods, see [Accessing Data Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

This method is the UMDF 2.0 equivalent of  [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference).

#### Examples

The following code example initializes a [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure, sets the driver's buffer-access preferences to direct I/O, specifies that transfers smaller than 32 KB should use buffered I/O, and calls **WdfDeviceInitSetIoTypeEx**.

```cpp
WDF_IO_TYPE_CONFIG ioConfig;
WDF_IO_TYPE_CONFIG_INIT(&ioConfig);
ioConfig.ReadWriteIoType = WdfDeviceIoDirect;
ioConfig.DeviceControlIoType = WdfDeviceIoDirect;
ioConfig.DirectTransferThreshold = 32;

WdfDeviceInitSetIoTypeEx(DeviceInit, &ioConfig);
}

```

## See also

 [IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference)

[WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config)

[WDF_IO_TYPE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_io_type_config_init)

[WdfDeviceGetDeviceStackIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetdevicestackiotype)

[WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype)