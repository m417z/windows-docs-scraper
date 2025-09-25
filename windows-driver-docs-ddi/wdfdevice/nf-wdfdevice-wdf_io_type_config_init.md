# WDF_IO_TYPE_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TYPE_CONFIG_INIT** function initializes a driver's [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure.

## Parameters

### `IoTypeConfig` [out]

A pointer to a driver-allocated [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure.

## Remarks

The **WDF_IO_TYPE_CONFIG_INIT** function zeros the specified [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure and sets the structure's **Size** member. It then sets the **ReadWriteIoType** member to **WdfDeviceIoBuffered**, and the **DeviceControlIoType** member to **WdfDeviceIoBuffered**.

#### Examples

For a code example that uses **WDF_IO_TYPE_CONFIG_INIT**, see [WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex).

## See also

[WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config)

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)